/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_RCM_REGISTERS_H__
#define __HW_RCM_REGISTERS_H__

#include "regs.h"

/*
 * MK64F12 RCM
 *
 * Reset Control Module
 *
 * Registers defined in this header file:
 * - HW_RCM_SRS0 - System Reset Status Register 0
 * - HW_RCM_SRS1 - System Reset Status Register 1
 * - HW_RCM_RPFC - Reset Pin Filter Control register
 * - HW_RCM_RPFW - Reset Pin Filter Width register
 * - HW_RCM_MR - Mode Register
 *
 * - hw_rcm_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_RCM_BASE
#define HW_RCM_INSTANCE_COUNT (1U) //!< Number of instances of the RCM module.
#define REGS_RCM_BASE (0x4007F000U) //!< Base address for RCM.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_RCM_SRS0 - System Reset Status Register 0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RCM_SRS0 - System Reset Status Register 0 (RO)
 *
 * Reset value: 0x82U
 *
 * This register includes read-only status flags to indicate the source of the
 * most recent reset. The reset state of these bits depends on what caused the MCU
 * to reset. The reset value of this register depends on the reset source: POR
 * (including LVD) - 0x82 LVD (without POR) - 0x02 VLLS mode wakeup due to RESET
 * pin assertion - 0x41 VLLS mode wakeup due to other wakeup sources - 0x01 Other
 * reset - a bit is set if its corresponding reset source caused the reset
 */
typedef union _hw_rcm_srs0
{
    uint8_t U;
    struct _hw_rcm_srs0_bitfields
    {
        uint8_t WAKEUP : 1;            //!< [0] Low Leakage Wakeup Reset
        uint8_t LVD : 1;               //!< [1] Low-Voltage Detect Reset
        uint8_t LOC : 1;               //!< [2] Loss-of-Clock Reset
        uint8_t LOL : 1;               //!< [3] Loss-of-Lock Reset
        uint8_t RESERVED0 : 1;         //!< [4]
        uint8_t WDOGb : 1;             //!< [5] Watchdog
        uint8_t PIN : 1;               //!< [6] External Reset Pin
        uint8_t POR : 1;               //!< [7] Power-On Reset
    } B;
} hw_rcm_srs0_t;
#endif

/*!
 * @name Constants and macros for entire RCM_SRS0 register
 */
//@{
#define HW_RCM_SRS0_ADDR         (REGS_RCM_BASE + 0x0U)

#ifndef __LANGUAGE_ASM__
#define HW_RCM_SRS0              (*(__I hw_rcm_srs0_t *) HW_RCM_SRS0_ADDR)
#define HW_RCM_SRS0_RD()         (HW_RCM_SRS0.U)
#endif
//@}

/*
 * Constants & macros for individual RCM_SRS0 bitfields
 */

/*!
 * @name Register RCM_SRS0, field WAKEUP[0] (RO)
 *
 * Indicates a reset has been caused by an enabled LLWU module wakeup source
 * while the chip was in a low leakage mode. In LLS mode, the RESET pin is the only
 * wakeup source that can cause this reset. Any enabled wakeup source in a VLLSx
 * mode causes a reset. This bit is cleared by any reset except WAKEUP.
 *
 * Values:
 * - 0 - Reset not caused by LLWU module wakeup source
 * - 1 - Reset caused by LLWU module wakeup source
 */
//@{
#define BP_RCM_SRS0_WAKEUP   (0U)          //!< Bit position for RCM_SRS0_WAKEUP.
#define BM_RCM_SRS0_WAKEUP   (0x01U)       //!< Bit mask for RCM_SRS0_WAKEUP.
#define BS_RCM_SRS0_WAKEUP   (1U)          //!< Bit field size in bits for RCM_SRS0_WAKEUP.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_WAKEUP field.
#define BR_RCM_SRS0_WAKEUP   (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_WAKEUP))
#endif
//@}

/*!
 * @name Register RCM_SRS0, field LVD[1] (RO)
 *
 * If the LVDRE bit is set and the supply drops below the LVD trip voltage, an
 * LVD reset occurs. This bit is also set by POR.
 *
 * Values:
 * - 0 - Reset not caused by LVD trip or POR
 * - 1 - Reset caused by LVD trip or POR
 */
//@{
#define BP_RCM_SRS0_LVD      (1U)          //!< Bit position for RCM_SRS0_LVD.
#define BM_RCM_SRS0_LVD      (0x02U)       //!< Bit mask for RCM_SRS0_LVD.
#define BS_RCM_SRS0_LVD      (1U)          //!< Bit field size in bits for RCM_SRS0_LVD.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_LVD field.
#define BR_RCM_SRS0_LVD      (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_LVD))
#endif
//@}

/*!
 * @name Register RCM_SRS0, field LOC[2] (RO)
 *
 * Indicates a reset has been caused by a loss of external clock. The MCG clock
 * monitor must be enabled for a loss of clock to be detected. Refer to the
 * detailed MCG description for information on enabling the clock monitor.
 *
 * Values:
 * - 0 - Reset not caused by a loss of external clock.
 * - 1 - Reset caused by a loss of external clock.
 */
//@{
#define BP_RCM_SRS0_LOC      (2U)          //!< Bit position for RCM_SRS0_LOC.
#define BM_RCM_SRS0_LOC      (0x04U)       //!< Bit mask for RCM_SRS0_LOC.
#define BS_RCM_SRS0_LOC      (1U)          //!< Bit field size in bits for RCM_SRS0_LOC.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_LOC field.
#define BR_RCM_SRS0_LOC      (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_LOC))
#endif
//@}

/*!
 * @name Register RCM_SRS0, field LOL[3] (RO)
 *
 * Indicates a reset has been caused by a loss of lock in the MCG PLL. See the
 * MCG description for information on the loss-of-clock event.
 *
 * Values:
 * - 0 - Reset not caused by a loss of lock in the PLL
 * - 1 - Reset caused by a loss of lock in the PLL
 */
//@{
#define BP_RCM_SRS0_LOL      (3U)          //!< Bit position for RCM_SRS0_LOL.
#define BM_RCM_SRS0_LOL      (0x08U)       //!< Bit mask for RCM_SRS0_LOL.
#define BS_RCM_SRS0_LOL      (1U)          //!< Bit field size in bits for RCM_SRS0_LOL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_LOL field.
#define BR_RCM_SRS0_LOL      (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_LOL))
#endif
//@}

/*!
 * @name Register RCM_SRS0, field WDOG[5] (RO)
 *
 * Indicates a reset has been caused by the watchdog timer Computer Operating
 * Properly (COP) timing out. This reset source can be blocked by disabling the COP
 * watchdog: write 00 to the SIM's COPC[COPT] field.
 *
 * Values:
 * - 0 - Reset not caused by watchdog timeout
 * - 1 - Reset caused by watchdog timeout
 */
//@{
#define BP_RCM_SRS0_WDOG     (5U)          //!< Bit position for RCM_SRS0_WDOG.
#define BM_RCM_SRS0_WDOG     (0x20U)       //!< Bit mask for RCM_SRS0_WDOG.
#define BS_RCM_SRS0_WDOG     (1U)          //!< Bit field size in bits for RCM_SRS0_WDOG.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_WDOG field.
#define BR_RCM_SRS0_WDOG     (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_WDOG))
#endif
//@}

/*!
 * @name Register RCM_SRS0, field PIN[6] (RO)
 *
 * Indicates a reset has been caused by an active-low level on the external
 * RESET pin.
 *
 * Values:
 * - 0 - Reset not caused by external reset pin
 * - 1 - Reset caused by external reset pin
 */
//@{
#define BP_RCM_SRS0_PIN      (6U)          //!< Bit position for RCM_SRS0_PIN.
#define BM_RCM_SRS0_PIN      (0x40U)       //!< Bit mask for RCM_SRS0_PIN.
#define BS_RCM_SRS0_PIN      (1U)          //!< Bit field size in bits for RCM_SRS0_PIN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_PIN field.
#define BR_RCM_SRS0_PIN      (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_PIN))
#endif
//@}

/*!
 * @name Register RCM_SRS0, field POR[7] (RO)
 *
 * Indicates a reset has been caused by the power-on detection logic. Because
 * the internal supply voltage was ramping up at the time, the low-voltage reset
 * (LVD) status bit is also set to indicate that the reset occurred while the
 * internal supply was below the LVD threshold.
 *
 * Values:
 * - 0 - Reset not caused by POR
 * - 1 - Reset caused by POR
 */
//@{
#define BP_RCM_SRS0_POR      (7U)          //!< Bit position for RCM_SRS0_POR.
#define BM_RCM_SRS0_POR      (0x80U)       //!< Bit mask for RCM_SRS0_POR.
#define BS_RCM_SRS0_POR      (1U)          //!< Bit field size in bits for RCM_SRS0_POR.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS0_POR field.
#define BR_RCM_SRS0_POR      (BITBAND_ACCESS8(HW_RCM_SRS0_ADDR, BP_RCM_SRS0_POR))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_RCM_SRS1 - System Reset Status Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RCM_SRS1 - System Reset Status Register 1 (RO)
 *
 * Reset value: 0x00U
 *
 * This register includes read-only status flags to indicate the source of the
 * most recent reset. The reset state of these bits depends on what caused the MCU
 * to reset. The reset value of this register depends on the reset source: POR
 * (including LVD) - 0x00 LVD (without POR) - 0x00 VLLS mode wakeup - 0x00 Other
 * reset - a bit is set if its corresponding reset source caused the reset
 */
typedef union _hw_rcm_srs1
{
    uint8_t U;
    struct _hw_rcm_srs1_bitfields
    {
        uint8_t JTAG : 1;              //!< [0] JTAG Generated Reset
        uint8_t LOCKUP : 1;            //!< [1] Core Lockup
        uint8_t SW : 1;                //!< [2] Software
        uint8_t MDM_AP : 1;            //!< [3] MDM-AP System Reset Request
        uint8_t EZPT : 1;              //!< [4] EzPort Reset
        uint8_t SACKERR : 1;           //!< [5] Stop Mode Acknowledge Error Reset
        uint8_t RESERVED0 : 2;         //!< [7:6]
    } B;
} hw_rcm_srs1_t;
#endif

/*!
 * @name Constants and macros for entire RCM_SRS1 register
 */
//@{
#define HW_RCM_SRS1_ADDR         (REGS_RCM_BASE + 0x1U)

#ifndef __LANGUAGE_ASM__
#define HW_RCM_SRS1              (*(__I hw_rcm_srs1_t *) HW_RCM_SRS1_ADDR)
#define HW_RCM_SRS1_RD()         (HW_RCM_SRS1.U)
#endif
//@}

/*
 * Constants & macros for individual RCM_SRS1 bitfields
 */

/*!
 * @name Register RCM_SRS1, field JTAG[0] (RO)
 *
 * Indicates a reset has been caused by JTAG selection of certain IR codes:
 * EZPORT, EXTEST, HIGHZ, and CLAMP.
 *
 * Values:
 * - 0 - Reset not caused by JTAG
 * - 1 - Reset caused by JTAG
 */
//@{
#define BP_RCM_SRS1_JTAG     (0U)          //!< Bit position for RCM_SRS1_JTAG.
#define BM_RCM_SRS1_JTAG     (0x01U)       //!< Bit mask for RCM_SRS1_JTAG.
#define BS_RCM_SRS1_JTAG     (1U)          //!< Bit field size in bits for RCM_SRS1_JTAG.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS1_JTAG field.
#define BR_RCM_SRS1_JTAG     (BITBAND_ACCESS8(HW_RCM_SRS1_ADDR, BP_RCM_SRS1_JTAG))
#endif
//@}

/*!
 * @name Register RCM_SRS1, field LOCKUP[1] (RO)
 *
 * Indicates a reset has been caused by the ARM core indication of a LOCKUP
 * event.
 *
 * Values:
 * - 0 - Reset not caused by core LOCKUP event
 * - 1 - Reset caused by core LOCKUP event
 */
//@{
#define BP_RCM_SRS1_LOCKUP   (1U)          //!< Bit position for RCM_SRS1_LOCKUP.
#define BM_RCM_SRS1_LOCKUP   (0x02U)       //!< Bit mask for RCM_SRS1_LOCKUP.
#define BS_RCM_SRS1_LOCKUP   (1U)          //!< Bit field size in bits for RCM_SRS1_LOCKUP.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS1_LOCKUP field.
#define BR_RCM_SRS1_LOCKUP   (BITBAND_ACCESS8(HW_RCM_SRS1_ADDR, BP_RCM_SRS1_LOCKUP))
#endif
//@}

/*!
 * @name Register RCM_SRS1, field SW[2] (RO)
 *
 * Indicates a reset has been caused by software setting of SYSRESETREQ bit in
 * Application Interrupt and Reset Control Register in the ARM core.
 *
 * Values:
 * - 0 - Reset not caused by software setting of SYSRESETREQ bit
 * - 1 - Reset caused by software setting of SYSRESETREQ bit
 */
//@{
#define BP_RCM_SRS1_SW       (2U)          //!< Bit position for RCM_SRS1_SW.
#define BM_RCM_SRS1_SW       (0x04U)       //!< Bit mask for RCM_SRS1_SW.
#define BS_RCM_SRS1_SW       (1U)          //!< Bit field size in bits for RCM_SRS1_SW.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS1_SW field.
#define BR_RCM_SRS1_SW       (BITBAND_ACCESS8(HW_RCM_SRS1_ADDR, BP_RCM_SRS1_SW))
#endif
//@}

/*!
 * @name Register RCM_SRS1, field MDM_AP[3] (RO)
 *
 * Indicates a reset has been caused by the host debugger system setting of the
 * System Reset Request bit in the MDM-AP Control Register.
 *
 * Values:
 * - 0 - Reset not caused by host debugger system setting of the System Reset
 *     Request bit
 * - 1 - Reset caused by host debugger system setting of the System Reset
 *     Request bit
 */
//@{
#define BP_RCM_SRS1_MDM_AP   (3U)          //!< Bit position for RCM_SRS1_MDM_AP.
#define BM_RCM_SRS1_MDM_AP   (0x08U)       //!< Bit mask for RCM_SRS1_MDM_AP.
#define BS_RCM_SRS1_MDM_AP   (1U)          //!< Bit field size in bits for RCM_SRS1_MDM_AP.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS1_MDM_AP field.
#define BR_RCM_SRS1_MDM_AP   (BITBAND_ACCESS8(HW_RCM_SRS1_ADDR, BP_RCM_SRS1_MDM_AP))
#endif
//@}

/*!
 * @name Register RCM_SRS1, field EZPT[4] (RO)
 *
 * Indicates a reset has been caused by EzPort receiving the RESET command while
 * the device is in EzPort mode.
 *
 * Values:
 * - 0 - Reset not caused by EzPort receiving the RESET command while the device
 *     is in EzPort mode
 * - 1 - Reset caused by EzPort receiving the RESET command while the device is
 *     in EzPort mode
 */
//@{
#define BP_RCM_SRS1_EZPT     (4U)          //!< Bit position for RCM_SRS1_EZPT.
#define BM_RCM_SRS1_EZPT     (0x10U)       //!< Bit mask for RCM_SRS1_EZPT.
#define BS_RCM_SRS1_EZPT     (1U)          //!< Bit field size in bits for RCM_SRS1_EZPT.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS1_EZPT field.
#define BR_RCM_SRS1_EZPT     (BITBAND_ACCESS8(HW_RCM_SRS1_ADDR, BP_RCM_SRS1_EZPT))
#endif
//@}

/*!
 * @name Register RCM_SRS1, field SACKERR[5] (RO)
 *
 * Indicates that after an attempt to enter Stop mode, a reset has been caused
 * by a failure of one or more peripherals to acknowledge within approximately one
 * second to enter stop mode.
 *
 * Values:
 * - 0 - Reset not caused by peripheral failure to acknowledge attempt to enter
 *     stop mode
 * - 1 - Reset caused by peripheral failure to acknowledge attempt to enter stop
 *     mode
 */
//@{
#define BP_RCM_SRS1_SACKERR  (5U)          //!< Bit position for RCM_SRS1_SACKERR.
#define BM_RCM_SRS1_SACKERR  (0x20U)       //!< Bit mask for RCM_SRS1_SACKERR.
#define BS_RCM_SRS1_SACKERR  (1U)          //!< Bit field size in bits for RCM_SRS1_SACKERR.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_SRS1_SACKERR field.
#define BR_RCM_SRS1_SACKERR  (BITBAND_ACCESS8(HW_RCM_SRS1_ADDR, BP_RCM_SRS1_SACKERR))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_RCM_RPFC - Reset Pin Filter Control register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RCM_RPFC - Reset Pin Filter Control register (RW)
 *
 * Reset value: 0x00U
 *
 * The reset values of bits 2-0 are for Chip POR only. They are unaffected by
 * other reset types. The bus clock filter is reset when disabled or when entering
 * stop mode. The LPO filter is reset when disabled or when entering any low
 * leakage stop mode .
 */
typedef union _hw_rcm_rpfc
{
    uint8_t U;
    struct _hw_rcm_rpfc_bitfields
    {
        uint8_t RSTFLTSRW : 2;         //!< [1:0] Reset Pin Filter Select in Run and
                                       //! Wait Modes
        uint8_t RSTFLTSS : 1;          //!< [2] Reset Pin Filter Select in Stop Mode
        uint8_t RESERVED0 : 5;         //!< [7:3]
    } B;
} hw_rcm_rpfc_t;
#endif

/*!
 * @name Constants and macros for entire RCM_RPFC register
 */
//@{
#define HW_RCM_RPFC_ADDR         (REGS_RCM_BASE + 0x4U)

#ifndef __LANGUAGE_ASM__
#define HW_RCM_RPFC              (*(__IO hw_rcm_rpfc_t *) HW_RCM_RPFC_ADDR)
#define HW_RCM_RPFC_RD()         (HW_RCM_RPFC.U)
#define HW_RCM_RPFC_WR(v)        (HW_RCM_RPFC.U = (v))
#define HW_RCM_RPFC_SET(v)       (HW_RCM_RPFC_WR(HW_RCM_RPFC_RD() |  (v)))
#define HW_RCM_RPFC_CLR(v)       (HW_RCM_RPFC_WR(HW_RCM_RPFC_RD() & ~(v)))
#define HW_RCM_RPFC_TOG(v)       (HW_RCM_RPFC_WR(HW_RCM_RPFC_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual RCM_RPFC bitfields
 */

/*!
 * @name Register RCM_RPFC, field RSTFLTSRW[1:0] (RW)
 *
 * Selects how the reset pin filter is enabled in run and wait modes.
 *
 * Values:
 * - 00 - All filtering disabled
 * - 01 - Bus clock filter enabled for normal operation
 * - 10 - LPO clock filter enabled for normal operation
 * - 11 - Reserved
 */
//@{
#define BP_RCM_RPFC_RSTFLTSRW (0U)         //!< Bit position for RCM_RPFC_RSTFLTSRW.
#define BM_RCM_RPFC_RSTFLTSRW (0x03U)      //!< Bit mask for RCM_RPFC_RSTFLTSRW.
#define BS_RCM_RPFC_RSTFLTSRW (2U)         //!< Bit field size in bits for RCM_RPFC_RSTFLTSRW.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_RPFC_RSTFLTSRW field.
#define BR_RCM_RPFC_RSTFLTSRW (HW_RCM_RPFC.B.RSTFLTSRW)
#endif

//! @brief Format value for bitfield RCM_RPFC_RSTFLTSRW.
#define BF_RCM_RPFC_RSTFLTSRW(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_RCM_RPFC_RSTFLTSRW), uint8_t) & BM_RCM_RPFC_RSTFLTSRW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSTFLTSRW field to a new value.
#define BW_RCM_RPFC_RSTFLTSRW(v) (HW_RCM_RPFC_WR((HW_RCM_RPFC_RD() & ~BM_RCM_RPFC_RSTFLTSRW) | BF_RCM_RPFC_RSTFLTSRW(v)))
#endif
//@}

/*!
 * @name Register RCM_RPFC, field RSTFLTSS[2] (RW)
 *
 * Selects how the reset pin filter is enabled in Stop and VLPS modes
 *
 * Values:
 * - 0 - All filtering disabled
 * - 1 - LPO clock filter enabled
 */
//@{
#define BP_RCM_RPFC_RSTFLTSS (2U)          //!< Bit position for RCM_RPFC_RSTFLTSS.
#define BM_RCM_RPFC_RSTFLTSS (0x04U)       //!< Bit mask for RCM_RPFC_RSTFLTSS.
#define BS_RCM_RPFC_RSTFLTSS (1U)          //!< Bit field size in bits for RCM_RPFC_RSTFLTSS.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_RPFC_RSTFLTSS field.
#define BR_RCM_RPFC_RSTFLTSS (BITBAND_ACCESS8(HW_RCM_RPFC_ADDR, BP_RCM_RPFC_RSTFLTSS))
#endif

//! @brief Format value for bitfield RCM_RPFC_RSTFLTSS.
#define BF_RCM_RPFC_RSTFLTSS(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_RCM_RPFC_RSTFLTSS), uint8_t) & BM_RCM_RPFC_RSTFLTSS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSTFLTSS field to a new value.
#define BW_RCM_RPFC_RSTFLTSS(v) (BITBAND_ACCESS8(HW_RCM_RPFC_ADDR, BP_RCM_RPFC_RSTFLTSS) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_RCM_RPFW - Reset Pin Filter Width register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RCM_RPFW - Reset Pin Filter Width register (RW)
 *
 * Reset value: 0x00U
 *
 * The reset values of the bits in the RSTFLTSEL field are for Chip POR only.
 * They are unaffected by other reset types.
 */
typedef union _hw_rcm_rpfw
{
    uint8_t U;
    struct _hw_rcm_rpfw_bitfields
    {
        uint8_t RSTFLTSEL : 5;         //!< [4:0] Reset Pin Filter Bus Clock Select
        uint8_t RESERVED0 : 3;         //!< [7:5]
    } B;
} hw_rcm_rpfw_t;
#endif

/*!
 * @name Constants and macros for entire RCM_RPFW register
 */
//@{
#define HW_RCM_RPFW_ADDR         (REGS_RCM_BASE + 0x5U)

#ifndef __LANGUAGE_ASM__
#define HW_RCM_RPFW              (*(__IO hw_rcm_rpfw_t *) HW_RCM_RPFW_ADDR)
#define HW_RCM_RPFW_RD()         (HW_RCM_RPFW.U)
#define HW_RCM_RPFW_WR(v)        (HW_RCM_RPFW.U = (v))
#define HW_RCM_RPFW_SET(v)       (HW_RCM_RPFW_WR(HW_RCM_RPFW_RD() |  (v)))
#define HW_RCM_RPFW_CLR(v)       (HW_RCM_RPFW_WR(HW_RCM_RPFW_RD() & ~(v)))
#define HW_RCM_RPFW_TOG(v)       (HW_RCM_RPFW_WR(HW_RCM_RPFW_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual RCM_RPFW bitfields
 */

/*!
 * @name Register RCM_RPFW, field RSTFLTSEL[4:0] (RW)
 *
 * Selects the reset pin bus clock filter width.
 *
 * Values:
 * - 00000 - Bus clock filter count is 1
 * - 00001 - Bus clock filter count is 2
 * - 00010 - Bus clock filter count is 3
 * - 00011 - Bus clock filter count is 4
 * - 00100 - Bus clock filter count is 5
 * - 00101 - Bus clock filter count is 6
 * - 00110 - Bus clock filter count is 7
 * - 00111 - Bus clock filter count is 8
 * - 01000 - Bus clock filter count is 9
 * - 01001 - Bus clock filter count is 10
 * - 01010 - Bus clock filter count is 11
 * - 01011 - Bus clock filter count is 12
 * - 01100 - Bus clock filter count is 13
 * - 01101 - Bus clock filter count is 14
 * - 01110 - Bus clock filter count is 15
 * - 01111 - Bus clock filter count is 16
 * - 10000 - Bus clock filter count is 17
 * - 10001 - Bus clock filter count is 18
 * - 10010 - Bus clock filter count is 19
 * - 10011 - Bus clock filter count is 20
 * - 10100 - Bus clock filter count is 21
 * - 10101 - Bus clock filter count is 22
 * - 10110 - Bus clock filter count is 23
 * - 10111 - Bus clock filter count is 24
 * - 11000 - Bus clock filter count is 25
 * - 11001 - Bus clock filter count is 26
 * - 11010 - Bus clock filter count is 27
 * - 11011 - Bus clock filter count is 28
 * - 11100 - Bus clock filter count is 29
 * - 11101 - Bus clock filter count is 30
 * - 11110 - Bus clock filter count is 31
 * - 11111 - Bus clock filter count is 32
 */
//@{
#define BP_RCM_RPFW_RSTFLTSEL (0U)         //!< Bit position for RCM_RPFW_RSTFLTSEL.
#define BM_RCM_RPFW_RSTFLTSEL (0x1FU)      //!< Bit mask for RCM_RPFW_RSTFLTSEL.
#define BS_RCM_RPFW_RSTFLTSEL (5U)         //!< Bit field size in bits for RCM_RPFW_RSTFLTSEL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_RPFW_RSTFLTSEL field.
#define BR_RCM_RPFW_RSTFLTSEL (HW_RCM_RPFW.B.RSTFLTSEL)
#endif

//! @brief Format value for bitfield RCM_RPFW_RSTFLTSEL.
#define BF_RCM_RPFW_RSTFLTSEL(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_RCM_RPFW_RSTFLTSEL), uint8_t) & BM_RCM_RPFW_RSTFLTSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RSTFLTSEL field to a new value.
#define BW_RCM_RPFW_RSTFLTSEL(v) (HW_RCM_RPFW_WR((HW_RCM_RPFW_RD() & ~BM_RCM_RPFW_RSTFLTSEL) | BF_RCM_RPFW_RSTFLTSEL(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_RCM_MR - Mode Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_RCM_MR - Mode Register (RO)
 *
 * Reset value: 0x00U
 *
 * This register includes read-only status flags to indicate the state of the
 * mode pins during the last Chip Reset.
 */
typedef union _hw_rcm_mr
{
    uint8_t U;
    struct _hw_rcm_mr_bitfields
    {
        uint8_t RESERVED0 : 1;         //!< [0]
        uint8_t EZP_MS : 1;            //!< [1] EZP_MS_B pin state
        uint8_t RESERVED1 : 6;         //!< [7:2]
    } B;
} hw_rcm_mr_t;
#endif

/*!
 * @name Constants and macros for entire RCM_MR register
 */
//@{
#define HW_RCM_MR_ADDR           (REGS_RCM_BASE + 0x7U)

#ifndef __LANGUAGE_ASM__
#define HW_RCM_MR                (*(__I hw_rcm_mr_t *) HW_RCM_MR_ADDR)
#define HW_RCM_MR_RD()           (HW_RCM_MR.U)
#endif
//@}

/*
 * Constants & macros for individual RCM_MR bitfields
 */

/*!
 * @name Register RCM_MR, field EZP_MS[1] (RO)
 *
 * Reflects the state of the EZP_MS pin during the last Chip Reset
 *
 * Values:
 * - 0 - Pin deasserted (logic 1)
 * - 1 - Pin asserted (logic 0)
 */
//@{
#define BP_RCM_MR_EZP_MS     (1U)          //!< Bit position for RCM_MR_EZP_MS.
#define BM_RCM_MR_EZP_MS     (0x02U)       //!< Bit mask for RCM_MR_EZP_MS.
#define BS_RCM_MR_EZP_MS     (1U)          //!< Bit field size in bits for RCM_MR_EZP_MS.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the RCM_MR_EZP_MS field.
#define BR_RCM_MR_EZP_MS     (BITBAND_ACCESS8(HW_RCM_MR_ADDR, BP_RCM_MR_EZP_MS))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_rcm_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All RCM module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_rcm
{
    __I hw_rcm_srs0_t SRS0;                //!< [0x0] System Reset Status Register 0
    __I hw_rcm_srs1_t SRS1;                //!< [0x1] System Reset Status Register 1
    uint8_t _reserved0[2];
    __IO hw_rcm_rpfc_t RPFC;               //!< [0x4] Reset Pin Filter Control register
    __IO hw_rcm_rpfw_t RPFW;               //!< [0x5] Reset Pin Filter Width register
    uint8_t _reserved1[1];
    __I hw_rcm_mr_t MR;                    //!< [0x7] Mode Register
} hw_rcm_t;
#pragma pack()

//! @brief Macro to access all RCM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_RCM</code>.
#define HW_RCM         (*(hw_rcm_t *) REGS_RCM_BASE)
#endif

#endif // __HW_RCM_REGISTERS_H__
// v22/130726/0.9
// EOF
