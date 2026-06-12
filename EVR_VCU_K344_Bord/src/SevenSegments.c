#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Dio.h"
#include "Port.h"
#include "Gpt.h"
#include "stdint.h"
#include "CDD_I2c.h"
#include "AS1115.h"
#include "SevenSegments.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define SCL_PORT						IP_SIUL2
#define SCL_PIN_IDX_CALCULAT			62U
#define SCL_PIN_IDX_NORMAL				14U
#define GPT_RECOVER_CHANNEL  			GptConf_GptChannelConfiguration_GptChannelConfiguration_for_timer_recover_i2c

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
static const SegmentsGroups_t SegmentsGroups = {
	{//DigitGroup_Speed
		DIGIT_0,
		DIGIT_1,
		DIGIT_2
	},
	{//DigitGroup_Battery
		DIGIT_3,
		DIGIT_4,
		DIGIT_5
	},
	{//DigitGroup_Temperature
		DIGIT_6,
		DIGIT_7
	}
};

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
// -- SPEED_KMH pentru digiti 0-2
// -- BATTERY_PERCENTAGE pentru digiti 3-5
// -- TEMPERATURE pentru digiti 6-7
static uint8_t displayBuffer[8] = {0};

// -- STAREA CURENTA
static SegmentsState_t i2c_system_state = INITIALIZING;

// -- INDEX PENTRU OPERATII ATOMICE
// index pentru monitorizarea operatiilor atomice de READ/WRITE din fiecare stare
static uint8_t index = 0;
// tot index dar mai junior in care se monitorizeaza scrierea in buffer
static uint8_t indexDigits = 0;
// pentru a face cele 9 clock uri la mana
static uint8_t recover_clk_count = 0;

// -- Variabile de flag pentru state machine
// flag de eroare
static bool i2c_error_flag = false;

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Segments_State_Update(void);
static void Recover_Bus_I2C(void);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

void I2c_Callback(uint8 Event, uint8 Channel){
	if (Channel != I2C_USED_CHANNEL) return;

	if (Event == I2C_MASTER_EVENT_END_TRANSFER) {
		switch (i2c_system_state) {
			case INITIALIZING:
				if (index == 3){
					indexDigits++;
					if (indexDigits >= 8U){
						indexDigits = 0U;
						index++;
					}
				} else {
					index++;
				}
				break;
			case OPERATIONAL:
				indexDigits = (indexDigits + 1U) % 8U;
				break;
			default:
				break;
		}
	}
}
void I2c_ErrorCallback(uint8 Event, uint8 Channel){
	if (Channel != I2C_USED_CHANNEL) return;

		if (Event == I2C_MASTER_EVENT_NACK ||
			Event == I2C_MASTER_EVENT_ARBITRATION_LOST ||
			Event == I2C_MASTER_EVENT_ERROR_FIFO ||
			Event == I2C_MASTER_EVENT_PIN_LOW_TIMEOUT ||
			Event == I2C_MASTER_EVENT_DMA_TRANSFER_ERROR)
		{
			i2c_error_flag = true;
		}
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

static void Recover_Bus_I2C(void) {
	I2c_DeInit();

	//setam pinul cu GPIO si il lasam pe HIGH
	Port_SetPinMode(SCL_PIN_IDX_NORMAL, PORT_MUX_AS_GPIO);
	Dio_WriteChannel(SCL_PIN_IDX_CALCULAT, 1);

	recover_clk_count = 0;

	Gpt_StopTimer(GPT_RECOVER_CHANNEL);
    Gpt_DisableNotification(GPT_RECOVER_CHANNEL);
	Gpt_EnableNotification(GPT_RECOVER_CHANNEL);
    Gpt_StartTimer(GPT_RECOVER_CHANNEL, 160000U);
}

void Timer_Callback(void){
	if (i2c_system_state != I2C_ERROR) return;

	if (recover_clk_count < 18U) {
		Dio_WriteChannel(SCL_PIN_IDX_CALCULAT, (Dio_LevelType)(recover_clk_count % 2U));
	    recover_clk_count++;
	} else {
        Gpt_StopTimer(GPT_RECOVER_CHANNEL);
        Gpt_DisableNotification(GPT_RECOVER_CHANNEL);

	    Port_SetPinMode(SCL_PIN_IDX_NORMAL, PORT_MUX_ALT3);
	    I2c_Init(NULL_PTR);

	    index = 0;
	    indexDigits = 0;
	    recover_clk_count = 255U; // valoare maxima pentru resetare
	}
}


void Segments_Init(void){

}

void Segments_Test(void){
	//variabila de test pentru simularea vitezei
	static uint16_t test_speed = 0;
	//variabila de test pentru simularea bateriei
	static uint16_t test_battery = 110;
	//variabila de test pentru simularea temperaturii
	static uint16_t test_temperature = 0;
	//counter pentru controlul refresh
	static uint32_t loop_counter = 0;

	while(1){
		// -- Actualizam valorile de test
		test_speed = (test_speed + 1) % 10000; //viteza urca pana la 999 km/h
		test_temperature = (loop_counter % 1000); //temperatura variaza intre 20-60 grade

		// -- La fiecare 10 cicluri, consumam o unitate din baterie
		if(loop_counter % 10 == 0){
			if(test_battery > 0){
				test_battery -= 1;
			} else {
				test_battery = 1000;
			}
		}

		// -- Mapam pe grupurile de digituri valorile de test
		Segments_Set(SPEED_KMH, test_speed);
		Segments_Set(BATTERY_PERCENTAGE, test_battery);
		Segments_Set(TEMPERATURE, test_temperature);


		// -- Trimitem tot bufferul catre driverul AS1115 prin I2C
		Segments_Update();

		// -- Controlul vitezei de refresh
		for(volatile uint32_t delay = 0; delay < 50000UL; delay++);
	    loop_counter++;
	}
}

void Segments_Set(SegmentsMonitoredValue_t SelectedMonitor, uint16_t Value){
	// -- SPEED_KMH pentru digiti 0-2
	// -- BATTERY_PERCENTAGE pentru digiti 3-5
	// -- TEMPERATURE pentru digiti 6-7

	switch(SelectedMonitor) {
		case SPEED_KMH:
			//limite de 0-999 kmh
			if(Value > 9999) Value = 9999;

			//valoarea va iesi de forma XYZ
			displayBuffer[SegmentsGroups.DigitGroup_Speed[0]] = (uint8_t)((Value / 10) % 10);
			displayBuffer[SegmentsGroups.DigitGroup_Speed[1]] = (uint8_t)((Value / 100) % 10);
			displayBuffer[SegmentsGroups.DigitGroup_Speed[2]] = (uint8_t)((Value / 1000) % 10);

			//stingem secventa de digituri din fata egale cu 0
			if(((uint8_t)((Value / 1000) % 10)) == 0){
				displayBuffer[SegmentsGroups.DigitGroup_Speed[2]] |= 0x0F;
				if(((uint8_t)((Value / 100) % 10)) == 0){
					displayBuffer[SegmentsGroups.DigitGroup_Speed[1]] |= 0x0F;
				}
			}
			break;
		case BATTERY_PERCENTAGE:
		    //limite de 0.00-100%
		    if(Value > 1000) Value = 1000;

		    if (Value == 1000) {
		        //valoare baterie plina
		        displayBuffer[SegmentsGroups.DigitGroup_Battery[0]] = 0;
		        displayBuffer[SegmentsGroups.DigitGroup_Battery[1]] = 0;
		        displayBuffer[SegmentsGroups.DigitGroup_Battery[2]] = 1;
		    } else {
		        //valori de forma xy.z
		        displayBuffer[SegmentsGroups.DigitGroup_Battery[0]] = (uint8_t)(Value % 10);
		        displayBuffer[SegmentsGroups.DigitGroup_Battery[1]] = ((uint8_t)(Value / 10) % 10) | 0x80;
		        displayBuffer[SegmentsGroups.DigitGroup_Battery[2]] = (uint8_t)(Value / 100);

		        //stingem digitul din fata
		        if (((uint8_t)(Value / 100)) == 0){
		        	displayBuffer[SegmentsGroups.DigitGroup_Battery[2]] |= 0x0F;
		        }
		    }
		    break;
		case TEMPERATURE:
			//limite de 0-60 grade Celsius
			if(Value > 999) Value = 999;

			//valoarea va iesi de forma XY
			displayBuffer[SegmentsGroups.DigitGroup_Temperature[0]] = (uint8_t)((Value / 10) % 10);
			displayBuffer[SegmentsGroups.DigitGroup_Temperature[1]] = (uint8_t)((Value / 100) % 10);

			//stingem primul digit daca e 0
			if(((uint8_t)((Value / 100) % 10)) == 0){
				displayBuffer[SegmentsGroups.DigitGroup_Temperature[1]] |= 0x0F;
			}
	        break;
	    default:
		    break;
	}
}

void Segments_Update(void){
	//modificam starea sistemului inainte de executie
	Segments_State_Update();

	// Inlocuitor nativ pentru i2c_tx_in_progress prin interogarea statusului hardware al canalului
	if (i2c_system_state != I2C_ERROR) {
		if (
				I2c_GetStatus(I2C_USED_CHANNEL) == I2C_CH_SEND ||
				I2c_GetStatus(I2C_USED_CHANNEL) == I2C_CH_RECEIVE
			) {
				return; //daca transmite protejam busul
			}
		}

	switch (i2c_system_state) {
		case INITIALIZING:
			//dupa revenirea din eroare, resetam pentru timer
			if (recover_clk_count == 255U){
				recover_clk_count = 0U;
			}

			switch (index) {
				case 0:
					AS1115_Async_Write(SHUTDOWN, 0x00);
					break;
				case 1:
					AS1115_Async_Write(GLOBAL_INTENSITY, 0x0F);
					break;
				case 2:
					AS1115_Async_Write(FEATURE, 0x00);
					break;
				case 3:
					// -- Se pune cifra cu cifra
					AS1115_Async_Write((AS1115Registers_t)(DIGIT0 + indexDigits), 0x0F);
					break;
				case 4:
					// -- Seteaza cati pini folosim de la dig0 pana la dig7 [ex: 0x00 - dig0 | 0x03 - dig0 -> dig3]
					AS1115_Async_Write(SCAN_LIMIT, 0x07);
					break;
				case 5:
					// -- Seteaza pana la ce pin folosim decodificare pe digits [ex: 0x03 - 00000011 - Decodifica pe dig0 si dig1, ne luam dupa pozitia bitilor de la LSB la MSB]
					AS1115_Async_Write(DECODE_MODE, 0xFF);
					break;
				case 6:
					// -- Seteaza Normal Mode fara modificari la Feature Register
					AS1115_Async_Write(SHUTDOWN, 0x81);
					break;
				case 7:
					//se face tranzitia din Segments_State_Update
					break;
				default:
					break;
			}
			break;

		case I2C_ERROR:
			//pornim reinitializarea bus-ului o singura data
			if (recover_clk_count == 0U) {
				Recover_Bus_I2C();
				recover_clk_count = 1U; // evitam reapelarea functiei
				i2c_error_flag = false;
			}
			break;

		case OPERATIONAL:
            // indexDigits avanseaza in callback dupa fiecare END_TRANSFER
            AS1115_Async_Write((AS1115Registers_t)(DIGIT0 + indexDigits),displayBuffer[indexDigits]);
            break;
	}
}

static void Segments_State_Update(void){
	switch(i2c_system_state){
		case INITIALIZING:
			if ( i2c_error_flag == false && index == 7 ) {
				i2c_system_state = OPERATIONAL;
				index = 0;
				indexDigits = 0;
			} else if ( i2c_error_flag == true ) {
				i2c_system_state = I2C_ERROR;
			}
			break;
		case I2C_ERROR:
			if (recover_clk_count == 255U){
				i2c_system_state = INITIALIZING;
			}
			break;
		case OPERATIONAL:
			if (i2c_error_flag == true) {
			    i2c_system_state = I2C_ERROR;
			}
			break;
	}
}

#ifdef __cplusplus
}
#endif

/** @} */
