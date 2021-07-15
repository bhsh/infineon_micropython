/**
 * \file IfxCpu_IntrinsicsGnuc.h
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
 * \defgroup IfxLld_Cpu_Intrinsics_Gnuc Intrinsics for GNU compiler
 * \ingroup IfxLld_Cpu_Intrinsics
 *
 */

#ifndef IFXCPU_INTRINSICSGNUC_H
#define IFXCPU_INTRINSICSGNUC_H

/* old style intrinsics handling for AGENtiX environment */
#if defined(SCTB_EMBEDDED)
# define IFXCPU_INTRINSICSGNUC_USE_MACHINE_INTRINSICS 0
#else
# define IFXCPU_INTRINSICSGNUC_USE_MACHINE_INTRINSICS 1
#endif

/******************************************************************************/
#include "Ifx_Types.h"

#if IFXCPU_INTRINSICSGNUC_USE_MACHINE_INTRINSICS
#include "machine/intrinsics.h"
#endif

/******************************************************************************/
/* *INDENT-OFF* */
#define STRINGIFY(x)    #x

/** Function call without return
 */
#define Ifx__non_return_call(fun)	__asm__ volatile ("ji %0"::"a"(fun))

/** Jump and link
 */
IFX_INLINE void Ifx__jump_and_link(void (*fun)(void))
{
	__asm__ volatile ("jli %0"::"a"(fun));
}

IFX_INLINE void Ifx__moveToDataParam0(unsigned int var)
{
	__asm__ volatile ("mov\t %%d4, %0"::"d"(var));
}

IFX_INLINE void Ifx__moveToDataParamRet(unsigned int var)
{
	__asm__ volatile ("mov\t %%d2, %0"::"d"(var));
}

IFX_INLINE unsigned int Ifx__getDataParamRet(void)
{
	unsigned int var;
	__asm__ volatile (" mov\t %0, %%d2":"=d"(var));
	return var;
}

IFX_INLINE void Ifx__moveToAddrParam0(const void *var)
{
	__asm__ volatile ("mov.aa\t %%a4, %0"::"a"(var));
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
	__asm__ volatile ("ji %a11");
}
/** \defgroup IfxLld_Cpu_Intrinsics_Gnuc_any_type Cross type arithmetic operation
 *
 * Macro compatible with float, fix point, signed integer and unsigned integer
 *
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */
#define Ifx__minX(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__maxX(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturateX(X,Min,Max)          ( Ifx__minX(Ifx__maxX(X, Min), Max) )
#define Ifx__checkrangeX(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnuc_singed_integer Signed integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */
#define Ifx__saturate(X,Min,Max)           ( Ifx__min(Ifx__max(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnuc_unsinged_integer Unsigned integer operation
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */
#define Ifx__saturateu(X,Min,Max)           ( Ifx__minu(Ifx__maxu(X, Min), Max) )
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucmin_max Minimum and Maximum of (sint16) Integers
 These intrinsic functions return the minimum or maximum of a sint16, uint16 or sint16
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Return maximum of two integers
 */
IFX_INLINE sint32 Ifx__max(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("max %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return maximum of two sint16
 */
IFX_INLINE sint32 Ifx__maxs(sint16 a, sint16 b)
{
    sint32 res;
    __asm__ volatile ("max.h %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}
/** Return maximum of two unsigned integers
 */
IFX_INLINE uint32 Ifx__maxu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("max.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two integers
 */
IFX_INLINE sint32 Ifx__min(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("min %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two sint16
 */
IFX_INLINE sint16 Ifx__mins(sint16 a, sint16 b)
{
    sint16 res;
    __asm__ volatile ("min.h %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** Return minimum of two unsigned integers
 */
IFX_INLINE uint32 Ifx__minu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("min.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** \} */

/** \defgroup intrinsicsgnuc_float Floating point operation
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

#define Ifx__sqrf(X)                       ((X) * (X))
#define Ifx__sqrtf(X)                      sqrtf(X)
#define Ifx__checkrange(X,Min,Max)         (((X) >= (Min)) && ((X) <= (Max)))

#define Ifx__roundf(X)                     ((((X) - (sint32)(X)) > 0.5) ? (1 + (sint32)(X)) : ((sint32)(X)))
#define Ifx__absf(X)                       ( ((X) < 0.0) ? -(X) : (X) )
#define Ifx__minf(X,Y)                     ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__maxf(X,Y)                     ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturatef(X,Min,Max)          ( Ifx__minf(Ifx__maxf(X, Min), Max) )
#define Ifx__checkrangef(X,Min,Max)        (((X) >= (Min)) && ((X) <= (Max)))

#define Ifx__abs_stdreal(X)                ( ((X) > 0.0) ? (X) : -(X) )
#define Ifx__min_stdreal(X,Y)              ( ((X) < (Y)) ? (X) : (Y) )
#define Ifx__max_stdreal(X,Y)              ( ((X) > (Y)) ? (X) : (Y) )
#define Ifx__saturate_stdreal(X,Min,Max)   ( Ifx__min_stdreal(Ifx__max_stdreal(X, Min), Max) )

#define Ifx__neqf(X,Y)                     ( ((X) > (Y)) ||  ((X) < (Y)) )     /**< X != Y */
#define Ifx__leqf(X,Y)                     ( !((X) > (Y)) )     /**< X <= Y */
#define Ifx__geqf(X,Y)                     ( !((X) < (Y)) )     /**< X >= Y */
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucfractional Fractional Arithmetic Support
 The next table provides an overview of intrinsic functions to convert fractional values. Note that the
 TASKING VX-toolset C compiler for TriCore fully supports the fractional type so normally you should not
 need these intrinsic functions (except for __mulfractlong). For compatibility reasons the TASKING C
 compiler does support these functions.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Count the consecutive number of bits that have the same value as bit 15 of an sfract
 */
IFX_INLINE sint16 Ifx__clssf(sfract a)
{
    sint16 res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                      cls  %0,%1":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert fract to float
 */
IFX_INLINE float Ifx__fract_to_float(fract a)
{
    float res;
    __asm__ volatile ("q31tof  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

/** Convert float to fract
 */
IFX_INLINE fract Ifx__float_to_fract(float a)
{
    fract res;
    __asm__ volatile ("ftoq31  %0,%1,%2":"=d"(res):"d"(a), "d"(0):"memory");
    return res;
}

/** Convert fract to sfract
 */
IFX_INLINE sfract Ifx__fract_to_sfract(fract a)
{
    sfract res;
    __asm__ volatile ("mov.u  %0,0x8000        \n\
                    adds  %0,%1              \n\
                    extr  %0,%0,0x10,0x10 "
                      :"=&d"(res):"d"(a):"memory");
    return res;
}

/** Convert float to sfract
 */
IFX_INLINE sfract Ifx__float_to_sfract(float a)
{
    fract tmp = Ifx__float_to_fract(a);
    return Ifx__fract_to_sfract(tmp);
}

/** Convert laccum to fract
 */
IFX_INLINE fract Ifx__getfract(laccum a)
{
    fract res;
    __asm__ volatile ("dextr  %0,%H1,%L1,0x11":"=&d" (res):"d" (a):"memory");
    return res;
}

/** Multiply-add with rounding. Returns the rounded result of ( a + b * c )
 */
IFX_INLINE sfract Ifx__mac_r_sf(sfract a, sfract b, sfract c)
{
    sfract res;
    __asm__ volatile ("sh  %1,%1,16        \n\
                       maddrs.q  %0,%1,%2L,%3L,1        \n\
                       sh %0,%0,-16":"=d"(res):"d"(a), "d"(b), "d"(c):"memory");
    return res;
}

/** Multiply-add sfract. Returns ( a + b * c )
 */
IFX_INLINE sfract Ifx__mac_sf(sfract a, sfract b, sfract c)
{
    sfract res;
    __asm__ volatile ("sh  %1,%1,16        \n\
                      madds.q  %0,%1,%2L,%3L,1        \n\
                      sh %0,%0,-16":"=d"(res):"d"(a), "d"(b), "d"(c):"memory");
    return res;
}

/** Integer part of the multiplication of a fract and a fract
 */
IFX_INLINE long Ifx__mulfractfract(fract a, fract b)
{
    long res;
    __asm__ volatile ("mul.q %0,%1,%2,1":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Integer part of the multiplication of a fract and a long
 */
IFX_INLINE long Ifx__mulfractlong(fract a, long b)
{
    long res;
    __asm__ volatile ("mul.q %0,%1,%2,1":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Convert fract to sfract
 */
IFX_INLINE sfract Ifx__round16(fract a)
{
    sfract res;
    __asm__ volatile ("mov.u  %0,0x8000        \n\
                    adds  %0,%1              \n\
                    insert  %0,%0,0,0,0x10 \n\
					sh  %0,%0,-16"
                      :"=&d"(res):"d"(a):"memory");
    return res;
}

/** Convert signed sint16 to sfract
 */
IFX_INLINE sfract Ifx__s16_to_sfract(sint16 a)
{
    sfract res;
    __asm__ volatile ("sh  %0,%1,16    \n\
                       sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert sfract to sint16
 */
IFX_INLINE sint16 Ifx__sfract_to_s16(sfract a)
{
    sint16 res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                       sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Convert sfract to uint16
 */
IFX_INLINE uint16 Ifx__sfract_to_u16(sfract a)
{
    uint16 res;
    __asm__ volatile ("sh  %1,%1,16    \n\
                       sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** Left/right shift of an laccum
 */
IFX_INLINE laccum Ifx__shaaccum(laccum a, sint32 b)
{
    laccum res;
    __asm__ volatile ("jge   %2,0,0f        \n\
                    sha   %H0,%H1,%2     \n\
                    rsub  %2,%2,0        \n\
                    dextr %L0,%H1,%L1,%2 \n\
                    j  1f                \n\
                    0:dextr %H0,%H1,%L1,%2 \n\
                    sha   %L0,%L1,%2     \n\
                    1:"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Left/right shift of an fract
 */
IFX_INLINE fract Ifx__shafracts(fract a, sint32 b)
{
    fract res;
    __asm__ volatile ("shas  %0,%1,%2":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Left/right shift of an sfract
 */
IFX_INLINE sfract Ifx__shasfracts(sfract a, sint32 b)
{
    sfract res;
    __asm__ volatile ("shas  %0,%1,%2":"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Convert uint16 to sfract
 */
IFX_INLINE sfract Ifx__u16_to_sfract(uint16 a)
{
    sfract res;
    __asm__ volatile ("sh  %0,%1,16    \n\
                       sh  %0,%1,-16":"=d"(res):"d"(a):"memory");
    return res;
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucinsert Insert / Extract Bit-fields and Bits
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Extract a bit-field (bit pos to bit pos+width) from value
 */
IFX_INLINE sint32 Ifx__extr(sint32 a, uint32 p, uint32 w)
{
    sint32 res;
    __asm__ volatile ("mov %%d14,%2  \n\
                     mov %%d15,%3  \n\
                     extr %0,%1,%%e14"
                      : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14", "d15");
    return res;
}

/** Same as __extr() but return bit-field as unsigned integer
 */
IFX_INLINE uint32 Ifx__extru(uint32 a, uint32 p, uint32 w)
{
    uint32 res;
    __asm__ volatile ("mov %%d14,%2  \n\
                     mov %%d15,%3  \n\
                     extr.u %0,%1,%%e14"
                      : "=d" (res) : "d" (a), "d" (p), "d" (w):"d14", "d15");
    return res;
}

/** Load a single bit.
 */
//#define __getbit(address,bitoffset ) __extru( *(address), bitoffset, 1 )
#define Ifx__getbit(address, bitoffset) ((*(address) & (1U << (bitoffset))) != 0)

/** Atomic load-modify-store.
 */
#define Ifx__imaskldmst(address, value, bitoffset, bits) \
  {long long tmp;\
  __asm__("imask %A0,%1,%2,%3"\
          :"=d"((long long)tmp)\
          :"d"(value),"d"(bitoffset),"i"(bits): "memory");\
  __asm__("ldmst [%0]0,%A1"::"a"(address),"d"(tmp): "memory");}

/** Return trg but replace trgbit by srcbit in src.
 */
IFX_INLINE sint32 Ifx__ins(sint32 trg, const sint32 trgbit, sint32 src, const sint32 srcbit)
{
    sint32 res;
    __asm__ volatile ("ins.t %0,%1,%2,%3,%4":"=d"(res):"d"(trg), "i"(trgbit), "d"(src), "i"(srcbit));
    return res;
}

/** Extract bit-field (width bits starting at bit 0) from src and insert it in trg at pos.
 */
IFX_INLINE sint32 Ifx__insert(sint32 a, sint32 b, sint32 p, const sint32 w)
{
    sint32 res;
    __asm__ volatile ("mov %%d14,%3  \n\
                     mov %%d15,%4  \n\
                     insert %0,%1,%2,%%e14"
                      :"=d"(res):"d"(a), "d"(b), "d"(p), "d"(w):"d14", "d15");
    return res;
}

/** Return trg but replace trgbit by inverse of srcbit in src.
 */
IFX_INLINE sint32 Ifx__insn(sint32 trg, const sint32 trgbit, sint32 src, const sint32 srcbit)
{
    sint32 res;
    __asm__ volatile ("insn.t %0,%1,%2,%3,%4":"=d"(res):"d"(trg), "i"(trgbit), "d"(src), "i"(srcbit));
    return res;
}

/** Store a single bit.
 */
#define Ifx__putbit(value,address,bitoffset ) Ifx__imaskldmst(address, value, bitoffset,1)

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucinterrupt_handling Interrupt Handling
 The next table provides an overview of the intrinsic functions to read or set interrupt handling.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

#if !IFXCPU_INTRINSICSGNUC_USE_MACHINE_INTRINSICS
/** Set CPU priority number [0..255] (or [0..1023] for TriCore 1.6.x) and enable interrupts immediately at function entry
 */
#define Ifx__bisr(intlvl) __asm__ volatile ("bisr "#intlvl : : : "memory")
#endif

/** Disable interrupts. Only supported for TriCore1
 */
#define Ifx__disable() __asm__ volatile ("disable" : : : "memory")

/** Disable interrupts and return previous interrupt state (enabled or disabled). Direct supported for TriCore1.6. Emulated on TC1.3.1
 */
IFX_INLINE sint32 Ifx__disable_and_save(void)
{
    sint32 res;
    __asm__ volatile("disable %0":"=d"(res));
    return res;
}

/** Enable interrupts immediately at function entry
 */
#define Ifx__enable() __asm__ volatile ("enable" : : : "memory")

/** Restore interrupt state. Direct supported for TriCore1.6. Emulated on TC1.3.1
 */
IFX_INLINE void Ifx__restore(sint32 ie)
{
    __asm__ volatile ("restore %0"::"d"(ie));
}

#if !IFXCPU_INTRINSICSGNUC_USE_MACHINE_INTRINSICS
/** Call a system call function number
 */
#define Ifx__syscall(svcno) __tric_syscall(svcno)
#define Ifx__tric_syscall(svcno) __asm__ volatile ("syscall "STRINGIFY(svcno) : : : "memory")
#endif

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucmiscellaneous Miscellaneous Intrinsic Functions
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/**  Write back and invalidate cache address "p". Generates CACHEA.WI [Ab].
 */
IFX_INLINE void Ifx__cacheawi(uint8* p)
{
    __asm__ volatile("cachea.wi [%0]0"::"a"(p));
}
/**  Write back and invalidate cache index "p". Generates CACHEI.WI [Ab].
 */
IFX_INLINE void Ifx__cacheiwi(uint8* p)
{
    __asm__ volatile("cachei.wi [%0]0"::"a"(p));
}

/**  Write back and invalidate cache address \"p\" and return post incremented
 * value of \"p\". Generates CACHEA.WI [Ab+].
 */
IFX_INLINE uint8* Ifx__cacheawi_bo_post_inc(uint8* p)
{
    __asm__ volatile("cachea.wi  [%0+]0"::"a"(p));
    return p;
}

/** Multiply two 32-bit numbers to an intermediate 64-bit result, and scale
 * back the result to 32 bits. To scale back the result, 32 bits are extracted
 * from the intermediate 64-bit result: bit 63-offset to bit 31-offset.
 */
IFX_INLINE sint32 Ifx__mulsc(sint32 a, sint32 b, sint32 offset)
{
    sint32 res;
    __asm__ volatile("mul  %%e12,%1,%2      \n\
                    dextr  %0,%%d13,%%d12,%3"
                     :"=d"(res):"d"(a), "d"(b), "d"(offset):"d12", "d13");
    return res;
}

/**  Rotate operand left count times. The bits that are shifted out are inserted at the right side (bit 31 is shifted to bit 0).
 */
IFX_INLINE uint32 Ifx__rol(uint32 operand, uint32 count)
{
    uint32 res;
    __asm__ volatile("dextr  %0,%1,%1,%2":"=d"(res):"d"(operand), "d"(count):"memory");
    return res;
}

/**  Rotate operand right count times. The bits that are shifted out are inserted at the left side (bit 0 is shifted to bit 31).
 */
IFX_INLINE uint32 Ifx__ror(uint32 operand, uint32 count)
{
    uint32 res;
    __asm__ volatile("rsub %2,%2,0 \n\
                    dextr  %0,%1,%1,%2"
                     :"=d"(res):"d"(operand), "d"(count):"memory");
    return res;
}
/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucpacked Packed Data Type Support
 The next table provides an overview of the intrinsic functions for initialization of packed data type.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/**  Absolute value of __packb
 */
IFX_INLINE __packb Ifx__absb(__packb a)
{
    __packb res;
    __asm__ volatile ("abs.b %0,%1"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Absolute value of __packhw
 */
IFX_INLINE __packhw Ifx__absh(__packhw a)
{
    __packhw res;
    __asm__ volatile ("abs.h %0,%1"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Absolute value of __packhw using saturation
 */
IFX_INLINE __packhw Ifx__abssh(__packhw a)
{
    __packb res;
    __asm__ volatile ("abss.h %0,%1"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first byte from a __packb
 */
IFX_INLINE sint8 Ifx__extractbyte1(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,0,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second byte from a __packb
 */
IFX_INLINE sint8 Ifx__extractbyte2(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,8,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract third byte from a __packb
 */
IFX_INLINE sint8 Ifx__extractbyte3(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,16,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Extract fourth byte from a __packb
 */
IFX_INLINE sint8 Ifx__extractbyte4(__packb a)
{
    sint8 res;
    __asm__ volatile ("extr  %0,%1,24,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first sint16 from a __packhw
 */
IFX_INLINE sint16 Ifx__extracthw1(__packhw a)
{
    sint16 res;
    __asm__ volatile ("extr  %0,%1,0,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second sint16 from a __packhw
 */
IFX_INLINE sint16 Ifx__extracthw2(__packhw a)
{
    sint16 res;
    __asm__ volatile ("extr  %0,%1,16,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__extractubyte1(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,0,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__extractubyte2(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,8,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract third uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__extractubyte3(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,16,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract fourth uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__extractubyte4(__upackb a)
{
    uint8 res;
    __asm__ volatile ("extr  %0,%1,24,8"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract first uint16 from a __packhw
 */
IFX_INLINE uint16 Ifx__extractuhw1(__upackhw a)
{
    uint16 res;
    __asm__ volatile ("extr  %0,%1,0,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/** Extract second uint16 from a __packhw
 */
IFX_INLINE uint16 Ifx__extractuhw2(__upackhw a)
{
    uint16 res;
    __asm__ volatile ("extr  %0,%1,16,16"
                      :"=d"(res):"d"(a):"memory");
    return res;
}

/**  Extract first byte from a __packb
 */
IFX_INLINE sint8 Ifx__getbyte1(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract second byte from a __packb
 */
IFX_INLINE sint8 Ifx__getbyte2(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,8,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract third byte from a __packb
 */
IFX_INLINE sint8 Ifx__getbyte3(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract fourth byte from a __packb
 */
IFX_INLINE sint8 Ifx__getbyte4(__packb* a)
{
    sint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,24,8"
                      :"=d"(res):"a"(a):"memory");
    return res;

}

/**  Extract first sint16 from a __packhw
 */
IFX_INLINE sint16 Ifx__gethw1(__packhw* a)
{
    sint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}
/**  Extract second sint16 from a __packhw
 */
IFX_INLINE sint16 Ifx__gethw2(__packhw* a)
{
    sint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract first uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__getubyte1(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract second uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__getubyte2(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,8,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract third uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__getubyte3(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract fourth uint8 from a __packb
 */
IFX_INLINE uint8 Ifx__getubyte4(__upackb* a)
{
    uint8 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,24,8"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract first uint16 from a __packhw
 */
IFX_INLINE uint16 Ifx__getuhw1(__upackhw* a)
{
    uint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,0,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Extract second uint16 from a __packhw
 */
IFX_INLINE uint16 Ifx__getuhw2(__upackhw* a)
{
    uint16 res;
    __asm__ volatile ("ld.w  %0,[%1]0 \n\
                     extr  %0,%0,16,16"
                      :"=d"(res):"a"(a):"memory");
    return res;
}

/**  Initialize  __packb with four integers
 */
IFX_INLINE __packb Ifx__initpackb(sint32 a, sint32 b, sint32 c, sint32 d)
{
    __packb res;
    __asm__ volatile ("insert  %3,%3,%4,8,8   \n\
                    insert  %4,%1,%2,8,8   \n\
                    insert  %0,%4,%3,16,16 "
                      :"=d"(res):"d"(a), "d"(b), "d"(c), "d"(d):"memory");
    return res;
}

/** Initialize  __packb with a long integer
 */
IFX_INLINE __packb Ifx__initpackbl(long a)
{
    return (__packb) a;
}

/** Initialize  __packhw with two integers
 */
IFX_INLINE __packhw Ifx__initpackhw(sint16 a, sint16 b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Initialize  __packhw with a long integer
 */
IFX_INLINE __packhw Ifx__initpackhwl(long a)
{
    return a;
}

/** Initialize  __packb with four unsigned integers
 */
IFX_INLINE __upackb    Ifx__initupackb( uint32 a, uint32 b, uint32 c, uint32 d)
{
    __upackb res;
    __asm__ volatile ("insert  %3,%3,%4,8,8   \n\
                    insert  %1,%1,%2,8,8   \n\
                    insert  %0,%1,%3,16,16"
                      :"=d"(res):"d"(a), "d"(b), "d"(c), "d"(d):"memory");
    return res;
}

/**  Initialize  __packhw with two unsigned integers
 */
IFX_INLINE __upackhw    Ifx__initupackhw( uint16 a, uint16 b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into first byte of a __packb
 */
IFX_INLINE __packb Ifx__insertbyte1(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,0,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into second byte of a __packb
 */
IFX_INLINE __packb Ifx__insertbyte2(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,8,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into third byte of a __packb
 */
IFX_INLINE __packb Ifx__insertbyte3(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,16,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into fourth byte of a __packb
 */
IFX_INLINE __packb Ifx__insertbyte4(__packb a, sint8 b)
{
    __packb res;
    __asm__ volatile ("insert  %0,%1,%2,24,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into first uint8 of a __packb
 */
IFX_INLINE __upackb    Ifx__insertubyte1( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,0,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into second uint8 of a __packb
 */
IFX_INLINE __upackb    Ifx__insertubyte2( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,8,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into third uint8 of a __packb
 */
IFX_INLINE __upackb     Ifx__insertubyte3( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,16,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert sint8 into fourth uint8 of a __packb
 */
IFX_INLINE __upackb     Ifx__insertubyte4( __upackb a, uint8 b)
{
    __upackb res;
    __asm__ volatile ("insert  %0,%1,%2,24,8"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert sint16 into first halfword of a __packhw
 */
IFX_INLINE __packhw Ifx__inserthw1(__packhw a, sint16 b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,0,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert sint16 into second halfword of a __packhw
 */
IFX_INLINE __packhw Ifx__inserthw2(__packhw a, sint16 b)
{
    __packhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert uint16 into first halfword of a __upackhw
 */
IFX_INLINE __upackhw    Ifx__insertuhw1( __upackhw a, uint16 b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,0,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/** Insert uint16 into second halfword of a __upackhw
 */
IFX_INLINE __upackhw    Ifx__insertuhw2( __upackhw a, uint16 b)
{
    __upackhw res;
    __asm__ volatile ("insert  %0,%1,%2,16,16"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two  __packb values
 */
IFX_INLINE __packb Ifx__minb(__packb a, __packb b)
{
    __packb res;
    __asm__ volatile ("min.b %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two __upackb  values
 */
IFX_INLINE __upackb     Ifx__minbu( __upackb  a, __upackb  b)
{
    __upackb res;
    __asm__ volatile ("min.bu %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two  __packhw values
 */
IFX_INLINE __packhw Ifx__minh(__packhw a, __packhw b)
{
    __packhw res;
    __asm__ volatile ("min.h %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Minimum of two __upackhw values
 */
IFX_INLINE __upackhw    Ifx__minhu( __upackhw a, __upackhw b)
{
    __upackhw res;
    __asm__ volatile ("min.hu %0,%1,%2"
                      :"=d"(res):"d"(a), "d"(b):"memory");
    return res;
}

/**  Insert sint8 into first byte of a __packb
 */
IFX_INLINE void Ifx__setbyte1(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint8 into second byte of a __packb
 */
IFX_INLINE void Ifx__setbyte2(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,8,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint8 into third byte of a __packb
 */
IFX_INLINE void Ifx__setbyte3(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint8 into fourth byte of a __packb
 */
IFX_INLINE void Ifx__setbyte4(__packb* a, sint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,24,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint16 into first halfword of a __packhw
 */
IFX_INLINE void Ifx__sethw1(__packhw* a, sint16 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert sint16 into second halfword of a __packhw
 */
IFX_INLINE void Ifx__sethw2(__packhw* a, sint16 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into first byte of a __upackb
 */
IFX_INLINE void Ifx__setubyte1(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into second byte of a __upackb
 */
IFX_INLINE void Ifx__setubyte2(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,8,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into third byte of a __upackb
 */
IFX_INLINE void Ifx__setubyte3(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint8 into fourth byte of a __upackb
 */
IFX_INLINE void Ifx__setubyte4(__upackb* a, uint8 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,24,8 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint16 into first halfword of a __upackhw
 */
IFX_INLINE void Ifx__setuhw1(__upackhw* a, uint16 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,0,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/**  Insert uint16 into second halfword of a __upackhw
 */
IFX_INLINE void Ifx__setuhw2(__upackhw* a, uint16 b)
{
    __asm__ volatile ("ld.w  %%d15,[%0] \n\
                    insert  %%d15,%%d15,%1,16,16 \n\
                    st.w [%0],%%d15"
                      ::"a"(a), "d"(b):"d15", "memory");
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucregister Register Handling
 The next table provides an overview of the intrinsic functions that you can use to access control registers.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/**  Return absolute value
 */
#define Ifx__abs(a) __builtin_abs(a)

/** Return absolue difference of two integers
 */
IFX_INLINE sint32 Ifx__absdif(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("absdif %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/**  Return absolute value with saturation
 */
IFX_INLINE sint32 Ifx__abss(sint32 a)
{
    sint32 res;
    __asm__ volatile ("abss %0, %1": "=d" (res) : "d" (a));
    return res;
}

/**  Count leading ones in int
 */
IFX_INLINE sint32 Ifx__clo(sint32 a)
{
    sint32 res;
    __asm__ volatile ("clo %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Count number of redundant sign bits (all consecutive bits with the same value as bit 31
 */
IFX_INLINE sint32 Ifx__cls(sint32 a)
{
    sint32 res;
    __asm__ volatile ("cls %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Count leading zeros in int
 */
#define  Ifx__clz(a) __builtin_clz(a)

/**  Return absolute double precision floating-point value
 */
IFX_INLINE double Ifx__fabs(double d)
{
    double res;
    __asm__ volatile ("insert  %0,%1,0,31,1": "=d" (res) : "d" (d):"memory");
    return res;
}

/**  Return absolute floating-point value
 */
IFX_INLINE float Ifx__fabsf(float f)
{
    float res;
    __asm__ volatile ("insert  %0,%1,0,31,1": "=d" (res) : "d" (f):"memory");
    return res;
}

#if !IFXCPU_INTRINSICSGNUC_USE_MACHINE_INTRINSICS
/**  Move contents of the addressed core SFR into a data register
 */
#define Ifx__mfcr(regaddr)  \
 ({ sint32 res; __asm__ volatile ("mfcr %0,%1": "=d" (res) :"i"(regaddr): "memory"); res; })

//({ sint32 res; __asm__ volatile ("mfcr %0,"#regaddr : "=d" (res) : : "memory"); res; })

/**  Move contents of a data register (second int) to the addressed core SFR (first int)
 */
#define Ifx__mtcr(regaddr,val) __asm__ volatile ("mtcr %0,%1\n\tisync"::"i"(regaddr),"d"(val):"memory")
#endif

/**  Return parity
 */
IFX_INLINE sint32 Ifx__parity(sint32 a)
{
    sint32 res;
    __asm__ volatile ("parity  %0,%1": "=d" (res) : "d" (a):"memory");
    return res;
}

/**  Return saturated byte
 */
IFX_INLINE sint8 Ifx__satb(sint32 a)
{
    sint8 res;
    __asm__ volatile ("sat.b %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated uint8
 */
IFX_INLINE uint8 Ifx__satbu(sint32 a)
{
    uint8 res;
    __asm__ volatile ("sat.bu %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated halfword
 */
IFX_INLINE sint16 Ifx__sath(sint32 a)
{
    sint8 res;
    __asm__ volatile ("sat.h %0,%1":"=d"(res):"d"(a));
    return res;
}

/**  Return saturated unsigned halfword
 */
IFX_INLINE uint16 Ifx__sathu(sint32 a)
{
    sint8 res;
    __asm__ volatile ("sat.hu %0,%1":"=d"(res):"d"(a));
    return res;
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucsaturation Saturation Arithmetic Support
 These intrinsics support saturation arithmetic
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** add signed with saturation
 */
IFX_INLINE sint32 Ifx__adds(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("adds %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** add unsigned with saturation
 */
IFX_INLINE uint32 Ifx__addsu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("adds.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** substract signed with saturation
 */
IFX_INLINE sint32 Ifx__subs(sint32 a, sint32 b)
{
    sint32 res;
    __asm__ volatile ("subs %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** substract unsigned with saturation
 */
IFX_INLINE uint32 Ifx__subsu(uint32 a, uint32 b)
{
    uint32 res;
    __asm__ volatile ("subs.u %0, %1, %2": "=d" (res) : "d" (a), "d" (b));
    return res;
}

/** \} */

/** \defgroup IfxLld_Cpu_Intrinsics_Gnucsingle_assembly Insert Single Assembly Instruction
 The next table provides an overview of the intrinsic functions that you can use to insert a single assembly
 instruction.You can also use inline assembly but these intrinsics provide a shorthand for frequently used
 assembly instructions.
 * \ingroup IfxLld_Cpu_Intrinsics_Gnuc
 * \{
 */

/** Insert DEBUG instruction
 */
IFX_INLINE void Ifx__debug(void)
{
    __asm__ volatile ("debug" : : : "memory");
}

/** Insert a memory barrier
 */
#define Ifx__mem_barrier __asm__ volatile("":::"memory");

/** Insert DSYNC instruction
 */
IFX_INLINE void Ifx__dsync(void)
{
    __asm__ volatile ("dsync" : : : "memory");
}

/** Insert ISYNC instruction
 */
IFX_INLINE void Ifx__isync(void)
{
    __asm__ volatile ("isync" : : : "memory");
}

/** Insert LDMST instruction. Note that all operands must be word-aligned.
 */
IFX_INLINE void Ifx__ldmst(volatile void* address, uint32 mask, uint32 value)
{
    __asm__ volatile("mov %H2,%1 \n\
                  ldmst [%0]0,%A2"
                     ::"a"(address), "d"(mask), "d"((long long)value));
}

/** Insert NOP instruction
 */
IFX_INLINE void Ifx__nop(void)
{
    __asm__ volatile ("nop" : : : "memory");
}

/** Insert a loop over cnt NOP instruction
 */
IFX_INLINE void Ifx__nops(void* cnt)
{
    __asm__ volatile ("0: nop \n\
        loop %0,0b"
                      ::"a"(((sint8*)cnt)-1));
}

/** Insert RSLCX instruction
 */
IFX_INLINE void Ifx__rslcx(void)
{
    __asm__ volatile ("rslcx" : : : "memory");
}

/** Insert SVLCX instruction
 */
IFX_INLINE void Ifx__svlcx(void)
{
    __asm__ volatile ("svlcx" : : : "memory");
}

/** Insert SWAP instruction. Note that all operands must be word-aligned.
 */
IFX_INLINE uint32 Ifx__swap(void* place, uint32 value)
{
    uint32 res;
    __asm__ volatile("swap.w [%1]0,%2":"=d"(res):"a"(place), "0"(value));
    return res;
}

/** Insert n NOP instruction
 */
#define Ifx__NOP(n)   __asm(".rept " #n "\n\tnop\n\t.endr\n")

/** \} */

/* FIXME use inline instead of #define */
#define Ifx__setareg(areg,val) \
    { uint32 reg_val= (uint32)val; \
        __asm__ volatile (" mov.a\t %%"#areg",%0"::"d"(reg_val)); }

/**__mtcr (CPU_CCTRL, 0);
*/
IFX_INLINE void Ifx__stopPerfCounters(void)
{
    __asm__ volatile("mov %%d0,0\n\
                  mtcr 0xFC00,%%d0\n\
                  isync\n"
            : : :"d0"); /* FIXME check that the parameter d0 is understood by the compiler as a register used by the inline */
}

/** \brief This function is a implementation of a binary semaphore using compare and swap instruction
 * \param address address of resource.
 * \param value This variable is updated with status of address
 * \param condition if the value of address matches with the value of condition, then swap of value & address occurs.
 *
 */
IFX_INLINE unsigned int Ifx__cmpAndSwap (unsigned int volatile *address,
           unsigned int value, unsigned int condition)
{
 /* Gnu C compiler with Tricore 1.6 support is required to use cmpswap instruction */
  __extension__ unsigned long long reg64
    = value | (unsigned long long) condition << 32;

  __asm__ __volatile__ ("cmpswap.w [%[addr]]0, %A[reg]"
                        : [reg] "+d" (reg64)
                        : [addr] "a" (address)
                        : "memory");
    return reg64;
}

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

    __asm__ volatile("q31tof %0, %1, %2": "=d" (result) : "d" (value), "d" (shift));
    return result;
}

IFX_INLINE void* Ifx__getA11(void)
{
    uint32 *res;
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    return res;
}

IFX_INLINE void Ifx__setStackPointer(void *stackAddr)
{
    __asm__ volatile ("mov.aa %%a10, %0": : "a" (stackAddr) :"a10");
}

IFX_INLINE uint32 Ifx__crc32(uint32 b, uint32 a)
{
    uint32 returnvalue = 0; /* set value to 0 */

    __asm__ volatile ("CRC32 %0,%1,%2" : "=d" (returnvalue) : "d"(b), "d"(a));

   return returnvalue;
}

IFX_INLINE uint32 IfxCpu_calculateCrc32(uint32 *startaddress, uint8 length) 
{
    uint32 returnvalue = 0; /* set seed value to 0 */
    for (;length > 0; length--) 
    { 
    	  /* calculate the CRC over all data */
        __asm__ ("CRC32 %0,%0,%1" : "+d" (returnvalue) : "d" (*startaddress)); 
        startaddress++; 
    } 
    return returnvalue;
}

IFX_INLINE uint32 IfxCpu_getRandomVal(uint32 a, uint32 x, uint32 m)
{
	uint32 result;
    __asm("      mul.u     %%e14,%1,%2       # d15 = Eh; d14 = El    \n"
        "        mov       %%d12,%%d14       #   e12 = El            \n"
        "        mov       %%d13, 0          #                       \n"
        "        madd.u    %%e14,%%e12,%%d15, 5 # e14 = El + 5 * d15    \n"
        " cmp_m_%=: jge.u     %%d14,%3,sub_m_%=    #                       \n"
        "        jz        %%d15,done_%=        #                       \n"
        " sub_m_%=: subx      %%d14,%%d14,%3    #  e12=e12-m            \n"
        "        subc      %%d15,%%d15,%%d13 # d13=d13-0             \n"
        "        loopu     cmp_m_%=             #                       \n"
        " done_%=:  mov       %0,%%d14          #                       \n"
        : "=d"(result) : "d"(a), "d"(x), "d"(m) : "d12","d13","d14","d15");
    return result;
}

IFX_INLINE sint32 Ifx__popcnt(sint32 a)
{ 
	sint32 res; 
	__asm__ volatile ("popcnt %0,%1":"=d"(res):"d"(a)); 
		return res; 
}

/**  Invalidate cache address "p". Generates CACHEA.I [Ab].
*/
IFX_INLINE void Ifx__cacheai(uint8* p)
{
    __asm__ volatile("cachea.i [%0]0"::"a"(p));
}

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

#ifndef __moveToDataParamRet
#define __moveToDataParamRet Ifx__moveToDataParamRet
#endif

#ifndef __getDataParamRet
#define __getDataParamRet Ifx__getDataParamRet
#endif

#ifndef __moveToAddrParam0
#define __moveToAddrParam0 Ifx__moveToAddrParam0
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

#ifndef __max
#define __max Ifx__max
#endif

#ifndef __maxs
#define __maxs Ifx__maxs
#endif

#ifndef __maxu
#define __maxu Ifx__maxu
#endif

#ifndef __min
#define __min Ifx__min
#endif

#ifndef __mins
#define __mins Ifx__mins
#endif

#ifndef __minu
#define __minu Ifx__minu
#endif

#ifndef __sqrtf
#define __sqrtf Ifx__sqrtf
#endif

#ifndef __sqrf
#define __sqrf Ifx__sqrf
#endif

#ifndef __checkrange
#define __checkrange Ifx__checkrange
#endif

#ifndef __roundf
#define __roundf Ifx__roundf
#endif

#ifndef __absf
#define __absf Ifx__absf
#endif

#ifndef __saturatef
#define __saturatef Ifx__saturatef
#endif

#ifndef __minf
#define __minf Ifx__minf
#endif

#ifndef __maxf
#define __maxf Ifx__maxf
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

#ifndef __clssf
#define __clssf Ifx__clssf
#endif

#ifndef __fract_to_float
#define __fract_to_float Ifx__fract_to_float
#endif

#ifndef __fract_to_sfract
#define __fract_to_sfract Ifx__fract_to_sfract
#endif

#ifndef __float_to_sfract
#define __float_to_sfract Ifx__float_to_sfract
#endif

#ifndef __float_to_fract
#define __float_to_fract Ifx__float_to_fract
#endif

#ifndef __getfract
#define __getfract Ifx__getfract
#endif

#ifndef __mac_r_sf
#define __mac_r_sf Ifx__mac_r_sf
#endif

#ifndef __mac_sf
#define __mac_sf Ifx__mac_sf
#endif

#ifndef __mulfractfract
#define __mulfractfract Ifx__mulfractfract
#endif

#ifndef __mulfractlong
#define __mulfractlong Ifx__mulfractlong
#endif

#ifndef __round16
#define __round16 Ifx__round16
#endif

#ifndef __s16_to_sfract
#define __s16_to_sfract Ifx__s16_to_sfract
#endif

#ifndef __sfract_to_s16
#define __sfract_to_s16 Ifx__sfract_to_s16
#endif

#ifndef __sfract_to_u16
#define __sfract_to_u16 Ifx__sfract_to_u16
#endif

#ifndef __shaaccum
#define __shaaccum Ifx__shaaccum
#endif

#ifndef __shafracts
#define __shafracts Ifx__shafracts
#endif

#ifndef __shasfracts
#define __shasfracts Ifx__shasfracts
#endif

#ifndef __u16_to_sfract
#define __u16_to_sfract Ifx__u16_to_sfract
#endif

#ifndef __extr
#define __extr Ifx__extr
#endif

#ifndef __extru
#define __extru Ifx__extru
#endif

#ifndef __getbit
#define __getbit Ifx__getbit
#endif

#ifndef __ins
#define __ins Ifx__ins
#endif

#ifndef __insert
#define __insert Ifx__insert
#endif

#ifndef __insn
#define __insn Ifx__insn
#endif

#ifndef __putbit
#define __putbit Ifx__putbit
#endif

#ifndef __imaskldmst
#define __imaskldmst Ifx__imaskldmst
#endif

#ifndef __bisr
#define __bisr Ifx__bisr
#endif

#ifndef __disable
#define __disable Ifx__disable
#endif

#ifndef __disable_and_save
#define __disable_and_save Ifx__disable_and_save
#endif

#ifndef __enable
#define __enable Ifx__enable
#endif

#ifndef __restore
#define __restore Ifx__restore
#endif

#ifndef __syscall
#define __syscall Ifx__syscall
#endif

#ifndef __tric_syscall
#define __tric_syscall Ifx__tric_syscall
#endif

#ifndef __cacheawi
#define __cacheawi Ifx__cacheawi
#endif

#ifndef __cacheiwi
#define __cacheiwi Ifx__cacheiwi
#endif

#ifndef __cacheawi_bo_post_inc
#define __cacheawi_bo_post_inc Ifx__cacheawi_bo_post_inc
#endif

#ifndef __mulsc
#define __mulsc Ifx__mulsc
#endif

#ifndef __rol
#define __rol Ifx__rol
#endif

#ifndef __ror
#define __ror Ifx__ror
#endif

#ifndef __extractbyte1
#define __extractbyte1 Ifx__extractbyte1
#endif

#ifndef __extractbyte2
#define __extractbyte2 Ifx__extractbyte2
#endif

#ifndef __extractbyte3
#define __extractbyte3 Ifx__extractbyte3
#endif

#ifndef __extractbyte4
#define __extractbyte4 Ifx__extractbyte4
#endif

#ifndef __extracthw1
#define __extracthw1 Ifx__extracthw1
#endif

#ifndef __extracthw2
#define __extracthw2 Ifx__extracthw2
#endif

#ifndef __extractubyte1
#define __extractubyte1 Ifx__extractubyte1
#endif

#ifndef __extractubyte2
#define __extractubyte2 Ifx__extractubyte2
#endif

#ifndef __extractubyte3
#define __extractubyte3 Ifx__extractubyte3
#endif

#ifndef __extractubyte4
#define __extractubyte4 Ifx__extractubyte4
#endif

#ifndef __extractuhw1
#define __extractuhw1 Ifx__extractuhw1
#endif

#ifndef __extractuhw2
#define __extractuhw2 Ifx__extractuhw2
#endif

#ifndef __getbyte1
#define __getbyte1 Ifx__getbyte1
#endif

#ifndef __getbyte2
#define __getbyte2 Ifx__getbyte2
#endif

#ifndef __getbyte3
#define __getbyte3 Ifx__getbyte3
#endif

#ifndef __getbyte4
#define __getbyte4 Ifx__getbyte4
#endif

#ifndef __gethw1
#define __gethw1 Ifx__gethw1
#endif

#ifndef __gethw2
#define __gethw2 Ifx__gethw2
#endif

#ifndef __getubyte1
#define __getubyte1 Ifx__getubyte1
#endif

#ifndef __getubyte2
#define __getubyte2 Ifx__getubyte2
#endif

#ifndef __getubyte3
#define __getubyte3 Ifx__getubyte3
#endif

#ifndef __getubyte4
#define __getubyte4 Ifx__getubyte4
#endif

#ifndef __getuhw1
#define __getuhw1 Ifx__getuhw1
#endif

#ifndef __getuhw2
#define __getuhw2 Ifx__getuhw2
#endif

#ifndef __setbyte1
#define __setbyte1 Ifx__setbyte1
#endif

#ifndef __setbyte2
#define __setbyte2 Ifx__setbyte2
#endif

#ifndef __setbyte3
#define __setbyte3 Ifx__setbyte3
#endif

#ifndef __setbyte4
#define __setbyte4 Ifx__setbyte4
#endif

#ifndef __sethw1
#define __sethw1 Ifx__sethw1
#endif

#ifndef __sethw2
#define __sethw2 Ifx__sethw2
#endif

#ifndef __setubyte1
#define __setubyte1 Ifx__setubyte1
#endif

#ifndef __setubyte2
#define __setubyte2 Ifx__setubyte2
#endif

#ifndef __setubyte3
#define __setubyte3 Ifx__setubyte3
#endif

#ifndef __setubyte4
#define __setubyte4 Ifx__setubyte4
#endif

#ifndef __setuhw1
#define __setuhw1 Ifx__setuhw1
#endif

#ifndef __setuhw2
#define __setuhw2 Ifx__setuhw2
#endif

#ifndef __minhu
#define __minhu Ifx__minhu
#endif

#ifndef __minh
#define __minh Ifx__minh
#endif

#ifndef __minbu
#define __minbu Ifx__minbu
#endif

#ifndef __minb
#define __minb Ifx__minb
#endif

#ifndef __insertuhw2
#define __insertuhw2 Ifx__insertuhw2
#endif

#ifndef __insertuhw1
#define __insertuhw1 Ifx__insertuhw1
#endif

#ifndef __inserthw2
#define __inserthw2 Ifx__inserthw2
#endif

#ifndef __inserthw1
#define __inserthw1 Ifx__inserthw1
#endif

#ifndef __insertubyte4
#define __insertubyte4 Ifx__insertubyte4
#endif

#ifndef __insertubyte3
#define __insertubyte3 Ifx__insertubyte3
#endif

#ifndef __insertubyte2
#define __insertubyte2 Ifx__insertubyte2
#endif

#ifndef __insertubyte1
#define __insertubyte1 Ifx__insertubyte1
#endif

#ifndef __insertbyte4
#define __insertbyte4 Ifx__insertbyte4
#endif

#ifndef __insertbyte3
#define __insertbyte3 Ifx__insertbyte3
#endif

#ifndef __insertbyte2
#define __insertbyte2 Ifx__insertbyte2
#endif

#ifndef __insertbyte1
#define __insertbyte1 Ifx__insertbyte1
#endif

#ifndef __initupackhw
#define __initupackhw Ifx__initupackhw
#endif

#ifndef __initupackb
#define __initupackb Ifx__initupackb
#endif

#ifndef __initpackhwl
#define __initpackhwl Ifx__initpackhwl
#endif

#ifndef __initpackhw
#define __initpackhw Ifx__initpackhw
#endif

#ifndef __initpackbl
#define __initpackbl Ifx__initpackbl
#endif

#ifndef __initpackb
#define __initpackb Ifx__initpackb
#endif

#ifndef __absb
#define __absb Ifx__absb
#endif

#ifndef __absh
#define __absh Ifx__absh
#endif

#ifndef __abssh
#define __abssh Ifx__abssh
#endif


#ifndef __abs
#define __abs Ifx__abs
#endif

#ifndef __absdif
#define __absdif Ifx__absdif
#endif

#ifndef __abss
#define __abss Ifx__abss
#endif

#ifndef __clo
#define __clo Ifx__clo
#endif

#ifndef __cls
#define __cls Ifx__cls
#endif

#ifndef __clz
#define __clz Ifx__clz
#endif

#ifndef __fabs
#define __fabs Ifx__fabs
#endif

#ifndef __fabsf
#define __fabsf Ifx__fabsf
#endif

#ifndef __mfcr
#define __mfcr Ifx__mfcr
#endif

#ifndef __mtcr
#define __mtcr Ifx__mtcr
#endif

#ifndef __parity
#define __parity Ifx__parity
#endif

#ifndef __satb
#define __satb Ifx__satb
#endif

#ifndef __satbu
#define __satbu Ifx__satbu
#endif

#ifndef __sath
#define __sath Ifx__sath
#endif

#ifndef __sathu
#define __sathu Ifx__sathu
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

#ifndef __debug
#define __debug Ifx__debug
#endif

#ifndef __mem_barrier
#define __mem_barrier Ifx__mem_barrier
#endif

#ifndef __dsync
#define __dsync Ifx__dsync
#endif

#ifndef __isync
#define __isync Ifx__isync
#endif

#ifndef __ldmst
#define __ldmst Ifx__ldmst
#endif

#ifndef __nop
#define __nop Ifx__nop
#endif

#ifndef __nops
#define __nops Ifx__nops
#endif

#ifndef __rslcx
#define __rslcx Ifx__rslcx
#endif

#ifndef __svlcx
#define __svlcx Ifx__svlcx
#endif

#ifndef __swap
#define __swap Ifx__swap
#endif

#if ((!defined(NOP)) && (!defined(IFX_CFG_DISABLE_DEFAULT_INTRINSICS)))
#define NOP Ifx__NOP
#endif

#ifndef __setareg
#define __setareg Ifx__setareg
#endif

#ifndef __stopPerfCounters
#define __stopPerfCounters Ifx__stopPerfCounters
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

#if ((!defined(__crc32)) && (!defined(IFX_CFG_DISABLE_DEFAULT_INTRINSICS)))
#define __crc32 Ifx__crc32
#endif

#ifndef __popcnt
#define __popcnt Ifx__popcnt
#endif

#ifndef __cacheai
#define __cacheai Ifx__cacheai
#endif

/******************************************************************************/
/* *INDENT-ON* */
/******************************************************************************/
#endif /* IFXCPU_INTRINSICSGNUC_H */
