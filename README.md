# AUTOSR_Based_LED_Control_Project
---
## Summary
---
#### A Full Layered Simple-Application based on AUTOSAR layered architecture :
*  **MCAL Layer :** Implemented following the AUTOSAR Software Specifications(AUTOSAR-SWS).
    * DIO Driver.
    * PORT Drivers.
    * DET STUB for just these two Drivers. 
*  **HAL Layer :** Implemented two External Modules. 
    * Button Module.
    * Led Module.
* **System Services Layer :** I created a Simple RTOS with General Purpose timer GPT to handle the   application tasks.
* **Application Layer :** Application which is to toggle a led every time a button is presssed.

## Full Layered Architecture
---
![Layered Architecture](https://user-images.githubusercontent.com/89493135/130728492-7608ce06-a8fc-4363-ac4e-2edfde71cbbb.png)
## Detailed Implementaion
---
### 1.AUTOSAR Based
#### **MCAL LAYER**
* ##### 1.Standard Types
    - **File Type :** Header file. 
    - **File Description:** Contains all types that are used across several modules of the basic software and that are platform and compiler independent.
* ##### 2.Platform Types
    - **File Type :** Header file. 
    - **File Description:** Platform types for ARM Cortex-M4F.
* ##### 3.Compiler Abstraction
    - Compiler.h
        - **File Type :** Header file.
        - **File Description:** This file contains the definitions and macros specified by AUTOSAR for the abstraction of compiler specific keywords.
    - Compiler_cfg.h
        - **File Type :** Header file. 
        - **File Description:** This file contains the module/component specific parameters (ptrclass and memclass) that are passed to the macros defined in Compiler.h .

* ##### 4.DIO Driver
    - Dio.h
        - **File Type :** Header file.
        - **File Description:** Header file for TM4C123GH6PM Microcontroller - Dio Driver.
    - Dio_cfg.h
        - **File Type :** Header file. 
        - **File Description:** Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver.
    - Dio_PBcfg.c
        - **File Type :** Source file. 
        - **File Description:** Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver.
    - Dio.c
        - **File Type :** Source file.
        - **File Description:**  Source file for TM4C123GH6PM Microcontroller - Dio Driver.

* ##### 4.PORT Driver
    - Port.h
        - **File Type :** Header file.
        - **File Description:** Header file for TM4C123GH6PM Microcontroller - Port Driver.
    - Port_cfg.h
        - **File Type :** Header file. 
        - **File Description:** Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver.
    - Port_PBcfg.c
        - **File Type :** Source file. 
        - **File Description:** Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver.
    - Port.c
        - **File Type :** Source file.
        - **File Description:**  Source file for TM4C123GH6PM Microcontroller - Port Driver.
* ##### 6.Default Error Tracer
    - DET.h
        - **File Type :** Header file. 
        - **File Description:** All detected development and runtime errors are reported to this module.This header file is a STUB for the Det Module.
    - DET.c
        - **File Type :** Source file. 
        - **File Description:** All detected development and runtime errors are reported to this module.This source file is a STUB for the Det Module.

### 2.Non-AUTOSAR Based
#### **MCAL LAYER**
* ##### 1.DIO Registers
    - **File Type :** Header file.
    - **File Description:** Header file for TM4C123GH6PM Microcontroller - Dio Driver Registers definitions.
* ##### 2.PORT Registers
    - **File Type :** Header file.
    - **File Description:** Header file for TM4C123GH6PM Microcontroller - Port Driver Registers definitions.
* ##### 3.Common Macros
    - **File Type :** Header file. 
    - **File Description:** Commonly used Macros.

#### **HAL LAYER**
* ##### 1.Button
    - Button.h
        - **File Type :** Header file.
        - **File Description:** Header file for Button Module.
    - Button.c
        - **File Type :** Source file. 
        - **File Description:** Source file for Button Module.
* ##### 2.Led
    - Led.h
        - **File Type :** Header file.
        - **File Description:** Header file for Led Module.
    - Led.c
        - **File Type :** Source file. 
        - **File Description:** Source file for Led Module.

#### **System Services Layer**
* ##### 1.General Purpose Timer GPT
    - Gpt.h
        - **File Type :** Header file.
        - **File Description:** Header file for TM4C123GH6PM Microcontroller - SysTick Timer Driver.
    - Gpt.c
        - **File Type :** Source file. 
        - **File Description:** Source file for TM4C123GH6PM Microcontroller - SysTick Timer Driver.
* ##### 2.Real Time Operating System RTOS
    - OS.h
        - **File Type :** Header file.
        - **File Description:** Header file for Os Scheduler.
    - OS.c
        - **File Type :** Source file. 
        - **File Description:** Source file for Os Scheduler.

#### **Application Layer**
* ##### 1.Application
    - App.h
        - **File Type :** Header file.
        - **File Description:** Header file for Application Tasks.
    - App.c
        - **File Type :** Source file. 
        - **File Description:** Source file for Application Tasks.
* ##### 2.Main
    - **File Type :** Source file.
    - **File Description:** Main file to run OS in.
## Feature Work
---
* We can replace this application with any other application that depends on DIO or PORT module we'll just need to addapt the configurations in PBcfg files to our needs.
* We can add more autosar modules with time to expand our application possibilities.

