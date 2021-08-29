 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.h
 *
 * Description: Header file for Os Scheduler.
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#ifndef OS_H_
#define OS_H_

#include "Std_Types.h"

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")

/* Timer counting time in ms */
#define OS_BASE_TIME 20

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Description: 
 * Function responsible for:
 * 1. Enable Interrupts
 * 2. Start the Os timer
 * 3. Execute the Init Task
 * 4. Start the Scheduler to run the tasks
 */
void Os_start(void);

/* Description: The Engine of the Os Scheduler used for switch between different tasks */
void Os_Scheduler(void);

/* Description: Function called by the Timer Driver in the MCAL layer using the call back pointer */
void Os_NewTimerTick(void);

#endif /* OS_H_ */
