/**
 * \file IfxScu_cfg.h
 * \brief SCU on-chip implementation data
 * \ingroup IfxLld_Scu
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
 * \defgroup IfxLld_Scu SCU
 * \ingroup IfxLld
 * \defgroup IfxLld_Scu_Impl Implementation
 * \ingroup IfxLld_Scu
 * \defgroup IfxLld_Scu_Std Standard Driver
 * \ingroup IfxLld_Scu
 */

#ifndef IFXSCU_CFG_H
#define IFXSCU_CFG_H
/******************************************************************************/
#include "Ifx_Cfg.h"
#include "IfxScu_bf.h"

/******************************************************************************/
/*                           Macro                                            */
/******************************************************************************/
#ifndef IFX_CFG_SCU_XTAL_FREQUENCY
#    define IFX_CFG_SCU_XTAL_FREQUENCY   20000000   /**< \brief Default External oscillator frequency */
#    warning "IFX_CFG_SCU_XTAL_FREQUENCY not specified in your IfxCfg.h file."
#    warning "Please double check the external XTAL frequency with the default setting of 20 MHz!"
#endif

#ifndef IFX_CFG_SCU_SYSCLK_FREQUENCY
#    define IFX_CFG_SCU_SYSCLK_FREQUENCY 20000000     /**< \brief Default External SysClk pin frequency */
#endif

#ifndef IFX_CFG_SCU_PLL_FREQUENCY
#    define IFX_CFG_SCU_PLL_FREQUENCY    300000000  /**< \brief Default PLL frequency */
#endif

#ifndef IFX_CFG_SCU_PLL1_FREQUENCY
#    define IFX_CFG_SCU_PLL1_FREQUENCY   320000000   /**< \brief Default PER PLL1 frequency */
#endif

#ifndef IFX_CFG_SCU_PLL2_FREQUENCY
#    define IFX_CFG_SCU_PLL2_FREQUENCY   200000000   /**< \brief Default PER PLL2 frequency */
#endif

#define IFXSCU_VCO_BASE_FREQUENCY        (100000000.0)
#define IFXSCU_EVR_OSC_FREQUENCY         (100000000.0)

/*The following frequency is the PLL free running frequency */
/* FIXME is this not redundant to IFXSCU_VCO_BASE_FREQUENCY */
#define IFXSCU_PLL_FREERUNNING_FREQUENCY (100000000.0)

/* By Default - external crystal is chosen as input */
/* This can be set to external clock input by user */
#ifndef IFX_CFG_SCU_EXT_CLOCK
#    define IFX_CFG_SCU_EXT_CLOCK 0 /**< \brief Default External Crystal input */
#endif


/* iLLD Configs from Master CFG file */
/*Utility macros for the configuration structure */
#if (IFX_CFG_SCU_XTAL_FREQUENCY == (20000000))
#define IFXSCU_CFG_XTAL_FREQ        20MHZ
#elif (IFX_CFG_SCU_XTAL_FREQUENCY == (25000000))
#define IFXSCU_CFG_XTAL_FREQ        25MHZ
#elif (IFX_CFG_SCU_XTAL_FREQUENCY == (40000000))
#define IFXSCU_CFG_XTAL_FREQ        40MHZ
#elif (IFX_CFG_SCU_XTAL_FREQUENCY == (16000000))
#define IFXSCU_CFG_XTAL_FREQ        16MHZ
#else
#error "Wrong XTAL frequency configuration! check IFX_CFG_SCU_XTAL_FREQUENCY configuration in Ifx_Cfg.h."
#error "AurixPlus Triboard supported crystal frequencies are  16MHz, 20MHz, 25MHz and 40MHz"
#endif

#if (IFX_CFG_SCU_PLL_FREQUENCY == (80000000))
#define IFXSCU_CFG_PLL_FREQ 80MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (133000000)) && (IFX_CFG_SCU_XTAL_FREQUENCY != (8000000))
#define IFXSCU_CFG_PLL_FREQ 133MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (160000000))
#define IFXSCU_CFG_PLL_FREQ 160MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (200000000))
#define IFXSCU_CFG_PLL_FREQ 200MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (240000000))
#define IFXSCU_CFG_PLL_FREQ 240MHZ
#elif (IFX_CFG_SCU_PLL_FREQUENCY == (300000000))
#define IFXSCU_CFG_PLL_FREQ 300MHZ
#else
#error "Wrong PLL frequency configuration!, check IFX_CFG_SCU_PLL_FREQUENCY configuration in Ifx_Cfg.h."
#error "Supported PLL frequencies are 80MHz, 133MHz (8MHz XTAL doesn't support), 160Mhz, 200MHz, 240Mhz, and 300MHz."
#endif
/******************************************************************************/
/*                           Per PLL Config                                   */
/******************************************************************************/

#if (IFX_CFG_SCU_PLL1_FREQUENCY == (320000000))
#define IFXSCU_CFG_PLL1_FREQ     320MHZ
#elif (IFX_CFG_SCU_PLL1_FREQUENCY == (160000000))
#define IFXSCU_CFG_PLL1_FREQ     160MHZ
#else
#error "Wrong PLL1 frequency configuration!, check IFX_CFG_SCU_PLL1_FREQUENCY configuration in Ifx_Cfg.h."
#error "Supported PLL1 frequencies are 160MHz and 320MHz."
#endif

#if (IFX_CFG_SCU_PLL2_FREQUENCY == (200000000))
#define IFXSCU_CFG_PLL2_FREQ 200MHZ
#else
#error "Wrong PLL2 frequency configuration!, check IFX_CFG_SCU_PLL2_FREQUENCY configuration in Ifx_Cfg.h."
#error "Supported PLL2 frequency is 200MHz."
#endif



/***************************************************************************************************/
/*************************MACROS To Configure SYSPLL Steps******************************************/
/* These Macros are used to Configure different profiles of frequency jump from FOsc to Target Freq*/
/* This is Important for the current jump Control during Clock Throttling                          */
/***************************************************************************************************/

#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_640MHZ_TO_TARGET_80MHZ
#define IFXSCU_CFG_PLL_STEPS_FDCO_640MHZ_TO_TARGET_80MHZ              \
    {                   /*Step 1 Config: 80MHz*/                     \
        (8 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    }
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_640MHZ_TO_TARGET_80MHZ */


#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_800MHZ_TO_TARGET_133MHZ
#define IFXSCU_CFG_PLL_STEPS_FDCO_800MHZ_TO_TARGET_133MHZ              \
    {                   /*Step 1 Config: 133.333333333333MHz*/                     \
        (6 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    }
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_800MHZ_TO_TARGET_133MHZ */


#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#define IFXSCU_CFG_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ              \
    {                   /*Step 1 Config: 120MHz*/                     \
        (6 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    },                                                                \
    {                   /*Step 2 Config: 180MHz*/                     \
        (4 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    },                                                                \
    {                   /*Step 3 Config: 240MHz*/                     \
        (3 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    }
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ */


#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#define IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ              \
    {                   /*Step 1 Config: 150MHz*/                     \
        (4 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    },                                                                \
    {                   /*Step 2 Config: 200MHz*/                     \
        (3 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    },                                                                \
    {                   /*Step 3 Config: 300MHz*/                     \
        (2 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    }
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ */


#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#define IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ              \
    {                   /*Step 1 Config: 150MHz*/                     \
        (4 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    },                                                                \
    {                   /*Step 2 Config: 200MHz*/                     \
        (3 - 1),        /*uint8 k2Step;*/                             \
        0.000100,       /*float32 waitTime;*/                         \
    }
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ */



/***************************************************************************************************/
/*********************** SYSPLL CONFIGURATIONS *****************************************************/
/***************************************************************************************************/

/*******************************16MHz Oscillator Frequency******************************************/


/************** Target = 80MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_16MHZ_80MHZ
/**** Macro for Initial Pll step, for profile with 16MHz Crystal and 80MHz target (fDCO= 640)*/
#define IFXSCU_CFG_SYS_PLL_16MHZ_80MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (40 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_16MHZ_80MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_80MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_80MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_80MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_80MHZ
/**** Macro for Pll step for profile with 16MHz Crystal and 80MHz target (fDCO= 640MHz)*/
#define IFXSCU_CFG_PLL_STEPS_16MHZ_80MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_640MHZ_TO_TARGET_80MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_80MHZ */

/************** Target = 133MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_16MHZ_133MHZ
/**** Macro for Initial Pll step, for profile with 16MHz Crystal and 133MHz target (fDCO= 800)*/
#define IFXSCU_CFG_SYS_PLL_16MHZ_133MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (50 - 1), (8 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_16MHZ_133MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_133MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_133MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_133MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_133MHZ
/**** Macro for Pll step for profile with 16MHz Crystal and 133MHz target (fDCO= 800MHz)*/
#define IFXSCU_CFG_PLL_STEPS_16MHZ_133MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_800MHZ_TO_TARGET_133MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_133MHZ */

/************** Target = 240MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_16MHZ_240MHZ
/**** Macro for Initial Pll step, for profile with 16MHz Crystal and 240MHz target (fDCO= 720)*/
#define IFXSCU_CFG_SYS_PLL_16MHZ_240MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (45 - 1), (8 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_16MHZ_240MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_240MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_240MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_240MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_240MHZ
/**** Macro for Pll step for profile with 16MHz Crystal and 240MHz target (fDCO= 720MHz)*/
#define IFXSCU_CFG_PLL_STEPS_16MHZ_240MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_240MHZ */

/************** Target = 300MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_16MHZ_300MHZ
/**** Macro for Initial Pll step, for profile with 16MHz Crystal and 300MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_16MHZ_300MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(2 - 1), (75 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_16MHZ_300MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_300MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_300MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_16MHZ_300MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_300MHZ
/**** Macro for Pll step for profile with 16MHz Crystal and 300MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_16MHZ_300MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_16MHZ_300MHZ */

/*******************************20MHz Oscillator Frequency******************************************/


/************** Target = 200MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_20MHZ_200MHZ
/**** Macro for Initial Pll step, for profile with 20MHz Crystal and 200MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_20MHZ_200MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (30 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_20MHZ_200MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_200MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_200MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_200MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_200MHZ
/**** Macro for Pll step for profile with 20MHz Crystal and 200MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_20MHZ_200MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_200MHZ */

/************** Target = 240MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_20MHZ_240MHZ
/**** Macro for Initial Pll step, for profile with 20MHz Crystal and 240MHz target (fDCO= 720)*/
#define IFXSCU_CFG_SYS_PLL_20MHZ_240MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (36 - 1), (8 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_20MHZ_240MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_240MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_240MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_240MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_240MHZ
/**** Macro for Pll step for profile with 20MHz Crystal and 240MHz target (fDCO= 720MHz)*/
#define IFXSCU_CFG_PLL_STEPS_20MHZ_240MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_240MHZ */

/************** Target = 300MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_20MHZ_300MHZ
/**** Macro for Initial Pll step, for profile with 20MHz Crystal and 300MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_20MHZ_300MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (30 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_20MHZ_300MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_300MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_300MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_20MHZ_300MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_300MHZ
/**** Macro for Pll step for profile with 20MHz Crystal and 300MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_20MHZ_300MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_20MHZ_300MHZ */

/*******************************25MHz Oscillator Frequency******************************************/


/************** Target = 200MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_25MHZ_200MHZ
/**** Macro for Initial Pll step, for profile with 25MHz Crystal and 200MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_25MHZ_200MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (24 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_25MHZ_200MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_25MHZ_200MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_25MHZ_200MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_25MHZ_200MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_25MHZ_200MHZ
/**** Macro for Pll step for profile with 25MHz Crystal and 200MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_25MHZ_200MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_25MHZ_200MHZ */

/************** Target = 300MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_25MHZ_300MHZ
/**** Macro for Initial Pll step, for profile with 25MHz Crystal and 300MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_25MHZ_300MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (24 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_25MHZ_300MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_25MHZ_300MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_25MHZ_300MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_25MHZ_300MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_25MHZ_300MHZ
/**** Macro for Pll step for profile with 25MHz Crystal and 300MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_25MHZ_300MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_25MHZ_300MHZ */

/*******************************40MHz Oscillator Frequency******************************************/


/************** Target = 200MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_40MHZ_200MHZ
/**** Macro for Initial Pll step, for profile with 40MHz Crystal and 200MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_40MHZ_200MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (15 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_40MHZ_200MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_200MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_200MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_200MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_200MHZ
/**** Macro for Pll step for profile with 40MHz Crystal and 200MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_40MHZ_200MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_200MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_200MHZ */

/************** Target = 240MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_40MHZ_240MHZ
/**** Macro for Initial Pll step, for profile with 40MHz Crystal and 240MHz target (fDCO= 720)*/
#define IFXSCU_CFG_SYS_PLL_40MHZ_240MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(2 - 1), (36 - 1), (8 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_40MHZ_240MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_240MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_240MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_240MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_240MHZ
/**** Macro for Pll step for profile with 40MHz Crystal and 240MHz target (fDCO= 720MHz)*/
#define IFXSCU_CFG_PLL_STEPS_40MHZ_240MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_720MHZ_TO_TARGET_240MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_240MHZ */

/************** Target = 300MHz *****************/

 #ifndef IFXSCU_CFG_SYS_PLL_40MHZ_300MHZ
/**** Macro for Initial Pll step, for profile with 40MHz Crystal and 300MHz target (fDCO= 600)*/
#define IFXSCU_CFG_SYS_PLL_40MHZ_300MHZ                            \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial }*/            \
    {(1 - 1), (15 - 1), (6 - 1)}
#endif /*#ifndef IFXSCU_CFG_SYS_PLL_40MHZ_300MHZ */

#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_300MHZ
#define IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_300MHZ 0.000200F
#endif /*#ifndef IFXSCU_CFG_WAIT_INITIAL_STEP_40MHZ_300MHZ */

#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_300MHZ
/**** Macro for Pll step for profile with 40MHz Crystal and 300MHz target (fDCO= 600MHz)*/
#define IFXSCU_CFG_PLL_STEPS_40MHZ_300MHZ  IFXSCU_CFG_PLL_STEPS_FDCO_600MHZ_TO_TARGET_300MHZ
#endif /*#ifndef IFXSCU_CFG_PLL_STEPS_40MHZ_300MHZ */

/***************************************************************************************************/
/*********************** PERPLL CONFIGURATIONS *****************************************************/
/***************************************************************************************************/

/*******************************16MHz Oscillator Frequency******************************************/


/************** Fpll1 = 320MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_16MHZ_320MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 16MHz Crystal and 320/200MHz target (fDCO= 640)*/
#define IFXSCU_CFG_PER_PLL_16MHZ_320MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (40 - 1), (2 - 1), (2 - 1), 0}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_16MHZ_320MHZ_200MHZ */

/************** Fpll1 = 160MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_16MHZ_160MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 16MHz Crystal and 160/200MHz target (fDCO= 640)*/
#define IFXSCU_CFG_PER_PLL_16MHZ_160MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (40 - 1), (4 - 1), (2 - 1), 0}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_16MHZ_160MHZ_200MHZ */

/*******************************20MHz Oscillator Frequency******************************************/


/************** Fpll1 = 320MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_20MHZ_320MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 320/200MHz target (fDCO= 640)*/
#define IFXSCU_CFG_PER_PLL_20MHZ_320MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (32 - 1), (2 - 1), (2 - 1), 0}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_20MHZ_320MHZ_200MHZ */

/************** Fpll1 = 160MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_20MHZ_160MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 20MHz Crystal and 160/200MHz target (fDCO= 640)*/
#define IFXSCU_CFG_PER_PLL_20MHZ_160MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (32 - 1), (4 - 1), (2 - 1), 0}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_20MHZ_160MHZ_200MHZ */

/*******************************25MHz Oscillator Frequency******************************************/


/************** Fpll1 = 160MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_25MHZ_160MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 25MHz Crystal and 160/200MHz target (fDCO= 800)*/
#define IFXSCU_CFG_PER_PLL_25MHZ_160MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (32 - 1), (5 - 1), (2 - 1), 1}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_25MHZ_160MHZ_200MHZ */

/*******************************40MHz Oscillator Frequency******************************************/


/************** Fpll1 = 320MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_40MHZ_320MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 40MHz Crystal and 320/200MHz target (fDCO= 640)*/
#define IFXSCU_CFG_PER_PLL_40MHZ_320MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (16 - 1), (2 - 1), (2 - 1), 0}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_40MHZ_320MHZ_200MHZ */

/************** Fpll1 = 160MHz, Fpll2 = 200MHz *****************/

#ifndef IFXSCU_CFG_PER_PLL_40MHZ_160MHZ_200MHZ
/** \brief Macro for Initial Pll step, for profile with 40MHz Crystal and 160/200MHz target (fDCO= 640)*/
#define IFXSCU_CFG_PER_PLL_40MHZ_160MHZ_200MHZ                           \
/*{ uint8 pDivider, uint8 nDivider, uint8 k2Initial, uint8 k3Initial, uint8 k3DividerBypass }*/\
    {(1 - 1), (16 - 1), (4 - 1), (2 - 1), 0}
#endif /*#ifndef IFXSCU_CFG_PER_PLL_40MHZ_160MHZ_200MHZ */

/***************************** Final Macro Setting for PLL ****************************************/
#define IFXSCU_CFG_PLL_STEPS_BASIC_(xtalFreq, pll0Freq)        IFXSCU_CFG_PLL_STEPS_##xtalFreq##_##pll0Freq
#define IFXSCU_CFG_PLL_STEPS_BASIC(xtalFreq, pll0Freq)         IFXSCU_CFG_PLL_STEPS_BASIC_(xtalFreq, pll0Freq)
#define IFXSCU_CFG_PLL_STEPS        IFXSCU_CFG_PLL_STEPS_BASIC(IFXSCU_CFG_XTAL_FREQ, IFXSCU_CFG_PLL_FREQ)

/****************** initial step configuration definitions ******************************/
/*macro for sys pll initial step configuration */
#define IFXSCU_CFG_SYS_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq) IFXSCU_CFG_SYS_PLL_##xtalFreq##_##pll0Freq
#define IFXSCU_CFG_SYS_PLL_INITIAL_STEP_BASIC(xtalFreq, pll0Freq)  IFXSCU_CFG_SYS_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq)
#define IFXSCU_CFG_SYS_PLL_INITIAL_STEP IFXSCU_CFG_SYS_PLL_INITIAL_STEP_BASIC(IFXSCU_CFG_XTAL_FREQ, IFXSCU_CFG_PLL_FREQ)

/*macro for per pll initial step configuration */
#define IFXSCU_CFG_PER_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll1Freq, pll2Freq) IFXSCU_CFG_PER_PLL_##xtalFreq##_##pll1Freq##_##pll2Freq
#define IFXSCU_CFG_PER_PLL_INITIAL_STEP_BASIC(xtalFreq, pll1Freq, pll2Freq)  IFXSCU_CFG_PER_PLL_INITIAL_STEP_BASIC_(xtalFreq, pll1Freq, pll2Freq)
#define IFXSCU_CFG_PER_PLL_INITIAL_STEP IFXSCU_CFG_PER_PLL_INITIAL_STEP_BASIC(IFXSCU_CFG_XTAL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/*macro for wait at initial step configuration */
#define IFXSCU_CFG_WAIT_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq) IFXSCU_CFG_WAIT_INITIAL_STEP_##xtalFreq##_##pll0Freq
#define IFXSCU_CFG_WAIT_INITIAL_STEP_BASIC(xtalFreq, pll0Freq) IFXSCU_CFG_WAIT_INITIAL_STEP_BASIC_(xtalFreq, pll0Freq)
#define IFXSCU_CFG_WAIT_INITIAL_STEP IFXSCU_CFG_WAIT_INITIAL_STEP_BASIC(IFXSCU_CFG_XTAL_FREQ, IFXSCU_CFG_PLL_FREQ)

/*macro for sys pll initial step configuration */
#define IFXSCU_CFG_PLL_INITIAL_STEP \
{\
    {\
        IFX_CFG_SCU_XTAL_FREQUENCY,\
        IfxScuCcu_PllInputClockSelection_fOsc0,\
        IFXSCU_CFG_SYS_PLL_INITIAL_STEP, \
        IFXSCU_CFG_PER_PLL_INITIAL_STEP, \
    },\
    IFXSCU_CFG_WAIT_INITIAL_STEP \
}

/***************************************************************************************************/
/*********************** DIVIDER CONFIGURATIONS ****************************************************/
/***************************************************************************************************/

/**************** DIVIDERS DEPENDING ON FSource0 (Fpll0) *******************************************/

/**************** Fsource = Fpll0 = 80MHz **********************************************************/

/************** CCUCON0 : STMDIV  (Output : fSTM)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_STMDIV_80MHZ
#define IFXSCU_CFG_STMDIV_80MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_STMDIV_80MHZ */

/************** CCUCON0 : GTMDIV  (Output : fGTM)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GTMDIV_80MHZ
#define IFXSCU_CFG_GTMDIV_80MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GTMDIV_80MHZ */

/************** CCUCON0 : SRIDIV  (Output : fSRI)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SRIDIV_80MHZ
#define IFXSCU_CFG_SRIDIV_80MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_SRIDIV_80MHZ */

/************** CCUCON0 : SPBDIV  (Output : fSPB)**************/
/* Target = 40 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SPBDIV_80MHZ
#define IFXSCU_CFG_SPBDIV_80MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_SPBDIV_80MHZ */

/************** CCUCON0 : BBBDIV  (Output : fBBB)**************/
/* Target = 40 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_BBBDIV_80MHZ
#define IFXSCU_CFG_BBBDIV_80MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_80MHZ */

/************** CCUCON0 : FSIDIV  (Output : fFSI)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSIDIV_80MHZ
#define IFXSCU_CFG_FSIDIV_80MHZ             (IFXSCU_CFG_SRIDIV_80MHZ * 1)
#endif /*#ifndef IFXSCU_CFG_FSIDIV_80MHZ */

/************** CCUCON0 : FSI2DIV  (Output : fFSI2)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSI2DIV_80MHZ
#define IFXSCU_CFG_FSI2DIV_80MHZ             (IFXSCU_CFG_SRIDIV_80MHZ * 1)
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_80MHZ */

/************** CCUCON5 : GETHDIV  (Output : fGETH)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GETHDIV_80MHZ
#define IFXSCU_CFG_GETHDIV_80MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GETHDIV_80MHZ */

/************** CCUCON5 : MCANHDIV  (Output : fMCANH)**************/
/* Target = 40 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_MCANHDIV_80MHZ
#define IFXSCU_CFG_MCANHDIV_80MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_MCANHDIV_80MHZ */

/************** CCUCON5 : ADASDIV  (Output : fADAS)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_ADASDIV_80MHZ
#define IFXSCU_CFG_ADASDIV_80MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ADASDIV_80MHZ */

/************** CCUCON6 : CPU0DIV  (Output : fCPU0)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU0DIV_80MHZ
#define IFXSCU_CFG_CPU0DIV_80MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_80MHZ */

/************** CCUCON7 : CPU1DIV  (Output : fCPU1)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU1DIV_80MHZ
#define IFXSCU_CFG_CPU1DIV_80MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_80MHZ */

/************** CCUCON8 : CPU2DIV  (Output : fCPU2)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU2DIV_80MHZ
#define IFXSCU_CFG_CPU2DIV_80MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_80MHZ */

/************** CCUCON9 : CPU3DIV  (Output : fCPU3)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU3DIV_80MHZ
#define IFXSCU_CFG_CPU3DIV_80MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU3DIV_80MHZ */

/************** CCUCON10 : CPU4DIV  (Output : fCPU4)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU4DIV_80MHZ
#define IFXSCU_CFG_CPU4DIV_80MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU4DIV_80MHZ */

/************** CCUCON11 : CPU5DIV  (Output : fCPU5)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU5DIV_80MHZ
#define IFXSCU_CFG_CPU5DIV_80MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU5DIV_80MHZ */

/**************** Fsource = Fpll0 = 133MHz **********************************************************/

/************** CCUCON0 : STMDIV  (Output : fSTM)**************/
/* Target = 66.5 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_STMDIV_133MHZ
#define IFXSCU_CFG_STMDIV_133MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_STMDIV_133MHZ */

/************** CCUCON0 : GTMDIV  (Output : fGTM)**************/
/* Target = 133 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GTMDIV_133MHZ
#define IFXSCU_CFG_GTMDIV_133MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GTMDIV_133MHZ */

/************** CCUCON0 : SRIDIV  (Output : fSRI)**************/
/* Target = 133 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SRIDIV_133MHZ
#define IFXSCU_CFG_SRIDIV_133MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_SRIDIV_133MHZ */

/************** CCUCON0 : SPBDIV  (Output : fSPB)**************/
/* Target = 66.5 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SPBDIV_133MHZ
#define IFXSCU_CFG_SPBDIV_133MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_SPBDIV_133MHZ */

/************** CCUCON0 : BBBDIV  (Output : fBBB)**************/
/* Target = 66.5 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_BBBDIV_133MHZ
#define IFXSCU_CFG_BBBDIV_133MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_133MHZ */

/************** CCUCON0 : FSIDIV  (Output : fFSI)**************/
/* Target = 66.5 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSIDIV_133MHZ
#define IFXSCU_CFG_FSIDIV_133MHZ             (IFXSCU_CFG_SRIDIV_133MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_FSIDIV_133MHZ */

/************** CCUCON0 : FSI2DIV  (Output : fFSI2)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSI2DIV_133MHZ
#define IFXSCU_CFG_FSI2DIV_133MHZ             (IFXSCU_CFG_SRIDIV_133MHZ * 1)
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_133MHZ */

/************** CCUCON5 : GETHDIV  (Output : fGETH)**************/
/* Target = 133 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GETHDIV_133MHZ
#define IFXSCU_CFG_GETHDIV_133MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GETHDIV_133MHZ */

/************** CCUCON5 : MCANHDIV  (Output : fMCANH)**************/
/* Target = 66.5 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_MCANHDIV_133MHZ
#define IFXSCU_CFG_MCANHDIV_133MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_MCANHDIV_133MHZ */

/************** CCUCON5 : ADASDIV  (Output : fADAS)**************/
/* Target = 133 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_ADASDIV_133MHZ
#define IFXSCU_CFG_ADASDIV_133MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ADASDIV_133MHZ */

/************** CCUCON6 : CPU0DIV  (Output : fCPU0)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU0DIV_133MHZ
#define IFXSCU_CFG_CPU0DIV_133MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_133MHZ */

/************** CCUCON7 : CPU1DIV  (Output : fCPU1)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU1DIV_133MHZ
#define IFXSCU_CFG_CPU1DIV_133MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_133MHZ */

/************** CCUCON8 : CPU2DIV  (Output : fCPU2)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU2DIV_133MHZ
#define IFXSCU_CFG_CPU2DIV_133MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_133MHZ */

/************** CCUCON9 : CPU3DIV  (Output : fCPU3)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU3DIV_133MHZ
#define IFXSCU_CFG_CPU3DIV_133MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU3DIV_133MHZ */

/************** CCUCON10 : CPU4DIV  (Output : fCPU4)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU4DIV_133MHZ
#define IFXSCU_CFG_CPU4DIV_133MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU4DIV_133MHZ */

/************** CCUCON11 : CPU5DIV  (Output : fCPU5)**************/
/* Target = 133 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU5DIV_133MHZ
#define IFXSCU_CFG_CPU5DIV_133MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU5DIV_133MHZ */

/**************** Fsource = Fpll0 = 200MHz **********************************************************/

/************** CCUCON0 : STMDIV  (Output : fSTM)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_STMDIV_200MHZ
#define IFXSCU_CFG_STMDIV_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_STMDIV_200MHZ */

/************** CCUCON0 : GTMDIV  (Output : fGTM)**************/
/* Target = 200 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GTMDIV_200MHZ
#define IFXSCU_CFG_GTMDIV_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GTMDIV_200MHZ */

/************** CCUCON0 : SRIDIV  (Output : fSRI)**************/
/* Target = 200 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SRIDIV_200MHZ
#define IFXSCU_CFG_SRIDIV_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_SRIDIV_200MHZ */

/************** CCUCON0 : SPBDIV  (Output : fSPB)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SPBDIV_200MHZ
#define IFXSCU_CFG_SPBDIV_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_SPBDIV_200MHZ */

/************** CCUCON0 : BBBDIV  (Output : fBBB)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_BBBDIV_200MHZ
#define IFXSCU_CFG_BBBDIV_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_200MHZ */

/************** CCUCON0 : FSIDIV  (Output : fFSI)**************/
/* Target = 100 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSIDIV_200MHZ
#define IFXSCU_CFG_FSIDIV_200MHZ             (IFXSCU_CFG_SRIDIV_200MHZ * 2)
#endif /*#ifndef IFXSCU_CFG_FSIDIV_200MHZ */

/************** CCUCON0 : FSI2DIV  (Output : fFSI2)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSI2DIV_200MHZ
#define IFXSCU_CFG_FSI2DIV_200MHZ             (IFXSCU_CFG_SRIDIV_200MHZ * 1)
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_200MHZ */

/************** CCUCON5 : GETHDIV  (Output : fGETH)**************/
/* Target = 200 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GETHDIV_200MHZ
#define IFXSCU_CFG_GETHDIV_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GETHDIV_200MHZ */

/************** CCUCON5 : MCANHDIV  (Output : fMCANH)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_MCANHDIV_200MHZ
#define IFXSCU_CFG_MCANHDIV_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_MCANHDIV_200MHZ */

/************** CCUCON5 : ADASDIV  (Output : fADAS)**************/
/* Target = 200 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_ADASDIV_200MHZ
#define IFXSCU_CFG_ADASDIV_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ADASDIV_200MHZ */

/************** CCUCON6 : CPU0DIV  (Output : fCPU0)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU0DIV_200MHZ
#define IFXSCU_CFG_CPU0DIV_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_200MHZ */

/************** CCUCON7 : CPU1DIV  (Output : fCPU1)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU1DIV_200MHZ
#define IFXSCU_CFG_CPU1DIV_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_200MHZ */

/************** CCUCON8 : CPU2DIV  (Output : fCPU2)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU2DIV_200MHZ
#define IFXSCU_CFG_CPU2DIV_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_200MHZ */

/************** CCUCON9 : CPU3DIV  (Output : fCPU3)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU3DIV_200MHZ
#define IFXSCU_CFG_CPU3DIV_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU3DIV_200MHZ */

/************** CCUCON10 : CPU4DIV  (Output : fCPU4)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU4DIV_200MHZ
#define IFXSCU_CFG_CPU4DIV_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU4DIV_200MHZ */

/************** CCUCON11 : CPU5DIV  (Output : fCPU5)**************/
/* Target = 200 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU5DIV_200MHZ
#define IFXSCU_CFG_CPU5DIV_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU5DIV_200MHZ */

/**************** Fsource = Fpll0 = 240MHz **********************************************************/

/************** CCUCON0 : STMDIV  (Output : fSTM)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_STMDIV_240MHZ
#define IFXSCU_CFG_STMDIV_240MHZ             (3)
#endif /*#ifndef IFXSCU_CFG_STMDIV_240MHZ */

/************** CCUCON0 : GTMDIV  (Output : fGTM)**************/
/* Target = 200 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GTMDIV_240MHZ
#define IFXSCU_CFG_GTMDIV_240MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GTMDIV_240MHZ */

/************** CCUCON0 : SRIDIV  (Output : fSRI)**************/
/* Target = 240 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SRIDIV_240MHZ
#define IFXSCU_CFG_SRIDIV_240MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_SRIDIV_240MHZ */

/************** CCUCON0 : SPBDIV  (Output : fSPB)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SPBDIV_240MHZ
#define IFXSCU_CFG_SPBDIV_240MHZ             (3)
#endif /*#ifndef IFXSCU_CFG_SPBDIV_240MHZ */

/************** CCUCON0 : BBBDIV  (Output : fBBB)**************/
/* Target = 120 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_BBBDIV_240MHZ
#define IFXSCU_CFG_BBBDIV_240MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_240MHZ */

/************** CCUCON0 : FSIDIV  (Output : fFSI)**************/
/* Target = 80 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSIDIV_240MHZ
#define IFXSCU_CFG_FSIDIV_240MHZ             (IFXSCU_CFG_SRIDIV_240MHZ * 3)
#endif /*#ifndef IFXSCU_CFG_FSIDIV_240MHZ */

/************** CCUCON0 : FSI2DIV  (Output : fFSI2)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSI2DIV_240MHZ
#define IFXSCU_CFG_FSI2DIV_240MHZ             (IFXSCU_CFG_SRIDIV_240MHZ * 1)
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_240MHZ */

/************** CCUCON5 : GETHDIV  (Output : fGETH)**************/
/* Target = 120 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GETHDIV_240MHZ
#define IFXSCU_CFG_GETHDIV_240MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_GETHDIV_240MHZ */

/************** CCUCON5 : MCANHDIV  (Output : fMCANH)**************/
/* Target = 80 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_MCANHDIV_240MHZ
#define IFXSCU_CFG_MCANHDIV_240MHZ             (3)
#endif /*#ifndef IFXSCU_CFG_MCANHDIV_240MHZ */

/************** CCUCON5 : ADASDIV  (Output : fADAS)**************/
/* Target = 240 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_ADASDIV_240MHZ
#define IFXSCU_CFG_ADASDIV_240MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ADASDIV_240MHZ */

/************** CCUCON6 : CPU0DIV  (Output : fCPU0)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU0DIV_240MHZ
#define IFXSCU_CFG_CPU0DIV_240MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_240MHZ */

/************** CCUCON7 : CPU1DIV  (Output : fCPU1)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU1DIV_240MHZ
#define IFXSCU_CFG_CPU1DIV_240MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_240MHZ */

/************** CCUCON8 : CPU2DIV  (Output : fCPU2)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU2DIV_240MHZ
#define IFXSCU_CFG_CPU2DIV_240MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_240MHZ */

/************** CCUCON9 : CPU3DIV  (Output : fCPU3)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU3DIV_240MHZ
#define IFXSCU_CFG_CPU3DIV_240MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU3DIV_240MHZ */

/************** CCUCON10 : CPU4DIV  (Output : fCPU4)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU4DIV_240MHZ
#define IFXSCU_CFG_CPU4DIV_240MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU4DIV_240MHZ */

/************** CCUCON11 : CPU5DIV  (Output : fCPU5)**************/
/* Target = 240 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU5DIV_240MHZ
#define IFXSCU_CFG_CPU5DIV_240MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU5DIV_240MHZ */

/**************** Fsource = Fpll0 = 300MHz **********************************************************/

/************** CCUCON0 : STMDIV  (Output : fSTM)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_STMDIV_300MHZ
#define IFXSCU_CFG_STMDIV_300MHZ             (3)
#endif /*#ifndef IFXSCU_CFG_STMDIV_300MHZ */

/************** CCUCON0 : GTMDIV  (Output : fGTM)**************/
/* Target = 200 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GTMDIV_300MHZ
#define IFXSCU_CFG_GTMDIV_300MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_GTMDIV_300MHZ */

/************** CCUCON0 : SRIDIV  (Output : fSRI)**************/
/* Target = 300 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SRIDIV_300MHZ
#define IFXSCU_CFG_SRIDIV_300MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_SRIDIV_300MHZ */

/************** CCUCON0 : SPBDIV  (Output : fSPB)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_SPBDIV_300MHZ
#define IFXSCU_CFG_SPBDIV_300MHZ             (3)
#endif /*#ifndef IFXSCU_CFG_SPBDIV_300MHZ */

/************** CCUCON0 : BBBDIV  (Output : fBBB)**************/
/* Target = 150 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_BBBDIV_300MHZ
#define IFXSCU_CFG_BBBDIV_300MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_BBBDIV_300MHZ */

/************** CCUCON0 : FSIDIV  (Output : fFSI)**************/
/* Target = 100 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSIDIV_300MHZ
#define IFXSCU_CFG_FSIDIV_300MHZ             (IFXSCU_CFG_SRIDIV_300MHZ * 3)
#endif /*#ifndef IFXSCU_CFG_FSIDIV_300MHZ */

/************** CCUCON0 : FSI2DIV  (Output : fFSI2)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_FSI2DIV_300MHZ
#define IFXSCU_CFG_FSI2DIV_300MHZ             (IFXSCU_CFG_SRIDIV_300MHZ * 1)
#endif /*#ifndef IFXSCU_CFG_FSI2DIV_300MHZ */

/************** CCUCON5 : GETHDIV  (Output : fGETH)**************/
/* Target = 150 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_GETHDIV_300MHZ
#define IFXSCU_CFG_GETHDIV_300MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_GETHDIV_300MHZ */

/************** CCUCON5 : MCANHDIV  (Output : fMCANH)**************/
/* Target = 100 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_MCANHDIV_300MHZ
#define IFXSCU_CFG_MCANHDIV_300MHZ             (3)
#endif /*#ifndef IFXSCU_CFG_MCANHDIV_300MHZ */

/************** CCUCON5 : ADASDIV  (Output : fADAS)**************/
/* Target = 300 MHz AND Source = Fsource0 */
#ifndef IFXSCU_CFG_ADASDIV_300MHZ
#define IFXSCU_CFG_ADASDIV_300MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ADASDIV_300MHZ */

/************** CCUCON6 : CPU0DIV  (Output : fCPU0)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU0DIV_300MHZ
#define IFXSCU_CFG_CPU0DIV_300MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU0DIV_300MHZ */

/************** CCUCON7 : CPU1DIV  (Output : fCPU1)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU1DIV_300MHZ
#define IFXSCU_CFG_CPU1DIV_300MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU1DIV_300MHZ */

/************** CCUCON8 : CPU2DIV  (Output : fCPU2)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU2DIV_300MHZ
#define IFXSCU_CFG_CPU2DIV_300MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU2DIV_300MHZ */

/************** CCUCON9 : CPU3DIV  (Output : fCPU3)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU3DIV_300MHZ
#define IFXSCU_CFG_CPU3DIV_300MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU3DIV_300MHZ */

/************** CCUCON10 : CPU4DIV  (Output : fCPU4)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU4DIV_300MHZ
#define IFXSCU_CFG_CPU4DIV_300MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU4DIV_300MHZ */

/************** CCUCON11 : CPU5DIV  (Output : fCPU5)**************/
/* Target = 300 MHz AND Source = Fsri */
#ifndef IFXSCU_CFG_CPU5DIV_300MHZ
#define IFXSCU_CFG_CPU5DIV_300MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_CPU5DIV_300MHZ */

/**************** DIVIDERS DEPENDING ON FSource1,2 (Fpll1_Fpll2) ***********************************/

/**************** Fpll1 = 320MHz, Fpll2 = 200MHz ***************************************************/

/************** CCUCON1 : MCANDIV  (Output : fMCAN)**************/
/* Target = 80 MHz AND Source = Fsource1 */
#ifndef IFXSCU_CFG_MCANDIV_320MHZ_200MHZ
#define IFXSCU_CFG_MCANDIV_320MHZ_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_MCANDIV_320MHZ_200MHZ */

/************** CCUCON1 : CLKSELMCAN  (Output : fMCANI)**************/
/* Target = Fmcani MHz AND Source = Fmcani/Fosc0 */
#ifndef IFXSCU_CFG_CLKSELMCAN_320MHZ_200MHZ
#define IFXSCU_CFG_CLKSELMCAN_320MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_CLKSELMCAN_320MHZ_200MHZ */

/************** CCUCON1 : PLL1DIVDIS  (Output : fsource1)**************/
/* Target = Fpll1by2 MHz AND Source = Fpll1 */
#ifndef IFXSCU_CFG_PLL1DIVDIS_320MHZ_200MHZ
#define IFXSCU_CFG_PLL1DIVDIS_320MHZ_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_PLL1DIVDIS_320MHZ_200MHZ */

/************** CCUCON1 : I2CDIV  (Output : fI2C)**************/
/* Target = 100 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_I2CDIV_320MHZ_200MHZ
#define IFXSCU_CFG_I2CDIV_320MHZ_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_I2CDIV_320MHZ_200MHZ */

/************** CCUCON1 : MSCDIV  (Output : fMSC)**************/
/* Target = 160 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_MSCDIV_320MHZ_200MHZ
#define IFXSCU_CFG_MSCDIV_320MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_MSCDIV_320MHZ_200MHZ */

/************** CCUCON1 : CLKSELMSC  (Output : fSOURCEMSC)**************/
/* Target = Fsource1 MHz AND Source = Fsource1/Fsource2 */
#ifndef IFXSCU_CFG_CLKSELMSC_320MHZ_200MHZ
#define IFXSCU_CFG_CLKSELMSC_320MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_CLKSELMSC_320MHZ_200MHZ */

/************** CCUCON1 : QSPIDIV  (Output : fQSPI)**************/
/* Target = 200 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_QSPIDIV_320MHZ_200MHZ
#define IFXSCU_CFG_QSPIDIV_320MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_QSPIDIV_320MHZ_200MHZ */

/************** CCUCON1 : CLKSELQSPI  (Output : fSOURCESPI)**************/
/* Target = Fsource2 MHz AND Source = Fsource1/Fsource2 */
#ifndef IFXSCU_CFG_CLKSELQSPI_320MHZ_200MHZ
#define IFXSCU_CFG_CLKSELQSPI_320MHZ_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_CLKSELQSPI_320MHZ_200MHZ */

/************** CCUCON2 : ASCLINFDIV  (Output : fASCLINF)**************/
/* Target = 200 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_ASCLINFDIV_320MHZ_200MHZ
#define IFXSCU_CFG_ASCLINFDIV_320MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ASCLINFDIV_320MHZ_200MHZ */

/************** CCUCON2 : ASCLINSDIV  (Output : fASCLINSI)**************/
/* Target = 80 MHz AND Source = Fsource1 */
#ifndef IFXSCU_CFG_ASCLINSDIV_320MHZ_200MHZ
#define IFXSCU_CFG_ASCLINSDIV_320MHZ_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_ASCLINSDIV_320MHZ_200MHZ */

/************** CCUCON2 : CLKSELASCLINS  (Output : fASCLINS)**************/
/* Target = Fasclinsi MHz AND Source = Fasclinsi/Fosc0 */
#ifndef IFXSCU_CFG_CLKSELASCLINS_320MHZ_200MHZ
#define IFXSCU_CFG_CLKSELASCLINS_320MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_CLKSELASCLINS_320MHZ_200MHZ */

/**************** Fpll1 = 160MHz, Fpll2 = 200MHz ***************************************************/

/************** CCUCON1 : MCANDIV  (Output : fMCAN)**************/
/* Target = 80 MHz AND Source = Fsource1 */
#ifndef IFXSCU_CFG_MCANDIV_160MHZ_200MHZ
#define IFXSCU_CFG_MCANDIV_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_MCANDIV_160MHZ_200MHZ */

/************** CCUCON1 : CLKSELMCAN  (Output : fMCANI)**************/
/* Target = Fmcani MHz AND Source = Fmcani/Fosc0 */
#ifndef IFXSCU_CFG_CLKSELMCAN_160MHZ_200MHZ
#define IFXSCU_CFG_CLKSELMCAN_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_CLKSELMCAN_160MHZ_200MHZ */

/************** CCUCON1 : PLL1DIVDIS  (Output : fsource1)**************/
/* Target = Fpll1by2 MHz AND Source = Fpll1 */
#ifndef IFXSCU_CFG_PLL1DIVDIS_160MHZ_200MHZ
#define IFXSCU_CFG_PLL1DIVDIS_160MHZ_200MHZ             (0)
#endif /*#ifndef IFXSCU_CFG_PLL1DIVDIS_160MHZ_200MHZ */

/************** CCUCON1 : I2CDIV  (Output : fI2C)**************/
/* Target = 100 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_I2CDIV_160MHZ_200MHZ
#define IFXSCU_CFG_I2CDIV_160MHZ_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_I2CDIV_160MHZ_200MHZ */

/************** CCUCON1 : MSCDIV  (Output : fMSC)**************/
/* Target = 80 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_MSCDIV_160MHZ_200MHZ
#define IFXSCU_CFG_MSCDIV_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_MSCDIV_160MHZ_200MHZ */

/************** CCUCON1 : CLKSELMSC  (Output : fSOURCEMSC)**************/
/* Target = Fsource1 MHz AND Source = Fsource1/Fsource2 */
#ifndef IFXSCU_CFG_CLKSELMSC_160MHZ_200MHZ
#define IFXSCU_CFG_CLKSELMSC_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_CLKSELMSC_160MHZ_200MHZ */

/************** CCUCON1 : QSPIDIV  (Output : fQSPI)**************/
/* Target = 200 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_QSPIDIV_160MHZ_200MHZ
#define IFXSCU_CFG_QSPIDIV_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_QSPIDIV_160MHZ_200MHZ */

/************** CCUCON1 : CLKSELQSPI  (Output : fSOURCESPI)**************/
/* Target = Fsource2 MHz AND Source = Fsource1/Fsource2 */
#ifndef IFXSCU_CFG_CLKSELQSPI_160MHZ_200MHZ
#define IFXSCU_CFG_CLKSELQSPI_160MHZ_200MHZ             (2)
#endif /*#ifndef IFXSCU_CFG_CLKSELQSPI_160MHZ_200MHZ */

/************** CCUCON2 : ASCLINFDIV  (Output : fASCLINF)**************/
/* Target = 200 MHz AND Source = Fsource2 */
#ifndef IFXSCU_CFG_ASCLINFDIV_160MHZ_200MHZ
#define IFXSCU_CFG_ASCLINFDIV_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ASCLINFDIV_160MHZ_200MHZ */

/************** CCUCON2 : ASCLINSDIV  (Output : fASCLINSI)**************/
/* Target = 80 MHz AND Source = Fsource1 */
#ifndef IFXSCU_CFG_ASCLINSDIV_160MHZ_200MHZ
#define IFXSCU_CFG_ASCLINSDIV_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_ASCLINSDIV_160MHZ_200MHZ */

/************** CCUCON2 : CLKSELASCLINS  (Output : fASCLINS)**************/
/* Target = Fasclinsi MHz AND Source = Fasclinsi/Fosc0 */
#ifndef IFXSCU_CFG_CLKSELASCLINS_160MHZ_200MHZ
#define IFXSCU_CFG_CLKSELASCLINS_160MHZ_200MHZ             (1)
#endif /*#ifndef IFXSCU_CFG_CLKSELASCLINS_160MHZ_200MHZ */

/***************************************************************************************************/
/*********************** REGISTER DEFAULT VALUES ***************************************************/
/***************************************************************************************************/

/************************** CCUCON0 **************************/
#define IFXSCU_CFG_CCUCON0_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON0_STMDIV_MSK << IFX_SCU_CCUCON0_STMDIV_OFF) | \
        (IFX_SCU_CCUCON0_GTMDIV_MSK << IFX_SCU_CCUCON0_GTMDIV_OFF) | \
        (IFX_SCU_CCUCON0_SRIDIV_MSK << IFX_SCU_CCUCON0_SRIDIV_OFF) | \
        (IFX_SCU_CCUCON0_SPBDIV_MSK << IFX_SCU_CCUCON0_SPBDIV_OFF) | \
        (IFX_SCU_CCUCON0_BBBDIV_MSK << IFX_SCU_CCUCON0_BBBDIV_OFF) | \
        (IFX_SCU_CCUCON0_FSIDIV_MSK << IFX_SCU_CCUCON0_FSIDIV_OFF) | \
        (IFX_SCU_CCUCON0_FSI2DIV_MSK << IFX_SCU_CCUCON0_FSI2DIV_OFF))

#define IFXSCU_CFG_CCUCON0_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_STMDIV_##pll0Freq << IFX_SCU_CCUCON0_STMDIV_OFF) | \
        (IFXSCU_CFG_GTMDIV_##pll0Freq << IFX_SCU_CCUCON0_GTMDIV_OFF) | \
        (IFXSCU_CFG_SRIDIV_##pll0Freq << IFX_SCU_CCUCON0_SRIDIV_OFF) | \
        (IFXSCU_CFG_SPBDIV_##pll0Freq << IFX_SCU_CCUCON0_SPBDIV_OFF) | \
        (IFXSCU_CFG_BBBDIV_##pll0Freq << IFX_SCU_CCUCON0_BBBDIV_OFF) | \
        (IFXSCU_CFG_FSIDIV_##pll0Freq << IFX_SCU_CCUCON0_FSIDIV_OFF) | \
        (IFXSCU_CFG_FSI2DIV_##pll0Freq << IFX_SCU_CCUCON0_FSI2DIV_OFF))

#define IFXSCU_CFG_CCUCON0_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON0_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON0 IFXSCU_CFG_CCUCON0_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON1 **************************/
#define IFXSCU_CFG_CCUCON1_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON1_MCANDIV_MSK << IFX_SCU_CCUCON1_MCANDIV_OFF) | \
        (IFX_SCU_CCUCON1_CLKSELMCAN_MSK << IFX_SCU_CCUCON1_CLKSELMCAN_OFF) | \
        (IFX_SCU_CCUCON1_PLL1DIVDIS_MSK << IFX_SCU_CCUCON1_PLL1DIVDIS_OFF) | \
        (IFX_SCU_CCUCON1_I2CDIV_MSK << IFX_SCU_CCUCON1_I2CDIV_OFF) | \
        (IFX_SCU_CCUCON1_MSCDIV_MSK << IFX_SCU_CCUCON1_MSCDIV_OFF) | \
        (IFX_SCU_CCUCON1_CLKSELMSC_MSK << IFX_SCU_CCUCON1_CLKSELMSC_OFF) | \
        (IFX_SCU_CCUCON1_QSPIDIV_MSK << IFX_SCU_CCUCON1_QSPIDIV_OFF) | \
        (IFX_SCU_CCUCON1_CLKSELQSPI_MSK << IFX_SCU_CCUCON1_CLKSELQSPI_OFF))

#define IFXSCU_CFG_CCUCON1_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_MCANDIV_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_MCANDIV_OFF) | \
        (IFXSCU_CFG_CLKSELMCAN_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_CLKSELMCAN_OFF) | \
        (IFXSCU_CFG_PLL1DIVDIS_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_PLL1DIVDIS_OFF) | \
        (IFXSCU_CFG_I2CDIV_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_I2CDIV_OFF) | \
        (IFXSCU_CFG_MSCDIV_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_MSCDIV_OFF) | \
        (IFXSCU_CFG_CLKSELMSC_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_CLKSELMSC_OFF) | \
        (IFXSCU_CFG_QSPIDIV_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_QSPIDIV_OFF) | \
        (IFXSCU_CFG_CLKSELQSPI_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON1_CLKSELQSPI_OFF))

#define IFXSCU_CFG_CCUCON1_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON1_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON1 IFXSCU_CFG_CCUCON1_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON2 **************************/
#define IFXSCU_CFG_CCUCON2_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON2_ASCLINFDIV_MSK << IFX_SCU_CCUCON2_ASCLINFDIV_OFF) | \
        (IFX_SCU_CCUCON2_ASCLINSDIV_MSK << IFX_SCU_CCUCON2_ASCLINSDIV_OFF) | \
        (IFX_SCU_CCUCON2_CLKSELASCLINS_MSK << IFX_SCU_CCUCON2_CLKSELASCLINS_OFF))

#define IFXSCU_CFG_CCUCON2_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_ASCLINFDIV_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON2_ASCLINFDIV_OFF) | \
        (IFXSCU_CFG_ASCLINSDIV_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON2_ASCLINSDIV_OFF) | \
        (IFXSCU_CFG_CLKSELASCLINS_##pll1Freq##_##pll2Freq << IFX_SCU_CCUCON2_CLKSELASCLINS_OFF))

#define IFXSCU_CFG_CCUCON2_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON2_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON2 IFXSCU_CFG_CCUCON2_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON5 **************************/
#define IFXSCU_CFG_CCUCON5_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON5_GETHDIV_MSK << IFX_SCU_CCUCON5_GETHDIV_OFF) | \
        (IFX_SCU_CCUCON5_MCANHDIV_MSK << IFX_SCU_CCUCON5_MCANHDIV_OFF) | \
        (IFX_SCU_CCUCON5_ADASDIV_MSK << IFX_SCU_CCUCON5_ADASDIV_OFF))

#define IFXSCU_CFG_CCUCON5_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_GETHDIV_##pll0Freq << IFX_SCU_CCUCON5_GETHDIV_OFF) | \
        (IFXSCU_CFG_MCANHDIV_##pll0Freq << IFX_SCU_CCUCON5_MCANHDIV_OFF) | \
        (IFXSCU_CFG_ADASDIV_##pll0Freq << IFX_SCU_CCUCON5_ADASDIV_OFF))

#define IFXSCU_CFG_CCUCON5_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON5_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON5 IFXSCU_CFG_CCUCON5_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON6 **************************/
#define IFXSCU_CFG_CCUCON6_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON6_CPU0DIV_MSK << IFX_SCU_CCUCON6_CPU0DIV_OFF))

#define IFXSCU_CFG_CCUCON6_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_CPU0DIV_##pll0Freq << IFX_SCU_CCUCON6_CPU0DIV_OFF))

#define IFXSCU_CFG_CCUCON6_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON6_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON6 IFXSCU_CFG_CCUCON6_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON7 **************************/
#define IFXSCU_CFG_CCUCON7_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON7_CPU1DIV_MSK << IFX_SCU_CCUCON7_CPU1DIV_OFF))

#define IFXSCU_CFG_CCUCON7_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_CPU1DIV_##pll0Freq << IFX_SCU_CCUCON7_CPU1DIV_OFF))

#define IFXSCU_CFG_CCUCON7_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON7_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON7 IFXSCU_CFG_CCUCON7_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON8 **************************/
#define IFXSCU_CFG_CCUCON8_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON8_CPU2DIV_MSK << IFX_SCU_CCUCON8_CPU2DIV_OFF))

#define IFXSCU_CFG_CCUCON8_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_CPU2DIV_##pll0Freq << IFX_SCU_CCUCON8_CPU2DIV_OFF))

#define IFXSCU_CFG_CCUCON8_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON8_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON8 IFXSCU_CFG_CCUCON8_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON9 **************************/
#define IFXSCU_CFG_CCUCON9_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON9_CPU3DIV_MSK << IFX_SCU_CCUCON9_CPU3DIV_OFF))

#define IFXSCU_CFG_CCUCON9_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_CPU3DIV_##pll0Freq << IFX_SCU_CCUCON9_CPU3DIV_OFF))

#define IFXSCU_CFG_CCUCON9_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON9_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON9 IFXSCU_CFG_CCUCON9_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON10 **************************/
#define IFXSCU_CFG_CCUCON10_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON10_CPU4DIV_MSK << IFX_SCU_CCUCON10_CPU4DIV_OFF))

#define IFXSCU_CFG_CCUCON10_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_CPU4DIV_##pll0Freq << IFX_SCU_CCUCON10_CPU4DIV_OFF))

#define IFXSCU_CFG_CCUCON10_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON10_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON10 IFXSCU_CFG_CCUCON10_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/************************** CCUCON11 **************************/
#define IFXSCU_CFG_CCUCON11_MASK \
    (uint32)( \
        (IFX_SCU_CCUCON11_CPU5DIV_MSK << IFX_SCU_CCUCON11_CPU5DIV_OFF))

#define IFXSCU_CFG_CCUCON11_BASIC_(pll0Freq, pll1Freq, pll2Freq) \
    (uint32)( \
        (IFXSCU_CFG_CPU5DIV_##pll0Freq << IFX_SCU_CCUCON11_CPU5DIV_OFF))

#define IFXSCU_CFG_CCUCON11_BASIC(pll0Freq, pll1Freq, pll2Freq) IFXSCU_CFG_CCUCON11_BASIC_(pll0Freq, pll1Freq, pll2Freq)

#define IFXSCU_CFG_CCUCON11 IFXSCU_CFG_CCUCON11_BASIC(IFXSCU_CFG_PLL_FREQ, IFXSCU_CFG_PLL1_FREQ, IFXSCU_CFG_PLL2_FREQ)

/**************** Final Clock Distribution ******************/

#define IFXSCU_CFG_CLK_DISTRIBUTION                                                              \
    {                                                                                            \
/*      {   uint32 value,            uint32 mask                    }*/                          \
        {IFXSCU_CFG_CCUCON0, IFXSCU_CFG_CCUCON0_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON0;*/  \
        {IFXSCU_CFG_CCUCON1, IFXSCU_CFG_CCUCON1_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON1;*/  \
        {IFXSCU_CFG_CCUCON2, IFXSCU_CFG_CCUCON2_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON2;*/  \
        {IFXSCU_CFG_CCUCON5, IFXSCU_CFG_CCUCON5_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON5;*/  \
        {IFXSCU_CFG_CCUCON6, IFXSCU_CFG_CCUCON6_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON6;*/  \
        {IFXSCU_CFG_CCUCON7, IFXSCU_CFG_CCUCON7_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON7;*/  \
        {IFXSCU_CFG_CCUCON8, IFXSCU_CFG_CCUCON8_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON8;*/  \
        {IFXSCU_CFG_CCUCON9, IFXSCU_CFG_CCUCON9_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON9;*/  \
        {IFXSCU_CFG_CCUCON10, IFXSCU_CFG_CCUCON10_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON10;*/  \
        {IFXSCU_CFG_CCUCON11, IFXSCU_CFG_CCUCON11_MASK},   /*IfxScuCcu_CcuconRegConfig CCUCON11;*/  \
    }

/** \brief Macros to configure FLASH.FCON registers */
#define IFXSCU_CFG_FLASH_WAITSTATE_MSK 0

#define IFXSCU_CFG_FLASH_WAITSTATE_VAL_BASIC_(pll0Freq) 0

#define IFXSCU_CFG_FLASH_WAITSTATE_VAL_BASIC(pll0Freq)  IFXSCU_CFG_FLASH_WAITSTATE_VAL_BASIC_(pll0Freq)

#define IFXSCU_CFG_FLASH_WAITSTATE_VAL IFXSCU_CFG_FLASH_WAITSTATE_VAL_BASIC(IFXSCU_CFG_PLL_FREQ)


#define IFXSCU_CFG_FLASH_WAITSTATE       \
/*  {   uint32 value,           uint32 mask                 }*/\
    {IFXSCU_CFG_FLASH_WAITSTATE_VAL, IFXSCU_CFG_FLASH_WAITSTATE_MSK}
/******************************************************************************/
/*---------------------------LBIST Config Macros------------------------------*/
/******************************************************************************/
#ifndef IFXSCULBIST_CFG_SIGNATURE_A
#ifndef IFX_CFG_LBIST_BODY_ENABLED
#define IFXSCULBIST_CFG_SIGNATURE_A         (0x01432DEBU)
#else
#define IFXSCULBIST_CFG_SIGNATURE_A         (0xF8097B38U)
#endif
#endif

#ifndef IFXSCULBIST_CFG_SIGNATURE_B
#ifndef IFX_CFG_LBIST_BODY_ENABLED
#define IFXSCULBIST_CFG_SIGNATURE_B         (0x80835418U)
#else
#define IFXSCULBIST_CFG_SIGNATURE_B         (0xDD5B50C5U)
#endif
#endif

#ifndef IFXSCULBIST_CFG_PATTERN_A
#define IFXSCULBIST_CFG_PATTERN_A           (0x80U)
#endif

#ifndef IFXSCULBIST_CFG_PATTERN_B
#define IFXSCULBIST_CFG_PATTERN_B           (0x500U)
#endif

#ifndef IFXSCULBIST_CFG_SCANCHAINLENGTH
#define IFXSCULBIST_CFG_SCANCHAINLENGTH     (0x86U)
#endif

#ifndef IFXSCULBIST_CFG_SEED
#define IFXSCULBIST_CFG_SEED                (0x07U)
#endif

/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/
/** Clock selection  */
typedef enum
{
    IfxScu_CCUCON0_CLKSEL_fBack = 0,
    IfxScu_CCUCON0_CLKSEL_fPll  = 1
} IfxScu_CCUCON0_CLKSEL;

/** Input frequency request control */
typedef enum
{
    IfxScu_WDTCON1_IR_divBy16384 = 0,
    IfxScu_WDTCON1_IR_divBy256   = 1,
    IfxScu_WDTCON1_IR_divBy64    = 2
} IfxScu_WDTCON1_IR;

typedef enum
{
    IfxScu_PMCSR_REQSLP_Run   = 0U, /* 00 Request CPU Run Mode */
    IfxScu_PMCSR_REQSLP_Idle  = 1U, /* 01 Request CPU Idle Mode */
    IfxScu_PMCSR_REQSLP_Sleep = 2U, /* 10 Request CPU System Sleep Mode */
    IfxScu_PMCSR_REQSLP_Stby  = 3U  /* 11 Request System Standby Mode */
} IfxScu_PMCSR_REQSLP;

/******************************************************************************/

#endif /* IFXSCU_CFG_H */
