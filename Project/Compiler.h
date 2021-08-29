 /******************************************************************************
 *
 * AUTOSAR name: Compiler Abstraction
 *
 * Compiler symbol: _IAR_C_ARM Cortex-M4F_
 *
 * File Name: Compiler.h
 *
 * Description:  This file contains the definitions and macros specified by
 *               AUTOSAR for the abstraction of compiler specific keywords.
 *
 * Author: Esmail Ahmed
 *
 *******************************************************************************/
#ifndef COMPILER_H
#define COMPILER_H


/* Id for the company in the AUTOSAR
 * for example  Siemens' ID = 0x0019 :) 
*/
#define COMPILER_VENDOR_ID                          (25U)

/*
 * Module ID = 198
 */
#define COMPILER_MODULE_ID                          (198U)

/*
 * AUTOSAR Version 4.3.1
 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION           (4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION           (3U)
#define COMPILER_AR_RELEASE_PATCH_VERSION           (1U)

/*
 * Module Version 1.0.0
 */
#define COMPILER_SW_MAJOR_VERSION                   (1U)
#define COMPILER_SW_MINOR_VERSION                   (0U)
#define COMPILER_SW_PATCH_VERSION                   (0U)


/* The memory class AUTOMATIC shall be provided as empty definition, used for the declaration of local pointers. */
#define AUTOMATIC

/* This memory class shall be used within type definitions, where no memory qualifier can be specified. */
#define TYPEDEF

/* The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero definition. */
#define NULL_PTR        ((void *)0)

/* The compiler abstraction shall provide the INLINE define for abstraction of the keyword inline. */
#define INLINE          inline

/* The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword inline in functions with “static” scope. */
#define LOCAL_INLINE    static inline

/* This is used to define the abstraction of compiler keyword static */
#define STATIC            static


/* The compiler abstraction shall define the FUNC macro for the declaration and definition of functions that ensures correct syntax 
 * of function declarations as required by a specific compiler. 
*/
#define FUNC(rettype, memclass)

/* The compiler abstraction shall define the FUNC_P2CONST macro for the declaration and definition of functions returning a pointer to a constant.
 * This shall ensure the correct syntax of function declarations as required by a specific compiler. 
*/
#define FUNC_P2CONST(rettype, ptrclass, memclass)

/* The compiler abstraction shall define the FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable.
 * This shall ensure the correct syntax of function declarations as required by a specific compiler. 
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass)

/* The compiler abstraction shall define the P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables. */
#define P2VAR(ptrtype, memclass, ptrclass)

/* The compiler abstraction shall define the P2CONST macro for the declaration and definition of pointers in RAM, pointing to constants. */
#define P2CONST(ptrtype, memclass, ptrclass)

/* The compiler abstraction shall define the CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables. */
#define CONSTP2VAR (ptrtype, memclass, ptrclass)

/* The compiler abstraction shall define the CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants. */
#define CONSTP2CONST(ptrtype, memclass, ptrclass)

/* The compiler abstraction shall define the P2FUNC macro for the type definition of pointers to functions. */
#define P2FUNC(rettype, ptrclass, fctname)

/* The compiler abstraction shall define the CONSTP2FUNC macro for the type definition of constant pointers to functions. */
#define CONSTP2FUNC(rettype, ptrclass, fctname)

/* The compiler abstraction shall define the CONST macro for the declaration and definition of constants. */
#define CONST(consttype, memclass)

/* The compiler abstraction shall define the VAR macro for the declaration and definition of variables. */
#define VAR(vartype, memclass)



#endif  /*COMPILER_H*/