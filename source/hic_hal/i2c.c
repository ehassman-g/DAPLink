/* 
 * i2c.c
 *
 * Evan Hassman
 * ehassman@google.com
 * July 14, 2020
 *
 */

#include "i2c.h"

/* I2C Signal Event function callback */
void I2C_SignalEvent (uint32_t event) {
 
  /* Save received events */
  I2C_Event |= event;
 
  /* Optionally, user can define specific actions for an event */
 
  if (event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) {
    /* Less data was transferred than requested */
  }
 
  if (event & ARM_I2C_EVENT_TRANSFER_DONE) {
    /* Transfer or receive is finished */
  }
 
  if (event & ARM_I2C_EVENT_ADDRESS_NACK) {
    /* Slave address was not acknowledged */
  }
 
  if (event & ARM_I2C_EVENT_ARBITRATION_LOST) {
    /* Master lost bus arbitration */
  }
 
  if (event & ARM_I2C_EVENT_BUS_ERROR) {
    /* Invalid start/stop position detected */
  }
 
  if (event & ARM_I2C_EVENT_BUS_CLEAR) {
    /* Bus clear operation completed */
  }
 
  if (event & ARM_I2C_EVENT_GENERAL_CALL) {
    /* Slave was addressed with a general call address */
  }
 
  if (event & ARM_I2C_EVENT_SLAVE_RECEIVE) {
    /* Slave addressed as receiver but SlaveReceive operation is not started */
  }
 
  if (event & ARM_I2C_EVENT_SLAVE_TRANSMIT) {
    /* Slave addressed as transmitter but SlaveTransmit operation is not started */
  }
}


void I2C_Init() {
    /* I2C driver instance */
    #if defined(I2C0)
    static ARM_DRIVER_I2C *I2Cdrv = &Driver_I2C0;
    #endif
    
    #if defined(I2C1)
    static ARM_DRIVER_I2C *I2Cdrv = &Driver_I2C1;
    #endif
    
    #if defined(I2C2)
    static ARM_DRIVER_I2C *I2Cdrv = &Driver_I2C2;
    #endif
    
    #if defined(I2C3)
    static ARM_DRIVER_I2C *I2Cdrv = &Driver_I2C3;
    #endif
    
    // Set external crystal oscillator freq.
    // 8MHz
    CLOCK_SetXtal0Freq(8000000);
    
    I2Cdrv->Initialize  (I2C_SignalEvent);
    I2Cdrv->PowerControl(ARM_POWER_FULL);
    I2Cdrv->Control     (ARM_I2C_BUS_SPEED, ARM_I2C_BUS_SPEED_FAST);
    I2Cdrv->Control     (ARM_I2C_BUS_CLEAR, 0);
}
