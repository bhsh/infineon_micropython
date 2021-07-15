/**
  * \file Ifx_Cfg_Ssw.c
 * \brief Configuration file for the Startup Software
 * \ingroup
 *
 *
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineons microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg_Ssw.h"
#include "Ifx_Ssw_Infra.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
#if defined(__TASKING__)
#pragma optimize RL
#elif defined(__HIGHTEC__)
#pragma GCC optimize ("O1")
#endif

#if (IFX_CFG_SSW_ENABLE_PMS_INIT == 1U)
void Ifx_Ssw_Pms_Init(void)
{
    if (IfxPmsEvr_runInitSequence(&IfxPmsEvr_cfgSequenceDefault) == 0)
    {
        __debug();
        /* Application may have call to error handling here*/
    }

    Ifx_Ssw_jumpBackToLink();
}

#if (IFX_CFG_SSW_ENABLE_PMS_INIT_CHECK == 1U)
void Ifx_Ssw_Pms_InitCheck(void)
{

    if (IfxPmsEvr_areInitValuesRight(&IfxPmsEvr_checkRegCfgDefault) == 0)
    {
        __debug();
        /* Application may have call to error handling here*/
    }
    Ifx_Ssw_jumpBackToLink();
}
#endif /* End of Ifx_Ssw_Pms_InitCheck() */
#endif /* End of Ifx_Ssw_Pms_Init() */

#if (IFX_CFG_SSW_ENABLE_LBIST == 1)
void Ifx_Ssw_Lbist(void)
{
    if (!IfxScuLbist_isDone())
    {
        if(Ifx_Ssw_isColdPoweronReset())
        {
            IfxScuLbist_triggerInline(&IfxScuLbist_defaultConfig);
        }
    }
    if (!IfxScuLbist_evaluateResult(IfxScuLbist_defaultConfig.signature))
    {
         __debug();
         /* Application may have call to error handling here*/
         while(1);   /* infinite loop to ensure that error is notified ass debugger is not connected at this point of time */
    }

    Ifx_Ssw_jumpBackToLink();
}
#endif

#if defined(__TASKING__)
#pragma endoptimize
#elif defined(__HIGHTEC__)
#pragma GCC reset_options
#endif
