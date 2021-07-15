/**
 * \file IfxPmsPm.c
 * \brief PMS  basic functionality
 *
 * \version iLLD_1_0_1_10_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPmsPm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPmsPm_setStandbyMode(Ifx_PMS *pms, IfxPmsPm_WakeupConfig *config, IfxPmsPm_RequestPowerMode powerMode)
{
    uint8  alarmGroup  = 8;
    uint32 alarmMask   = 0x1DU;
    uint8  smuTrapEnable;
    uint32 wait_cycles = 0;
    uint16 cpuWdtPw    = IfxScuWdt_getCpuWatchdogPassword();
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    {
        /* Disable TRAP for SMU (oscillator watchdog and unlock detection) */
        IfxScuWdt_clearCpuEndinit(cpuWdtPw);
        smuTrapEnable           = SCU_TRAPDIS0.B.CPU0SMUT;
        SCU_TRAPDIS0.B.CPU0SMUT = 1U;
        IfxScuWdt_setCpuEndinit(cpuWdtPw);
    }

    /* Select fback (fosc-evr) as CCU input clock */
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    /* Disable SMU Alarms  */
    {
        /* Enable access to SMU registers */
        SMU_KEYS.U                       = (uint32)0x000000bc;
        /*Clear all SMU alarms for PLL and OSC*/
        MODULE_SMU.AGCF[alarmGroup][0].U = (MODULE_SMU.AGCF[alarmGroup][0].U & ~alarmMask);
        MODULE_SMU.AGCF[alarmGroup][1].U = (MODULE_SMU.AGCF[alarmGroup][1].U & ~alarmMask);
        MODULE_SMU.AGCF[alarmGroup][2].U = (MODULE_SMU.AGCF[alarmGroup][2].U & ~alarmMask);

        /* Clear the keys to avoid any further update to SMU registers */
        SMU_KEYS.U = (uint32)0U;
    }
    /* Select fback (fosc-evr) as CCU input clock */
    SCU_CCUCON0.B.CLKSEL = IfxScu_CCUCON0_CLKSEL_fBack;

    /* Update for all CCUCONx registers*/
    SCU_CCUCON0.B.UP = 1U;

    /* Providing delay between Clock source switch to Backup and PLL power down*/
    for (wait_cycles = 0; wait_cycles < IFXPMS_WAIT_CYCLES; wait_cycles++)
    {
        __nop();
    }

    /* PLL block is put into the Power Saving Mode */
    SCU_SYSPLLCON0.B.PLLPWD = 0U;
    SCU_PERPLLCON0.B.PLLPWD = 0U;

    /* Disable Oscillator*/
    SCU_OSCCON.B.MODE = 3U;

    /* Configure IRADIS bit to disable Idle Request Acknowledge sequence
     * activation for fast Standby Mode entry. This ensures that standby request
     * is not blocked by pending request or sequence*/

    SCU_PMSWCR1.B.IRADIS = 1U;

    /* Configure Standby entry through REQSLP bit setting only */
    SCU_PMSWCR1.B.STBYEVEN = 1U;
    SCU_PMSWCR1.B.STBYEV   = 0U;

    /* Set all pads to tristate and enable Standby RAM */

    pms->PMSWCR5.B.BPTRISTREQ = 1;
    pms->PMSWCR5.B.TRISTREQ   = 0;
    pms->PMSWCR0.B.STBYRAMSEL = config->standbyRam;

    IfxPmsPm_enableWakeup(pms, config);

    IfxScuWdt_setSafetyEndinit(safetyWdtPw);

    {
        /* Enable VCO unlock Trap if it was disabled before */
        IfxScuWdt_clearCpuEndinit(cpuWdtPw);
        SCU_TRAPCLR.B.SMUT      = 1U;
        SCU_TRAPDIS0.B.CPU0SMUT = smuTrapEnable;
        IfxScuWdt_setCpuEndinit(cpuWdtPw);
    }

    uint8 index = IfxCpu_getCoreIndex();
    IfxScuWdt_clearCpuEndinit(cpuWdtPw);

    switch (index)
    {
    case 0:
        MODULE_SCU.PMCSR0.B.REQSLP = powerMode;
        break;
    case 1:
        MODULE_SCU.PMCSR1.B.REQSLP = powerMode;
        break;
    case 2:
        MODULE_SCU.PMCSR2.B.REQSLP = powerMode;
        break;
    case 3:
        MODULE_SCU.PMCSR3.B.REQSLP = powerMode;
        break;
    case 4:
        MODULE_SCU.PMCSR4.B.REQSLP = powerMode;
        break;
    case 5:
        MODULE_SCU.PMCSR5.B.REQSLP = powerMode;
        break;
    }

    IfxScuWdt_setCpuEndinit(cpuWdtPw);
}


boolean IfxPmsPm_setCoreMode(IfxCpu_ResourceCpu cpuIndex, IfxCpu_CoreMode mode)
{
    uint8            reqSleep = (uint8)-1;
    boolean          retValue;
    volatile uint32 *cpu;
    uint8            pmcIndex = cpuIndex;

    /*Modes such as HALT and STBY are not handled at CPU level */
    retValue = ((mode == IfxCpu_CoreMode_halt) || (mode == IfxCpu_CoreMode_stby)) ? FALSE : TRUE;

    switch (mode)
    {
    case IfxCpu_CoreMode_idle:
        reqSleep = IfxScu_PMCSR_REQSLP_Idle;
        break;
    case IfxCpu_CoreMode_run:
        reqSleep = IfxScu_PMCSR_REQSLP_Run;
        break;
    case IfxCpu_CoreMode_sleep:
        reqSleep = IfxScu_PMCSR_REQSLP_Sleep;
        break;
    default:
        return 0;
    }

    if (retValue == TRUE)
    {
        /*Check if the same core is requesting to change the core run mode */
        if (IfxCpu_getCoreIndex() != cpuIndex)
        {                       /*Request is for the other core */
            /*To access PMCSR of other CPUs handle the safety EndInit protection */
            uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
            IfxScuWdt_clearSafetyEndinit(safetyWdtPw);

            switch (pmcIndex)
            {
            case 0:
                MODULE_SCU.PMCSR0.B.REQSLP = reqSleep;
                break;
            case 1:
                MODULE_SCU.PMCSR1.B.REQSLP = reqSleep;
                break;
            case 2:
                MODULE_SCU.PMCSR2.B.REQSLP = reqSleep;
                break;
            case 3:
                MODULE_SCU.PMCSR3.B.REQSLP = reqSleep;
                break;
            case 4:
                MODULE_SCU.PMCSR4.B.REQSLP = reqSleep;
                break;
            case 5:
                MODULE_SCU.PMCSR5.B.REQSLP = reqSleep;
                break;
            }

            IfxScuWdt_setSafetyEndinit(safetyWdtPw);
            cpu                       = (volatile uint32 *)IfxCpu_getAddress(cpuIndex);
            /*Temprory patch for MCMETILLD-682 FIXME*/
            (*(cpu + (0x1FD00 / 4))) |= (2 << IFX_CPU_DBGSR_DE_MSK); /*reset the HALT bit, if it is already done it is no harm in writing again */
        }
        else
        {                                                            /*Request is for self, this request normally only for halt, otherwise the core is already running anyway! */
            /*To access PMCSR of self handle the cpu EndInit protection */
            uint16 cpuWdtPw = IfxScuWdt_getCpuWatchdogPassword();
            IfxScuWdt_clearCpuEndinit(cpuWdtPw);

            switch (pmcIndex)
            {
            case 0:
                MODULE_SCU.PMCSR0.B.REQSLP = reqSleep;
                break;
            case 1:
                MODULE_SCU.PMCSR1.B.REQSLP = reqSleep;
                break;
            case 2:
                MODULE_SCU.PMCSR2.B.REQSLP = reqSleep;
                break;
            case 3:
                MODULE_SCU.PMCSR3.B.REQSLP = reqSleep;
                break;
            case 4:
                MODULE_SCU.PMCSR4.B.REQSLP = reqSleep;
                break;
            case 5:
                MODULE_SCU.PMCSR5.B.REQSLP = reqSleep;
                break;
            }

            IfxScuWdt_setCpuEndinit(cpuWdtPw);
        }
    }

    return retValue;
}


void IfxPmsPm_enableWakeup(Ifx_PMS *pms, IfxPmsPm_WakeupConfig *wakeup)
{
    Ifx_PMS_PMSWCR0 tempPMSW;

    switch (wakeup->wakeup)
    {
    case IfxPmsPm_WakeupOn_esr0:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.PORSTWKEN = 0;
        tempPMSW.B.ESR0WKEN  = 1;
        tempPMSW.B.ESR0DFEN  = wakeup->filter;
        tempPMSW.B.ESR0EDCON = wakeup->trigger;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    case IfxPmsPm_WakeupOn_esr1:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.PORSTWKEN = 0;
        tempPMSW.B.ESR1WKEN  = 1;
        tempPMSW.B.ESR1DFEN  = wakeup->filter;
        tempPMSW.B.ESR1EDCON = wakeup->trigger;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    case IfxPmsPm_WakeupOn_pinA:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.PORSTWKEN = 0;
        tempPMSW.B.PINAWKEN  = 1;
        tempPMSW.B.PINADFEN  = wakeup->filter;
        tempPMSW.B.PINAEDCON = wakeup->trigger;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    case IfxPmsPm_WakeupOn_pinB:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.PORSTWKEN = 0;
        tempPMSW.B.PINBWKEN  = 1;
        tempPMSW.B.PINBDFEN  = wakeup->filter;
        tempPMSW.B.PINBEDCON = wakeup->trigger;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    case IfxPmsPm_WakeupOn_timer:
        tempPMSW.U         = pms->PMSWCR0.U;
        tempPMSW.B.WUTWKEN = 1;
        pms->PMSWCR0.U     = tempPMSW.U;
        pms->PMSWCR3.U    |= ((wakeup->mode << 30) | (1 << 27) | (wakeup->reloadCounter));
        break;
    case IfxPmsPm_WakeupOn_porst:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.PORSTWKEN = 1;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    case IfxPmsPm_WakeupOn_scr:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.SCRWKEN   = 1;
        tempPMSW.B.PORSTWKEN = 0;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    case IfxPmsPm_WakeupOn_power:
        tempPMSW.U         = pms->PMSWCR0.U;
        tempPMSW.B.PWRWKEN = 1;
        pms->PMSWCR0.U     = tempPMSW.U;
        break;
    default:
        tempPMSW.U           = pms->PMSWCR0.U;
        tempPMSW.B.PORSTWKEN = 1;
        pms->PMSWCR0.U       = tempPMSW.U;
        break;
    }
}


void IfxPmsPm_configureSupplyMonitoring(Ifx_PMS *pms, IfxPmsPm_VoltageSource source, IfxPmsPm_ThresholdEvent event, IfxPmsPm_RampingMode mode)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    uint32 mask        = 0x3 << (source + event);
    pms->MONCTRL.U = (pms->MONCTRL.U & ~mask) | ((mode & 0x3) << (source + event)); //ramp & 0x3 added to ensure that even if a value>3 is passed as an argument and compiler doesn't catch it, other bits aren't screwed up.
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


void IfxPmsPm_initStandbyConfig(IfxPmsPm_StandbyConfig *standbyConfig)
{
    standbyConfig->trigger                        = IfxPmsPm_StandbyTriggerMode_hardware_undervoltage;
    standbyConfig->standbyRamBlock                = IfxPmsPm_StandbyRamSupply_cpu0Cpu1;
    standbyConfig->enableScr                      = TRUE;
    standbyConfig->minDelayBeforeWakeUp           = IfxPmsPm_BlankingFilterDelay_5ms;
    standbyConfig->vextUnderVoltageThresholdLevel = 0x0;
    standbyConfig->vddUnderVoltageThresholdLevel  = 0x0;

    standbyConfig->enableStandbyOnVextRampDown    = FALSE;
    standbyConfig->enableStandbyOnVddRampDown     = FALSE;
    standbyConfig->scrClockSupply                 = IfxPmsPm_ScrClocking_100mhzOptional;
    standbyConfig->esr0PinStateRequest            = IfxPmsPm_Esr0PinStateRequest_tristate;
    standbyConfig->padStateRequest                = IfxPmsPm_PadStateRequest_tristate;
    standbyConfig->enableWakeupOnEsr0             = FALSE;
    standbyConfig->enableWakeupOnEsr1             = FALSE;
    standbyConfig->enableWakeupOnPinA             = FALSE;
    standbyConfig->enableWakeupOnPinB             = FALSE;
    standbyConfig->enableWakeupOnPorst            = TRUE;
    standbyConfig->enableWakeupOnScr              = FALSE;
    standbyConfig->enableWakeupOnPower            = TRUE;
    standbyConfig->enableWakeupOnTimer            = FALSE;
    standbyConfig->wutClock                       = IfxPmsPm_WutClock_70kHz;
    standbyConfig->useWutStandbyAutoStopMode      = FALSE;
    standbyConfig->wutReloadValue                 = 0xFFFF000;

    standbyConfig->esr0DigitalFilterUsage         = IfxPmsPm_DigitalFilter_used;
    standbyConfig->esr1DigitalFilterUsage         = IfxPmsPm_DigitalFilter_used;
    standbyConfig->pinADigitalFilterUsage         = IfxPmsPm_DigitalFilter_used;
    standbyConfig->pinBDigitalFilterUsage         = IfxPmsPm_DigitalFilter_used;

    standbyConfig->esr0TriggerEvent               = IfxPmsPm_PinEdgeTriggerEvent_risingEdge;
    standbyConfig->esr1TriggerEvent               = IfxPmsPm_PinEdgeTriggerEvent_risingEdge;
    standbyConfig->pinATriggerEvent               = IfxPmsPm_PinEdgeTriggerEvent_risingEdge;
    standbyConfig->pinBTriggerEvent               = IfxPmsPm_PinEdgeTriggerEvent_risingEdge;
}


void IfxPmsPm_startStandbySequenceInFlash(IfxPmsPm_StandbyConfig *standbyConfig, const IfxScuCcu_Config *clockConfig)
{
    uint16          endinitSfty_pw;
    Ifx_SCU_PMSWCR1 pmswcr1;

    IFXPMS_DISABLE_ALL_MODULES_STANDBY
/*Setting the current CPU as the Master CPU.Care has to be taken while locating IfxPmsPm_runStandbySequenceInPSPR() and standbyConfig in RAM.*/

    IfxPmsPm_setMasterCpu(IfxCpu_getCoreIndex());

    standbyConfig->masterCpu = IfxPmsPm_getMasterCpu();

/*Disabling interrupts for all CPUs except the Master CPU, a designation assigned to current CPU using IfxPmsPm_setMasterCpu(). This is to avoid wakeup
 * of the CPUs once they are put into IDLE state.*/
    IfxCpu_disableInterruptsAllExceptMaster(IfxCpu_getCoreIndex());

/*Placing all CPUs to Idle state except the Master CPU, a designation assigned to current CPU using IfxPmsPm_setMasterCpu().*/
    IfxCpu_setAllIdleExceptMasterCpu(IfxCpu_getCoreIndex());

    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

/*Clearing all overrun and wakeup status bits.*/
    PMS_PMSWSTATCLR.U = (PMS_PMSWSTATCLR.U | 0xEFFF);

/*Choosing Standby entry mode in the case of both VEVRSB and VEXT remaining active in Standby Mode*/
    if ((standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_software) || (standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_hardware_nmi))
    {
        pmswcr1.U          = SCU_PMSWCR1.U;
        pmswcr1.B.STBYEVEN = 1;
        pmswcr1.B.STBYEV   = standbyConfig->trigger;
        SCU_PMSWCR1.U      = pmswcr1.U;
    }

    if (standbyConfig->enableStandbyOnVextRampDown)
    {
        PMS_PMSWCR0.B.VEXTSTBYEN = 1;
    }

    if (standbyConfig->enableStandbyOnVextRampDown)
    {
        PMS_PMSWCR0.B.VDDSTBYEN = 1;
    }

    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);

    if (standbyConfig->enableStandbyOnVextRampDown)
    {
        IfxPmsEvr_setSecondaryUnderVoltageThresholdMv(&MODULE_PMS, standbyConfig->vextUnderVoltageThresholdLevel, IfxPmsEvr_SupplyMode_swd);
    }

    if (standbyConfig->enableStandbyOnVddRampDown)
    {
        IfxPmsEvr_setSecondaryUnderVoltageThresholdMv(&MODULE_PMS, standbyConfig->vddUnderVoltageThresholdLevel, IfxPmsEvr_SupplyMode_evrc);
    }

/*Configuring Wakeup modes.*/
    IfxPmsPm_configureWakeup(standbyConfig);

/* Continue the remainig part of Standby sequence from PSPR/DLMU RAM*/

    IfxPmsPm_continueStandbySequenceInRAM(standbyConfig, clockConfig);
}


void IfxPmsPm_continueStandbySequenceInRAM(IfxPmsPm_StandbyConfig *standbyConfig, const IfxScuCcu_Config *clockConfig)
{
    uint16 endinitSfty_pw = 0;
    uint16 cpuPassword    = 0;
/*Putting Flash to Sleep*/
    DMU_HF_PCONTROL.B.SLEEP = 0x3;

/*Waiting for flash to enter sleep mode*/
    while (!DMU_HF_PSTATUS.B.SLEEP)
    {}

/* Frequency Ramp-down and switching of clock source to 100MHz Backup clock */
/* Place clockConfig and standbyConfig in respective core's PSPR/DLMU */
    uint32                      pllStepsCount;
    IfxScuCcu_PllThrottleConfig pllThrottleConfig = clockConfig->sysPllThrottleConfig;

    if (SCU_CCUCON0.B.CLKSEL != 0) /* If source not already using backup clock */
    {
        endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

        /*Start Pll ramp down sequence */
        for (pllStepsCount = pllThrottleConfig.numOfSteps; pllStepsCount > 0; pllStepsCount--)
        {                   /*iterate through number of pll steps */
            {
                IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

                /*Configure K2 divider */
                while (SCU_SYSPLLSTAT.B.K2RDY == 0U)
                {
                    /*Wait until K2 divider is ready */
                    /*No "timeout" required, because if it hangs, Safety Endinit will give a trap */
                }

                /*Now set the K2 divider value for the step corresponding to step count */
                SCU_SYSPLLCON1.B.K2DIV = pllThrottleConfig.pllSteps[pllStepsCount - 1].k2Step;
                IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);

                /*Wait for waitCounter corresponding to the pll step */
                //IfxScuCcu_wait(pllThrottleConfig.pllSteps[pllStepsCount - 1].waitTime);
            }
        }

        /* Reset Safety ENDINIT, SCU_CCUCON registers are protected*/
        IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

        while (SCU_CCUCON0.B.LCK != 0U)
        {} /*Wait till ccucon0 lock is set, No "timeout" required, ENDINIT watch-dog is active! */

        {
            Ifx_SCU_CCUCON0 scu_ccucon0;
            scu_ccucon0.U        = SCU_CCUCON0.U;
            scu_ccucon0.B.CLKSEL = 0; /*Select the EVR as fsource0/1/2 for the clock distribution */
            scu_ccucon0.B.UP     = 1; /*Update the ccucon0 register */
            SCU_CCUCON0.U        = scu_ccucon0.U;
        }
    }

    /*Clock dividers for SPB, SRI, BBB, FSI, GETH, GTM, ADAS programmed to have lowest frequency*/
    SCU_CCUCON0.B.LPDIV = 0x4;

/* Shutting down System PLL and Peripheral PLL */

    SCU_SYSPLLCON0.B.PLLPWD = 0U;
    SCU_PERPLLCON0.B.PLLPWD = 0U;

/*Disabling SMU Standby module*/
    Ifx_PMS_CMD_STDBY cmdStdby;
    cmdStdby.U         = PMS_CMD_STDBY.U;
    cmdStdby.B.SMUEN   = 0;
    cmdStdby.B.BITPROT = 1;
    PMS_CMD_STDBY.U    = cmdStdby.U;

/* Disabling Idle Request Acknowledge sequence activation for fast Standby Mode entry so that standby request is not blocked by a pending reset idle request acknowledge sequence */
    SCU_PMSWCR1.B.IRADIS = 1U;

/*Disabling possibilities for Application Reset and System Reset*/
    MODULE_SCU.RSTCON.U = 0U;

    Ifx_PMS_PMSWCR0 pmswcr0;
    pmswcr0.U         = PMS_PMSWCR0.U;
/* Setting the amount of blanking filter delay required */
    pmswcr0.B.BLNKFIL = standbyConfig->minDelayBeforeWakeUp;

/* Select standby RAM region to be powered on during standby */
    pmswcr0.B.STBYRAMSEL = standbyConfig->standbyRamBlock;

/*Configuring the Pins for use in wakeup mode*/

    if ((standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_software) || (standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_hardware_nmi))
    {
        pmswcr0.B.ESR0DFEN  = standbyConfig->esr0DigitalFilterUsage;
        pmswcr0.B.ESR1DFEN  = standbyConfig->esr1DigitalFilterUsage;
        pmswcr0.B.PINADFEN  = standbyConfig->pinADigitalFilterUsage;
        pmswcr0.B.PINBDFEN  = standbyConfig->pinBDigitalFilterUsage;

        pmswcr0.B.ESR0EDCON = standbyConfig->esr0TriggerEvent;
        pmswcr0.B.ESR1EDCON = standbyConfig->esr1TriggerEvent;
        pmswcr0.B.PINAEDCON = standbyConfig->pinATriggerEvent;
        pmswcr0.B.PINBEDCON = standbyConfig->pinBTriggerEvent;
    }

    PMS_PMSWCR0.U = pmswcr0.U;

/* Configuring state of port pins and ESR0 pins upon wakeup */
    Ifx_PMS_PMSWCR5 pmswcr5;
    pmswcr5.U            = PMS_PMSWCR5.U;
    pmswcr5.B.BPTRISTREQ = 1;
    pmswcr5.B.TRISTREQ   = 1;
    pmswcr5.B.BPTRISTREQ = 1;
    pmswcr5.B.ESR0TRIST  = 1;
    PMS_PMSWCR5.U        = pmswcr5.U;

/* Configuring Standby Controller(SCR) if usage during standby mode is enabled */

    if (standbyConfig->enableScr)
    {
        Ifx_PMS_PMSWCR4 pmswcr4;
        pmswcr4.U           = PMS_PMSWCR4.U;
        pmswcr4.B.BPSCREN   = 1U;
        pmswcr4.B.SCREN     = 1U;
/* SCR clock supply configuration */
        pmswcr4.B.SCRCLKSEL = standbyConfig->scrClockSupply;

        if (standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_hardware_undervoltage)
        {
/* Disabling reset of SCR due to standby entry*/
            pmswcr4.B.PORSTREQ = 0;
        }

        PMS_PMSWCR4.U = pmswcr4.U;
    }

    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
/* In case of manual standby entry using software, requesting Standby entry and waiting for Standby Reqested status */
    cpuPassword = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[standbyConfig->masterCpu]);

    if (standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_software)
    {
        IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[standbyConfig->masterCpu], cpuPassword);

        switch (standbyConfig->masterCpu)
        {
        case IfxCpu_ResourceCpu_0: SCU_PMCSR0.B.REQSLP = 0x3;
            break;
        case IfxCpu_ResourceCpu_1: SCU_PMCSR1.B.REQSLP = 0x3;
            break;
        case IfxCpu_ResourceCpu_2: SCU_PMCSR2.B.REQSLP = 0x3;
            break;
        case IfxCpu_ResourceCpu_3: SCU_PMCSR3.B.REQSLP = 0x3;
            break;
        case IfxCpu_ResourceCpu_4: SCU_PMCSR4.B.REQSLP = 0x3;
            break;
        case IfxCpu_ResourceCpu_5: SCU_PMCSR5.B.REQSLP = 0x3;
            break;
        default:
            /* Invalid core selected */
            break;
        }
    }

    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[standbyConfig->masterCpu], cpuPassword);
}


void IfxPmsPm_configureWakeup(IfxPmsPm_StandbyConfig *standbyConfig)
{
    uint16          endinitSfty_pw;
    Ifx_PMS_PMSWCR0 pmswcr0;
    Ifx_PMS_PMSWCR3 pmswcr3;
    pmswcr0.U = PMS_PMSWCR0.U;
    pmswcr3.U = PMS_PMSWCR3.U;

    if (standbyConfig->trigger == IfxPmsPm_StandbyTriggerMode_hardware_undervoltage)
    {
        //TODO:	IFX_ASSERT("Enabling Wakeup on VEXT ramp-up.Disabling Wakeup via ESR0,ESR1,PINA and PORST in VEVRSB only mode as supply to these pins in from VEXT")
        standbyConfig->enableWakeupOnEsr0  = FALSE;
        standbyConfig->enableWakeupOnEsr1  = FALSE;
        standbyConfig->enableWakeupOnPinA  = FALSE;
        standbyConfig->enableWakeupOnPorst = FALSE;
        standbyConfig->enableWakeupOnPower = TRUE;
    }

    pmswcr0.B.ESR0WKEN  = standbyConfig->enableWakeupOnEsr0;
    pmswcr0.B.ESR1WKEN  = standbyConfig->enableWakeupOnEsr1;
    pmswcr0.B.PINAWKEN  = standbyConfig->enableWakeupOnPinA;
    pmswcr0.B.PINBWKEN  = standbyConfig->enableWakeupOnPinB;
    pmswcr0.B.PWRWKEN   = standbyConfig->enableWakeupOnPower;
    pmswcr0.B.SCRWKEN   = standbyConfig->enableWakeupOnScr;
    pmswcr0.B.PORSTWKEN = standbyConfig->enableWakeupOnPorst;
    pmswcr0.B.WUTWKEN   = standbyConfig->enableWakeupOnTimer;

    if ((standbyConfig->enableWakeupOnTimer == TRUE) && (standbyConfig->useWutStandbyAutoStopMode == TRUE))
    {
        /* Setting the clock input for WUT*/
        pmswcr3.B.WUTDIV  = standbyConfig->wutClock;
        /*Enable Wakeup Timer*/
        pmswcr3.B.WUTEN   = TRUE;
        /* Load the value from which the WUT will start downward count upon entering Standby */
        pmswcr3.B.WUTREL  = standbyConfig->wutReloadValue;
        /* Selecting WUT Auto Stop Mode */
        pmswcr3.B.WUTMODE = 1;
    }

    /*get the watch-dog passwords for usage with this function*/
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);
    PMS_PMSWCR0.U  = pmswcr0.U;
    PMS_PMSWCR3.U  = pmswcr3.U;
    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
}


void IfxPmsPm_initSleepConfig(IfxPmsPm_SleepConfig *sleepConfig)
{
    sleepConfig->mcanEnabled       = FALSE;
    sleepConfig->mcanClockSource   = IfxScuCcu_Fsource_0;
    sleepConfig->asclinEnabled     = FALSE;
    sleepConfig->asclinClockSource = IfxScuCcu_Fsource_0;
    sleepConfig->gpt12Enabled      = FALSE;
    sleepConfig->ccu6Enabled       = FALSE;
    sleepConfig->qspiEnabled       = FALSE;
    sleepConfig->qspiClockSource   = IfxScuCcu_Fsource_0;
    sleepConfig->gethEnabled       = FALSE;
    sleepConfig->i2cEnabled        = FALSE;
    sleepConfig->gtmEnabled        = FALSE;
    sleepConfig->stmEnabled        = FALSE;
}


void IfxPmsPm_startSleepSequenceinFlash(IfxPmsPm_SleepConfig *sleepConfig, IfxScuCcu_Config *clockConfig)
{
    uint16 endinitSfty_pw = 0;

/*Set current CPU as the Master CPU*/

    IfxPmsPm_setMasterCpu(IfxCpu_getCoreIndex());

    sleepConfig->masterCpu = IfxPmsPm_getMasterCpu();

/*Placing all CPUs to Idle state except the Master CPU, a designation assigned to current CPU using IfxPmsPm_setMasterCpu().*/
    IfxCpu_setAllIdleExceptMasterCpu(IfxCpu_getCoreIndex());

    IFXPMS_DISABLE_MODULES_DURING_SLEEP

/*Disable(or not) SYSPLL and PERPLL depending on which modules are required to be kept active*/

    Ifx_SCU_SYSPLLCON0 syspllcon0;
    Ifx_SCU_PERPLLCON0 perpllcon0;
    syspllcon0.U        = SCU_SYSPLLCON0.U;
    perpllcon0.U        = SCU_PERPLLCON0.U;

    syspllcon0.B.PLLPWD = 0; //Setting in Power Saving Mode.Will enable it if any of the modules(GPT12(through SPB),CCU6(through SPB),GETH,GTM,STM) need it.
    perpllcon0.B.PLLPWD = 0; //Setting in Power Saving Mode.Will enable it if any of the modules need it.

    if (sleepConfig->gpt12Enabled || sleepConfig->ccu6Enabled || sleepConfig->gethEnabled || sleepConfig->gtmEnabled || sleepConfig->stmEnabled)
    {
        syspllcon0.B.PLLPWD = 1;
    }

    if (sleepConfig->qspiEnabled | sleepConfig->i2cEnabled)
    {
        perpllcon0.B.PLLPWD = 1;
    }

    if ((sleepConfig->mcanEnabled && (sleepConfig->mcanClockSource == IfxScuCcu_Fsource_1)) || (sleepConfig->asclinEnabled && (sleepConfig->asclinClockSource == IfxScuCcu_Fsource_1)))
    {
        perpllcon0.B.PLLPWD = 1;
    }

    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

    SCU_SYSPLLCON0.U            = syspllcon0.U;
    SCU_PERPLLCON0.U            = perpllcon0.U;
/*Clock dividers for SPB, SRI, BBB, FSI, GETH, GTM, ADAS programmed to operate at lowest frequency*/
    SCU_CCUCON0.B.LPDIV         = 0x4;
    SCU_CCUCON0.B.UP            = 1;
    SCU_CCUCON1.B.CLKSELMCAN    = sleepConfig->mcanClockSource;
    SCU_CCUCON2.B.CLKSELASCLINS = sleepConfig->asclinClockSource;
    SCU_CCUCON1.B.CLKSELQSPI    = sleepConfig->qspiClockSource;

    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);

    if (!(sleepConfig->asclinEnabled || sleepConfig->mcanEnabled || sleepConfig->gpt12Enabled || sleepConfig->ccu6Enabled || sleepConfig->qspiEnabled || sleepConfig->gethEnabled || sleepConfig->i2cEnabled || sleepConfig->gtmEnabled || sleepConfig->stmEnabled))
    {
        IfxScuCcu_switchToBackupClock(clockConfig);
    }

    IfxPmsPm_continueSleepSequenceInRAM(sleepConfig);
}


void IfxPmsPm_continueSleepSequenceInRAM(IfxPmsPm_SleepConfig *sleepConfig)
{
    uint16 endinit_pw = 0;

/*Putting Flash to Sleep*/
    DMU_HF_PCONTROL.B.SLEEP = 3;

/*Waiting for flash to sleep*/
    while (!DMU_HF_PSTATUS.B.SLEEP)
    {}

    endinit_pw = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[sleepConfig->masterCpu]);

    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], endinit_pw);

    switch (sleepConfig->masterCpu)
    {
    case IfxCpu_ResourceCpu_0: SCU_PMCSR0.B.REQSLP = 0x2;

        while (SCU_PMCSR0.B.PMST == 0x4)
        {}

        break;

    case IfxCpu_ResourceCpu_1: SCU_PMCSR1.B.REQSLP = 0x2;

        while (SCU_PMCSR1.B.PMST == 0x4)
        {}

        break;

    case IfxCpu_ResourceCpu_2: SCU_PMCSR2.B.REQSLP = 0x2;

        while (SCU_PMCSR2.B.PMST == 0x4)
        {}

        break;

    case IfxCpu_ResourceCpu_3: SCU_PMCSR3.B.REQSLP = 0x2;

        while (SCU_PMCSR3.B.PMST == 0x4)
        {}

        break;

    case IfxCpu_ResourceCpu_4: SCU_PMCSR4.B.REQSLP = 0x2;

        while (SCU_PMCSR4.B.PMST == 0x4)
        {}

        break;
    case IfxCpu_ResourceCpu_5: SCU_PMCSR5.B.REQSLP = 0x2;

        while (SCU_PMCSR5.B.PMST == 0x4)
        {}

        break;
    default:
        /* Invalid core selected */
        break;
    }

    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[sleepConfig->masterCpu], endinit_pw);
}


void IfxPmsPm_initiateWakeup(IfxScuCcu_Config *clockConfig)
{
    /*Put Flash to Normal mode from Sleep*/

    DMU_HF_PCONTROL.B.SLEEP = 0;

/*Wait till Flash is active*/

    while (DMU_HF_PSTATUS.B.SLEEP)
    {}

    IfxScuCcu_init(clockConfig);

    IFXPMS_WAKEUP_MODULES

        IFXPMS_RESTART_EXECUTION
}


void IfxPmsPm_initLoadJumpConfig(IfxPmsPm_LoadJumpConfig *loadJumpConfig)
{
    loadJumpConfig->enableLoadJumpTimer                  = TRUE;
    loadJumpConfig->enableLoadJumpTimerOverflowFlag      = TRUE;
    loadJumpConfig->enableLoadJumpTimerOverflowInterrupt = FALSE;
}


void IfxPmsPm_initAndRequestLoadJump(IfxPmsPm_LoadJumpConfig *loadJumpConfig)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);

    SCU_PMTRCSR0.B.LJTEN    = loadJumpConfig->enableLoadJumpTimer;
    SCU_PMTRCSR0.B.LJTOVEN  = loadJumpConfig->enableLoadJumpTimerOverflowFlag;
    SCU_PMTRCSR0.B.LJTOVIEN = loadJumpConfig->enableLoadJumpTimerOverflowInterrupt;
    __dsync();
    SCU_PMTRCSR2.B.LDJMPREQ = 1U;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


void IfxPmsPm_initVoltageDroopConfig(IfxPmsPm_VoltageDroopConfig *voltageDroopConfig)
{
    /*Enabling usage of Voltage Droop Timer*/
    voltageDroopConfig->enableVoltageDroopTimer                  = TRUE;
    /*Enabling update of Voltage Droop Timer Overflow Flag in event of overflow*/
    voltageDroopConfig->enableVoltageDroopTimerOverflowFlag      = TRUE;
    /*Disabling Voltage Droop Timer interrupt*/
    voltageDroopConfig->enableVoltageDroopTimerOverflowInterrupt = FALSE;
/* Requesting for a reduction voltage(negative voltage droop)*/
    voltageDroopConfig->droopRequestType                         = IfxPmsPm_VoltageDroopRequest_negative;
/*The amount by which voltage change is required is 40mV*/
    voltageDroopConfig->droopStep                                = IfxPmsPm_VoltageDroopStep_40mV;
}


void IfxPmsPm_initAndRequestVoltageDroop(IfxPmsPm_VoltageDroopConfig *voltageDroopConfig)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);

    SCU_PMTRCSR0.B.VDTEN     = voltageDroopConfig->enableVoltageDroopTimer;
    SCU_PMTRCSR0.B.VDTOVEN   = voltageDroopConfig->enableVoltageDroopTimerOverflowFlag;
    SCU_PMTRCSR0.B.VDTOVIEN  = voltageDroopConfig->enableVoltageDroopTimerOverflowInterrupt;
    SCU_PMTRCSR0.B.SDSTEP    = voltageDroopConfig->droopStep;
    __dsync();
    SCU_PMTRCSR3.B.VDROOPREQ = voltageDroopConfig->droopRequestType;
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


void IfxPmsPm_handleStandbyRam(uint32 *dataPointer, uint8 dataSize)
{
    uint32 *redundantDataPointer = (uint32 *)dataPointer;

    uint32  i;

    for (i = 0U; i < dataSize; i++)
    {
        {
            /*Effectively reading addresses from redundantDataPointer and replacing it with data in those addresses*/
            uint32 *temp;
            /*Copy the data(which is an address) into temp pointer */
            temp                  = (uint32 *)(*redundantDataPointer);
            /*Copy the data in temp pointer to redundant data pointer*/
            *redundantDataPointer = *temp;
        }
        redundantDataPointer++;
    }

    /*Calculate the CRC over all the copied data*/
    *redundantDataPointer = IfxCpu_calculateCrc32(dataPointer, dataSize);
}
