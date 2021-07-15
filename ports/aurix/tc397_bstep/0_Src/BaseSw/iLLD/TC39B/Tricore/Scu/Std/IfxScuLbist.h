/**
 * \file IfxScuLbist.h
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
 * LBIST module scans and tests the digital circutary within the microcontroller.
 * This driver provides LBIST APIs which are used to trigger the Logic BIST module.
 * Caution: Draft implementation, APIs may change.
 *
 * \defgroup IfxLld_Scu_Std_Lbist Lbist Basic Functionality
 * \ingroup IfxLld_Scu_Std
 */

#ifndef IFXSCULBIST_H
#define IFXSCULBIST_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxScu_cfg.h"
#include "Cpu/Std/Ifx_Types.h"
#include "IfxScu_reg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"
#include "IfxScu_bf.h"

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Application selection bit for LBIST
 */
typedef enum
{
    IfxScuLbist_Application_pt   = 0, /**< \brief LBIST Power-train Application */
    IfxScuLbist_Application_body = 1  /**< \brief LBIST Body Application */
} IfxScuLbist_Application;

/** \brief prescaler values to divide the EVR frequency for the LBIST operational clock
 */
typedef enum
{
    IfxScuLbist_Freq_div1  = 0,   /**< \brief LBIST Frequency, EVR Clock Divided by 1 */
    IfxScuLbist_Freq_div2  = 1,   /**< \brief LBIST Frequency, EVR Clock Divided by 2 */
    IfxScuLbist_Freq_div3  = 2,   /**< \brief LBIST Frequency, EVR Clock Divided by 3 */
    IfxScuLbist_Freq_div4  = 3,   /**< \brief LBIST Frequency, EVR Clock Divided by 4 */
    IfxScuLbist_Freq_div5  = 4,   /**< \brief LBIST Frequency, EVR Clock Divided by 5 */
    IfxScuLbist_Freq_div6  = 5,   /**< \brief LBIST Frequency, EVR Clock Divided by 6 */
    IfxScuLbist_Freq_div7  = 6,   /**< \brief LBIST Frequency, EVR Clock Divided by 7 */
    IfxScuLbist_Freq_div8  = 7,   /**< \brief LBIST Frequency, EVR Clock Divided by 8 */
    IfxScuLbist_Freq_div9  = 8,   /**< \brief LBIST Frequency, EVR Clock Divided by 9 */
    IfxScuLbist_Freq_div10 = 9,   /**< \brief LBIST Frequency, EVR Clock Divided by 10 */
    IfxScuLbist_Freq_div11 = 10,  /**< \brief LBIST Frequency, EVR Clock Divided by 11 */
    IfxScuLbist_Freq_div12 = 11,  /**< \brief LBIST Frequency, EVR Clock Divided by 12 */
    IfxScuLbist_Freq_div13 = 12,  /**< \brief LBIST Frequency, EVR Clock Divided by 13 */
    IfxScuLbist_Freq_div14 = 13,  /**< \brief LBIST Frequency, EVR Clock Divided by 14 */
    IfxScuLbist_Freq_div15 = 14,  /**< \brief LBIST Frequency, EVR Clock Divided by 15 */
    IfxScuLbist_Freq_div16 = 15   /**< \brief LBIST Frequency, EVR Clock Divided by 16 */
} IfxScuLbist_Freq;

/** \brief Split Shift Selection
 */
typedef enum
{
    IfxScuLbist_SplitShiftSel_allScanPartitions  = 0,  /**< \brief LBIST Split-Shift Concurrent Scan-Shift Selection */
    IfxScuLbist_SplitShiftSel_fourScanPartitions = 4,  /**< \brief LBIST Split-Shift Four Scan-Shift Selection */
    IfxScuLbist_SplitShiftSel_twoScanPartitions  = 5   /**< \brief LBIST Split-Shift Two Scan-Shift Selection */
} IfxScuLbist_SplitShiftSel;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief configuration data structure for the LBIST parameters
 */
typedef struct
{
    IfxScuLbist_Application   application;           /**< \brief LBIST application selection */
    IfxScuLbist_Freq          freq;                  /**< \brief LBIST Frequency Selection. Pre-scaler value to derive LBIST operation clock from EVR oscillator */
    IfxScuLbist_SplitShiftSel splitShiftSel;         /**< \brief LBIST Split-Shift Selection */
    uint32                    seed;                  /**< \brief LBIST Seed value (start value for the random pattern generator) */
    uint32                    pattern;               /**< \brief LBIST Pattern Number for the scan loads */
    uint32                    scanChainLength;       /**< \brief LBIST maximum scan chain length */
    uint32                    signature;             /**< \brief LBIST Signature Value to compare with MISR signature from the last LBIST */
} IfxScuLbist_ParameterSet;

typedef struct
{
    uint8                     numOfConfigSets;       /**< \brief Number of LBIST configuration sets */
    IfxScuLbist_ParameterSet *parameterSets;         /**< \brief Pointer to LBIST configuration set array */
} IfxScuLbist_MultiTriggerConfig;

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Evaluate Previous LBIST result.
 * Note: LBIST trigger normally resets the controller to have warm power on reset.
 * \param signature result signature to be evaulated
 * \return False :If the previous LBIST is not done or if the previous LBIST signature did not match with configured value.
 * True : If the previous LBIST is done and signature did match with the configured value
 */
IFX_INLINE boolean IfxScuLbist_evaluateResult(const uint32 signature);

/** \brief Init the default config parameter set
 * \param parameterSet pointer to the datastructure which is used for triggering the latest LBIST activity.
 * \return None
 */
IFX_INLINE void IfxScuLbist_initParameterSetInline(IfxScuLbist_ParameterSet *parameterSet);

/** \brief the api returns Lbist done status
 * \return True: Lbist done. False: Lbist not done
 */
IFX_INLINE boolean IfxScuLbist_isDone(void);

/** \brief API is to trigger an LBIST test multiple times for all the configured parameters sets. This API could be triggered only if the firmware LBIST is disabled.
 * \param multiTriggerConfig pointer to the datastructure which is used for triggering the latest LBIST activity.
 * \return True - All the LBIST signatures are matching to the corresponding parameterSets
 * False - If one of the the signatures from multiple LBIST triggers did not match with configured signature within corresponding parameterSet
 */
IFX_INLINE boolean IfxScuLbist_multiTriggersInline(const IfxScuLbist_MultiTriggerConfig *multiTriggerConfig);

/** \brief API to re trigger an LBIST test with new parameters configured to the LBIST controller.
 * \param parameterSet pointer to the datastructure which is used for triggering the latest LBIST activity.
 * \return None
 */
IFX_INLINE void IfxScuLbist_retriggerInline(const IfxScuLbist_ParameterSet *parameterSet);

/** \brief trigger a fresh LBIST irrespective of previous LBIST
 * \param parameterSet pointer to the datastructure which is used for triggering the latest LBIST activity.
 * \return None
 */
IFX_INLINE void IfxScuLbist_triggerInline(const IfxScuLbist_ParameterSet *parameterSet);

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxScuLbist_ParameterSet IfxScuLbist_defaultConfig;

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxScuLbist_evaluateResult(const uint32 signature)
{
    return (signature == MODULE_SCU.LBISTCTRL3.B.SIGNATURE) && (MODULE_SCU.RSTSTAT.B.LBTERM == 1U);
}


IFX_INLINE void IfxScuLbist_initParameterSetInline(IfxScuLbist_ParameterSet *parameterSet)
{
    *parameterSet = IfxScuLbist_defaultConfig;
}


IFX_INLINE boolean IfxScuLbist_isDone(void)
{
    return (boolean)MODULE_SCU.LBISTCTRL0.B.LBISTDONE;
}


IFX_INLINE boolean IfxScuLbist_multiTriggersInline(const IfxScuLbist_MultiTriggerConfig *multiTriggerConfig)
{
    boolean returnVal = 0;
    uint16  password;

    password = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()]);

    /*  Previous LBIST done?*/
    if (MODULE_SCU.LBISTCTRL0.B.LBISTDONE == 1U)
    {
        /* Does Signature match with the param sets? */
        if (multiTriggerConfig->parameterSets[MODULE_SCU.RSTCON2.B.USRINFO].signature == MODULE_SCU.LBISTCTRL3.B.SIGNATURE)
        {
            /* Is config sets which matched - the Last one in 'param set List'? */
            if (MODULE_SCU.RSTCON2.B.USRINFO == 0)
            {
                returnVal = 1;
            }
            else
            {
                /* Store the "number of Config sets" to RSTCON2.USRINFO for the first time.  */
                IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);
                MODULE_SCU.RSTCON2.B.USRINFO -= 1;
                IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);

                /* Configure next param set and re-trigger LBIST */
                IfxScuLbist_retriggerInline(&multiTriggerConfig->parameterSets[MODULE_SCU.RSTCON2.B.USRINFO]);
            }
        }
        else
        {
            /* Signature failed */
            returnVal = 0;
        }
    }
    else
    {
        /* Store the "number of Config sets" to RSTCON2.USRINFO for the first time.  */
        IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);
        MODULE_SCU.RSTCON2.B.USRINFO = multiTriggerConfig->numOfConfigSets;
        IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);

        /* Configure LBIST for param set0 and trigger LBIST */
        IfxScuLbist_triggerInline(&multiTriggerConfig->parameterSets[MODULE_SCU.RSTCON2.B.USRINFO]);

        while (1)
        {
            __nop();     /* Wait till warm reset */
        }
    }

    return returnVal;
}


IFX_INLINE void IfxScuLbist_retriggerInline(const IfxScuLbist_ParameterSet *parameterSet)
{
    Ifx_SCU_LBISTCTRL1 LBISTCTRL1;
    uint16             password = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(password);

    /* Reset the LBIST before re-trigger and wait till it's done */
    MODULE_SCU.LBISTCTRL0.B.LBISTRES = 1;
    IfxScuWdt_setSafetyEndinitInline(password);

    while (MODULE_SCU.LBISTCTRL0.B.LBISTDONE == 1U)
    {}

    LBISTCTRL1.U            = MODULE_SCU.LBISTCTRL1.U;
    LBISTCTRL1.B.BODY       = parameterSet->application;
    LBISTCTRL1.B.SEED       = parameterSet->seed;
    LBISTCTRL1.B.SPLITSH    = parameterSet->splitShiftSel;
    LBISTCTRL1.B.LBISTFREQU = parameterSet->freq;

    IfxScuWdt_clearSafetyEndinitInline(password);
    MODULE_SCU.LBISTCTRL1.U          = LBISTCTRL1.U;

    MODULE_SCU.LBISTCTRL0.B.PATTERNS = parameterSet->pattern;
    MODULE_SCU.LBISTCTRL0.B.LBISTREQ = 1;

    while (1)
    {
        __nop(); /* Wait till warm reset */
    }
}


IFX_INLINE void IfxScuLbist_triggerInline(const IfxScuLbist_ParameterSet *parameterSet)
{
    IfxScuWdt_clearGlobalSafetyEndinitInline(IfxScuWdt_getGlobalSafetyEndinitPasswordInline());

    MODULE_SCU.LBISTCTRL1.U =
        (parameterSet->application << IFX_SCU_LBISTCTRL1_BODY_OFF) |
        (parameterSet->seed << IFX_SCU_LBISTCTRL1_SEED_OFF) |
        (parameterSet->splitShiftSel << IFX_SCU_LBISTCTRL1_SPLITSH_OFF) |
        (parameterSet->freq << IFX_SCU_LBISTCTRL1_LBISTFREQU_OFF);

    MODULE_SCU.LBISTCTRL0.B.PATTERNS = parameterSet->pattern;
    MODULE_SCU.LBISTCTRL2.B.LENGTH   = parameterSet->scanChainLength;
    MODULE_SCU.LBISTCTRL0.U         |=
        (IFX_SCU_LBISTCTRL0_LBISTREQRED_MSK << IFX_SCU_LBISTCTRL0_LBISTREQRED_OFF) |
        (IFX_SCU_LBISTCTRL0_LBISTREQ_MSK << IFX_SCU_LBISTCTRL0_LBISTREQ_OFF);
}


#endif /* IFXSCULBIST_H */
