/******************************************************************************
 *
 * AUTOSAR name: Default Error Tracer
 *
 * File Name: Det.h
 *
 * Description: All detected development and runtime errors are reported to this module.
 *
 * Author: Esmail Ahmed 
 *
 *******************************************************************************/

#ifndef DET_H
#define DET_H

/* Id for the company in the AUTOSAR
 * for example  Siemens' ID = 0x0019 :) 
*/
#define DET_VENDOR_ID                          (25U)

/*
 * Module ID = 015
 */
#define DET_MODULE_ID                          (015U)

/*
 * AUTOSAR Version 4.3.1
 */
#define DET_AR_RELEASE_MAJOR_VERSION           (4U)
#define DET_AR_RELEASE_MINOR_VERSION           (3U)
#define DET_AR_RELEASE_PATCH_VERSION           (1U)

/*
 * Module Version 1.0.0
 */
#define DET_SW_MAJOR_VERSION                   (1U)
#define DET_SW_MINOR_VERSION                   (0U)
#define DET_SW_PATCH_VERSION                   (0U)

#include "Std_Types.h"
/* AUTOSAR checking between Det and Std Types Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


#define DET_E_PARAM_POINTER     1U

/* Configuration data structure of the Det module. */
typedef struct{
uint8 DET_Init_Value;
}Det_ConfigType;

/*******************************************************************************
 *                      External Variables                                     *
 *******************************************************************************/   
extern uint16 Det_ModuleId;       /*DET module ID*/
extern uint8 Det_InstanceId;      /*DET instance ID*/
extern uint8 Det_ApiId;           /* DET API ID*/
extern uint8 Det_ErrorId;         /* DET Error ID*/

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Service to initialize the Default Error Tracer. */
void Det_Init( const Det_ConfigType* ConfigPtr );

/* Service to report development errors. */
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

/* Service to start the Default Error Tracer. */
void Det_Start( void ); 

/* Service to report runtime errors. If a callout has been configured then this callout shall be called. */
Std_ReturnType Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

/*Service to report transient faults. If a callout has been configured than this callout shall be called
 *and the returned value of the callout shall be returned. Otherwise it returns immediately with E_OK.
*/
Std_ReturnType Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId );

/* Returns the version information of this module. */
void Det_GetVersionInfo( Std_VersionInfoType* versioninfo );



#endif /*DET_H */