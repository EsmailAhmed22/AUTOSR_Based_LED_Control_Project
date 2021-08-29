 /******************************************************************************
 *
 *  AUTOSAR name: Compiler Abstraction
 *
 * File Name: Compiler_Cfg.h
 *
 * Description:  This file contains the module/component specific parameters
 *               (ptrclass and memclass)
 *               that are passed to the macros defined in Compiler.h.
 *
 * Author: Esmail Ahmed
 *
 *******************************************************************************/
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/* To be used for code. */
#define <PREFIX>_CODE   

/* To be used for callout code.
 *<CN> is the callback name (including module reference) written in uppercase letters. 
*/
#define <PREFIX>_<CN>_CODE

/* To be used for code that shall go into fast code memory segments. */
#define <PREFIX>_CODE_FAST

/* To be used for code that shall go into slow code memory segments. */
#define <PREFIX>_CODE_SLOW

/* To be used for global or static constants. */
#define <PREFIX>_CONST

/* To be used for calibration constants. */
#define <PREFIX>_CALIB

/* To be used for module configuration constants. */
#define <PREFIX>_CONFIG_DATA

/* To be used for ROM buffers of variables saved in non-volatile memory. 
 * X shall be replaced with the number of bytes (i.e. 8,16 or 32)
*/
#define <PREFIX>_CONST_SAVED_RECOVERY_ZONE<X>

/* To be used for references on application data (expected to be in RAM or ROM) passed via API */
#define <PREFIX>_APPL_DATA

/* To be used for references on application constants (expected to be certainly in ROM,
 * for instance pointer of Init-function) passed via API 
*/
#define <PREFIX>_APPL_CONST

 /* To be used for pointers to registers */
#define REGSPACE

/* To be used for all global or static variables. */
#define <PREFIX>_VAR_<INIT_POLICY>

/* To be used for all global or static variables that have at least one of the following properties:
 * 1- accessed bitwise
 * 2- frequently used
 * 3- high number of accesses in source code
*/
#define <PREFIX>_VAR_FAST_<INIT_POLICY>

 /* To be used for all infrequently accessed global or static variables. */
#define <PREFIX>_VAR_SLOW_<INIT_POLICY>

/* To be used for global or static variables which are accessible from a calibration tool. */
#define <PREFIX>_INTERNAL_VAR_<INIT_POLICY>

/* To be used for RAM buffers of variables saved in non-volatile memory.
 * X shall be replaced with the number of bytes (i.e. 8,16 or 32). 
*/
#define <PREFIX>_VAR_SAVED_ZONE<X>

#endif  /*COMPILER_CFG_H*/