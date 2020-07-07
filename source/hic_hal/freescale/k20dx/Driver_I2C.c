/*
 * Copyright (c) 2013-2020 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include "Driver_I2C.h"
#include "fsl_i2c.h"

/* I2C driver instance */
/*
extern ARM_DRIVER_I2C            Driver_I2C0;
static ARM_DRIVER_I2C *I2Cdrv = &Driver_I2C0;
 */

/* ARM_I2C_Event instance */
static volatile unsigned long I2C_Event;
ARM_I2C_STATUS* status;

#define ARM_I2C_DRV_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0) /* driver version */

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_I2C_API_VERSION,
    ARM_I2C_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_I2C_CAPABILITIES DriverCapabilities = {
    0  /* supports 10-bit addressing */
};

//
//  Functions
//

static ARM_DRIVER_VERSION ARM_I2C_GetVersion(void)
{
  return DriverVersion;
}

static ARM_I2C_CAPABILITIES ARM_I2C_GetCapabilities(void)
{
  return DriverCapabilities;
}

/*!
 * Initializes the I2C peripheral to default configutation in master mode. 
 * Registers the ARM_I2C_SignalEvent callback function.
 *
 */
static int32_t ARM_I2C_Initialize(ARM_I2C_SignalEvent_t cb_event)
{
	if (status->mode) {
		i2c_master_config_t config = {
			.enableMaster = true,
			.baudRate_Bps = 100000,
			.glitchFilterWidth = 0};
		
		I2C_MasterGetDefaultConfig(&config);
		I2C_MasterInit(I2C0, &config, 12000000U);
	}
	
	else {
		i2c_slave_config_t config = {
			.enableSlave = true,
			.enableGeneralCall = false,
			.addressingMode = kI2C_Address7bit,
			.slaveAddress = 0x1DU,
			.enableWakeUp = false,
			.enableBaudRateCtl = false,
			.sclStopHoldTime_ns = 4000};
	
		I2C_SlaveInit(I2C0, &config, 12000000U);
	}

}

static int32_t ARM_I2C_Uninitialize(void)
{
}

static int32_t ARM_I2C_PowerControl(ARM_POWER_STATE state)
{
    switch (state)
    {
    case ARM_POWER_OFF:
        break;

    case ARM_POWER_LOW:
        break;

    case ARM_POWER_FULL:
        break;
    }
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C_MasterReceive(uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C_SlaveTransmit(const uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C_SlaveReceive(uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C_GetDataCount(void)
{
}

static int32_t ARM_I2C_Control(uint32_t control, uint32_t arg)
{
		switch (control)
    {
    case ARM_I2C_OWN_ADDRESS:
        break;

    case ARM_I2C_BUS_SPEED:
			if (status->mode)
        switch (arg)
        {
        case ARM_I2C_BUS_SPEED_STANDARD:
						I2C_MasterSetBaudRate(I2C0, 100000, 12000000U);
            break;
        case ARM_I2C_BUS_SPEED_FAST:
						I2C_MasterSetBaudRate(I2C0, 400000, 12000000U);
            break;
        case ARM_I2C_BUS_SPEED_FAST_PLUS:
						I2C_MasterSetBaudRate(I2C0, 1000000, 12000000U);
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
        }
        break;

    case ARM_I2C_BUS_CLEAR:
        break;

    case ARM_I2C_ABORT_TRANSFER:
        break;

    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
}

static ARM_I2C_STATUS ARM_I2C_GetStatus(void)
{
	return *status;
}

static void ARM_I2C_SignalEvent(uint32_t event)
{
	// Provided in ARM CMSIS example code 
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

// End I2C Interface

extern \
ARM_DRIVER_I2C Driver_I2C0;
ARM_DRIVER_I2C Driver_I2C0 = {
    ARM_I2C_GetVersion,
    ARM_I2C_GetCapabilities,
    ARM_I2C_Initialize,
    ARM_I2C_Uninitialize,
    ARM_I2C_PowerControl,
    ARM_I2C_MasterTransmit,
    ARM_I2C_MasterReceive,
    ARM_I2C_SlaveTransmit,
    ARM_I2C_SlaveReceive,
    ARM_I2C_GetDataCount,
    ARM_I2C_Control,
    ARM_I2C_GetStatus
};
