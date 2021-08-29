/******************************************************************************
 *
 * AUTOSAR name: Default Error Tracer
 *
 * File Name: Det.c
 *
 * Description: All detected development and runtime errors are reported to this module.
 *              This source file is a STUB for the Det Module.
 *
 * Author: Esmail Ahmed 
 *
 *******************************************************************************/

#include "Det.h"

/* Variables to store last DET error */
uint16 Det_ModuleId = 0;       /*DET module ID*/
uint8 Det_InstanceId = 0;      /*DET instance ID*/
uint8 Det_ApiId = 0;           /* DET API ID*/
uint8 Det_ErrorId = 0;         /* DET Error ID*/

/************************************************************************************
* Service Name: Det_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr-Pointer to the selected configuration set.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Service to initialize the Default Error Tracer.
************************************************************************************/
void Det_Init( const Det_ConfigType* ConfigPtr ){

}

/************************************************************************************
* Service Name: Det_Start
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: None.
* Description: Service to start the Default Error Tracer.
************************************************************************************/
void Det_Start( void ){

}

/************************************************************************************
* Service Name: Det_ReportError
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ModuleId     Module ID of calling module.
*                  InstanceId   The identifier of the index based instance of 
* a module, starting from 0, If the module is a single instance module it shall pass 0 as the InstanceId.
*                  ApiId        ID of API service in which error is detected.
*                  ErrorId      ID of detected development error.
* Parameters (inout): None.
* Parameters (out): None.
* Return value: Std_ReturnType  Has a return type for compatibility with services and hooks.
* Description: Service to report development errors.
************************************************************************************/
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ){
    Det_ModuleId = ModuleId; 
    Det_InstanceId = InstanceId;
    Det_ApiId = ApiId; 
    Det_ErrorId = ErrorId;
    return E_OK;
}
