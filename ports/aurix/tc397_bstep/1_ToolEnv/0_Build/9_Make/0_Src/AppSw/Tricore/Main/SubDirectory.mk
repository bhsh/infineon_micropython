# -----------------------------------------------------------------------------
#
# Copyright (C) 2015-2019 Infineon Technologies AG. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# - Redistributions of source code must retain the above copyright notice,
#   this list of conditions and the following disclaimer.
# - Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation.
#   and/or other materials provided with the distribution.
# - Neither the name of the copyright holders nor the names of its
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
# ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# To improve the quality of the software, users are encouraged to share
# modifications, enhancements or bug fixes with Infineon Technologies AG
# (support@infineon.com).
# 
# -----------------------------------------------------------------------------
# Subdirectory make file for 0_Src/AppSw/Tricore/Main
# !! Generated make file, modifications could be overwritten !!
#------------------------------------------------------------------------------


# Make-Rules:
# Make-rules for architecture: Tricore

#Make-rule to build file: AsclinShellInterface.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/AsclinShellInterface.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/AsclinShellInterface.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/AsclinShellInterface.o: 0_Src/AppSw/Tricore/Main/AsclinShellInterface.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file AsclinShellInterface.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: Cpu0_Main.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu0_Main.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu0_Main.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu0_Main.o: 0_Src/AppSw/Tricore/Main/Cpu0_Main.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file Cpu0_Main.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: Cpu1_Main.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu1_Main.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu1_Main.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu1_Main.o: 0_Src/AppSw/Tricore/Main/Cpu1_Main.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file Cpu1_Main.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: Cpu2_Main.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu2_Main.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu2_Main.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu2_Main.o: 0_Src/AppSw/Tricore/Main/Cpu2_Main.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file Cpu2_Main.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: Cpu3_Main.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu3_Main.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu3_Main.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu3_Main.o: 0_Src/AppSw/Tricore/Main/Cpu3_Main.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file Cpu3_Main.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: Cpu4_Main.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu4_Main.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu4_Main.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu4_Main.o: 0_Src/AppSw/Tricore/Main/Cpu4_Main.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file Cpu4_Main.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: Cpu5_Main.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu5_Main.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu5_Main.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/Cpu5_Main.o: 0_Src/AppSw/Tricore/Main/Cpu5_Main.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file Cpu5_Main.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: GtmTomPwmHlDemo.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/GtmTomPwmHlDemo.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/GtmTomPwmHlDemo.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/GtmTomPwmHlDemo.o: 0_Src/AppSw/Tricore/Main/GtmTomPwmHlDemo.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file GtmTomPwmHlDemo.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: GtmTomTimerDemo.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/GtmTomTimerDemo.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/GtmTomTimerDemo.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/GtmTomTimerDemo.o: 0_Src/AppSw/Tricore/Main/GtmTomTimerDemo.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file GtmTomTimerDemo.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: TimPwmDemo.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/TimPwmDemo.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/TimPwmDemo.o

2_Out/Tricore_Gnuc/Gnuc_Files/0_Src/AppSw/Tricore/Main/TimPwmDemo.o: 0_Src/AppSw/Tricore/Main/TimPwmDemo.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file TimPwmDemo.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD
