/* 
 * i2c.c
 *
 * Evan Hassman
 * ehassman@google.com
 * July 14, 2020
 *
 */

#ifndef I2C_H_
#define I2C_H_

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "fsl_i2c_cmsis.h"

static ARM_DRIVER_I2C *I2Cdrv = &Driver_I2C0;

// I2C_SignalEvent from CMSIS I2C Sample code
static volatile uint32_t I2C_Event;

void I2C_SignalEvent (uint32_t event);

void I2C_Init();

void I2C_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending);

#endif /* I2C_H_ */
