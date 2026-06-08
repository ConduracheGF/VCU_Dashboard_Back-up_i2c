#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "AS1115.h"
#include "CDD_I2c.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
// adresa slave a driverului
#define DRIVER_SLAVE_ADDRESS 0x00

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
//cerere globala pentru a nu suprascrie in timp ce perifericul transmite
static I2c_RequestType request_write;
static I2c_RequestType request_read;
I2c_RequestType request;

//buffere statice
static uint8_t async_write_buffer[2];
static uint8_t async_read_reg_buffer[1];


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

void AS1115_Write(AS1115Registers_t SelectedRegister, uint8_t Value){
    //structura bufferului
	uint8_t buffer[2] = {
    		(uint8_t)SelectedRegister,
			Value
    };

    //pregatire cerere
    request.SlaveAddress = DRIVER_SLAVE_ADDRESS;
    request.BitsSlaveAddressSize = false;
    request.HighSpeedMode = false;
    request.ExpectNack = false;
    request.RepeatedStart = false;
    request.BufferSize = 2;
    request.DataDirection = I2C_SEND_DATA;
    request.DataBuffer = buffer;

    // trimitem datele si primim statusul livrarii
    I2c_SyncTransmit(I2C_USED_CHANNEL, &request); //cerere pe canalul 0
}

uint8_t AS1115_Read(AS1115Registers_t SelectedRegister){
	uint8_t value = 0;

    //scriem registrul dorit
    request.SlaveAddress = DRIVER_SLAVE_ADDRESS;
    request.BitsSlaveAddressSize = false;
    request.HighSpeedMode = false;
    request.ExpectNack = false;
    request.RepeatedStart = false;
    request.BufferSize = 1;
    request.DataDirection = I2C_SEND_DATA;
    request.DataBuffer = (uint8_t*)&SelectedRegister;

    // trimitem datele si primim statusul livrarii
    I2c_SyncTransmit(I2C_USED_CHANNEL, &request);

    //citim valoarea
    request.SlaveAddress = DRIVER_SLAVE_ADDRESS;
    request.BitsSlaveAddressSize = false;
    request.HighSpeedMode = false;
    request.ExpectNack = false;
    request.RepeatedStart = false;
    request.BufferSize = 1;
    request.DataDirection = I2C_RECEIVE_DATA;
    request.DataBuffer = &value;

    // trimitem datele si primim statusul livrarii
    I2c_SyncTransmit(I2C_USED_CHANNEL, &request);

    return value;
}

void AS1115_Async_Write(AS1115Registers_t SelectedRegister, uint8_t Value){
	//structura bufferului
	async_write_buffer[0] = (uint8_t)SelectedRegister;
	async_write_buffer[1] = Value;

    //pregatire cerere
    request_write.SlaveAddress = DRIVER_SLAVE_ADDRESS;
    request_write.BitsSlaveAddressSize = false;
    request_write.HighSpeedMode = false;
    request_write.ExpectNack = false;
    request_write.RepeatedStart = false;
    request_write.BufferSize = 2;
    request_write.DataDirection = I2C_SEND_DATA;
    request_write.DataBuffer = async_write_buffer;

    // trimitem datele si primim statusul livrarii
    I2c_AsyncTransmit(I2C_USED_CHANNEL, &request_write); //cerere pe canalul 0
}

uint8_t AS1115_Async_Read(AS1115Registers_t SelectedRegister){
	uint8_t value = 0;

	async_read_reg_buffer[0] = (uint8_t)SelectedRegister;

    //scriem registrul dorit
    request_read.SlaveAddress = DRIVER_SLAVE_ADDRESS;
    request_read.BitsSlaveAddressSize = false;
    request_read.HighSpeedMode = false;
    request_read.ExpectNack = false;
    request_read.RepeatedStart = false;
    request_read.BufferSize = 1;
    request_read.DataDirection = I2C_SEND_DATA;
    request_read.DataBuffer = async_read_reg_buffer;

    // trimitem datele si primim statusul livrarii
    I2c_AsyncTransmit(I2C_USED_CHANNEL, &request_read);

    //citim valoarea
    request_read.SlaveAddress = DRIVER_SLAVE_ADDRESS;
    request_read.BitsSlaveAddressSize = false;
    request_read.HighSpeedMode = false;
    request_read.ExpectNack = false;
    request_read.RepeatedStart = false;
    request_read.BufferSize = 1;
    request_read.DataDirection = I2C_RECEIVE_DATA;
    request_read.DataBuffer = &value;

    // trimitem datele si primim statusul livrarii
    I2c_AsyncTransmit(I2C_USED_CHANNEL, &request_read);


    return value;
}

#ifdef __cplusplus
}
#endif
