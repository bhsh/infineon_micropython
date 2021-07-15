/**
 * \file Ifx_Ssw_Tc3.c
 * \brief Startup Software for Core3
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
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Cfg.h"
#include "Ifx_Ssw.h"
#include "Ifx_Ssw_Infra.h"

#include "IfxScu_reg.h"
#include "IfxStm_reg.h"

/******************************************************************************/
/*                          Macros                                            */
/******************************************************************************/
/** \brief Configuration for cache enable.
 *
 */
#ifndef IFX_CFG_SSW_ENABLE_TRICORE3_PCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE3_PCACHE (1U)  /**< Program Cache enabled by default*/
#endif
#ifndef IFX_CFG_SSW_ENABLE_TRICORE3_DCACHE
#   define IFX_CFG_SSW_ENABLE_TRICORE3_DCACHE (1U)  /**< Data Cache enabled by default*/
#endif
/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
IFX_SSW_COMMON_LINKER_SYMBOLS();
IFX_SSW_CORE_LINKER_SYMBOLS(3);

extern void core3_main(void);
#if defined(__TASKING__)
__asm("\t .extern core3_main");
#endif

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*********************************************************************************
* - startup code
*********************************************************************************/
/*Add options to eliminate usage of stack pointers unnecessarily*/
#if defined(__HIGHTEC__)
#pragma GCC optimize "O2"
#endif

void __Core3_start(void)
{
    unsigned int   stmCount;
    unsigned int   stmCountBegin = STM0_TIM0.U;     /* it is necessary to get this value to have minimum 100uS delay in subsequent CPU start */
    unsigned short wdtPassword   = Ifx_Ssw_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[3]);

    /* Load user stack pointer */
    Ifx_Ssw_setAddressReg(sp, __USTACK(3));
    Ifx_Ssw_DSYNC();

    /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
    Ifx_Ssw_MTCR(CPU_PSW, IFX_CFG_SSW_PSW_DEFAULT);

    /* Clear the ENDINIT bit in the WDT_CON0 register, inline function */
    Ifx_Ssw_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[3], wdtPassword);

    {
        Ifx_CPU_PCON0 pcon0;
        pcon0.U       = 0;
        pcon0.B.PCBYP = IFX_CFG_SSW_ENABLE_TRICORE3_PCACHE ? 0 : 1; /*depending on the enable bypass bit is reset/set */
        Ifx_Ssw_MTCR(CPU_PCON0, pcon0.U);
        Ifx_Ssw_ISYNC();
    }

    {
        Ifx_CPU_DCON0 dcon0;
        dcon0.U       = 0;
        dcon0.B.DCBYP = IFX_CFG_SSW_ENABLE_TRICORE3_DCACHE ? 0 : 1; /*depending on the enable bypass bit is reset/set */
        Ifx_Ssw_MTCR(CPU_DCON0, dcon0.U);
        Ifx_Ssw_ISYNC();
    }

    /* Load Base Address of Trap Vector Table. */
    Ifx_Ssw_MTCR(CPU_BTV, (unsigned int)__TRAPTAB(3));

    /* Load Base Address of Interrupt Vector Table. we will do this later in the program */
    Ifx_Ssw_MTCR(CPU_BIV, (unsigned int)__INTTAB(3));

    /* Load interrupt stack pointer. */
    Ifx_Ssw_MTCR(CPU_ISP, (unsigned int)__ISTACK(3));

    Ifx_Ssw_setCpuEndinitInline(&MODULE_SCU.WDTCPU[3], wdtPassword);

    /* initialize SDA base pointers */
    Ifx_Ssw_setAddressReg(a0, __SDATA1(3));
    Ifx_Ssw_setAddressReg(a1, __SDATA2(3));
    Ifx_Ssw_setAddressReg(a8, __SDATA3(3));
    Ifx_Ssw_setAddressReg(a9, __SDATA4(3));

    Ifx_Ssw_initCSA((unsigned int *)__CSA(3), (unsigned int *)__CSA_END(3));

    /* Clears any instruction buffer */
    Ifx_Ssw_ISYNC();

    stmCount = (unsigned int)(Ifx_Ssw_getStmFrequency() * IFX_CFG_SSW_STARTCPU_WAIT_TIME_IN_SECONDS);

    while ((unsigned int)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }

    /*Start remaining cores down the line in a daisy-chain fashion*/
#if (IFX_CFG_SSW_ENABLE_TRICORE4 != 0)
    (void)Ifx_Ssw_startCore(&MODULE_CPU4, (unsigned int)__START(4));       /*The status returned by function call is ignored */
#endif
#if (IFX_CFG_SSW_ENABLE_TRICORE4 == 0)
#if (IFX_CFG_SSW_ENABLE_TRICORE5 != 0)
    (void)Ifx_Ssw_startCore(&MODULE_CPU5, (unsigned int)__START(5));       /*The status returned by function call is ignored */
#endif
#endif /* #if (IFX_CFG_SSW_ENABLE_TRICORE4 == 0) */

    /*Initialize CPU Private Global Variables*/
    //TODO : This implementation is done once all compilers support this
#if (IFX_CFG_SSW_ENABLE_INDIVIDUAL_C_INIT != 0)
    (void)Ifx_Ssw_C_Init();
#endif

    /*Call main function of Cpu3 */
    Ifx_Ssw_jumpToFunction(core3_main);
}

/******************************************************************************
 *                        reset vector address                                *
 *****************************************************************************/
#if defined(__HIGHTEC__)
#pragma section
#pragma section ".start_cpu3" x
#endif
#if defined(__TASKING__)
#pragma protect on
#pragma section code "start_cpu3"
#endif
#if defined(__DCC__)
#pragma section CODE ".start_cpu3" X
#endif
#if defined(__ghs__)
#pragma ghs section text=".start_cpu3"
#endif

void _START3(void)
{
    Ifx_Ssw_jumpToFunction(__Core3_start);
}

/* reset the sections defined above, to normal region */
#if defined(__HIGHTEC__)
#pragma section
#endif
#if defined(__TASKING__)
#pragma protect restore
#pragma section code restore
#endif
#if defined(__DCC__)
#pragma section CODE
#endif
#if defined(__ghs__)
#pragma ghs section text=default
#endif

/*Restore the options to command line provided ones*/
#if defined(__HIGHTEC__)
#pragma GCC reset_options
#endif
