#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "stdint.h"
#include "CDD_I2c.h"
#include "SevenSegments.h"
#include "AS1115.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


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
static SegmentsState_t g_sistem_state = INITIALIZING;

// -- Variabile de flag pentru state machine
static uint8_t index = 0;
static uint8_t reset_flag = 0;
static bool i2c_success = true;
static bool timeout = false;
static bool recovery = false;
static bool nack = false;
//
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void Segments_Init(void){

	// -- Flag pentru resetarea sistemului
	reset_flag = 0;

	// -- Seteaza modul Shutdown cu Reset Feature Register
	AS1115_Write(SHUTDOWN, 0x00);

	// -- Seteaza Luminozitatea Globala la 7 Segment Display-uri
	AS1115_Write(GLOBAL_INTENSITY, 0x0F);

	// -- Schimba Feature Register pentru modul de decodificare al 7 Segment Display
	AS1115_Write(FEATURE, 0x00);

	// -- Seteaza ca toate Segmentele de pe display sa fie stinse
	for(uint8_t i = 0; i < 8; i++){
		//pentru teste poti pune 4
		AS1115_Write((AS1115Registers_t)(DIGIT0 + i), 0x0F);
	}

	// -- Seteaza cati pini folosim de la dig0 pana la dig7 [ex: 0x00 - dig0 | 0x03 - dig0 -> dig3]
	AS1115_Write(SCAN_LIMIT, 0x07);
	//aici era 3 pentru teste pe PCB

	// -- Seteaza pana la ce pin folosim decodificare pe digits [ex: 0x03 - 00000011 - Decodifica pe dig0 si dig1, ne luam dupa pozitia bitilor de la LSB la MSB]
	AS1115_Write(DECODE_MODE, 0xFF);

	// -- Seteaza Normal Mode fara modificari la Feature Register
	AS1115_Write(SHUTDOWN, 0x81);
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
	//pas de scadere al bateriei
	static uint16_t step = 1;

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
		System_Task_Run();

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
			if(Value < 0) Value = 0;
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
			if(Value < 0) Value = 0;
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
			if(Value < 0) Value = 0;
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
    // -- Actualizeaza digitii din bufferul local
	for(uint8_t i = 0; i < 8; i++){
		//aici e 4 pentru teste
		AS1115_Write((AS1115Registers_t)(DIGIT0 + i), displayBuffer[i]);
	}
}

SegmentsState_t System_Get_State(void) {
	return g_sistem_state;
}

void System_Reset(void) {
	g_sistem_state = INITIALIZING;
	reset_flag = 0;
	i2c_success = true;
	recovery = true;
	timeout = false;
	nack = false;

}

void System_Task_Run(void){
	switch (g_sistem_state)
	{
		case INITIALIZING:
			index = 1;

			//facem initializarea
			Segments_Init();

			//verificam cazuri critice
			if ( reset_flag == 1 ) {
				g_sistem_state = INITIALIZING;
			} else if ( i2c_succes == true && timeout == false ) {
				g_sistem_state = OPERATIONAL;
			} else if ( i2c_succes == false ) {
				g_sistem_state = I2C_ERROR;
			}

			break;
	
		case OPERATIONAL:
			//actualizam index
			index = 3;
			
			//afisam date
			Segments_Update();

			//verificari critice
			if ( timeout == false ) {
				g_sistem_state = OPERATIONAL;
			} else if ( timeout == true && nack == true ) {
				g_sistem_state = I2C_ERROR;
			}
			break;
		
		case I2C_ERROR:
			//actualizam index
			index = 2;
			reset_flag = 1;
			System_Reset();

			if( recovery == false ) {
				g_sistem_state = I2C_ERROR;
			} else if ( i2c_success == false && timeout == false && recovery == true) {
				g_sistem_state = INITIALIZING;
			}

			break;
	}
}

#ifdef __cplusplus
}
#endif

/** @} */
