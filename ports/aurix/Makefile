include ../../py/mkenv.mk

CROSS = 1

MICROPY_VFS_FAT = 1
# qstr definitions (must come before including py.mk)
QSTR_DEFS = qstrdefsport.h pins_qstr.h

# MicroPython feature configurations
MICROPY_ROM_TEXT_COMPRESSION ?= 1

# include py core make definitions
include $(TOP)/py/py.mk

TRICORE_TOOL  ?= C:\HIGHTEC\toolchains\tricore\v4.9.4.1

ifeq ($(CROSS), 1)
CROSS_COMPILE ?= $(TRICORE_TOOL)\bin\tricore-
endif

INC += -I.
INC += -I$(TOP)
INC += -I$(BUILD)

#Include the directories of the tc397 source code
INC += -I./tc397_bstep/0_Src/AppSw/CpuGeneric/Config
INC += -I./tc397_bstep/0_Src/AppSw/Tricore/CAN
INC += -I./tc397_bstep/0_Src/AppSw/Tricore/Cfg_Ssw
INC += -I./tc397_bstep/0_Src/AppSw/Tricore/Main
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/Bsp
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/StdIf
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/_Utilities
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap
INC += -I./tc397_bstep/0_Src/BaseSw/Infra/Platform/Tricore/Compilers
INC += -I./tc397_bstep/0_Src/BaseSw/Infra/Sfr/TC39B/_Reg
INC += -I./tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Bsp
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Comm
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Time
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Asc
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Lin
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Spi
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Can/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Cpu/Irq
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Cpu/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Cpu/Trap
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Dma/Dma
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Dma/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Trig
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Mtu/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Pms/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Port/Io
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Port/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Scu/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Src/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Stm/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Flash/Std
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Lib/DataHandling
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Lib/InternalMux
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Atom/Pwm
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Atom/PwmHl
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Atom/Timer
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tim/In
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tim/Timer
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tom/Pwm
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tom/PwmHl
INC += -I./tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tom/Timer
INC += -I./tc397_bstep/0_Src/BaseSw/Infra/Sfr/TC39B
INC += -I./tc397_bstep/0_Src/BaseSw/Infra/Platform/Tricore
INC += -I./tc397_bstep/0_Src/BaseSw/Infra/Platform
INC += -I./tc397_bstep/0_Src/BaseSw/Service/CpuGeneric
INC += -I$(TRICORE_TOOL)/tricore/include

CPP = gcc -E
CFLAGS_GNU  = $(INC) -fno-common -Os -g3 -W -Wall -Wextra -Wdiv-by-zero -std=c99 -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -DTRIBOARD_TC39XB -DUSE_IRQ $(CFLAGS_MOD) -fshort-double -mcpu=tc39xx -mversion-info -MMD -MP
LDFILE_GNU  = tc397_bstep\1_ToolEnv\0_Build\1_Config\Config_Tricore_Gnuc\Lcf_Gnuc_Tricore_Tc.lsl
LDFLAGS_GNU = -T$(LDFILE_GNU) -Wl,@"iROM.objectlist" -Wl,--gc-sections -mcpu=tc39xx -Wl,--mem-holes -Wl,--no-warn-flags -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,-n -Wl,--extmap="a"

ifeq ($(CROSS), 1)
DFU = $(TOP)/tools/dfu.py
PYDFU = $(TOP)/tools/pydfu.py
CFLAGS_CORTEX_M4 = -mthumb -mtune=cortex-m4 -mcpu=cortex-m4 -msoft-float -fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion
#CFLAGS = $(INC) -Wall -Werror -std=c99 -nostdlib $(CFLAGS_CORTEX_M4) $(COPT)
CFLAGS = $(INC) -Wall -Werror -Wdouble-promotion -D__HIGHTEC__  $(CFLAGS_MOD) -Wfloat-conversion -std=c99 $(COPT)
#LDFLAGS = -nostdlib -T stm32f405.ld -Map=$@.map --cref --gc-sections
LDFLAGS = -Wl,-Map=$@.map,--cref -Wl,--gc-sections
else
LD = gcc
CFLAGS = $(INC) -Wall -Werror -Wdouble-promotion -Wfloat-conversion -std=c99 $(COPT)
LDFLAGS = -Wl,-Map=$@.map,--cref -Wl,--gc-sections
endif

CSUPEROPT = -Os # save some code space

# Tune for Debugging or Optimization
ifeq ($(DEBUG), 1)
CFLAGS += -O0 -ggdb
else
CFLAGS += -Os -DNDEBUG
CFLAGS += -fdata-sections -ffunction-sections
endif

LIBS =

SRC_C = \
	main.c \
	uart_core.c \
	led.c \
	modpyb.c \
	pin.c \
	systick.c \
	help.c \
	modmachine.c \
	rng.c \
	pins_TC397.c \
	pin_defs_aurix.c \
	pin_named_pins.c \
	adc.c \
	pyb_can.c \
    can.c \
	bufhelper.c \
	mphalport.c \
	moduos.c \
	storage.c \
	flashbdev.c \
	boardctrl.c \
	flash.c \
	factoryreset.c \
	irq.c \
	$(SRC_MOD) \
	lib/utils/printf.c \
	lib/utils/stdout_helpers.c \
	lib/utils/pyexec.c \
	lib/mp-readline/readline.c \
	$(BUILD)/_frozen_mpy.c \

ifeq ($(CROSS), 1)
SRC_C += lib/libc/string0.c
endif

#Add from self
SRC_C += lib/timeutils/timeutils.c

SRC_C += \
      tc397_bstep/0_Src/AppSw/CpuGeneric/Config/Ifx_InterfaceConst.c \
	  tc397_bstep/0_Src/AppSw/Tricore/CAN/Can.c \
	  tc397_bstep/0_Src/AppSw/Tricore/CAN/Can.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/CAN/Can_Cb.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/CAN/Can_Cfg.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/CAN/Can_Io.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Cfg_Ssw/Ifx_Cfg_Ssw.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Cfg_Ssw/Ifx_Cfg_SswBmhd.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/AsclinShellInterface.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/Cpu0_Main.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/Cpu1_Main.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/Cpu2_Main.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/Cpu3_Main.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/Cpu4_Main.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/Cpu5_Main.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/GtmTomPwmHlDemo.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/GtmTomTimerDemo.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/TimPwmDemo.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/FlashDemo.c  \
	  tc397_bstep/0_Src/AppSw/Tricore/Main/EvadcQueueTransferDemo.c \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/Bsp/Assert.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_DPipe.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_PwmHl.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/StdIf/IfxStdIf_Timer.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxAsclin_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxCan_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxCpu_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxGtm_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxMtu_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxPort_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxStm_cfg.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxAsclin_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxCan_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxDmu_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxGtm_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxPms_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxPort_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxScu_PinMap.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerDcc.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGhs.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerGnuc.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Platform/Tricore/Compilers/CompilerTasking.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Infra.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc0.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc1.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc2.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc3.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc4.c  \
	  tc397_bstep/0_Src/BaseSw/Infra/Ssw/TC39B/Tricore/Ifx_Ssw_Tc5.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Bsp/Bsp.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Comm/Ifx_Console.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Comm/Ifx_Shell.c  \
	  tc397_bstep/0_Src/BaseSw/Service/CpuGeneric/SysSe/Time/Ifx_DateTime.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Asc/IfxAsclin_Asc.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Lin/IfxAsclin_Lin.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Spi/IfxAsclin_Spi.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Asclin/Std/IfxAsclin.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Can/Std/IfxCan.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Cpu/Irq/IfxCpu_Irq.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Cpu/Std/IfxCpu.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Cpu/Trap/IfxCpu_Trap.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Dma/Dma/IfxDma_Dma.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Dma/Std/IfxDma.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Atom.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Cmu.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Dpll.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Dtm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Psm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Spe.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Tbu.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Tim.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Std/IfxGtm_Tom.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Trig/IfxGtm_Trig.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Mtu/Std/IfxMtu.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Pms/Std/IfxPmsEvr.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Pms/Std/IfxPmsPm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Port/Io/IfxPort_Io.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Port/Std/IfxPort.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Scu/Std/IfxScuCcu.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Scu/Std/IfxScuEru.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Scu/Std/IfxScuLbist.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Scu/Std/IfxScuRcu.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Scu/Std/IfxScuWdt.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Src/Std/IfxSrc.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Stm/Std/IfxStm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Lib/DataHandling/Ifx_Fifo.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Lib/InternalMux/Ifx_InternalMux.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Atom/Pwm/IfxGtm_Atom_Pwm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Atom/PwmHl/IfxGtm_Atom_PwmHl.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Atom/Timer/IfxGtm_Atom_Timer.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tim/In/IfxGtm_Tim_In.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tim/Timer/IfxGtm_Tim_Timer.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tom/Pwm/IfxGtm_Tom_Pwm.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tom/PwmHl/IfxGtm_Tom_PwmHl.c  \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.c \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Evadc/Adc/IfxEvadc_Adc.c \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Evadc/Std/IfxEvadc.c \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxEvadc_cfg.c \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_PinMap/IfxEvadc_PinMap.c \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/Flash/Std/IfxFlash.c \
	  tc397_bstep/0_Src/BaseSw/iLLD/TC39B/Tricore/_Impl/IfxFlash_cfg.c \


#OBJ = $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o))
OBJ = $(PY_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o))
#all2:
#	$(ECHO) $(OBJ)

#all3: $(BUILD)/firmware.elf

ifeq ($(CROSS), 1)
all: $(BUILD)/firmware.dfu
else
all: $(BUILD)/firmware.elf
endif

$(BUILD)/_frozen_mpy.c: frozentest.mpy $(BUILD)/genhdr/qstrdefs.generated.h
	$(ECHO) "MISC freezing bytecode"
	$(Q) $(subst /,\,$(TOP)/tools/mpy-tool.py) -f -q $(BUILD)/genhdr/qstrdefs.preprocessed.h -mlongint-impl=none $< > $@

#$(BUILD)/firmware.elf: $(OBJ)
$(BUILD)/firmware.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(CC) -o $@ $(LDFLAGS_GNU) $(LIBS)
	$(Q)$(SIZE) $@

$(BUILD)/firmware.bin: $(BUILD)/firmware.elf
	$(Q)$(OBJCOPY) -O binary -j .isr_vector -j .text -j .data $^ $(BUILD)/firmware.bin

$(BUILD)/firmware.dfu: $(BUILD)/firmware.bin
	$(ECHO) "Create $@"
	$(Q)$(PYTHON) $(DFU) -b 0x08000000:$(BUILD)/firmware.bin $@

deploy: $(BUILD)/firmware.dfu
	$(ECHO) "Writing $< to the board"
	$(Q)$(PYTHON) $(PYDFU) -u $<

# Run emulation build on a POSIX system with suitable terminal settings
run:
	stty raw opost -echo
	build/firmware.elf
	@echo Resetting terminal...
# This sleep is useful to spot segfaults
	sleep 1
	reset

test: $(BUILD)/firmware.elf
	$(Q)/bin/echo -e "print('hello world!', list(x+1 for x in range(10)), end='eol\\\\n')\\r\\n\\x04" | $(BUILD)/firmware.elf | tail -n2 | grep "^hello world! \\[1, 2, 3, 4, 5, 6, 7, 8, 9, 10\\]eol"

include $(TOP)/py/mkrules.mk
