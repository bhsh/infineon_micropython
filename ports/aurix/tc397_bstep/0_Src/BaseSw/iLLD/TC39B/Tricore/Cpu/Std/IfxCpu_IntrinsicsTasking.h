/**
 * \file IfxCpu_IntrinsicsTasking.h
 *
 * \version iLLD_1_0_1_10_0
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
 * \defgroup IfxLld_Cpu_Intrinsics_Tasking Intrinsics for TASKING compiler
 * \ingroup IfxLld_Cpu_Intrinsics
 *
 */
#ifndef IFXCPU_INTRINSICSTASKING_H
#define IFXCPU_INTRINSICSTASKING_H
/******************************************************************************/
#include "Ifx_Types.h"
/******************************************************************************/
/* *INDENT-OFF* */

#ifndef __cplusplus
/** Function call without return
 */
#define Ifx__non_return_call(fun)	__asm("\tji %0"::"a"(fun))

/** Jump and link
 */
IFX_INLINE void Ifx__jump_and_link(void (*fun)(void))
{
	__asm("jli %0"::"a"(fun));
}

IFX_INLINE void Ifx__moveToDataParam0(unsigned int var)
{
	__asm("mov d4, %0"::"d"(var));
}

IFX_INLINE void Ifx__moveToAddrParam0(const void *var)
{
	__asm("mov.aa a4, %0"::"a"(var));
}

IFX_INLINE unsigned int Ifx__getDataParamRet(void)
{
	unsigned int var;
	__asm(" mov\t %0, d2":"=d"(var));
	return var;
}

IFX_INLINE void Ifx__moveToDataParamRet(unsigned int var)
{
	__asm("mov d2, %0"::"d"(var));
}

IFX_INLINE void Ifx__jumpToFunction(const void *fun)
{
	Ifx__non_return_call(fun);
}

IFX_INLINE void Ifx__jumpToFunctionWithLink(const void *fun)
{
	Ifx__jump_and_link((void (*)(void))fun);
}

IFX_INLINE void Ifx__jumpBackToLink(void)
{
	__asm("ji a11");
}
#endif
/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_any_type Cross type arithmetic operation
 *
 * Macro compatible with float, fix point, signed integer and unsigned integer
 *
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__minX(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__maxX(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturateX(X,Min,Max)          ( Ifx__minX(Ifx__maxX(X, Min), Max) )
#define Ifx__checkrangeX(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_singed_integer Signed integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__saturate(X,Min,Max)           ( __min(__max(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_unsinged_integer Unsigned integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__saturateu(X,Min,Max)           ( __minu(__maxu(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_float Floating point operation
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__checkrange(X,Min,Max)         (((X) >= (Min)) && ((X) <= (Max)))

#define Ifx__sqrf(X)                       ((X) * (X))
#define Ifx__sqrtf(X)                      sqrtf(X)

#define Ifx__roundf(X)                     ((((X) - (int)(X)) > 0.5) ? (1 + (int)(X)) : ((int)(X)))
#define Ifx__absf(X)                       ( ((X) < 0.0) ? -(X) : (X) )
#define Ifx__minf(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__maxf(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturatef(X,Min,Max)          ( Ifx__minf(_Ifx_maxf(X, Min), Max) )
#define Ifx__checkrangef(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))

#define Ifx__abs_stdreal(X)                ( ((X) > 0.0) ? (X) : -(X) )
#define Ifx__min_stdreal(X,Y)              ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__max_stdreal(X,Y)              ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturate_stdreal(X,Min,Max)   ( Ifx__min_stdreal(Ifx__max_stdreal(X, Min), Max) )

#define Ifx__neqf(X,Y)                     ( ((X) > (Y)) ||  ((X) < (Y)) )     /**< X != Y */
#define Ifx__leqf(X,Y)                     ( !((X) > (Y)) )     /**< X <= Y */
#define Ifx__geqf(X,Y)                     ( !((X) < (Y)) )     /**< X >= Y */
/** \} */
/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_fractional Fractional Arithmetic Support
 The next table provides an overview of intrinsic functions to convert fractional values. Note that the
 TASKING VX-toolset C compiler for TriCore fully supports the fractional type so normally you should not
 need these intrinsic functions (except for __mulfractlong). For compatibility reasons the TASKING C
 compiler does support these functions.
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__fract_to_float(value)  ((float)(value))

#define Ifx__mulfractlong __mulfractlong

#define Ifx__mulfractfract(fractvalue1,fractvalue2)  ((fractvalue1)*(fractvalue2))

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_insert Insert / Extract Bit-fields and Bits
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */

#define Ifx__extru(a, p, w)            __extru(a,p,w)

#define Ifx__extr(a, p, w)             __extr(a,p,w)

#define Ifx__imaskldmst(a, v, b, p)    __imaskldmst((int*)a, v, b, p)

#define Ifx__insert(a,b,p,w)           __insert(a,b,p,w)

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_interrupt_handling Interrupt Handling
 The next table provides an overview of the intrinsic functions to read or set interrupt handling.
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__disable_and_save __disable_and_save

#define Ifx__restore __restore

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_miscellaneous Miscellaneous Intrinsic Functions
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_packed Packed Data Type Support
 The next table provides an overview of the intrinsic functions for initialization of packed data type.
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */

/** \} */

#ifndef __cplusplus
/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_register Register Handling
 The next table provides an overview of the intrinsic functions that you can use to access control registers.
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */
#define Ifx__mtcr_no_isync(reg, val)   \
    __asm("mtcr %0,%1"::"i"(reg),"d"(val));

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_saturation Saturation Arithmetic Support
 These intrinsics support saturation arithmetic
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */

#define Ifx__adds(a,b)                 ((__sat int)(a)+(__sat int)(b))

#define Ifx__addsu(a,b)                ((__sat unsigned int)(a)+(__sat unsigned int)(b))

#define Ifx__subs(a,b)                 ((__sat int)(a)-(__sat int)(b))

#define Ifx__subsu(a,b)                ((__sat unsigned int )(a)-(__sat unsigned int )(b))

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Tasking_single_assembly Insert Single Assembly Instruction
 The next table provides an overview of the intrinsic functions that you can use to insert a single assembly
 instruction.You can also use inline assembly but these intrinsics provide a shorthand for frequently used
 assembly instructions.
 * \ingroup IfxLld_Cpu_Intrinsics_Tasking
 * \{
 */

IFX_INLINE void Ifx__nops(void* cnt)
{
    __asm("nop16 \n\t"
          "loop %0,*-2"
          ::"a"(((char*)cnt) - 1));
}

#define Ifx__NOP(n)   __asm(".DUP " #n "\n\tnop16\n\t.ENDM\n")

/** Insert a memory barrier
 */
#define Ifx__mem_barrier __asm("":::"memory");

#if CPU_NO_LDMST
IFX_INLINE void Ifx__ldmstC(volatile void *addr, uint32 mask, uint32 data)
{
    *(volatile uint32 *)addr = (*(volatile uint32 *)addr & ~mask) | (mask & data);
}

#define Ifx__ldmst(a,b,c) Ifx__ldmstC(a,b,c)
#else

IFX_INLINE void Ifx__ldmstAsm(volatile void *addr, uint32 mask, uint32 data)
{
    __asm("\tmov d3, %1 \n"
          "\tmov d2, %2 \n"
          "\tldmst [%0],e2"
          ::"a"(addr), "d"(mask), "d"(data):"d2", "d3");

}

/** Convert float to fract
 */
IFX_INLINE fract Ifx__float_to_fract(float a)
{
    fract res;
    __asm("ftoq31  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

#define Ifx__fract_to_sfract __round16

/** Convert float to sfract
 */
IFX_INLINE sfract Ifx__float_to_sfract(float a)
{
    fract tmp = Ifx__float_to_fract(a);
    return Ifx__fract_to_sfract(tmp);
}

#define Ifx__ldmst(addr, mask, data) Ifx__ldmstAsm(addr, mask, data)
#endif

IFX_INLINE void Ifx__stopPerfCounters(void)
{ //__mtcr (CPU_CCTRL, 0);
    __asm(
            "    mov d0,#0\n"
            "    mtcr #0xFC00,d0\n"
            "    isync\n"
            :::"d0");
}

/** \} */

/* FIXME use inline instead of #define */
/* FIXME is it really required to have #define __setareg(areg,val) ___setareg(areg,val) or can __setareg() implemented directly */
#define Ifx___setareg(areg,val) \
    { __asm (" movh.a\t "#areg",#@his("#val")\n lea\t "#areg",["#areg"]@los("#val")"); }
#define Ifx__setareg(areg,val) Ifx___setareg(areg,val)

/** \brief This function is a implementation of a binary semaphore using compare and swap instruction
 * \param address address of resource.
 * \param value This variable is updated with status of address
 * \param condition if the value of address matches with the value of condition, then swap of value & address occurs.
 *
 */
#define  Ifx__cmpAndSwap(address,value,condition) \
     __cmpswapw((address), ((unsigned long)value), (condition) )

/** \brief Convert a fixpoint value to float32
 *
 * This function converts a value from a fixpoint format to a float32 format.
 *
 *
 * \param value value to be converted.
 * \param shift position of the fix point. Range = [-256, 255] => (Qx.y format where x = shift+1).
 *
 * \return Returns the converted value in the float32 format.
 *
 */
IFX_INLINE float32 Ifx__fixpoint_to_float32(fract value, sint32 shift)
{
    float32 result;

    __asm(
        "   q31tof\t%0, %1, %2  \n"
        : "=d" (result)
        : "d" (value), "d" (shift));
    return result;
}

IFX_INLINE void* Ifx__getA11(void)
{
    unsigned int *res;
    __asm("mov.aa %0, a11": "=a" (res) : :"a11");
    return res;
}

IFX_INLINE void Ifx__setStackPointer(void *stackAddr)
{
    __asm("mov.aa a10, %0": : "a" (stackAddr) :"a10");
}

IFX_INLINE uint32 IfxCpu_calculateCrc32(uint32 *startaddress, uint8 length) 
{
    uint32 returnvalue;
    __asm("MOV d0, #0x0"); /* set seed value to 0 */
    for (;length > 0; length--) 
    { 
        /*calculate the CRC over all data */
        __asm("MOV d1,%0" : : "d" (*startaddress)); 
        __asm("CRC32 d0,d0,d1"); 
        startaddress++; 
    } 
    __asm("MOV %0,d0" : "=d" (returnvalue)); /* return result of CRC*/
    return returnvalue;
}

IFX_INLINE uint32 IfxCpu_getRandomVal(uint32 a, uint32 x, uint32 m)
{
	uint32 result;
    __asm("      mul.u     e14,%1,%2      ; d15 = Eh; d14 = El    \n"
        "        mov       d12,d14        ;   e12 = El            \n"
        "        mov       d13,#0         ;                       \n"
        "        madd.u    e14,e12,d15,#5 ; e14 = El + 5 * d15    \n"
        " 1:     jge.u     d14,%3,2n      ;                       \n"
        "        jz        d15,3n         ;                       \n"
        " 2:     subx      d14,d14,%3     ;  e12=e12-m            \n"
        "        subc      d15,d15,d13    ; d13=d13-0             \n"
        "        loopu     1p             ;                       \n"
        " 3:     mov       %0,d14         ;                       \n"
        : "=d"(result) : "d"(a), "d"(x), "d"(m) : "e14","e12");
    return result;
}

IFX_INLINE sint32 Ifx__popcnt(sint32 a)
{ 
	sint32 res; 
	__asm("popcnt %0,%1":"=d"(res):"d"(a)); 
		return res; 
}
#endif

/* Macros for backward compatibility of the intrinsics*/
/******************************************************************************/

#ifndef __non_return_call
#define __non_return_call Ifx__non_return_call
#endif

#ifndef __jump_and_link
#define __jump_and_link Ifx__jump_and_link
#endif

#ifndef __moveToDataParam0
#define __moveToDataParam0 Ifx__moveToDataParam0
#endif

#ifndef __moveToAddrParam0
#define __moveToAddrParam0 Ifx__moveToAddrParam0
#endif

#ifndef __getDataParamRet
#define __getDataParamRet Ifx__getDataParamRet
#endif

#ifndef __moveToDataParamRet
#define __moveToDataParamRet Ifx__moveToDataParamRet
#endif

#ifndef __jumpToFunction
#define __jumpToFunction Ifx__jumpToFunction
#endif

#ifndef __jumpToFunctionWithLink
#define __jumpToFunctionWithLink Ifx__jumpToFunctionWithLink
#endif

#ifndef __jumpBackToLink
#define __jumpBackToLink Ifx__jumpBackToLink
#endif

#ifndef __minX
#define __minX Ifx__minX
#endif

#ifndef __maxX
#define __maxX Ifx__maxX
#endif

#ifndef __saturateX
#define __saturateX Ifx__saturateX
#endif

#ifndef __checkrangeX
#define __checkrangeX Ifx__checkrangeX
#endif

#ifndef __saturate
#define __saturate Ifx__saturate
#endif

#ifndef __saturateu
#define __saturateu Ifx__saturateu
#endif

#ifndef __checkrange
#define __checkrange Ifx__checkrange
#endif

#ifndef __sqrtf
#define __sqrtf Ifx__sqrtf
#endif

#ifndef __sqrf
#define __sqrf Ifx__sqrf
#endif

#ifndef __roundf
#define __roundf Ifx__roundf
#endif

#ifndef __absf
#define __absf Ifx__absf
#endif

#ifndef __maxf
#define __maxf Ifx__maxf
#endif

#ifndef __saturatef
#define __saturatef Ifx__saturatef
#endif

#ifndef __minf
#define __minf Ifx__minf
#endif

#ifndef __checkrangef
#define __checkrangef Ifx__checkrangef
#endif

#ifndef __abs_stdreal
#define __abs_stdreal Ifx__abs_stdreal
#endif

#ifndef __saturate_stdreal
#define __saturate_stdreal Ifx__saturate_stdreal
#endif

#ifndef __min_stdreal
#define __min_stdreal Ifx__min_stdreal
#endif

#ifndef __max_stdreal
#define __max_stdreal Ifx__max_stdreal
#endif

#ifndef __neqf
#define __neqf Ifx__neqf
#endif

#ifndef __leqf
#define __leqf Ifx__leqf
#endif

#ifndef __geqf
#define __geqf Ifx__geqf
#endif

#ifndef __fract_to_float
#define __fract_to_float Ifx__fract_to_float
#endif

#ifndef __mulfractlong
#define __mulfractlong Ifx__mulfractlong
#endif

#ifndef __mulfractfract
#define __mulfractfract Ifx__mulfractfract
#endif

#ifndef __disable_and_save
#define __disable_and_save Ifx__disable_and_save
#endif

#ifndef __restore
#define __restore Ifx__restore
#endif

#ifndef __mtcr_no_isync
#define __mtcr_no_isync Ifx__mtcr_no_isync
#endif

#ifndef __adds
#define __adds Ifx__adds
#endif

#ifndef __addsu
#define __addsu Ifx__addsu
#endif

#ifndef __subs
#define __subs Ifx__subs
#endif

#ifndef __subsu
#define __subsu Ifx__subsu
#endif

#ifndef __nops
#define __nops Ifx__nops
#endif

#if ((!defined(NOP)) && (!defined(IFX_CFG_DISABLE_DEFAULT_INTRINSICS)))
#define NOP Ifx__NOP
#endif

#ifndef __mem_barrier
#define __mem_barrier Ifx__mem_barrier
#endif

#ifndef __ldmst
#define __ldmst Ifx__ldmst
#endif

#ifndef __ldmstC
#define __ldmstC Ifx__ldmstC
#endif

#ifndef __float_to_sfract
#define __float_to_sfract Ifx__float_to_sfract
#endif

#ifndef __float_to_fract
#define __float_to_fract Ifx__float_to_fract
#endif

#ifndef __fract_to_sfract
#define __fract_to_sfract Ifx__fract_to_sfract
#endif

#ifndef __ldmstAsm
#define __ldmstAsm Ifx__ldmstAsm
#endif

#ifndef __stopPerfCounters
#define __stopPerfCounters Ifx__stopPerfCounters
#endif

#ifndef __setareg
#define __setareg Ifx__setareg
#endif

#ifndef ___setareg
#define ___setareg Ifx___setareg
#endif

#ifndef __cmpAndSwap
#define __cmpAndSwap Ifx__cmpAndSwap
#endif

#ifndef __fixpoint_to_float32
#define __fixpoint_to_float32 Ifx__fixpoint_to_float32
#endif

#ifndef __getA11
#define __getA11 Ifx__getA11
#endif

#ifndef __setStackPointer
#define __setStackPointer Ifx__setStackPointer
#endif

#ifndef __popcnt
#define __popcnt Ifx__popcnt
#endif

/******************************************************************************/
/* *INDENT-ON* */
/******************************************************************************/
#endif /* IFXCPU_INTRINSICSTASKING_H */
