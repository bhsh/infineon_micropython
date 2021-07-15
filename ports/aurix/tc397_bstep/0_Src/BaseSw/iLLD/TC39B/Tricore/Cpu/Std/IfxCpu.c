/**
 * \file IfxCpu.c
 * \brief CPU  basic functionality
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCpu.h"
#include "Pms/Std/IfxPmsPm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxCpu_acquireMutex(IfxCpu_mutexLock *lock)
{
    boolean         retVal;
    volatile uint32 spinLockVal;

    retVal      = FALSE;

    spinLockVal = 1UL;
    spinLockVal =
        (uint32)__cmpAndSwap(((unsigned int *)lock), spinLockVal, 0);

    /* Check if the SpinLock WAS set before the attempt to acquire spinlock */
    if (spinLockVal == 0)
    {
        retVal = TRUE;
    }

    return retVal;
}


void IfxCpu_disableOverlayBlock(IfxCpu_ResourceCpu cpu, uint16 overlayBlock)
{
    Ifx_CPU          *ovcSfrBase = NULL_PTR;

    Ifx_SCU_OVCCON    ovccon;
    Ifx_SCU_OVCENABLE ovcenable;
    uint16            safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    ovccon.U    = MODULE_SCU.OVCCON.U;
    ovcenable.U = MODULE_SCU.OVCENABLE.U;

    /* Disable Overlay in SCU */
    switch (cpu)
    {
    case IfxCpu_ResourceCpu_1:
        ovcSfrBase        = &MODULE_CPU1;
        ovcenable.B.OVEN1 = 0;
        ovccon.B.CSEL1    = 0;
        break;
    case IfxCpu_ResourceCpu_2:
        ovcSfrBase        = &MODULE_CPU2;
        ovcenable.B.OVEN2 = 0;
        ovccon.B.CSEL2    = 0;
        break;

    case IfxCpu_ResourceCpu_3:
        ovcSfrBase        = &MODULE_CPU3;
        ovcenable.B.OVEN3 = 0;
        ovccon.B.CSEL3    = 0;
        break;
    case IfxCpu_ResourceCpu_4:
        ovcSfrBase        = &MODULE_CPU4;
        ovcenable.B.OVEN4 = 0;
        ovccon.B.CSEL4    = 0;
        break;
    case IfxCpu_ResourceCpu_5:
        ovcSfrBase        = &MODULE_CPU5;
        ovcenable.B.OVEN5 = 0;
        ovccon.B.CSEL5    = 0;
        break;
    default:
        ovcSfrBase        = &MODULE_CPU0;
        ovcenable.B.OVEN0 = 0;
        ovccon.B.CSEL0    = 0;
        break;
    }

    ovccon.B.OVSTP         = 1;
    ovccon.B.DCINVAL       = 1;
    MODULE_SCU.OVCCON.U    = ovccon.U;
    MODULE_SCU.OVCENABLE.U = ovcenable.U;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);

    ovcSfrBase->BLK[overlayBlock].RABR.U  = 0;
    ovcSfrBase->BLK[overlayBlock].OTAR.U  = 0;
    ovcSfrBase->BLK[overlayBlock].OMASK.U = 0;
}


void IfxCpu_enableOverlayBlock(IfxCpu_ResourceCpu cpu, uint16 overlayBlock, IfxCpu_OverlayMemorySelect overlayMemorySelect, IfxCpu_OverlayAddressMask overlayAddressMask, uint32 targetBaseAddress, uint32 overlayBaseAddress)
{
    Ifx_CPU *ovcSfrBase = NULL_PTR;

    switch (cpu)
    {
    case IfxCpu_ResourceCpu_1:
        ovcSfrBase = &MODULE_CPU1;
        break;
    case IfxCpu_ResourceCpu_2:
        ovcSfrBase = &MODULE_CPU2;
        break;

    case IfxCpu_ResourceCpu_3:
        ovcSfrBase = &MODULE_CPU3;
        break;

    case IfxCpu_ResourceCpu_4:
        ovcSfrBase = &MODULE_CPU4;
        break;
    case IfxCpu_ResourceCpu_5:
        ovcSfrBase = &MODULE_CPU5;
        break;
    default:
        ovcSfrBase = &MODULE_CPU0;
        break;
    }

    /* Select overlay Block */
    ovcSfrBase->OSEL.U |= 1 << overlayBlock;

    /* Configure ovcBlock */
    Ifx_CPU_BLK_RABR rabr;
    Ifx_CPU_BLK_OTAR otar;
    rabr.U                                = 0;
    rabr.B.OMEM                           = overlayMemorySelect;
    rabr.B.OBASE                          = overlayBaseAddress;

    otar.U                                = 0;
    otar.B.TBASE                          = targetBaseAddress;

    ovcSfrBase->BLK[overlayBlock].RABR.U  = rabr.U;
    ovcSfrBase->BLK[overlayBlock].OTAR.U  = otar.U;
    ovcSfrBase->BLK[overlayBlock].OMASK.U = (overlayAddressMask & 0x0001FFE0);

    /* Enable Overlay in SCU */
    uint16         safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    Ifx_SCU_OVCCON ovccon;
    ovccon.U = MODULE_SCU.OVCCON.U;

    switch (cpu)
    {
    case IfxCpu_ResourceCpu_1:
        MODULE_SCU.OVCENABLE.B.OVEN1 = 1;
        ovccon.B.CSEL1               = 1;
        break;
    case IfxCpu_ResourceCpu_2:
        MODULE_SCU.OVCENABLE.B.OVEN2 = 1;
        ovccon.B.CSEL2               = 1;
        break;
    case IfxCpu_ResourceCpu_3:
        MODULE_SCU.OVCENABLE.B.OVEN3 = 1;
        ovccon.B.CSEL3               = 1;
        break;
    case IfxCpu_ResourceCpu_4:
        MODULE_SCU.OVCENABLE.B.OVEN4 = 1;
        ovccon.B.CSEL4               = 1;
        break;
    case IfxCpu_ResourceCpu_5:
        MODULE_SCU.OVCENABLE.B.OVEN5 = 1;
        ovccon.B.CSEL5               = 1;
        break;
    default:
        MODULE_SCU.OVCENABLE.B.OVEN0 = 1;
        ovccon.B.CSEL0               = 1;
        break;
    }

    ovccon.B.OVSTRT     = 1;
    MODULE_SCU.OVCCON.U = ovccon.U;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IfxCpu_CoreMode IfxCpu_getCoreMode(Ifx_CPU *cpu)
{
    IfxCpu_CoreMode          cpuMode;
    Ifx_CPU_DBGSR            dbgsr;
    IfxCpu_ResourceCpu       index = IfxCpu_getIndex(cpu);

    volatile Ifx_SCU_PMCSR0 *pmcsr_val0;
    volatile Ifx_SCU_PMCSR1 *pmcsr_val1;
    volatile Ifx_SCU_PMCSR2 *pmcsr_val2;
    volatile Ifx_SCU_PMCSR3 *pmcsr_val3;
    volatile Ifx_SCU_PMCSR4 *pmcsr_val4;
    volatile Ifx_SCU_PMCSR5 *pmcsr_val5;
    cpuMode = IfxCpu_CoreMode_unknown;

    /*get the DBGSR.HALT status */
    /*Check if the request is done for same cpu as the host for this call */
    if (IfxCpu_getCoreIndex() != index)
    {                           /*status request is for other cpu than the host */
        dbgsr = cpu->DBGSR;
    }
    else
    {                           /*status request is for same cpu as the host */
        dbgsr.U = __mfcr(CPU_DBGSR);
    }

    /*Check if the requested CPU is in DBG HALT mode */
    if (dbgsr.B.HALT == (uint32)IfxCpu_DBGST_HALT_halt)
    {                           /*CPU is in DBG HALT mode */
        cpuMode = IfxCpu_CoreMode_halt;
    }
    else
    {
        if (dbgsr.B.HALT == (uint32)IfxCpu_DBGST_HALT_run)
        {                       /*CPU is in DBG RUNNING mode now check PMCSR status */
            switch (index)
            {
            case IfxCpu_ResourceCpu_0:

                pmcsr_val0 = &MODULE_SCU.PMCSR0;

                if (pmcsr_val0->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val0->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
            case IfxCpu_ResourceCpu_1:

                pmcsr_val1 = &MODULE_SCU.PMCSR1;

                if (pmcsr_val1->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val1->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
            case IfxCpu_ResourceCpu_2:

                pmcsr_val2 = &MODULE_SCU.PMCSR2;

                if (pmcsr_val2->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val2->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
            case IfxCpu_ResourceCpu_3:

                pmcsr_val3 = &MODULE_SCU.PMCSR3;

                if (pmcsr_val3->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val3->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
            case IfxCpu_ResourceCpu_4:

                pmcsr_val4 = &MODULE_SCU.PMCSR4;

                if (pmcsr_val4->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val4->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
            case IfxCpu_ResourceCpu_5:

                pmcsr_val5 = &MODULE_SCU.PMCSR5;

                if (pmcsr_val5->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val5->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
            default:
                /* Invalid core selected */
                break;
            }
        }
    }

    return cpuMode;
}


IfxCpu_ResourceCpu IfxCpu_getIndex(Ifx_CPU *cpu)
{
    IfxCpu_ResourceCpu result;
    uint32             index;
    result = IfxCpu_ResourceCpu_none;

    for (index = 0; index < IFXCPU_NUM_MODULES; index++)
    {
        if (IfxCpu_cfg_indexMap[index].module == cpu)
        {
            result = (IfxCpu_ResourceCpu)IfxCpu_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


uint32 IfxCpu_getRandomValue(uint32 *seed)
{
    /*************************************************************************
     * the choice of a and m is important for a long period of the LCG
     * with a =  279470273 and
     *       m = 4294967291
     * a maximum period of 2^32-5 is given
     * values for a:
     * 0x5EB0A82F = 1588635695
     * 0x48E7211F = 1223106847
     * 0x10a860c1 =  279470273
     ***************************************************************************/
    uint32 x = *seed;

    /* a seed of 0 is not allowed, and therefore will be changed to a valid value */
    if (x == 0)
    {
        x = 42;
    }

    uint32 a = 0x10a860c1;  // 279470273
    uint32 m = 0xfffffffb;  // 4294967291
    uint32 result;

    //__asm(a,m,x,tmp1,tmp2              );
    //EhEl = a * x;
    //result = e14 %  m;
    // %0 result
    // %1 a
    // %2 x
    // %3 m
    result = IfxCpu_getRandomVal(a, x, m);

    *seed  = result; // to simplify seed passing

    return result;
}


uint32 IfxCpu_getRandomValueWithinRange(uint32 *seed, uint32 min, uint32 max)
{
    uint32 new_value = IfxCpu_getRandomValue(seed);

    /* swap min/max if required */
    if (min > max)
    {
        unsigned swap = max;
        max = min;
        min = swap;
    }

    /* special case */
    if ((min == 0) && (max == 0xffffffff))
    {
        return new_value;
    }

    /* return value within range */
    return (new_value % (max - min + 1)) + min;
}


void IfxCpu_releaseMutex(IfxCpu_mutexLock *lock)
{
    /*Reset the SpinLock*/
    *lock = 0;
}


void IfxCpu_resetSpinLock(IfxCpu_spinLock *lock)
{
    /*Reset the SpinLock*/
    *lock = 0;
}


boolean IfxCpu_setCoreMode(Ifx_CPU *cpu, IfxCpu_CoreMode mode)
{
    // this switch is only temporary required
    // once the IfxCan driver is generated via lldgen, we will vary the code without #ifdef
#ifdef IFX_TC27x
/* FIXME Copied from old TC27xA code, check that this is up to date code */
    IfxCpu_CoreMode     cpuMode;
    boolean             RetVal;
    IfxScu_PMCSR_REQSLP modeSet;

    RetVal  = TRUE;

    modeSet = IfxScu_PMCSR_REQSLP_Idle;

    /* Check the mode the CPU is in */
    cpuMode = IfxCpu_getCoreMode(cpu);

    /* if requested mode is same as current mode nothing to do */
    if (cpuMode != mode)
    {
        /* transition from halt to Run */
        if (IfxCpu_CoreMode_halt == cpuMode)
        {
            if (IfxCpu_CoreMode_run == mode)
            {
                Ifx_CPU_DBGSR dbgsr;

                if (IfxCpu_getCoreIndex() != IfxCpu_getIndex(cpu))
                {
                    cpu->DBGSR.B.HALT = 0x2;
                }
                else
                {
                    dbgsr.U      = __mfcr(CPU_DBGSR);
                    dbgsr.B.HALT = 0x2;
                    __mtcr(CPU_DBGSR, dbgsr.U);
                }
            }
            else                /* cannot go to any other mode e.g. IfxCpu_CoreMode_idle */
            {
                RetVal = FALSE;
            }
        }
        /* From Run to Idle or vice versa */
        else
        {
            if (IfxCpu_CoreMode_run == cpuMode)
            {
                if (IfxCpu_CoreMode_idle == mode)
                {
                    modeSet = IfxScu_PMCSR_REQSLP_Idle;
                }
                else
                {
                    RetVal = FALSE;
                }
            }
            /* idle to Run */
            else if (IfxCpu_CoreMode_idle == cpuMode)
            {
                if (IfxCpu_CoreMode_run == mode)
                {
                    modeSet = IfxScu_PMCSR_REQSLP_Run;
                }
                else
                {
                    RetVal = FALSE;
                }
            }
            else
            {
                RetVal = FALSE;
            }

            if (TRUE == RetVal)
            {
                /* To take care of the Work Around in A step
                 * In A Step the PMCSR is Cpu Endinit protected
                 * in B step it is by safety endinit*/
                uint16          password;
                uint32          wdtCon0_Val;
                Ifx_SCU_WDTCPU *watchdog;
                watchdog = &MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()];    /* FIXME access to the watchdog of an other CPU, this might not work! */
                password = IfxScuWdt_getCpuWatchdogPassword();
                IfxScuWdt_clearCpuEndinit(password);
                /*  password access   */
                watchdog->CON0.U                                        = (password << 2U) | 0x1U;
                /* modify access, E=0 */
                watchdog->CON0.U                                        = (password << 2U) | 0x2U;
                /* password access in advance */
                watchdog->CON0.U                                        = (password << 2U) | 0x1U;
                /* prepare write value */
                wdtCon0_Val                                             = ((0x0000U) << 16U) | (password << 2U) | (0x3U);
                MODULE_SCU.PMCSR[(uint32)IfxCpu_getIndex(cpu)].B.REQSLP = modeSet;
                /* modify access, E=1, reload WDT */
                watchdog->CON0.U                                        = wdtCon0_Val;
                IfxScuWdt_setCpuEndinit(password);
            }
        }
    }

    return RetVal;
#else
    IfxCpu_ResourceCpu cpuIndex;
    cpuIndex = IfxCpu_getIndex(cpu);
    return IfxPmsPm_setCoreMode(cpuIndex, mode);

#endif
}


boolean IfxCpu_setProgramCounter(Ifx_CPU *cpu, uint32 programCounter)
{
    boolean retVal = TRUE;

    if (cpu == IfxCpu_getAddress(IfxCpu_getCoreIndex()))
    {
        retVal = FALSE;
    }
    else
    {
        cpu->PC.B.PC = programCounter >> 1;
    }

    return retVal;
}


boolean IfxCpu_setSpinLock(IfxCpu_spinLock *lock, uint32 timeoutCount)
{
    boolean         retVal;
    volatile uint32 spinLockVal;

    retVal = FALSE;

    do
    {
        spinLockVal = 1UL;
        spinLockVal =
            (uint32)__cmpAndSwap(((unsigned int *)lock), spinLockVal, 0);

        /* Check if the SpinLock WAS set before the attempt to acquire spinlock */
        if (spinLockVal == 0)
        {
            retVal = TRUE;
        }
        else
        {
            timeoutCount--;
        }
    } while ((retVal == FALSE) && (timeoutCount > 0));

    return retVal;
}


boolean IfxCpu_startCore(Ifx_CPU *cpu, uint32 programCounter)
{
    boolean retVal = TRUE;

    /* Set the PC */
    retVal &= IfxCpu_setProgramCounter(cpu, programCounter);

    /* release boot halt mode if required */
    {
        Ifx_CPU_SYSCON syscon;
        syscon = cpu->SYSCON;

        if (syscon.B.BHALT)
        {
            syscon.B.BHALT = 0; cpu->SYSCON = syscon;
        }
    }

    return retVal;
}


boolean IfxCpu_waitEvent(IfxCpu_syncEvent *event, uint32 timeoutMilliSec)
{
    volatile uint32 *sync          = (volatile uint32 *)IFXCPU_GLB_ADDR_DSPR(__mfcr(CPU_CORE_ID), event);

    boolean          errorcnt      = 0U;
    /* Divide with 1000, gives the count value equivalent to milliseconds */
    uint32           stmCount      = (uint32)((IfxScuCcu_getStmFrequency() / 1000) * timeoutMilliSec);
    uint32           stmCountBegin = STM0_TIM0.U;

    while ((*sync & IFXCPU_CFG_ALLCORE_DONE) != IFXCPU_CFG_ALLCORE_DONE)
    {
        __nop();

        if ((uint32)(STM0_TIM0.U - stmCountBegin) >= stmCount)
        {
            errorcnt = 1;
            break;
        }

        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }

    return errorcnt;
}

boolean IfxCpu_waitdelay(uint32 timeoutMilliSec)
{
    boolean          errorcnt      = 0U;
    /* Divide with 1000, gives the count value equivalent to milliseconds */
    uint32           stmCount      = (uint32)((IfxScuCcu_getStmFrequency() / 1000) * timeoutMilliSec);
    uint32           stmCountBegin = STM0_TIM0.U;

    while (1)
    {
        __nop();

        if ((uint32)(STM0_TIM0.U - stmCountBegin) >= stmCount)
        {
            errorcnt = 1;
            break;
        }

        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }

    return errorcnt;
}


void IfxCpu_emitEvent(IfxCpu_syncEvent *event)
{
    Ifx__imaskldmst(event, 1, __mfcr(CPU_CORE_ID), 1);
}


void IfxCpu_triggerCpuReset(IfxCpu_ResourceCpu coreIndex)
{
    if (coreIndex != IfxCpu_getCoreIndex())
    {
        uint16   password = IfxScuWdt_getGlobalEndinitPassword();
        Ifx_CPU *cpu      = IfxCpu_getAddress(coreIndex);
        IfxScuWdt_clearGlobalEndinit(password);
        cpu->KRST0.B.RST = 1;
        cpu->KRST1.B.RST = 1;
        IfxScuWdt_setGlobalEndinit(password);
    }

    else

    {
//Do nothing because one cannot set the endinit back from the same CPU which is reset
    }
}


IfxCpu_ResetStatus IfxCpu_getCpuResetStatus(IfxCpu_ResourceCpu coreIndex)
{
    Ifx_CPU           *cpu    = IfxCpu_getAddress(coreIndex);
    IfxCpu_ResetStatus status = (IfxCpu_ResetStatus)cpu->KRST0.B.RSTSTAT;
    cpu->KRSTCLR.B.CLR = 1;
    return status;
}


void IfxCpu_setAllIdleExceptMasterCpu(IfxCpu_ResourceCpu masterCpu)
{
    uint16 endinitSfty_pw;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

    switch (masterCpu)
    {
    case IfxCpu_ResourceCpu_0:
        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}

        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}

        break;

    case IfxCpu_ResourceCpu_1:
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}

        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}

        break;

    case IfxCpu_ResourceCpu_2:
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}

        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}

        break;

    case IfxCpu_ResourceCpu_3:
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}

        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}

        break;

    case IfxCpu_ResourceCpu_4:
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}

        break;

    case IfxCpu_ResourceCpu_5:
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}

        break;
    default:
        /* Invalid core selected */
        break;
    }

    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
}


void IfxCpu_disableInterruptsAllExceptMaster(IfxCpu_ResourceCpu masterCpu)
{
    uint16 password = IfxScuWdt_getGlobalEndinitPassword();
    IfxScuWdt_clearGlobalEndinit(password);

    switch (masterCpu)
    {
    case IfxCpu_ResourceCpu_0:
        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}

        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}

        break;

    case IfxCpu_ResourceCpu_1:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}

        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}

        break;

    case IfxCpu_ResourceCpu_2:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}

        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}

        break;

    case IfxCpu_ResourceCpu_3:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}

        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}

        break;

    case IfxCpu_ResourceCpu_4:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}

        break;

    case IfxCpu_ResourceCpu_5:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}

        break;
    default:
        /* Invalid core selected */
        break;
    }

    IfxScuWdt_setGlobalEndinit(password);
}
