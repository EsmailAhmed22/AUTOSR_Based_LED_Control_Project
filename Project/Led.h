/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 * Author: Esmail Ahmed.
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "Std_Types.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW

/* Set the LED Port */
#define LED_PORT DioConf_LED1_PORT_NUM

/* Set the LED Pin Number */
#define LED_PIN_NUM DioConf_LED1_CHANNEL_NUM

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Description: Set the LED state to ON */
void LED_setOn(void);

/* Description: Set the LED state to OFF */
void LED_setOff(void);

/*Description: Toggle the LED state */
void LED_toggle(void);

/* Description: Refresh the LED state */
void LED_refreshOutput(void);

#endif /* LED_H */
