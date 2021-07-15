/**
 * \file IfxMtu_cfg.c
 * \brief Mtu on-chip implementation data
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

#include "IfxMtu_cfg.h"
#include "Mtu/Std/IfxMtu.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

const IfxMtu_SramItem           IfxMtu_sramTable[IFXMTU_NUM_MBIST_TABLE_ITEMS] = {
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu0Dspr0 */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu0Dtag */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu0Pspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu0Ptag */
    {2 * 1, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu0Dlmu */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu1Dspr0 */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu1Dtag */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu1Pspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu1Ptag */
    {2 * 1, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu1Dlmu */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu2Dspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu2Dtag */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu2Pspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu2Ptag */
    {2 * 1, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu2Dlmu */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu3Dspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu3Dtag */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu3Pspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu3Ptag */
    {2 * 1, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu3Dlmu */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu4Dspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu4Dtag */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu4Pspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu4Ptag */
    {2 * 1, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu4Dlmu */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu5Dspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu5Dtag */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu5Pspr */
    {2 * 1, 19,  10, 0, 4}, /**< \brief IfxMtu_MbistSel_cpu5Ptag */
    {2 * 1, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu5Dlmu */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_lmu0 */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_lmu1 */
    {2 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_lmu2 */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu0Dspr1 */
    {2 * 4, 16,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_cpu1Dspr1 */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {1 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_dam0 */
    {1 * 2, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_dam1 */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {1 * 4, 64,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_dma */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {1 * 4, 32,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_mcds */
    {1 * 4, 256, 10, 0, 1}, /**< \brief IfxMtu_MbistSel_ememUpper0 */
    {1 * 4, 256, 10, 0, 1}, /**< \brief IfxMtu_MbistSel_ememUpper1 */
    {1 * 4, 256, 10, 0, 1}, /**< \brief IfxMtu_MbistSel_ememUpper2 */
    {1 * 8, 256, 10, 0, 1}, /**< \brief IfxMtu_MbistSel_emem */
    {1 * 4, 128, 9,  0, 1}, /**< \brief IfxMtu_MbistSel_ememXtm */
    {1 * 4, 128, 9,  0, 1}, /**< \brief IfxMtu_MbistSel_spu0Buffer */
    {1 * 4, 128, 9,  0, 1}, /**< \brief IfxMtu_MbistSel_spu1Buffer */
    {2 * 2, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_spu0Config */
    {2 * 2, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_spu1Config */
    {1 * 3, 29,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmFifo */
    {1 * 5, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmMcs0 */
    {1 * 5, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmMcs01 */
    {1 * 5, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmMcs1 */
    {1 * 5, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmMcs11 */
    {1 * 1, 24,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmDpll1a */
    {1 * 1, 24,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmDpll1b */
    {1 * 1, 24,  6,  0, 1}, /**< \brief IfxMtu_MbistSel_gtmDpll2 */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_mcan0 */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_mcan1 */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_mcan2 */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_psi5 */
    {1 * 2, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_eray0Obf */
    {1 * 2, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_eray1Obf */
    {1 * 4, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_eray0IbfTbf */
    {1 * 4, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_eray1IbfTbf */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_eray0Mbf */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_eray1Mbf */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {2 * 2, 8,   5,  0, 1}, /**< \brief IfxMtu_MbistSel_scrXram */
    {1 * 1, 8,   5,  0, 1}, /**< \brief IfxMtu_MbistSel_scrIram */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {1 * 2, 35,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_ethermacRx */
    {1 * 2, 35,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_ethermacTx */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_sdmmc */
    {1 * 1, 32,  7,  0, 1}, /**< \brief IfxMtu_MbistSel_hspdm */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {0 * 0, 0,   0,  0, 0}, /**< \brief IfxMtu_MbistSel_none */
    {1 * 2, 70,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu0Fft0 */
    {1 * 2, 70,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu1Fft0 */
    {1 * 2, 70,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu0Fft1 */
    {1 * 2, 70,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu1Fft1 */
    {1 * 2, 72,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu0Fft2 */
    {1 * 2, 72,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu1Fft2 */
    {1 * 4, 72,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu0Fft3 */
    {1 * 4, 72,  8,  0, 1}, /**< \brief IfxMtu_MbistSel_spu1Fft3 */
};

const IfxMtu_MbistConfigPattern nonDestructiveTestPattern[] = {
    {
        IFXMTU_MBIST_CONFIG_NONDISTTEST_CONFIG0,
        IFXMTU_MBIST_CONFIG_NONDISTTEST_CONFIG1
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang0[] = {
    {
        IfxMtu_MbistSel_mcan0,                                   /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x7F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
//  {
//      IfxMtu_MbistSel_ememUpper0,                              /* sshSel          */
//      0x00,                                                    /* lowAddress      */
//      0x3F,                                                    /* highAddress     */
//      5,                                                       /* uncorrectableErrorThreshold*/
//      1                                                        /* preClearEnable  */
//  }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang1[] = {
//   {
//      IfxMtu_MbistSel_ememUpper1,                              /* sshSel          */
//      0x00,                                                    /* lowAddress      */
//      0x3F,                                                    /* highAddress     */
//      5,                                                       /* uncorrectableErrorThreshold*/
//      1                                                        /* preClearEnable  */
//  },
    {
        IfxMtu_MbistSel_mcan1,                                   /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_mcan2,                                   /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_eray0Mbf,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x1F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang2[] = {
//  {
//      IfxMtu_MbistSel_ememUpper2,                              /* sshSel          */
//      0x00,                                                    /* lowAddress      */
//      0x3F,                                                    /* highAddress     */
//      5,                                                       /* uncorrectableErrorThreshold*/
//      1                                                        /* preClearEnable  */
//  },
    {
        IfxMtu_MbistSel_eray1Mbf,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x1F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang3[] = {
    {
        IfxMtu_MbistSel_emem,                                   /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang4[] = {
    {
        IfxMtu_MbistSel_cpu0Dspr,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu1Dspr,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmDpll2,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x3F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang6[] = {
    {
        IfxMtu_MbistSel_lmu0,                                   /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu0Dlmu,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x3F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmFifo,                                /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0xF,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang7[] = {
    {
        IfxMtu_MbistSel_cpu2Dspr,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x6F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmMcs0Slow,                            /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x1F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang8[] = {
    {
        IfxMtu_MbistSel_cpu3Dspr,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x6F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu4Dspr,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x6F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang9[] = {
    {
        IfxMtu_MbistSel_cpu5Dspr,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x6F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu0Config,                             /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x3F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu1Config,                             /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x3F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmMcs1Slow,                            /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x0F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};
const IfxMtu_MbistSshConfig     mbistSshConfigGang10[] = {
    {
        IfxMtu_MbistSel_cpu3Dlmu,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu4Dlmu,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu5Dlmu,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang11[] = {
    {
        IfxMtu_MbistSel_cpu1Dlmu,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu2Dlmu,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x3F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu0Pspr,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x2F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmMcs0Fast,                             /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x1F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmMcs1Fast,                             /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x0F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_psi5,                                    /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x03,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang12[] = {
    {
        IfxMtu_MbistSel_cpu1Pspr,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x2F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu2Pspr,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x2F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu3Pspr,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x2F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang13[] = {
    {
        IfxMtu_MbistSel_cpu4Pspr,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x2F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu5Pspr,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x2F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        0                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_mcds,                                    /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x0F,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },

    {
        IfxMtu_MbistSel_cpu0Ptag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang14[] = {
    {
        IfxMtu_MbistSel_spu0Buffer,                             /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x1F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu1Buffer,                             /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x1F,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmDpll1b,                              /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x5,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu1Ptag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu2Ptag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu3Ptag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x7,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu4Ptag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x07,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu5Ptag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x07,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang15[] = {
    {
        IfxMtu_MbistSel_spu0Fft0,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x07,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu1Fft0,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x07,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_dma,                                     /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x01,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        0                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_eray0IbfTbf,                             /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x01,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_eray1IbfTbf,                             /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x01,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
//  {
//      IfxMtu_MbistSel_mod7, /*PKC SCM*/                        /* sshSel          */
//      0x00,                                                    /* lowAddress      */
//      0x01,                                                    /* highAddress     */
//      5,                                                       /* uncorrectableErrorThreshold*/
//      1                                                        /* preClearEnable  */
//  },
    {
        IfxMtu_MbistSel_cpu0Dtag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu1Dtag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu2Dtag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu3Dtag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu4Dtag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_cpu5Dtag,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu0Fft1,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu1Fft1,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x03,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_gtmDpll1a,                              /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x01,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_eray0Obf,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x00,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_eray1Obf,                               /* sshSel          */
        0x00,                                                   /* lowAddress      */
        0x00,                                                   /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
//  {
//      IfxMtu_MbistSel_mod6, /*PKC TCM*/                        /* sshSel          */
//      0x00,                                                    /* lowAddress      */
//      0x01,                                                    /* highAddress     */
//      5,                                                       /* uncorrectableErrorThreshold*/
//      1                                                        /* preClearEnable  */
//  },
    {
        IfxMtu_MbistSel_spu0Fft2,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x01,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu1Fft2,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x01,                                                    /* highAddress     */
        5,                                                       /* uncorrectableErrorThreshold*/
        1                                                        /* preClearEnable  */
    }
};

const IfxMtu_MbistSshConfig     mbistSshConfigGang16[] = {
    {
        IfxMtu_MbistSel_spu0Fft3,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x00,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    },
    {
        IfxMtu_MbistSel_spu1Fft3,                                /* sshSel          */
        0x00,                                                    /* lowAddress      */
        0x00,                                                    /* highAddress     */
        5,                                                      /* uncorrectableErrorThreshold*/
        1                                                       /* preClearEnable  */
    }
};

const IfxMtu_MbistConfig        mbistGang0Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang0) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang0,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang1Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang1) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang1,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang2Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang2) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang2,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang3Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang3) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang3,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang4Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang4) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang4,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang6Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang6) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang6,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang7Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang7) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang7,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang8Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang8) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang8,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang9Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang9) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang9,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang10Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang10) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang10,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang11Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang11) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang11,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang12Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang12) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang12,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang13Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang13) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang13,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang14Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang14) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang14,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang15Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang15) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang15,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig        mbistGang16Config = {
    IFXMTU_MBIST_CONFIG_NONDISTTEST_MCONTROL,                             /* mcontrol        */
    sizeof(mbistSshConfigGang16) / sizeof(IfxMtu_MbistSshConfig),
    sizeof(nonDestructiveTestPattern) / sizeof(IfxMtu_MbistConfigPattern),
    mbistSshConfigGang16,
    nonDestructiveTestPattern
};

const IfxMtu_MbistConfig *const mbistGangConfig[] = {
    &mbistGang0Config,
    &mbistGang1Config,
    &mbistGang2Config,
//  &mbistGang3Config, // emem
    &mbistGang4Config,
    &mbistGang6Config,
    &mbistGang7Config,
    &mbistGang8Config,
    &mbistGang9Config,
    &mbistGang10Config,
    &mbistGang11Config,
    &mbistGang12Config,
    &mbistGang13Config,
    &mbistGang14Config,
    &mbistGang15Config,
    &mbistGang16Config,
    (void *)0 //End indicator
};
