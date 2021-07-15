#include <stdint.h>

#include "mpconfigboard.h"
#include "mpconfigboard_common.h"
// options to control how MicroPython is built
//#define MICROPY_NLR_SETJMP                  (1)
// You can disable the built-in MicroPython compiler by setting the following
// config option to 0.  If you do this then you won't get a REPL prompt, but you
// will still be able to execute pre-compiled scripts, compiled with mpy-cross.
#define MICROPY_ENABLE_COMPILER     (1)

#define MICROPY_QSTR_BYTES_IN_HASH  (1)
#define MICROPY_QSTR_EXTRA_POOL     mp_qstr_frozen_const_pool
#define MICROPY_ALLOC_PATH_MAX      (256)
#define MICROPY_ALLOC_PARSE_CHUNK_INIT (16)
#define MICROPY_COMP_CONST          (0)
#define MICROPY_COMP_DOUBLE_TUPLE_ASSIGN (0)
#define MICROPY_ENABLE_GC           (1)
#define MICROPY_GC_ALLOC_THRESHOLD  (0)
#define MICROPY_HELPER_REPL         (1)
#define MICROPY_ERROR_REPORTING     (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_BUILTIN_METHOD_CHECK_SELF_ARG (0)
#define MICROPY_PY_ASYNC_AWAIT      (0)
#define MICROPY_PY_ASSIGN_EXPR      (0)
//YP #define MICROPY_PY_BUILTINS_BYTEARRAY (0)
#define MICROPY_ENABLE_SCHEDULER    (1)
#define MICROPY_VFS                 (1)

#define MICROPY_READER_VFS          (1)

//#define MICROPY_PY_BUILTINS_DICT_FROMKEYS (0)
#define MICROPY_PY_BUILTINS_ENUMERATE (0)
#define MICROPY_PY_BUILTINS_FILTER  (0)
#define MICROPY_PY_BUILTINS_REVERSED (0)
#define MICROPY_PY_BUILTINS_SET     (0)
#define MICROPY_PY_BUILTINS_SLICE   (0)
#define MICROPY_PY_BUILTINS_PROPERTY (0)
#define MICROPY_PY_BUILTINS_MIN_MAX (0)
#define MICROPY_PY_BUILTINS_STR_COUNT (0)
#define MICROPY_PY_BUILTINS_STR_OP_MODULO (0)
#define MICROPY_PY_BUILTINS_HELP    (1)
#ifndef MICROPY_PY_BUILTINS_HELP_TEXT
#define MICROPY_PY_BUILTINS_HELP_TEXT aurix_help_text
#endif

#define MICROPY_PY___FILE__         (0)
#define MICROPY_PY_GC               (0)
#define MICROPY_PY_ARRAY            (0)
//#define MICROPY_PY_ATTRTUPLE        (0)
#define MICROPY_PY_COLLECTIONS      (0)
#define MICROPY_PY_IO               (1)
#define MICROPY_PY_IO_IOBASE        (1)
#define MICROPY_PY_IO_FILEIO        (MICROPY_VFS_FAT || MICROPY_VFS_LFS1 || MICROPY_VFS_LFS2)
#define MICROPY_PY_STRUCT           (0)
#define MICROPY_PY_SYS              (0)
#define MICROPY_MODULE_FROZEN_MPY   (1)
//YP #define MICROPY_CPYTHON_COMPAT      (0)
#define MICROPY_MODULE_GETATTR      (0)
#define MICROPY_NO_ALLOCA           (1)

#define MICROPY_FATFS_NORTC         (1)

// fatfs configuration used in ffconf.h
#define MICROPY_FATFS_ENABLE_LFN       (1)
#define MICROPY_FATFS_LFN_CODE_PAGE    437 /* 1=SFN/ANSI 437=LFN/U.S.(OEM) */
#define MICROPY_FATFS_USE_LABEL        (1)
#define MICROPY_FATFS_RPATH            (2)
#define MICROPY_FATFS_MULTI_PARTITION  (0)

// TODO these should be generic, not bound to a particular FS implementation
#if MICROPY_VFS_FAT
#define mp_type_fileio mp_type_vfs_fat_fileio
#define mp_type_textio mp_type_vfs_fat_textio
#elif MICROPY_VFS_LFS1
#define mp_type_fileio mp_type_vfs_lfs1_fileio
#define mp_type_textio mp_type_vfs_lfs1_textio
#elif MICROPY_VFS_LFS2
#define mp_type_fileio mp_type_vfs_lfs2_fileio
#define mp_type_textio mp_type_vfs_lfs2_textio
#endif

// use vfs's functions for import stat and builtin open
#define mp_import_stat mp_vfs_import_stat
#define mp_builtin_open mp_vfs_open
#define mp_builtin_open_obj mp_vfs_open_obj

// extra built in names to add to the global namespace
#define MICROPY_PORT_BUILTINS \
    { MP_ROM_QSTR(MP_QSTR_open), MP_ROM_PTR(&mp_builtin_open_obj) },

// type definitions for the specific machine

#ifndef MICROPY_FLOAT_IMPL // can be configured by each board via mpconfigboard.mk
#define MICROPY_FLOAT_IMPL          (MICROPY_FLOAT_IMPL_FLOAT)
#endif
#ifndef MICROPY_PY_UOS
#define MICROPY_PY_UOS              (1)
#endif

typedef intptr_t mp_int_t; // must be pointer size
typedef uintptr_t mp_uint_t; // must be pointer size
typedef long mp_off_t;
typedef int ssize_t;

#define assert(level)   ((void)0)


extern const struct _mp_obj_module_t pyb_module;
extern const struct _mp_obj_module_t mp_module_uos;

#if MICROPY_PY_UOS
#define UOS_BUILTIN_MODULE                  { MP_ROM_QSTR(MP_QSTR_uos), MP_ROM_PTR(&mp_module_uos) },
#else
#define UOS_BUILTIN_MODULE
#endif
#if MICROPY_PY_PYB
#define PYB_BUILTIN_MODULE                  { MP_ROM_QSTR(MP_QSTR_pyb), MP_ROM_PTR(&pyb_module) },
#else
#define PYB_BUILTIN_MODULE
#endif

#define MICROPY_PORT_BUILTIN_MODULES \
    PYB_BUILTIN_MODULE \
    UOS_BUILTIN_MODULE \

// extra constants
#define MICROPY_PORT_CONSTANTS \
    PYB_BUILTIN_MODULE \

// We need to provide a declaration/definition of alloca()
//#include <alloca.h>

#ifdef __linux__
#define MICROPY_MIN_USE_STDOUT (1)
#endif

#ifdef __thumb__
#define MICROPY_MIN_USE_CORTEX_CPU (1)
#define MICROPY_MIN_USE_STM32_MCU (1)
#endif

#define MP_STATE_PORT MP_STATE_VM

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8]; \
    \
    mp_obj_t pyb_config_main; \
    \
    mp_obj_t pin_class_mapper; \
    mp_obj_t pin_class_map_dict; \
    \
    /* pointers to all CAN objects (if they have been created) */ \
    struct _pyb_can_obj_t *pyb_can_obj_all[MICROPY_HW_MAX_CAN];
    
