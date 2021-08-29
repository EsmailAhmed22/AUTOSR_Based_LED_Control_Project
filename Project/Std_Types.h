 /******************************************************************************
 *
 * AUTOSAR name:Standard Types
 *
 * File Name: Std_Types.h
 *
 * Description: Contains all types that are used across several modules of the 
 *              basic software and that are platform and compiler independent.
 *
 * Author: Esmail Ahmed
 *
 *******************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Id for the company in the AUTOSAR
 * for example  Siemens' ID = 0x0019 :) 
*/
#define STD_TYPES_VENDOR_ID                          (25U)

/*
 * Module ID = 199
 */
#define STD_TYPES_MODULE_ID                          (197U)

/*
 * AUTOSAR Version 4.3.1
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION           (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION           (3U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION           (1U)

/*
 * Module Version 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION                   (1U)
#define STD_TYPES_SW_MINOR_VERSION                   (0U)
#define STD_TYPES_SW_PATCH_VERSION                   (0U)

#include "Platform_Types.h"
/* AUTOSAR checking between Platform Types and Std Types Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PLATFORM_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Platform_Types.h does not match the expected version"
#endif

#include "Compiler.h"
/* AUTOSAR checking between Compiler and Std Types Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != COMPILER_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Compiler.h does not match the expected version"
#endif
   
/* This type can be used as standard API return type which is shared between the RTE and the BSW modules. */
typedef uint8 Std_ReturnType;


/* Structure shall be used to request the version of a module using the <Module name>_GetVersionInfo() function */
typedef struct{
uint16  vendorID;

uint16  moduleID;

uint8   sw_major_version;

uint8   sw_minor_version;

uint8   sw_patch_version;
}Std_VersionInfoType;


#ifndef STATUSTYPEDEFINED 
#define STATUSTYPEDEFINED 

#define E_OK     ((Std_ReturnType)0x00U) 
typedef unsigned char StatusType; /* OSEK compliance */ 

#endif 

#define E_NOT_OK ((Std_ReturnType)0x01U)


#define STD_HIGH        0x01U          /* Physical state 5V or 3.3V */ 
#define STD_LOW         0x00U          /* Physical state 0V */

#define STD_ACTIVE      0x01U         /* Logical state active */ 
#define STD_IDLE        0x00U         /* Logical state idle */

#define STD_ON          0x01U 
#define STD_OFF         0x00U




#endif /* STD_TYPES_H */