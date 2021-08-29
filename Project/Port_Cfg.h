/******************************************************************************
 *
 * Autosar name : Port Driver 
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Esmail Ahmed
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * AUTOSAR Version 4.3.1
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION   (3U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION           (1U)
#define PORT_CFG_SW_MINOR_VERSION           (0U)
#define PORT_CFG_SW_PATCH_VERSION           (0U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for Set Pin Direction API */   
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)   

/* Pre-compile option for Set Pin Mode API */   
#define PORT_SET_PIN_MODE_API                (STD_ON)    
      
/* Pre_compile option for initialized pins*/   
#define PORT_CONFIGURED_PORT_PINS            (43U)   

/* Pre_compile option for Port Status */
#define PORT_INITIALIZED                  (1U)
#define PORT_NOT_INITIALIZED              (0U)

/*  Pre_compile option for Pin position in Port */
#define PIN_0                             (0U)
#define PIN_1                             (1U)  
#define PIN_2                             (2U)  
#define PIN_3                             (3U)  
#define PIN_4                             (4U)  
#define PIN_5                             (5U)  
#define PIN_6                             (6U)
#define PIN_7                             (7U)

/*  Pre_compile option for Port Number */
#define PORT_A                            (0U)
#define PORT_B                            (1U)
#define PORT_C                            (2U)
#define PORT_D                            (3U)
#define PORT_E                            (4U)
#define PORT_F                            (5U)

/* Pre_compile option for Pin Status */
#define PORT_PIN_IN                       (0U)    
#define PORT_PIN_OUT                      (1U) 

/* Pre_compile option for Pin Pull up or Pull down or OFF*/
#define PORT_PIN_NO_PULL                  (0U)
#define PORT_PIN_PULL_UP                  (1U)
#define PORT_PIN_PULL_DOWN                (2U)

/* Pre_compile option for different Modes*/
#define MAX_MODE_NUMBER                 (17U) /* Maximum Mode Number */
#define PORT_DIGITAL_IO                 (0U)  /* DIGITAL I/O MODE    */
#define PORT_ANALOG_IO                  (16U) /* ANALOG I/O MODE     */
#define PORT_PA0_U0RX                   (1U)  /* PA0 Modes-UART      */                  
#define PORT_PA0_CAN1Rx                 (8U)  /* PA0 Modes-CAN       */
#define PORT_PA1_U0Tx                   (1U)  /* PA1 Modes-UART      */         
#define PORT_PA1_CAN1Tx                 (8U)  /* PA1 Modes-CAN       */
#define PORT_PA2_SSI0Clk                (2U)  /* PA2 Modes-SPI       */
#define PORT_PA3_SSI0Fss                (2U)  /* PA3 Modes-SPI       */
#define PORT_PA4_SSI0Rx                 (2U)  /* PA4 Modes-SPI       */
#define PORT_PA5_SSI0Tx                 (2U)  /* PA5 Modes-SPI       */
#define PORT_PA6_I2C1SCL                (3U)  /* PA6 Modes-I2C       */
#define PORT_PA6_M1PWM2                 (5U)  /* PA6 Modes-PWM       */
#define PORT_PA7_I2C1SDA                (3U)  /* PA7 Modes-I2C       */
#define PORT_PA7_M1PWM3                 (5U)  /* PA7 Modes-PWM       */
#define PORT_PB0_U1Rx                   (1U)  /* PB0 Modes-UART      */
#define PORT_PB0_T2CCP0                 (7U)  /* PB0 Modes-TCCP      */
#define PORT_PB1_U1Tx                   (1U)  /* PB1 Modes-UART      */
#define PORT_PB1_T2CCP1                 (7U)  /* PB1 Modes-TCCP      */
#define PORT_PB2_I2C0SCL                (3U)  /* PB2 Modes-I2C       */
#define PORT_PB2_T3CCP0                 (7U)  /* PB2 Modes-TCCP      */
#define PORT_PB3_I2C0SDA                (3U)  /* PB3 Modes-I2C       */
#define PORT_PB3_T3CCP1                 (7U)  /* PB3 Modes-TCCP      */
#define PORT_PB4_SSI2Clk                (2U)  /* PB4 Modes-SPI       */
#define PORT_PB4_M0PWM2                 (4U)  /* PB4 Modes-PWM       */
#define PORT_PB4_T1CCP0                 (7U)  /* PB4 Modes-TCCP      */
#define PORT_PB4_CAN0Rx                 (8U)  /* PB4 Modes-CAN       */
#define PORT_PB5_SSI2Fss                (2U)  /* PB5 Modes-SPI       */
#define PORT_PB5_M0PWM3                 (4U)  /* PB5 Modes-PWM       */
#define PORT_PB5_T1CCP1                 (7U)  /* PB5 Modes-TCCP      */
#define PORT_PB5_CAN0Tx                 (8U)  /* PB5 Modes-CAN       */
#define PORT_PB6_SSI2Rx                 (2U)  /* PB6 Modes-SPI       */
#define PORT_PB6_M0PWM0                 (4U)  /* PB6 Modes-PWM       */
#define PORT_PB6_T0CCP0                 (7U)  /* PB6 Modes-TCCP      */
#define PORT_PB7_SSI2Tx                 (2U)  /* PB7 Modes-SPI       */
#define PORT_PB7_M0PWM1                 (4U)  /* PB7 Modes-PWM       */
#define PORT_PB7_T0CCP1                 (7U)  /* PB7 Modes-TCCP      */
#define PORT_PC0_TCK_SWCLK              (1U)  /* PC0 Modes-TCK_SWCLK */
#define PORT_PC0_T4CCP0                 (7U)  /* PC0 Modes-TCCP      */
#define PORT_PC1_TMS_SWDIO              (1U)  /* PC1 Modes-TMS_SWDIO */
#define PORT_PC1_T4CCP1                 (7U)  /* PC1 Modes-TCCP      */
#define PORT_PC2_TDI                    (1U)  /* PC2 Modes-TDI       */
#define PORT_PC2_T5CCP0                 (7U)  /* PC2 Modes-TCCP      */
#define PORT_PC3_TDO_SWO                (1U)  /* PC3 Modes-TDO_SWO   */
#define PORT_PC3_T5CCP1                 (7U)  /* PC3 Modes-TCCP      */
#define PORT_PC4_U4Rx                   (1U)  /* PC4 Modes-UART      */  
#define PORT_PC4_U1Rx                   (2U)  /* PC4 Modes-UART      */
#define PORT_PC4_M0PWM6                 (4U)  /* PC4 Modes-PWM       */
#define PORT_PC4_IDX1                   (6U)  /* PC4 Modes-IDX       */
#define PORT_PC4_WT0CCP0                (7U)  /* PC4 Modes-WTCCP     */
#define PORT_PC4_U1RTS                  (8U)  /* PC4 Modes-UART      */
#define PORT_PC5_U4Tx                   (1U)  /* PC5 Modes-UART      */
#define PORT_PC5_U1Tx                   (2U)  /* PC5 Modes-UART      */
#define PORT_PC5_M0PWM7                 (4U)  /* PC5 Modes-PWM       */
#define PORT_PC5_PhA1                   (6U)  /* PC5 Modes-PHA       */
#define PORT_PC5_WT0CCP1                (7U)  /* PC5 Modes-TCCP      */
#define PORT_PC5_U1CTS                  (8U)  /* PC5 Modes-UCTS      */
#define PORT_PC6_U3Rx                   (1U)  /* PC6 Modes-UART      */
#define PORT_PC6_PhB1                   (6U)  /* PC6 Modes-PHB       */
#define PORT_PC6_WT1CCP0                (7U)  /* PC6 Modes-WTCCP     */
#define PORT_PC6_USB0EPEN               (8U)  /* PC6 Modes-USB       */
#define PORT_PC7_U3Tx                   (1U)  /* PC7 Modes-UART      */
#define PORT_PC7_WT1CCP1                (7U)  /* PC7 Modes-WTCCP     */
#define PORT_PC7_USB0PFLT               (8U)  /* PC7 Modes-USB       */
#define PORT_PD0_SSI3Clk                (1U)  /* PD0 Modes-SPI       */  
#define PORT_PD0_SSI1Clk                (2U)  /* PD0 Modes-SPI       */
#define PORT_PD0_I2C3SCL                (3U)  /* PD0 Modes-I2C       */
#define PORT_PD0_M0PWM6                 (4U)  /* PD0 Modes-PWM       */
#define PORT_PD0_M1PWM0                 (5U)  /* PD0 Modes-PWM       */
#define PORT_PD0_WT2CCP0                (7U)  /* PD0 Modes-WTCCP     */ 
#define PORT_PD1_SSI3Fss                (1U)  /* PD1 Modes-SPI       */
#define PORT_PD1_SSI1Fss                (2U)  /* PD1 Modes-SPI       */
#define PORT_PD1_I2C3SDA                (3U)  /* PD1 Modes-I2C       */
#define PORT_PD1_M0PWM7                 (4U)  /* PD1 Modes-PWM       */
#define PORT_PD1_M1PWM1                 (5U)  /* PD1 Modes-PWM       */
#define PORT_PD1_WT2CCP1                (7U)  /* PD1 Modes-WTCCP     */
#define PORT_PD2_SSI3Rx                 (1U)  /* PD2 Modes-SPI       */ 
#define PORT_PD2_SSI1Rx                 (2U)  /* PD2 Modes-SPI       */
#define PORT_PD2_M0FAULT0               (4U)  /* PD2 Modes-MFAULT    */
#define PORT_PD2_WT3CCP0                (7U)  /* PD2 Modes-WTCCP     */
#define PORT_PD2_USB0EPEN               (8U)  /* PD2 Modes-USB       */
#define PORT_PD3_SSI3Tx                 (1U)  /* PD3 Modes-SPI       */
#define PORT_PD3_SSI1Tx                 (2U)  /* PD3 Modes-SPI       */
#define PORT_PD3_IDX0                   (6U)  /* PD3 Modes-IDX       */
#define PORT_PD3_WT3CCP1                (7U)  /* PD3 Modes-WTCCP     */
#define PORT_PD3_USB0PFLT               (8U)  /* PD3 Modes-USB       */
#define PORT_PD4_U6Rx                   (1U)  /* PD4 Modes-UART      */
#define PORT_PD4_WT4CCP0                (7U)  /* PD4 Modes-WTCCP     */
#define PORT_PD5_U6Tx                   (1U)  /* PD5 Modes-UART      */
#define PORT_PD5_WT4CCP1                (7U)  /* PD5 Modes-WTCCP     */
#define PORT_PD6_U2Rx                   (1U)  /* PD6 Modes-UART      */
#define PORT_PD6_M0FAULT0               (4U)  /* PD6 Modes-MFAULt    */
#define PORT_PD6_PhA0                   (6U)  /* PD6 Modes-PHA       */
#define PORT_PD6_WT5CCP0                (7U)  /* PD6 Modes-WTCCP     */
#define PORT_PD7_U2Tx                   (1U)  /* PD7 Modes-UART      */
#define PORT_PD7_PhB0                   (6U)  /* PD7 Modes-PHB       */
#define PORT_PD7_WT5CCP1                (7U)  /* PD7 Modes-WTCCP     */
#define PORT_PD7_NMI                    (8U)  /* PD7 Modes-NMI       */
#define PORT_PE0_U7Rx                   (1U)  /* PE0 Modes-UART      */
#define PORT_PE1_U7Tx                   (1U)  /* PE1 Modes-UART      */
#define PORT_PE4_U5Rx                   (1U)  /* PE4 Modes-UART      */
#define PORT_PE4_I2C2SCL                (3U)  /* PE4 Modes-I2C       */
#define PORT_PE4_M0PWM4                 (4U)  /* PE4 Modes-PWM       */
#define PORT_PE4_M1PWM2                 (5U)  /* PE4 Modes-PWM       */
#define PORT_PE4_CAN0Rx                 (8U)  /* PE4 Modes-CAN       */
#define PORT_PE5_U5Tx                   (1U)  /* PE5 Modes-UART      */ 
#define PORT_PE5_I2C2SDA                (3U)  /* PE5 Modes-I2C       */
#define PORT_PE5_M0PWM5                 (4U)  /* PE5 Modes-PWM       */
#define PORT_PE5_M1PWM3                 (5U)  /* PE5 Modes-PWM       */
#define PORT_PE5_CAN0Tx                 (8U)  /* PE5 Modes-CAN       */
#define PORT_PF0_U1RTS                  (1U)  /* PF0 Modes-UART      */
#define PORT_PF0_SSI1Rx                 (2U)  /* PF0 Modes-SPI       */
#define PORT_PF0_CAN0Rx                 (3U)  /* PF0 Modes-CAN       */
#define PORT_PF0_M1PWM4                 (5U)  /* PF0 Modes-PWM       */
#define PORT_PF0_PhA0                   (6U)  /* PF0 Modes-PHA       */
#define PORT_PF0_T0CCP0                 (7U)  /* PF0 Modes-TCCP      */
#define PORT_PF0_NMI                    (8U)  /* PF0 Modes-NMI       */
#define PORT_PF0_C0o                    (9U)  /* PF0 Modes-C0o       */
#define PORT_PF1_U1CTS                  (1U)  /* PF1 Modes-UCTS      */
#define PORT_PF1_SSI1Tx                 (2U)  /* PF1 Modes-SPI       */
#define PORT_PF1_M1PWM5                 (5U)  /* PF1 Modes-PWM       */
#define PORT_PF1_PhB0                   (6U)  /* PF1 Modes-PHB       */
#define PORT_PF1_T0CCP1                 (7U)  /* PF1 Modes-TCCP      */
#define PORT_PF1_C1o                    (9U)  /* PF1 Modes-C1o       */
#define PORT_PF1_TRD1                   (14U) /* PF1 Modes-TRD       */
#define PORT_PF2_SSI1Clk                (2U)  /* PF2 Modes-SPI       */
#define PORT_PF2_M0FAULT0               (4U)  /* PF2 Modes-MFAULT    */
#define PORT_PF2_M1PWM6                 (5U)  /* PF2 Modes-PWM       */
#define PORT_PF2_T1CCP0                 (7U)  /* PF2 Modes-TCCP      */
#define PORT_PF2_TRD0                   (14U) /* PF2 Modes-TRD       */
#define PORT_PF3_SSI1Fss                (2U)  /* PF3 Modes-SPI       */
#define PORT_PF3_CAN0Tx                 (3U)  /* PF3 Modes-CAN       */
#define PORT_PF3_M1PWM7                 (5U)  /* PF3 Modes-PWM       */
#define PORT_PF3_T1CCP1                 (7U)  /* PF3 Modes-TCCP      */
#define PORT_PF3_TRCLK                  (14U) /* PF3 Modes-TRCLK     */
#define PORT_PF4_M1FAULT0               (5U)  /* PF4 Modes-MFAULT    */
#define PORT_PF4_IDX0                   (6U)  /* PF4 Modes-IDX       */
#define PORT_PF4_T2CCP0                 (7U)  /* PF4 Modes-TCCP      */
#define PORT_PF4_USB0EPEN               (8U)  /* PF4 Modes-USB       */

/* Pre_compile option for Pin Initial value */
#define PORT_INITIAL_VALUE_OFF          (0U)        
#define PORT_INITIAL_VALUE_ON           (1U)
   
/* Pre_compile option for Pin Changeable or not*/
#define PORT_PIN_CHANGEABLE             (1U)
#define PORT_PIN_NOT_CHANGEABLE         (0U)

/* Pre_compile option for Pin ID */
#define PORT_A_PIN_0                      (0U)
#define PORT_A_PIN_1                      (1U)
#define PORT_A_PIN_2                      (2U)
#define PORT_A_PIN_3                      (3U)
#define PORT_A_PIN_4                      (4U)
#define PORT_A_PIN_5                      (5U)
#define PORT_A_PIN_6                      (6U)
#define PORT_A_PIN_7                      (7U)
#define PORT_B_PIN_0                      (8U)
#define PORT_B_PIN_1                      (9U)
#define PORT_B_PIN_2                      (10U)
#define PORT_B_PIN_3                      (11U)
#define PORT_B_PIN_4                      (12U)
#define PORT_B_PIN_5                      (13U)
#define PORT_B_PIN_6                      (14U)
#define PORT_B_PIN_7                      (15U)
#define PORT_C_PIN_0                      (16U)
#define PORT_C_PIN_1                      (17U)
#define PORT_C_PIN_2                      (18U)
#define PORT_C_PIN_3                      (19U)
#define PORT_C_PIN_4                      (20U)
#define PORT_C_PIN_5                      (21U)
#define PORT_C_PIN_6                      (22U)
#define PORT_C_PIN_7                      (23U)
#define PORT_D_PIN_0                      (24U)
#define PORT_D_PIN_1                      (25U)
#define PORT_D_PIN_2                      (26U)
#define PORT_D_PIN_3                      (27U)
#define PORT_D_PIN_4                      (28U)
#define PORT_D_PIN_5                      (29U)
#define PORT_D_PIN_6                      (30U)
#define PORT_D_PIN_7                      (31U)
#define PORT_E_PIN_0                      (32U)
#define PORT_E_PIN_1                      (33U)
#define PORT_E_PIN_2                      (34U)
#define PORT_E_PIN_3                      (35U)
#define PORT_E_PIN_4                      (36U)
#define PORT_E_PIN_5                      (37U)
#define PORT_F_PIN_0                      (38U)
#define PORT_F_PIN_1                      (39U)
#define PORT_F_PIN_2                      (40U)
#define PORT_F_PIN_3                      (41U)
#define PORT_F_PIN_4                      (42U)

#endif /* PORT_CFG_H */