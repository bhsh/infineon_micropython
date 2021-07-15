/**
 * \file IfxScuRcu.h
 * \brief SCU  basic functionality
 * \ingroup IfxLld_Scu
 *
 * \version iLLD_1_0_1_10_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * This file contains the APIs for Reset related functions.
 * Caution: Draft implementation, APIs may change.
 *
 * \defgroup IfxLld_Scu_Std_Rcu Rcu Basic Functionality
 * \ingroup IfxLld_Scu_Std
 */

#ifndef IFXSCURCU_H
#define IFXSCURCU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxScu_cfg.h"
#include "Cpu/Std/Ifx_Types.h"
#include "IfxScu_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief PowerOn Reset Mask
 */
#define IFXSCURCU_POWERONRESET_MASK                             \
    ((IFX_SCU_RSTSTAT_STBYR_MSK << IFX_SCU_RSTSTAT_STBYR_OFF) | \
     (IFX_SCU_RSTSTAT_SWD_MSK << IFX_SCU_RSTSTAT_SWD_OFF) |     \
     (IFX_SCU_RSTSTAT_EVR33_MSK << IFX_SCU_RSTSTAT_EVR33_OFF) | \
     (IFX_SCU_RSTSTAT_EVRC_MSK << IFX_SCU_RSTSTAT_EVRC_OFF) |   \
     (IFX_SCU_RSTSTAT_CB1_MSK << IFX_SCU_RSTSTAT_CB1_OFF) |     \
     (IFX_SCU_RSTSTAT_CB0_MSK << IFX_SCU_RSTSTAT_CB0_OFF) |     \
     (IFX_SCU_RSTSTAT_PORST_MSK << IFX_SCU_RSTSTAT_PORST_OFF))

/** \brief Application Reset Mask
 */
#define IFXSCURCU_APPLICATIONRESET_MASK                       \
    ((IFX_SCU_RSTSTAT_SW_MSK << IFX_SCU_RSTSTAT_SW_OFF) |     \
     (IFX_SCU_RSTSTAT_STM5_MSK << IFX_SCU_RSTSTAT_STM5_OFF) | \
     (IFX_SCU_RSTSTAT_STM4_MSK << IFX_SCU_RSTSTAT_STM4_OFF) | \
     (IFX_SCU_RSTSTAT_STM3_MSK << IFX_SCU_RSTSTAT_STM3_OFF) | \
     (IFX_SCU_RSTSTAT_STM2_MSK << IFX_SCU_RSTSTAT_STM2_OFF) | \
     (IFX_SCU_RSTSTAT_STM1_MSK << IFX_SCU_RSTSTAT_STM1_OFF) | \
     (IFX_SCU_RSTSTAT_STM0_MSK << IFX_SCU_RSTSTAT_STM0_OFF) | \
     (IFX_SCU_RSTSTAT_SMU_MSK << IFX_SCU_RSTSTAT_SMU_OFF) |   \
     (IFX_SCU_RSTSTAT_ESR1_MSK << IFX_SCU_RSTSTAT_ESR1_OFF) | \
     (IFX_SCU_RSTSTAT_ESR0_MSK << IFX_SCU_RSTSTAT_ESR0_OFF))

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Reset type
 */
typedef enum
{
    IfxScuRcu_ResetType_coldpoweron = 0,  /**< \brief Cold Power On Reset */
    IfxScuRcu_ResetType_system      = 1,  /**< \brief system Reset */
    IfxScuRcu_ResetType_application = 2,  /**< \brief application reset */
    IfxScuRcu_ResetType_warmpoweron = 3,  /**< \brief Warm Power On Reset */
    IfxScuRcu_ResetType_debug       = 4,  /**< \brief debug reset */
    IfxScuRcu_ResetType_undefined   = 5   /**< \brief Undefined Reset */
} IfxScuRcu_ResetType;

/** \brief Reset Trigger
 */
typedef enum
{
    IfxScuRcu_Trigger_esr0      = 0,   /**< \brief ESR0 */
    IfxScuRcu_Trigger_esr1      = 1,   /**< \brief ESR1 */
    IfxScuRcu_Trigger_smu       = 3,   /**< \brief SMU */
    IfxScuRcu_Trigger_sw        = 4,   /**< \brief SW */
    IfxScuRcu_Trigger_stm0      = 5,   /**< \brief STM0 Compare Match */
    IfxScuRcu_Trigger_stm1      = 6,   /**< \brief STM1  Compare Match */
    IfxScuRcu_Trigger_stm2      = 7,   /**< \brief STM2 Compare Match */
    IfxScuRcu_Trigger_stm3      = 8,   /**< \brief STM3 Compare Match */
    IfxScuRcu_Trigger_stm4      = 9,   /**< \brief STM4 Compare Match */
    IfxScuRcu_Trigger_stm5      = 10,  /**< \brief STM5 Compare Match */
    IfxScuRcu_Trigger_portst    = 16,  /**< \brief PORTST */
    IfxScuRcu_Trigger_cb0       = 18,  /**< \brief Cerberus System Reset */
    IfxScuRcu_Trigger_cb1       = 19,  /**< \brief Cerberus Debug Reset */
    IfxScuRcu_Trigger_cb3       = 20,  /**< \brief Cerberus Application Reset */
    IfxScuRcu_Trigger_tp        = 21,  /**< \brief Tuning protection */
    IfxScuRcu_Trigger_tcu       = 22,  /**< \brief TCU */
    IfxScuRcu_Trigger_evrc      = 23,  /**< \brief EVRC */
    IfxScuRcu_Trigger_evr33     = 24,  /**< \brief EVR33 */
    IfxScuRcu_Trigger_swd       = 25,  /**< \brief Supply Watchdog */
    IfxScuRcu_Trigger_hsms      = 26,  /**< \brief HSM System Reset */
    IfxScuRcu_Trigger_hsma      = 27,  /**< \brief HSM Application Reset */
    IfxScuRcu_Trigger_stbyr     = 28,  /**< \brief Standby Regulator Watchdog */
    IfxScuRcu_Trigger_undefined = 255  /**< \brief Undefined Value */
} IfxScuRcu_Trigger;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    boolean             cpuSafeState;       /**< \brief CPU Safe state ( 1- Safe, 0 - Non-Safe) */
    IfxScuRcu_ResetType resetType;          /**< \brief Reset Type */
    IfxScuRcu_Trigger   resetTrigger;       /**< \brief reset Trigger */
    uint16              resetReason;        /**< \brief Reset Reason */
} IfxScuRcu_ResetCode;

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to clear the Cold Reset Status
 * \return None
 */
IFX_INLINE void IfxScuRcu_clearColdResetStatus(void);

/** \brief This function configures the request trigger in the Reset Configuration Register
 * \return None
 */
IFX_INLINE void IfxScuRcu_configureResetRequestTrigger(IfxScuRcu_Trigger trigger, IfxScuRcu_ResetType resetType);

/** \brief API to check if the previous reset is application reset or not.
 * \return returns application reset (1) or not (0)
 */
IFX_INLINE boolean IfxScuRcu_isApplicationReset(uint32 rawResetStatus);

/** \brief API reads and returns the raw reset value from the hardware register.
 * \return Raw reset status
 */
IFX_INLINE uint32 IfxScuRcu_readRawResetStatus(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief This function Evaluate the Reset and returns the reset cause/details.
 * \return Reset code which contains Reset type, trigger and reason details.
 */
IFX_EXTERN IfxScuRcu_ResetCode IfxScuRcu_evaluateReset(void);

/** \brief This function triggers system/application reset via software.
 * \param resetType reset type (only application and system reset are valid)
 * \param userResetInfo user Reset Information
 * \return None
 */
IFX_EXTERN void IfxScuRcu_performReset(IfxScuRcu_ResetType resetType, uint16 userResetInfo);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxScuRcu_clearColdResetStatus(void)
{
    uint16 password;

    password = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()]);
    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);
    /* Clear Cold Reset status */
    MODULE_SCU.RSTCON2.B.CLRC = 1U;
    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);
}


IFX_INLINE void IfxScuRcu_configureResetRequestTrigger(IfxScuRcu_Trigger trigger, IfxScuRcu_ResetType resetType)
{
    Ifx_SCU_RSTCON Rstcon;
    uint8          resetConfig = 2; /* Default - Application reset  */
    uint16         password;
    password = IfxScuWdt_getSafetyWatchdogPassword();
    Rstcon.U = MODULE_SCU.RSTCON.U;

    if (resetType == IfxScuRcu_ResetType_system)
    {
        resetConfig = 1;
    }

    switch (trigger)
    {
    case IfxScuRcu_Trigger_esr0:
        Rstcon.B.ESR0 = resetConfig;
        break;
    case IfxScuRcu_Trigger_esr1:
        Rstcon.B.ESR1 = resetConfig;
        break;
    case IfxScuRcu_Trigger_smu:
        Rstcon.B.SMU = resetConfig;
        break;
    case IfxScuRcu_Trigger_sw:
        Rstcon.B.SW = resetConfig;
        break;
    case IfxScuRcu_Trigger_stm0:
        Rstcon.B.STM0 = resetConfig;
        break;
    case IfxScuRcu_Trigger_stm1:
        Rstcon.B.STM1 = resetConfig;
        break;
    case IfxScuRcu_Trigger_stm2:
        Rstcon.B.STM2 = resetConfig;
        break;
    case IfxScuRcu_Trigger_stm3:
        Rstcon.B.STM3 = resetConfig;
        break;
    case IfxScuRcu_Trigger_stm4:
        Rstcon.B.STM4 = resetConfig;
        break;
    case IfxScuRcu_Trigger_stm5:
        Rstcon.B.STM5 = resetConfig;
        break;
    default:
        break;
    }

    IfxScuWdt_clearSafetyEndinitInline(password);

    MODULE_SCU.RSTCON.U = Rstcon.U;
    IfxScuWdt_setSafetyEndinit(password);
}


IFX_INLINE boolean IfxScuRcu_isApplicationReset(uint32 rawResetStatus)
{
    boolean returnVal;
    uint32  tempValue;

    if ((rawResetStatus & IFXSCURCU_POWERONRESET_MASK) > 0)
    {
        returnVal = 0;
    }
    else if ((rawResetStatus & IFXSCURCU_APPLICATIONRESET_MASK) > 0)   // CB3 TP HSMA ??
    {
        // get the bit which is set at RSTSTAT (assumption: RSTSTAT register was cleared before and only one bit can be set)
        tempValue = rawResetStatus & IFXSCURCU_APPLICATIONRESET_MASK;
        tempValue = (SCU_RSTCON.U >> ((31U - __clz(tempValue)) * 2)) & 3U;

        if (tempValue == 2)
        {
            returnVal = 1;
        }
        else
        {
            returnVal = 0;
        }
    }
    else if ((rawResetStatus & (IFX_SCU_RSTSTAT_CB3_MSK << IFX_SCU_RSTSTAT_CB3_OFF)))
    {
        // CB3 reset is not configurable and is always application reset
        returnVal = 1;
    }
    else if (CPU0_KRST0.B.RSTSTAT != 0)   /*CPU0 KRST status */
    {
        returnVal = 1;
    }
    else
    {
        returnVal = 0;
    }

    return returnVal;
}


IFX_INLINE uint32 IfxScuRcu_readRawResetStatus(void)
{
    return MODULE_SCU.RSTSTAT.U;
}


#endif /* IFXSCURCU_H */
