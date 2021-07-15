/**
 * \file IfxScuWdt.asm.h
 * \brief SCU  basic functionality
 * \ingroup IfxLld_Scu
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
 * \defgroup IfxLld_Scu_Std_Wdt_Operative Wdt Operative Functionality
 * \ingroup IfxLld_Scu_Std_Wdt
 */
#ifndef IFXSCUWDT_ASM_H
#define IFXSCUWDT_ASM_H 1

#include "Cpu/Std/Ifx_Types.h"
#include "IfxScu_reg.h"

/** \addtogroup IfxLld_Scu_Std_Wdt_Operative
 * \{ */
#define IFXSCUWDT_CALCULATELFSR(pwd) ((((((pwd) >> 13) ^ ((pwd) >> 12) ^ ((pwd) >> 11) ^ ((pwd) >> 1 )) & 1)) | (((pwd)<<1) & 0x3FFF))
/**
 * \brief SCUWDT Inline API utility to Calculte new 14-bit LFSR.
 *
 * This API will Calculte new 14-bit LFSR (Linear Feedback Shift Register) with characteristic polynomial
 * x14+x13+x12+x2+1.
 *
 * \param password Password for which LFSR value to be calculated.
 * \return New LFSR.
 */
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 password);
/** \}  */

/**
 * \brief SCUWDT Inline API utility to Calculte new 14-bit LFSR.
 */
#if defined(__HIGHTEC__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           extr.u %0,%1,0,14     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#endif
#if defined(__TASKING__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           mov d4,#0 \n\
           mov d5,#14 \n\
           extr.u %0,%1,e4     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#endif
#if defined(__DCC__)
/* *INDENT-OFF* */
asm uint16 IfxScuWdt_calculateLfsr_asm(uint16 password)
{
%reg password
!"%d2"
    xor.t %d2, password, 13, password, 12
    xor.t %d2, %d2, 0, password, 11
	sh.xor.t password,%d2,0,password,1
	extr.u %d2,password,0,14
}
/* *INDENT-ON* */
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    return IfxScuWdt_calculateLfsr_asm(pwd);
}
#endif
#if defined(__ghs__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           extr.u %0,%1,0,14     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#endif
#endif
