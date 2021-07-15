/**
 * \file IfxCpu_Irq.c
 * \brief This file contains the APIs for Interrupt related functions.
 *
 *
 * \version iLLD_1_0_1_10_0
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "Tricore/Compilers/Compilers.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxCpu_reg.h"

/*******************************************************************************
**                      Private macros                                        **
*******************************************************************************/

/*******************************************************************************
**                       Global variables/constants                           **
*******************************************************************************/
#if defined(IFX_USE_SW_MANAGED_INT)

typedef void (*Ifx_Isr)(void);

BEGIN_DATA_SECTION(.bss_cpu0)
static Ifx_Isr IfxCpu_Irq_swIntVector0[256];
END_DATA_SECTION

BEGIN_DATA_SECTION(.bss_cpu1)
static Ifx_Isr IfxCpu_Irq_swIntVector1[256];
END_DATA_SECTION

BEGIN_DATA_SECTION(.bss_cpu2)
static Ifx_Isr IfxCpu_Irq_swIntVector2[256];
END_DATA_SECTION

BEGIN_DATA_SECTION(.bss_cpu3)
static Ifx_Isr IfxCpu_Irq_swIntVector3[256];
END_DATA_SECTION

BEGIN_DATA_SECTION(.bss_cpu4)
static Ifx_Isr IfxCpu_Irq_swIntVector4[256];
END_DATA_SECTION

BEGIN_DATA_SECTION(.bss_cpu5)
static Ifx_Isr IfxCpu_Irq_swIntVector5[256];
END_DATA_SECTION

#ifndef IFX_CFG_CPU_IRQ_DEBUG
 #define IFX_CFG_CPU_IRQ_DEBUG __debug()
#endif

#endif /*defined(IFX_USE_SW_MANAGED_INT) */

/*******************************************************************************
**                      Global Function definitions                          **
*******************************************************************************/
#if defined(IFX_USE_SW_MANAGED_INT)

/** \brief API to install the interrupt service routine for Software Managed Interrupts.
 *
 */
void IfxCpu_Irq_installInterruptHandler(void *isrFuncPointer, uint32 serviceReqPrioNumber)
{
	switch (IfxCpu_Irq_getTos(IfxCpu_getCoreIndex()))
    {
    case IfxSrc_Tos_cpu0:
        IfxCpu_Irq_swIntVector0[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
    case IfxSrc_Tos_cpu1:
        IfxCpu_Irq_swIntVector1[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
    case IfxSrc_Tos_cpu2:
        IfxCpu_Irq_swIntVector2[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
    case IfxSrc_Tos_cpu3:
        IfxCpu_Irq_swIntVector3[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
    case IfxSrc_Tos_cpu4:
        IfxCpu_Irq_swIntVector4[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
    case IfxSrc_Tos_cpu5:
        IfxCpu_Irq_swIntVector5[serviceReqPrioNumber] = (Ifx_Isr)isrFuncPointer;
        break;
    case IfxSrc_Tos_dma:
    	break;
    default:
    	break;
    }
}


/** SW managed Interrupt vector tables
 *
 * These are vector tables with single entry for Software Managed Interrupts defined for each core.
 * This function need to be located at boundary 0xXFE0 where (X=1,3,5 and so on). For the software managed
 * interrupts to work correctly, the BIV must be set to address of this function.
 *
 */
IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable0, 0, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if(IfxCpu_Irq_swIntVector0[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector0[icr.B.CCPN]();
    }
    else
    {
    	IFX_CFG_CPU_IRQ_DEBUG;
    }
}

IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable1, 1, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if(IfxCpu_Irq_swIntVector1[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector1[icr.B.CCPN]();
    }
    else
    {
    	IFX_CFG_CPU_IRQ_DEBUG;
    }
}

IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable2, 2, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if(IfxCpu_Irq_swIntVector2[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector2[icr.B.CCPN]();
    }
    else
    {
    	IFX_CFG_CPU_IRQ_DEBUG;
    }
}

IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable3, 3, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if(IfxCpu_Irq_swIntVector3[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector3[icr.B.CCPN]();
    }
    else
    {
    	IFX_CFG_CPU_IRQ_DEBUG;
    }
}

IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable4, 4, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if(IfxCpu_Irq_swIntVector4[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector4[icr.B.CCPN]();
    }
    else
    {
    	IFX_CFG_CPU_IRQ_DEBUG;
    }
}

IFX_INTERRUPT_INTERNAL(IfxCpu_Irq_intVecTable5, 5, 255)
{
    Ifx_CPU_ICR icr;

    icr.U = __mfcr(CPU_ICR);    /*Fetch the ICR value */

    /*Call the ISR */
    if(IfxCpu_Irq_swIntVector5[icr.B.CCPN])
    {
        IfxCpu_Irq_swIntVector5[icr.B.CCPN]();
    }
    else
    {
    	IFX_CFG_CPU_IRQ_DEBUG;
    }
}


#endif /*defined(IFX_USE_SW_MANAGED_INT) */

/** \brief API to get type of service of the caller CPU.
 *
 */
IfxSrc_Tos IfxCpu_Irq_getTos(IfxCpu_ResourceCpu coreId)
{
    const IfxSrc_Tos tos[IFXCPU_NUM_MODULES] = {
        IfxSrc_Tos_cpu0, IfxSrc_Tos_cpu1,
        IfxSrc_Tos_cpu2, IfxSrc_Tos_cpu3,
        IfxSrc_Tos_cpu4, IfxSrc_Tos_cpu5,
    };

    return tos[coreId];
}
