/**
 * \file Cpu0_Main.c
 * \brief Main function definition for Cpu core 0 .
 *
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
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

#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "can.h"
#include "can_cb.h"
#include "can_io.h"
#include "GtmTomTimerDemo.h"
#include "GtmTomPwmHlDemo.h"
#include "TimPwmDemo.h"
#include "IfxPort.h"
#include "AsclinShellInterface.h"
#include "EvadcQueueTransferDemo.h"
#include "FlashDemo.h"
#include "Cpu0_Main.h"

//extern function from python
void SysTick_Handler(void);


IFX_ALIGN(4) IfxCpu_syncEvent cpuSyncEvent= 0;

uint32 one_ms_cnt;
Can_Message_t msg1;
App_Cpu0 g_AppCpu0; /**< \brief CPU 0 global data */

#define IRQ_PRIORITY_STM0   5

//----------------------------------------------------------------
// The ISR interface for the micropython
//-------------------------------------------------------------
void py_tc397_set_globalisr_disable(void)
{
  IfxCpu_disableInterrupts();
}

void py_tc397_set_globalisr_enable(void)
{
  IfxCpu_enableInterrupts();
}
//----------------------------------------------------------------
// CAN Interface for python
//----------------------------------------------------------------
void Can_Test(void)
{
	msg1.CanId = 0x123;
	msg1.DLC   = 8;
	msg1.FDF   = 0;
	msg1.BRS   = 0;
	msg1.XTD   = 0;

	for(uint8 i=0; i<8; i++)
	{
		msg1.MessageData.Byte[i] = i;
	}

	//Can_TxFIFO_Write(2, &msg1);
    Can_TxQueue0_Write(2, &msg1);
}

void py_tc397_set_can_msg(unsigned char can_idx, uint32_t can_id,uint8_t* data,uint8_t len)
{
   if(can_idx == 1)  //First CAN
   {
	  msg1.CanId = can_id;
	  msg1.DLC   = len;
	  msg1.FDF   = 0;
	  msg1.BRS   = 0;
	  msg1.XTD   = 0;

	  for(uint8 i=0; i< len; i++)
	  {
	    msg1.MessageData.Byte[i] = data[i];
	  }

	  //Can_TxFIFO_Write(2, &msg1);
	  Can_TxQueue0_Write(2, &msg1);
   }
}
void py_tc397_reset_can(unsigned char can_idx)
{
   if(can_idx == 1)  //First CAN
   {
     Can_ChInit(2);
     Can_Io_Init();
   }
}
void py_tc397_set_can_filter(unsigned char can_idx,unsigned int id)
{
  if(can_idx == 1)  //First CAN
  {
    Can_Configurre_Filters(2,id);
  }
}
//----------------------------------------------------------------
// Flash API
//----------------------------------------------------------------
void  py_tc397_erase_dflash(unsigned char sector,unsigned char sector_num)
{
  IfxFlash_erase_dflash(sector,sector_num);
}

void py_tc397_programme_dflash(unsigned int destpageaddr,unsigned int           wordL, unsigned int wordU)
{
  IfxFlash_programme_dflash(destpageaddr,wordL,wordU);
}

//----------------------------------------------------------------
// Clock Interface for python
//----------------------------------------------------------------
unsigned int py_tc397_get_OscFrequency(void)
{
  return (unsigned int)(IfxScuCcu_getOscFrequency()/1000000);
}
unsigned int py_tc397_get_Pll1Frequency(void)
{
  return (unsigned int)(IfxScuCcu_getPerPllFrequency1()/1000000);
}
unsigned int py_tc397_get_Pll2Frequency(void)
{
  return (unsigned int)(IfxScuCcu_getPerPllFrequency2()/1000000);
}
unsigned int py_tc397_get_SriFrequency(void)
{
  return (unsigned int)(IfxScuCcu_getSriFrequency()/1000000);
}
unsigned int py_tc397_get_SbpFrequency(void)
{
  return (unsigned int)(IfxScuCcu_getSpbFrequency()/1000000);
}
unsigned int py_tc397_get_CpuFrequency(unsigned char cpu)
{
  return (unsigned int)(IfxScuCcu_getCpuFrequency(cpu)/1000000);
}
unsigned int py_tc397_get_McuDieTemp(void)
{ 
  unsigned int raw_result = PMS_DTSSTAT.B.RESULT;
  float G_nom = 7.505,f_result;
  
  f_result = (float)raw_result;

  return (unsigned int) (f_result/G_nom - 273.15);
}
float py_tc397_get_McuDieTemp_Float(void)
{ 
  unsigned int raw_result = PMS_DTSSTAT.B.RESULT;
  float G_nom = 7.505,f_result;
  
  f_result = (float)raw_result;

  return (float) (f_result/G_nom - 273.15);
}

unsigned int py_tc397_get_StmTimer(void)
{
  return STM0_TIM0.U;
}

//float32 IfxScuCcu_getCpuFrequency(const IfxCpu_ResourceCpu cpu);

IFX_INTERRUPT(STM0SR0ISR, 0, IRQ_PRIORITY_STM0)
{
	uint32	ui32_LastCompareValue = 0;

	ui32_LastCompareValue = STM0_CMP0.B.CMPVAL;
	STM0_CMP0.B.CMPVAL  = ui32_LastCompareValue + 100000U;

	if((STM0_TIM0.U - ui32_LastCompareValue) >= 100000U)
	{
		STM0_CMP0.U = STM0_TIM0.U + 100000U;
	}

	one_ms_cnt++;
	//Can_Test();
	SysTick_Handler();
}

void	StartSystemTimer(void)
{
	STM0_CMCON.B.MSIZE0 = 0x1F;		//CMP0
	STM0_CMCON.B.MSTART0 = 0;

	SRC_STM_STM0_SR0.B.SRPN = IRQ_PRIORITY_STM0;
	SRC_STM_STM0_SR0.B.SRE = 1;		//service request enable
	SRC_STM_STM0_SR0.B.TOS = 0;		//CPU0 provide service

	STM0_CMP0.U = STM0_TIM0.U + 100000U;
	STM0_ISCR.B.CMP0IRR = 1;
	STM0_ICR.B.CMP0EN = 1;			// Enable
}

void test_toggle_pin(void)
{
    IfxPort_togglePin(&MODULE_P33,8);
}
void py_tx(void);
int main(int argc, char **argv);

//----------------------------------------------------------------
//PIN API for MP LED
//----------------------------------------------------------------
void py_tc397_led_state(unsigned char idx,unsigned char status )
{
  if(idx == 1)
  {
     if(status == 1) //HIGH
     {
       IfxPort_setPinHigh(&MODULE_P33,4);
     }
	 else // LOW
	 {
	   IfxPort_setPinLow(&MODULE_P33,4);
	 }
  }
  else if(idx == 2)
  {
     if(status == 1) //HIGH
     {
       IfxPort_setPinHigh(&MODULE_P33,5);
     }
	 else // LOW
	 {
	   IfxPort_setPinLow(&MODULE_P33,5);
	 }
  }
  else if(idx == 3)
  {
     if(status == 1) //HIGH
     {
       IfxPort_setPinHigh(&MODULE_P33,6);
     }
	 else // LOW
	 {
	   IfxPort_setPinLow(&MODULE_P33,6);
	 }
  }
  else if(idx == 4)
  {
     if(status == 1) //HIGH
     {
       IfxPort_setPinHigh(&MODULE_P33,7);
     }
	 else // LOW
	 {
	   IfxPort_setPinLow(&MODULE_P33,7);
	 }
  }
}
void py_tc397_led_toggle(unsigned char idx )
{
  if(idx == 1)
  {
    IfxPort_togglePin(&MODULE_P33,4);
  }
  else if(idx == 2)
  { 
    IfxPort_togglePin(&MODULE_P33,5);
  }
  else if(idx == 3)
  { 
    IfxPort_togglePin(&MODULE_P33,6);
  }
  else if(idx == 4)
  { 
    IfxPort_togglePin(&MODULE_P33,7);
  }
}

//----------------------------------------------------------------
//PIN API for MP PIN
//----------------------------------------------------------------
void py_tc397_set_pin_high(unsigned char idx)
{
  IfxPort_setPinHigh(&MODULE_P33,idx);
}
void py_tc397_set_pin_low(unsigned char idx)
{
  IfxPort_setPinLow(&MODULE_P33,idx);
}
unsigned char py_tc397_get_pin_state(unsigned char idx )
{
  return IfxPort_getPinState(&MODULE_P33,idx);
}
unsigned char py_tc397_get_pin_mode(unsigned char idx )
{
  return (unsigned char)IfxPort_getPinMode(&MODULE_P33,idx);
}
void py_tc397_set_pin_mode(unsigned char idx ,unsigned char mode)
{
  IfxPort_setPinMode(&MODULE_P33,idx,mode);
}

//----------------------------------------------------------------
//PIN API for MP ADC
//----------------------------------------------------------------
unsigned int py_tc397_get_adc_result(unsigned char idx)
{
  return EvadcQueueTransfer_ch_run(idx);
}
//----------------------------------------------------------------
//PIN API for MP TIMER
//----------------------------------------------------------------
void py_tc397_delay_ms(unsigned int delay_ms )
{
  IfxCpu_waitdelay(delay_ms);
}

//----------------------------------------------------------------
//MP Application entry for core0
//----------------------------------------------------------------
void core0_main (void)
{
    //IfxCpu_enableInterrupts();
    /*
     * !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdog in the demo if it is required and also service the watchdog periodically
     * */
    IfxScuWdt_disableCpuWatchdog (IfxScuWdt_getCpuWatchdogPassword ());
    IfxScuWdt_disableSafetyWatchdog (IfxScuWdt_getSafetyWatchdogPassword ());

    /* Cpu sync event wait*/
    IfxCpu_emitEvent(&cpuSyncEvent);
    IfxCpu_waitEvent(&cpuSyncEvent, 1);
	
    IfxPort_setPinModeOutput(&MODULE_P33,8,IfxPort_OutputMode_pushPull,IfxPort_OutputIdx_general);

	//LED for the Python
	IfxPort_setPinModeOutput(&MODULE_P33,4,IfxPort_OutputMode_pushPull,IfxPort_OutputIdx_general);
	IfxPort_setPinModeOutput(&MODULE_P33,5,IfxPort_OutputMode_pushPull,IfxPort_OutputIdx_general);
	IfxPort_setPinModeOutput(&MODULE_P33,6,IfxPort_OutputMode_pushPull,IfxPort_OutputIdx_general);
	IfxPort_setPinModeOutput(&MODULE_P33,7,IfxPort_OutputMode_pushPull,IfxPort_OutputIdx_general);

	IfxPort_setPinHigh(&MODULE_P33,4);
	IfxPort_setPinHigh(&MODULE_P33,5);
	IfxPort_setPinHigh(&MODULE_P33,6);
	IfxPort_setPinHigh(&MODULE_P33,7);

	//MCAN initialization for Python
    Can_ChInit(2);
    Can_Io_Init();

    StartSystemTimer();
	
    /* Demo init */
    //GtmTomTimerDemo_init();

	/* Demo init */   
	//GtmTomPwmHlDemo_init();

    /* Demo init */    
	//TimPwmDemo_init();
	/* Demo init */
    AsclinShellInterface_init();
	EvadcQueueTransferDemo_init();
	//IfxFlashDemo_init();

	//Test the flash programming here.
	//IfxFlashDemo_run();

	main(0, NULL);

    while (1)
    {	  
	  //Never reach here.
      //AsclinShellInterface_run();
		 
      //GtmTomPwmHlDemo_run();
      //GtmTomTimerDemo_run();
      py_tx();
      
	  //TimPwmDemo_run();       

	  if (TimPwmDemo_Info.isrHitCount > 5) /* stop after 5 runs */       
	  {        	
	    REGRESSION_RUN_STOP_PASS;       
	  }
    }
}

