/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* *********************************************************************************************** 
 * File:        MyBoard_RXX_pinmap.h
 * Author:      M91406
 * Comments:    Hardware abstraction layer for dsPIC33CH512MP506 master core
 * Board No:    TBD
 * 
 * Description:
 * This is a header file template adding signal labels for the hardware abstraction layer
 * In this example user defined signals are directly associated to specific device pins. 
 * These associations have been created using the MS Excel macro-based code generation tool
 * MyBoard_RXX_pinout.xlsm located in the h/hal/config directory of the project. 
 * 
 * Note:
 * This file is the junction point between hardware and microcontroller abstraction layer.
 * To better separate them from each other (e.g. for supporting CPU cards in hardware platforms),
 * generic signal labels may be used in these declarations, which can be used to associate MCU 
 * device pins in MCAL to signals defined here in HAL.
 * 
 * EXAMPLE OF BOTH USE CASES
 * 
 * a) Direct pin assignment using ONE header file in HAL
 * 
 *  File:       MyBoard_RXX_pinmap.h                
 * -----------------------------------------------------------------------
 * 
 *              #define CLKOUT  _LATB1            
 * 
 * Any usage of the label CLKOUT in user code will automatically be mapped to the 
 * specific device pin RB1. Thus board hardware and MCU itself become independent, 
 * exchangeable elements in the firmware and pin-out changes made won't affect 
 * the rest of the firmware.
 * 
 * However, although this assignment simplifies the hardware abstraction, HAL and MCAL 
 * are not clearly separated as MCU specific registers are assigned here.
 *
 * 
 * b) Indirect pin assignment using TWO header files in HAL and MCAL
 *
 *  File:       MyBoard_RXX_pinmap.h            MyController_pinmap.h     
 * -----------------------------------------------------------------------
 * 
 *              #define CLKOUT  TP08            #define TP08    _LATB1          
 * 
 * Any usage of the label CLKOUT in user code will automatically be mapped to the 
 * specific device pin RB1. Thus board hardware, MCU adapter card and MCU itself become
 * independent, exchangeable elements in the firmware and changes made here won't affect 
 * the rest of the firmware.
 * 
 * This functional assignment scheme clearly separates HAL and MCAL, but adds more complexity
 * to the structure. This scheme works best when working with CPU adapter cards like 
 * Microchip's Digital Power Plug-In Modules.
 * 
 * 
 * Revision history: 
 *     1.0    (initial release)
 * 
 * ***********************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _MYBOARD_RXX_PINMAP_H_
#define	_MYBOARD_RXX_PINMAP_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
#include "mcal/mcal.h"

/* @@PNMAP_VERSION
 * *********************************************************************************************** 
 * Description:
 * This flag is a user defined flag helping to provide version information about the
 * pinmap file. This string can be used universally across the firmware to identify the 
 * hardware version this firmaware was written for.
 * 
 * Please Note:
 * His label is not connected to the generic macro specified in the compiler settings
 * and need to maintained by the designer independently. 
 * ***********************************************************************************************/
#ifndef PINMAP_VERSION
    #define PINMAP_VERSION "R10"
#endif
/* ***********************************************************************************************/

// Generated Content: Generic defines used to map device pins to board signals

#ifndef PINDIR_INPUT
    #define PINDIR_INPUT 1
#endif
#ifndef PINDIR_OUTPUT
    #define PINDIR_OUTPUT 0
#endif
#ifndef PINSTATE_HIGH
    #define PINSTATE_HIGH 1
#endif
#ifndef PINSTATE_LOW
    #define PINSTATE_LOW 0
#endif

#ifndef LED_ON
    #define LED_ON 0
#endif
#ifndef LED_OFF
    #define LED_OFF 1
#endif

#ifndef PINCFG_OPEN_DRAIN
    #define PINCFG_OPEN_DRAIN 1
#endif
#ifndef PINCFG_PUSH_PULL
    #define PINCFG_PUSH_PULL 0
#endif

#ifndef PINCFG_PULL_UP_DOWN_NONE
    #define PINCFG_PULL_UP_DOWN_NONE 0
#endif
#ifndef PINCFG_PULL_DOWN
    #define PINCFG_PULL_DOWN 1
#endif
#ifndef PINCFG_PULL_UP
    #define PINCFG_PULL_UP 2
#endif

#if defined (__P33SMPS_CH_MSTR__)

	#define DP14_TRIS    TRISAbits.TRISA0 // GPIO direction register bit
	#define DP14_WR      LATAbits.LATA0 // GPIO port latch register bit
	#define DP14_RD      PORTAbits.RA0 // GPIO port register bit
	#define DP14_ODC     ODCAbits.ODCA0 // GPIO port open drain configuration register bit
	#define DP14_CNPU    CNPUAbits.CNPUA0 // GPIO port pull-up resistor register bit
	#define DP14_CNPD    CNPDAbits.CNPDA0 // GPIO port pull-down resistor register bit
	#define DP14_CNEN0   CNEN0Abits.CNEN0A0 // GPIO port change notification Enable register bit
	#define DP14_CNSTAT  CNSTATAbits.CNSTATA0 // GPIO port change notification Status register bit
	#define DP14_CNEN1   CNEN1Abits.CNEN1A0 // GPIO port change notification Edge Select Enable register bit
	#define DP14_CNF     CNFAbits.CNFA0 // GPIO port change notification flag bit register bit
	#define DP14_SET     { asm volatile ("bset _LATA, #0 \n"); }
	#define DP14_CLEAR   { asm volatile ("bclr _LATA, #0 \n"); }
	#define DP14_TOGGLE  { asm volatile ("btg  _LATA, #0 \n"); }
	#define DP14_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP14_ANSEL   _ANSELA0 // analog/digital pin configuration register bit
	#define DP14_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP14_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP14_ADC_AN_INPUT 0   // ANx input pin number
	#define DP14_ADCBUF  ADCBUF0 // ADC buffer register for this input
	#define DP14_ADC_ANIE ADIELbits.IE0
	#define DP14_ADC_ANEIE ADEIELbits.EIEN0
	#define DP14_ADC_IF   _ADCAN0IF // interrupt flag bit
	#define DP14_ADC_IE   _ADCAN0IE // interrupt enable bit
	#define DP14_ADC_IP   _ADCAN0IP // interrupt priority for this analog input
	#define DP14_ADC_RDY  _AN0RDY // ADC buffer ready bit
	#define _DP14_ADC_Interrupt _ADCAN0Interrupt
	#define DP14_INIT_ANALOG	{DP14_ANSEL = 1; DP14_WR = PINSTATE_HIGH; DP14_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP14_INIT_OUTPUT  {DP14_WR = PINSTATE_LOW; DP14_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP14_INIT_INPUT   {DP14_WR = PINSTATE_HIGH; DP14_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP15_TRIS    TRISAbits.TRISA1 // GPIO direction register bit
	#define DP15_WR      LATAbits.LATA1 // GPIO port latch register bit
	#define DP15_RD      PORTAbits.RA1 // GPIO port register bit
	#define DP15_ODC     ODCAbits.ODCA1 // GPIO port open drain configuration register bit
	#define DP15_CNPU    CNPUAbits.CNPUA1 // GPIO port pull-up resistor register bit
	#define DP15_CNPD    CNPDAbits.CNPDA1 // GPIO port pull-down resistor register bit
	#define DP15_CNEN0   CNEN0Abits.CNEN0A1 // GPIO port change notification Enable register bit
	#define DP15_CNSTAT  CNSTATAbits.CNSTATA1 // GPIO port change notification Status register bit
	#define DP15_CNEN1   CNEN1Abits.CNEN1A1 // GPIO port change notification Edge Select Enable register bit
	#define DP15_CNF     CNFAbits.CNFA1 // GPIO port change notification flag bit register bit
	#define DP15_SET     { asm volatile ("bset _LATA, #1 \n"); }
	#define DP15_CLEAR   { asm volatile ("bclr _LATA, #1 \n"); }
	#define DP15_TOGGLE  { asm volatile ("btg  _LATA, #1 \n"); }
	#define DP15_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP15_ANSEL   _ANSELA1 // analog/digital pin configuration register bit
	#define DP15_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP15_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP15_ADC_AN_INPUT 1   // ANx input pin number
	#define DP15_ADCBUF  ADCBUF1 // ADC buffer register for this input
	#define DP15_ADC_ANIE ADIELbits.IE1
	#define DP15_ADC_ANEIE ADEIELbits.EIEN1
	#define DP15_ADC_IF   _ADCAN1IF // interrupt flag bit
	#define DP15_ADC_IE   _ADCAN1IE // interrupt enable bit
	#define DP15_ADC_IP   _ADCAN1IP // interrupt priority for this analog input
	#define DP15_ADC_RDY  _AN1RDY // ADC buffer ready bit
	#define _DP15_ADC_Interrupt _ADCAN1Interrupt
	#define DP15_INIT_ANALOG	{DP15_ANSEL = 1; DP15_WR = PINSTATE_HIGH; DP15_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP15_INIT_OUTPUT  {DP15_WR = PINSTATE_LOW; DP15_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP15_INIT_INPUT   {DP15_WR = PINSTATE_HIGH; DP15_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP16_TRIS    TRISAbits.TRISA2 // GPIO direction register bit
	#define DP16_WR      LATAbits.LATA2 // GPIO port latch register bit
	#define DP16_RD      PORTAbits.RA2 // GPIO port register bit
	#define DP16_ODC     ODCAbits.ODCA2 // GPIO port open drain configuration register bit
	#define DP16_CNPU    CNPUAbits.CNPUA2 // GPIO port pull-up resistor register bit
	#define DP16_CNPD    CNPDAbits.CNPDA2 // GPIO port pull-down resistor register bit
	#define DP16_CNEN0   CNEN0Abits.CNEN0A2 // GPIO port change notification Enable register bit
	#define DP16_CNSTAT  CNSTATAbits.CNSTATA2 // GPIO port change notification Status register bit
	#define DP16_CNEN1   CNEN1Abits.CNEN1A2 // GPIO port change notification Edge Select Enable register bit
	#define DP16_CNF     CNFAbits.CNFA2 // GPIO port change notification flag bit register bit
	#define DP16_SET     { asm volatile ("bset _LATA, #2 \n"); }
	#define DP16_CLEAR   { asm volatile ("bclr _LATA, #2 \n"); }
	#define DP16_TOGGLE  { asm volatile ("btg  _LATA, #2 \n"); }
	#define DP16_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP16_ANSEL   _ANSELA2 // analog/digital pin configuration register bit
	#define DP16_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP16_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP16_ADC_AN_INPUT 2   // ANx input pin number
	#define DP16_ADCBUF  ADCBUF2 // ADC buffer register for this input
	#define DP16_ADC_ANIE ADIELbits.IE2
	#define DP16_ADC_ANEIE ADEIELbits.EIEN2
	#define DP16_ADC_IF   _ADCAN2IF // interrupt flag bit
	#define DP16_ADC_IE   _ADCAN2IE // interrupt enable bit
	#define DP16_ADC_IP   _ADCAN2IP // interrupt priority for this analog input
	#define DP16_ADC_RDY  _AN2RDY // ADC buffer ready bit
	#define _DP16_ADC_Interrupt _ADCAN2Interrupt
	#define DP16_INIT_ANALOG	{DP16_ANSEL = 1; DP16_WR = PINSTATE_HIGH; DP16_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP16_INIT_OUTPUT  {DP16_WR = PINSTATE_LOW; DP16_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP16_INIT_INPUT   {DP16_WR = PINSTATE_HIGH; DP16_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP17_TRIS    TRISAbits.TRISA3 // GPIO direction register bit
	#define DP17_WR      LATAbits.LATA3 // GPIO port latch register bit
	#define DP17_RD      PORTAbits.RA3 // GPIO port register bit
	#define DP17_ODC     ODCAbits.ODCA3 // GPIO port open drain configuration register bit
	#define DP17_CNPU    CNPUAbits.CNPUA3 // GPIO port pull-up resistor register bit
	#define DP17_CNPD    CNPDAbits.CNPDA3 // GPIO port pull-down resistor register bit
	#define DP17_CNEN0   CNEN0Abits.CNEN0A3 // GPIO port change notification Enable register bit
	#define DP17_CNSTAT  CNSTATAbits.CNSTATA3 // GPIO port change notification Status register bit
	#define DP17_CNEN1   CNEN1Abits.CNEN1A3 // GPIO port change notification Edge Select Enable register bit
	#define DP17_CNF     CNFAbits.CNFA3 // GPIO port change notification flag bit register bit
	#define DP17_SET     { asm volatile ("bset _LATA, #3 \n"); }
	#define DP17_CLEAR   { asm volatile ("bclr _LATA, #3 \n"); }
	#define DP17_TOGGLE  { asm volatile ("btg  _LATA, #3 \n"); }
	#define DP17_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP17_ANSEL   _ANSELA3 // analog/digital pin configuration register bit
	#define DP17_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP17_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP17_ADC_AN_INPUT 3   // ANx input pin number
	#define DP17_ADCBUF  ADCBUF3 // ADC buffer register for this input
	#define DP17_ADC_ANIE ADIELbits.IE3
	#define DP17_ADC_ANEIE ADEIELbits.EIEN3
	#define DP17_ADC_IF   _ADCAN3IF // interrupt flag bit
	#define DP17_ADC_IE   _ADCAN3IE // interrupt enable bit
	#define DP17_ADC_IP   _ADCAN3IP // interrupt priority for this analog input
	#define DP17_ADC_RDY  _AN3RDY // ADC buffer ready bit
	#define _DP17_ADC_Interrupt _ADCAN3Interrupt
	#define DP17_INIT_ANALOG	{DP17_ANSEL = 1; DP17_WR = PINSTATE_HIGH; DP17_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP17_INIT_OUTPUT  {DP17_WR = PINSTATE_LOW; DP17_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP17_INIT_INPUT   {DP17_WR = PINSTATE_HIGH; DP17_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP18_TRIS    TRISAbits.TRISA4 // GPIO direction register bit
	#define DP18_WR      LATAbits.LATA4 // GPIO port latch register bit
	#define DP18_RD      PORTAbits.RA4 // GPIO port register bit
	#define DP18_ODC     ODCAbits.ODCA4 // GPIO port open drain configuration register bit
	#define DP18_CNPU    CNPUAbits.CNPUA4 // GPIO port pull-up resistor register bit
	#define DP18_CNPD    CNPDAbits.CNPDA4 // GPIO port pull-down resistor register bit
	#define DP18_CNEN0   CNEN0Abits.CNEN0A4 // GPIO port change notification Enable register bit
	#define DP18_CNSTAT  CNSTATAbits.CNSTATA4 // GPIO port change notification Status register bit
	#define DP18_CNEN1   CNEN1Abits.CNEN1A4 // GPIO port change notification Edge Select Enable register bit
	#define DP18_CNF     CNFAbits.CNFA4 // GPIO port change notification flag bit register bit
	#define DP18_SET     { asm volatile ("bset _LATA, #4 \n"); }
	#define DP18_CLEAR   { asm volatile ("bclr _LATA, #4 \n"); }
	#define DP18_TOGGLE  { asm volatile ("btg  _LATA, #4 \n"); }
	#define DP18_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP18_ANSEL   _ANSELA4 // analog/digital pin configuration register bit
	#define DP18_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP18_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP18_ADC_AN_INPUT 4   // ANx input pin number
	#define DP18_ADCBUF  ADCBUF4 // ADC buffer register for this input
	#define DP18_ADC_ANIE ADIELbits.IE4
	#define DP18_ADC_ANEIE ADEIELbits.EIEN4
	#define DP18_ADC_IF   _ADCAN4IF // interrupt flag bit
	#define DP18_ADC_IE   _ADCAN4IE // interrupt enable bit
	#define DP18_ADC_IP   _ADCAN4IP // interrupt priority for this analog input
	#define DP18_ADC_RDY  _AN4RDY // ADC buffer ready bit
	#define _DP18_ADC_Interrupt _ADCAN4Interrupt
	#define DP18_INIT_ANALOG	{DP18_ANSEL = 1; DP18_WR = PINSTATE_HIGH; DP18_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP18_INIT_OUTPUT  {DP18_WR = PINSTATE_LOW; DP18_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP18_INIT_INPUT   {DP18_WR = PINSTATE_HIGH; DP18_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP28_TRIS    TRISBbits.TRISB0 // GPIO direction register bit
	#define DP28_WR      LATBbits.LATB0 // GPIO port latch register bit
	#define DP28_RD      PORTBbits.RB0 // GPIO port register bit
	#define DP28_ODC     ODCBbits.ODCB0 // GPIO port open drain configuration register bit
	#define DP28_CNPU    CNPUBbits.CNPUB0 // GPIO port pull-up resistor register bit
	#define DP28_CNPD    CNPDBbits.CNPDB0 // GPIO port pull-down resistor register bit
	#define DP28_CNEN0   CNEN0Bbits.CNEN0B0 // GPIO port change notification Enable register bit
	#define DP28_CNSTAT  CNSTATBbits.CNSTATB0 // GPIO port change notification Status register bit
	#define DP28_CNEN1   CNEN1Bbits.CNEN1B0 // GPIO port change notification Edge Select Enable register bit
	#define DP28_CNF     CNFBbits.CNFB0 // GPIO port change notification flag bit register bit
	#define DP28_RP      32 // Number of Remappable Pin
	#define DP28_SET     { asm volatile ("bset _LATB, #0 \n"); }
	#define DP28_CLEAR   { asm volatile ("bclr _LATB, #0 \n"); }
	#define DP28_TOGGLE  { asm volatile ("btg  _LATB, #0 \n"); }
	#define DP28_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP28_ANSEL   _ANSELB0 // analog/digital pin configuration register bit
	#define DP28_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP28_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP28_ADC_AN_INPUT 5   // ANx input pin number
	#define DP28_ADCBUF  ADCBUF5 // ADC buffer register for this input
	#define DP28_ADC_ANIE ADIELbits.IE5
	#define DP28_ADC_ANEIE ADEIELbits.EIEN5
	#define DP28_ADC_IF   _ADCAN5IF // interrupt flag bit
	#define DP28_ADC_IE   _ADCAN5IE // interrupt enable bit
	#define DP28_ADC_IP   _ADCAN5IP // interrupt priority for this analog input
	#define DP28_ADC_RDY  _AN5RDY // ADC buffer ready bit
	#define _DP28_ADC_Interrupt _ADCAN5Interrupt
	#define DP28_INIT_ANALOG	{DP28_ANSEL = 1; DP28_WR = PINSTATE_HIGH; DP28_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP28_INIT_OUTPUT  {DP28_WR = PINSTATE_LOW; DP28_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP28_INIT_INPUT   {DP28_WR = PINSTATE_HIGH; DP28_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP29_TRIS    TRISBbits.TRISB1 // GPIO direction register bit
	#define DP29_WR      LATBbits.LATB1 // GPIO port latch register bit
	#define DP29_RD      PORTBbits.RB1 // GPIO port register bit
	#define DP29_ODC     ODCBbits.ODCB1 // GPIO port open drain configuration register bit
	#define DP29_CNPU    CNPUBbits.CNPUB1 // GPIO port pull-up resistor register bit
	#define DP29_CNPD    CNPDBbits.CNPDB1 // GPIO port pull-down resistor register bit
	#define DP29_CNEN0   CNEN0Bbits.CNEN0B1 // GPIO port change notification Enable register bit
	#define DP29_CNSTAT  CNSTATBbits.CNSTATB1 // GPIO port change notification Status register bit
	#define DP29_CNEN1   CNEN1Bbits.CNEN1B1 // GPIO port change notification Edge Select Enable register bit
	#define DP29_CNF     CNFBbits.CNFB1 // GPIO port change notification flag bit register bit
	#define DP29_RP      33 // Number of Remappable Pin
	#define DP29_SET     { asm volatile ("bset _LATB, #1 \n"); }
	#define DP29_CLEAR   { asm volatile ("bclr _LATB, #1 \n"); }
	#define DP29_TOGGLE  { asm volatile ("btg  _LATB, #1 \n"); }
	#define DP29_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP29_ANSEL   _ANSELB1 // analog/digital pin configuration register bit
	#define DP29_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP29_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP29_ADC_AN_INPUT 6   // ANx input pin number
	#define DP29_ADCBUF  ADCBUF6 // ADC buffer register for this input
	#define DP29_ADC_ANIE ADIELbits.IE6
	#define DP29_ADC_ANEIE ADEIELbits.EIEN6
	#define DP29_ADC_IF   _ADCAN6IF // interrupt flag bit
	#define DP29_ADC_IE   _ADCAN6IE // interrupt enable bit
	#define DP29_ADC_IP   _ADCAN6IP // interrupt priority for this analog input
	#define DP29_ADC_RDY  _AN6RDY // ADC buffer ready bit
	#define _DP29_ADC_Interrupt _ADCAN6Interrupt
	#define DP29_INIT_ANALOG	{DP29_ANSEL = 1; DP29_WR = PINSTATE_HIGH; DP29_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP29_INIT_OUTPUT  {DP29_WR = PINSTATE_LOW; DP29_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP29_INIT_INPUT   {DP29_WR = PINSTATE_HIGH; DP29_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP61_TRIS    TRISBbits.TRISB10 // GPIO direction register bit
	#define DP61_WR      LATBbits.LATB10 // GPIO port latch register bit
	#define DP61_RD      PORTBbits.RB10 // GPIO port register bit
	#define DP61_ODC     ODCBbits.ODCB10 // GPIO port open drain configuration register bit
	#define DP61_CNPU    CNPUBbits.CNPUB10 // GPIO port pull-up resistor register bit
	#define DP61_CNPD    CNPDBbits.CNPDB10 // GPIO port pull-down resistor register bit
	#define DP61_CNEN0   CNEN0Bbits.CNEN0B10 // GPIO port change notification Enable register bit
	#define DP61_CNSTAT  CNSTATBbits.CNSTATB10 // GPIO port change notification Status register bit
	#define DP61_CNEN1   CNEN1Bbits.CNEN1B10 // GPIO port change notification Edge Select Enable register bit
	#define DP61_CNF     CNFBbits.CNFB10 // GPIO port change notification flag bit register bit
	#define DP61_RP      42 // Number of Remappable Pin
	#define DP61_SET     { asm volatile ("bset _LATB, #10 \n"); }
	#define DP61_CLEAR   { asm volatile ("bclr _LATB, #10 \n"); }
	#define DP61_TOGGLE  { asm volatile ("btg  _LATB, #10 \n"); }
	#define DP61_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP61_INIT_OUTPUT  {DP61_WR = PINSTATE_LOW; DP61_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP61_INIT_INPUT   {DP61_WR = PINSTATE_HIGH; DP61_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP61_PGx_CHANNEL  3 // PWM channel index
	#define DP61_PGx_PER      PG3PER // PWM channel period register
	#define DP61_PGx_PHASE    PG3PHASE // PWM channel phase register
	#define DP61_PGx_DC       PG3DC // PWM channel duty cycle register
	#define DP61_PGx_OVRENH   PG3IOCONLbits.OVRENH // PWM channel IO config register override high control bit
	#define DP61_PGx_PENH     PG3IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
	#define DP61_PGxUPDREQ    PG3STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP61_PGxTRIGA     PG3TRIGA // PWM channel ADC trigger A register
	#define DP61_PGxTRIGB     PG3TRIGB // PWM channel ADC trigger A register
	#define DP61_PGxTRIGC     PG3TRIGC // PWM channel ADC trigger A register

	#define DP62_TRIS    TRISBbits.TRISB11 // GPIO direction register bit
	#define DP62_WR      LATBbits.LATB11 // GPIO port latch register bit
	#define DP62_RD      PORTBbits.RB11 // GPIO port register bit
	#define DP62_ODC     ODCBbits.ODCB11 // GPIO port open drain configuration register bit
	#define DP62_CNPU    CNPUBbits.CNPUB11 // GPIO port pull-up resistor register bit
	#define DP62_CNPD    CNPDBbits.CNPDB11 // GPIO port pull-down resistor register bit
	#define DP62_CNEN0   CNEN0Bbits.CNEN0B11 // GPIO port change notification Enable register bit
	#define DP62_CNSTAT  CNSTATBbits.CNSTATB11 // GPIO port change notification Status register bit
	#define DP62_CNEN1   CNEN1Bbits.CNEN1B11 // GPIO port change notification Edge Select Enable register bit
	#define DP62_CNF     CNFBbits.CNFB11 // GPIO port change notification flag bit register bit
	#define DP62_RP      43 // Number of Remappable Pin
	#define DP62_SET     { asm volatile ("bset _LATB, #11 \n"); }
	#define DP62_CLEAR   { asm volatile ("bclr _LATB, #11 \n"); }
	#define DP62_TOGGLE  { asm volatile ("btg  _LATB, #11 \n"); }
	#define DP62_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP62_INIT_OUTPUT  {DP62_WR = PINSTATE_LOW; DP62_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP62_INIT_INPUT   {DP62_WR = PINSTATE_HIGH; DP62_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP62_PGx_CHANNEL  3 // PWM channel index
	#define DP62_PGx_PER      PG3PER // PWM channel period register
	#define DP62_PGx_PHASE    PG3PHASE // PWM channel phase register
	#define DP62_PGx_DC       PG3DC // PWM channel duty cycle register
	#define DP62_PGx_OVRENL   PG3IOCONLbits.OVRENL // PWM channel IO config register override low control bit
	#define DP62_PGx_PENL     PG3IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
	#define DP62_PGxUPDREQ    PG3STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP62_PGxTRIGA     PG3TRIGA // PWM channel ADC trigger A register
	#define DP62_PGxTRIGB     PG3TRIGB // PWM channel ADC trigger A register
	#define DP62_PGxTRIGC     PG3TRIGC // PWM channel ADC trigger A register

	#define DP63_TRIS    TRISBbits.TRISB12 // GPIO direction register bit
	#define DP63_WR      LATBbits.LATB12 // GPIO port latch register bit
	#define DP63_RD      PORTBbits.RB12 // GPIO port register bit
	#define DP63_ODC     ODCBbits.ODCB12 // GPIO port open drain configuration register bit
	#define DP63_CNPU    CNPUBbits.CNPUB12 // GPIO port pull-up resistor register bit
	#define DP63_CNPD    CNPDBbits.CNPDB12 // GPIO port pull-down resistor register bit
	#define DP63_CNEN0   CNEN0Bbits.CNEN0B12 // GPIO port change notification Enable register bit
	#define DP63_CNSTAT  CNSTATBbits.CNSTATB12 // GPIO port change notification Status register bit
	#define DP63_CNEN1   CNEN1Bbits.CNEN1B12 // GPIO port change notification Edge Select Enable register bit
	#define DP63_CNF     CNFBbits.CNFB12 // GPIO port change notification flag bit register bit
	#define DP63_RP      44 // Number of Remappable Pin
	#define DP63_SET     { asm volatile ("bset _LATB, #12 \n"); }
	#define DP63_CLEAR   { asm volatile ("bclr _LATB, #12 \n"); }
	#define DP63_TOGGLE  { asm volatile ("btg  _LATB, #12 \n"); }
	#define DP63_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP63_INIT_OUTPUT  {DP63_WR = PINSTATE_LOW; DP63_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP63_INIT_INPUT   {DP63_WR = PINSTATE_HIGH; DP63_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP63_PGx_CHANNEL  2 // PWM channel index
	#define DP63_PGx_PER      PG2PER // PWM channel period register
	#define DP63_PGx_PHASE    PG2PHASE // PWM channel phase register
	#define DP63_PGx_DC       PG2DC // PWM channel duty cycle register
	#define DP63_PGx_OVRENH   PG2IOCONLbits.OVRENH // PWM channel IO config register override high control bit
	#define DP63_PGx_PENH     PG2IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
	#define DP63_PGxUPDREQ    PG2STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP63_PGxTRIGA     PG2TRIGA // PWM channel ADC trigger A register
	#define DP63_PGxTRIGB     PG2TRIGB // PWM channel ADC trigger A register
	#define DP63_PGxTRIGC     PG2TRIGC // PWM channel ADC trigger A register

	#define DP64_TRIS    TRISBbits.TRISB13 // GPIO direction register bit
	#define DP64_WR      LATBbits.LATB13 // GPIO port latch register bit
	#define DP64_RD      PORTBbits.RB13 // GPIO port register bit
	#define DP64_ODC     ODCBbits.ODCB13 // GPIO port open drain configuration register bit
	#define DP64_CNPU    CNPUBbits.CNPUB13 // GPIO port pull-up resistor register bit
	#define DP64_CNPD    CNPDBbits.CNPDB13 // GPIO port pull-down resistor register bit
	#define DP64_CNEN0   CNEN0Bbits.CNEN0B13 // GPIO port change notification Enable register bit
	#define DP64_CNSTAT  CNSTATBbits.CNSTATB13 // GPIO port change notification Status register bit
	#define DP64_CNEN1   CNEN1Bbits.CNEN1B13 // GPIO port change notification Edge Select Enable register bit
	#define DP64_CNF     CNFBbits.CNFB13 // GPIO port change notification flag bit register bit
	#define DP64_RP      45 // Number of Remappable Pin
	#define DP64_SET     { asm volatile ("bset _LATB, #13 \n"); }
	#define DP64_CLEAR   { asm volatile ("bclr _LATB, #13 \n"); }
	#define DP64_TOGGLE  { asm volatile ("btg  _LATB, #13 \n"); }
	#define DP64_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP64_INIT_OUTPUT  {DP64_WR = PINSTATE_LOW; DP64_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP64_INIT_INPUT   {DP64_WR = PINSTATE_HIGH; DP64_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP64_PGx_CHANNEL  2 // PWM channel index
	#define DP64_PGx_PER      PG2PER // PWM channel period register
	#define DP64_PGx_PHASE    PG2PHASE // PWM channel phase register
	#define DP64_PGx_DC       PG2DC // PWM channel duty cycle register
	#define DP64_PGx_OVRENL   PG2IOCONLbits.OVRENL // PWM channel IO config register override low control bit
	#define DP64_PGx_PENL     PG2IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
	#define DP64_PGxUPDREQ    PG2STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP64_PGxTRIGA     PG2TRIGA // PWM channel ADC trigger A register
	#define DP64_PGxTRIGB     PG2TRIGB // PWM channel ADC trigger A register
	#define DP64_PGxTRIGC     PG2TRIGC // PWM channel ADC trigger A register

	#define DP01_TRIS    TRISBbits.TRISB14 // GPIO direction register bit
	#define DP01_WR      LATBbits.LATB14 // GPIO port latch register bit
	#define DP01_RD      PORTBbits.RB14 // GPIO port register bit
	#define DP01_ODC     ODCBbits.ODCB14 // GPIO port open drain configuration register bit
	#define DP01_CNPU    CNPUBbits.CNPUB14 // GPIO port pull-up resistor register bit
	#define DP01_CNPD    CNPDBbits.CNPDB14 // GPIO port pull-down resistor register bit
	#define DP01_CNEN0   CNEN0Bbits.CNEN0B14 // GPIO port change notification Enable register bit
	#define DP01_CNSTAT  CNSTATBbits.CNSTATB14 // GPIO port change notification Status register bit
	#define DP01_CNEN1   CNEN1Bbits.CNEN1B14 // GPIO port change notification Edge Select Enable register bit
	#define DP01_CNF     CNFBbits.CNFB14 // GPIO port change notification flag bit register bit
	#define DP01_RP      46 // Number of Remappable Pin
	#define DP01_SET     { asm volatile ("bset _LATB, #14 \n"); }
	#define DP01_CLEAR   { asm volatile ("bclr _LATB, #14 \n"); }
	#define DP01_TOGGLE  { asm volatile ("btg  _LATB, #14 \n"); }
	#define DP01_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP01_INIT_OUTPUT  {DP01_WR = PINSTATE_LOW; DP01_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP01_INIT_INPUT   {DP01_WR = PINSTATE_HIGH; DP01_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP01_PGx_CHANNEL  1 // PWM channel index
	#define DP01_PGx_PER      PG1PER // PWM channel period register
	#define DP01_PGx_PHASE    PG1PHASE // PWM channel phase register
	#define DP01_PGx_DC       PG1DC // PWM channel duty cycle register
	#define DP01_PGx_OVRENH   PG1IOCONLbits.OVRENH // PWM channel IO config register override high control bit
	#define DP01_PGx_PENH     PG1IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
	#define DP01_PGxUPDREQ    PG1STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP01_PGxTRIGA     PG1TRIGA // PWM channel ADC trigger A register
	#define DP01_PGxTRIGB     PG1TRIGB // PWM channel ADC trigger A register
	#define DP01_PGxTRIGC     PG1TRIGC // PWM channel ADC trigger A register

	#define DP02_TRIS    TRISBbits.TRISB15 // GPIO direction register bit
	#define DP02_WR      LATBbits.LATB15 // GPIO port latch register bit
	#define DP02_RD      PORTBbits.RB15 // GPIO port register bit
	#define DP02_ODC     ODCBbits.ODCB15 // GPIO port open drain configuration register bit
	#define DP02_CNPU    CNPUBbits.CNPUB15 // GPIO port pull-up resistor register bit
	#define DP02_CNPD    CNPDBbits.CNPDB15 // GPIO port pull-down resistor register bit
	#define DP02_CNEN0   CNEN0Bbits.CNEN0B15 // GPIO port change notification Enable register bit
	#define DP02_CNSTAT  CNSTATBbits.CNSTATB15 // GPIO port change notification Status register bit
	#define DP02_CNEN1   CNEN1Bbits.CNEN1B15 // GPIO port change notification Edge Select Enable register bit
	#define DP02_CNF     CNFBbits.CNFB15 // GPIO port change notification flag bit register bit
	#define DP02_RP      47 // Number of Remappable Pin
	#define DP02_SET     { asm volatile ("bset _LATB, #15 \n"); }
	#define DP02_CLEAR   { asm volatile ("bclr _LATB, #15 \n"); }
	#define DP02_TOGGLE  { asm volatile ("btg  _LATB, #15 \n"); }
	#define DP02_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP02_INIT_OUTPUT  {DP02_WR = PINSTATE_LOW; DP02_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP02_INIT_INPUT   {DP02_WR = PINSTATE_HIGH; DP02_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP02_PGx_CHANNEL  1 // PWM channel index
	#define DP02_PGx_PER      PG1PER // PWM channel period register
	#define DP02_PGx_PHASE    PG1PHASE // PWM channel phase register
	#define DP02_PGx_DC       PG1DC // PWM channel duty cycle register
	#define DP02_PGx_OVRENL   PG1IOCONLbits.OVRENL // PWM channel IO config register override low control bit
	#define DP02_PGx_PENL     PG1IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
	#define DP02_PGxUPDREQ    PG1STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP02_PGxTRIGA     PG1TRIGA // PWM channel ADC trigger A register
	#define DP02_PGxTRIGB     PG1TRIGB // PWM channel ADC trigger A register
	#define DP02_PGxTRIGC     PG1TRIGC // PWM channel ADC trigger A register

	#define DP33_TRIS    TRISBbits.TRISB2 // GPIO direction register bit
	#define DP33_WR      LATBbits.LATB2 // GPIO port latch register bit
	#define DP33_RD      PORTBbits.RB2 // GPIO port register bit
	#define DP33_ODC     ODCBbits.ODCB2 // GPIO port open drain configuration register bit
	#define DP33_CNPU    CNPUBbits.CNPUB2 // GPIO port pull-up resistor register bit
	#define DP33_CNPD    CNPDBbits.CNPDB2 // GPIO port pull-down resistor register bit
	#define DP33_CNEN0   CNEN0Bbits.CNEN0B2 // GPIO port change notification Enable register bit
	#define DP33_CNSTAT  CNSTATBbits.CNSTATB2 // GPIO port change notification Status register bit
	#define DP33_CNEN1   CNEN1Bbits.CNEN1B2 // GPIO port change notification Edge Select Enable register bit
	#define DP33_CNF     CNFBbits.CNFB2 // GPIO port change notification flag bit register bit
	#define DP33_RP      34 // Number of Remappable Pin
	#define DP33_SET     { asm volatile ("bset _LATB, #2 \n"); }
	#define DP33_CLEAR   { asm volatile ("bclr _LATB, #2 \n"); }
	#define DP33_TOGGLE  { asm volatile ("btg  _LATB, #2 \n"); }
	#define DP33_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP33_ANSEL   _ANSELB2 // analog/digital pin configuration register bit
	#define DP33_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP33_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP33_ADC_AN_INPUT 7   // ANx input pin number
	#define DP33_ADCBUF  ADCBUF7 // ADC buffer register for this input
	#define DP33_ADC_ANIE ADIELbits.IE7
	#define DP33_ADC_ANEIE ADEIELbits.EIEN7
	#define DP33_ADC_IF   _ADCAN7IF // interrupt flag bit
	#define DP33_ADC_IE   _ADCAN7IE // interrupt enable bit
	#define DP33_ADC_IP   _ADCAN7IP // interrupt priority for this analog input
	#define DP33_ADC_RDY  _AN7RDY // ADC buffer ready bit
	#define _DP33_ADC_Interrupt _ADCAN7Interrupt
	#define DP33_INIT_ANALOG	{DP33_ANSEL = 1; DP33_WR = PINSTATE_HIGH; DP33_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP33_INIT_OUTPUT  {DP33_WR = PINSTATE_LOW; DP33_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP33_INIT_INPUT   {DP33_WR = PINSTATE_HIGH; DP33_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define PGD_TRIS    TRISBbits.TRISB3 // GPIO direction register bit
	#define PGD_WR      LATBbits.LATB3 // GPIO port latch register bit
	#define PGD_RD      PORTBbits.RB3 // GPIO port register bit
	#define PGD_ODC     ODCBbits.ODCB3 // GPIO port open drain configuration register bit
	#define PGD_CNPU    CNPUBbits.CNPUB3 // GPIO port pull-up resistor register bit
	#define PGD_CNPD    CNPDBbits.CNPDB3 // GPIO port pull-down resistor register bit
	#define PGD_CNEN0   CNEN0Bbits.CNEN0B3 // GPIO port change notification Enable register bit
	#define PGD_CNSTAT  CNSTATBbits.CNSTATB3 // GPIO port change notification Status register bit
	#define PGD_CNEN1   CNEN1Bbits.CNEN1B3 // GPIO port change notification Edge Select Enable register bit
	#define PGD_CNF     CNFBbits.CNFB3 // GPIO port change notification flag bit register bit
	#define PGD_RP      35 // Number of Remappable Pin
	#define PGD_SET     { asm volatile ("bset _LATB, #3 \n"); }
	#define PGD_CLEAR   { asm volatile ("bclr _LATB, #3 \n"); }
	#define PGD_TOGGLE  { asm volatile ("btg  _LATB, #3 \n"); }
	#define PGD_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define PGD_ANSEL   _ANSELB3 // analog/digital pin configuration register bit
	#define PGD_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define PGD_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define PGD_ADC_AN_INPUT 8   // ANx input pin number
	#define PGD_ADCBUF  ADCBUF8 // ADC buffer register for this input
	#define PGD_ADC_ANIE ADIELbits.IE8
	#define PGD_ADC_ANEIE ADEIELbits.EIEN8
	#define PGD_ADC_IF   _ADCAN8IF // interrupt flag bit
	#define PGD_ADC_IE   _ADCAN8IE // interrupt enable bit
	#define PGD_ADC_IP   _ADCAN8IP // interrupt priority for this analog input
	#define PGD_ADC_RDY  _AN8RDY // ADC buffer ready bit
	#define _PGD_ADC_Interrupt _ADCAN8Interrupt
	#define PGD_INIT_ANALOG	{PGD_ANSEL = 1; PGD_WR = PINSTATE_HIGH; PGD_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define PGD_INIT_OUTPUT  {PGD_WR = PINSTATE_LOW; PGD_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define PGD_INIT_INPUT   {PGD_WR = PINSTATE_HIGH; PGD_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define PGC_TRIS    TRISBbits.TRISB4 // GPIO direction register bit
	#define PGC_WR      LATBbits.LATB4 // GPIO port latch register bit
	#define PGC_RD      PORTBbits.RB4 // GPIO port register bit
	#define PGC_ODC     ODCBbits.ODCB4 // GPIO port open drain configuration register bit
	#define PGC_CNPU    CNPUBbits.CNPUB4 // GPIO port pull-up resistor register bit
	#define PGC_CNPD    CNPDBbits.CNPDB4 // GPIO port pull-down resistor register bit
	#define PGC_CNEN0   CNEN0Bbits.CNEN0B4 // GPIO port change notification Enable register bit
	#define PGC_CNSTAT  CNSTATBbits.CNSTATB4 // GPIO port change notification Status register bit
	#define PGC_CNEN1   CNEN1Bbits.CNEN1B4 // GPIO port change notification Edge Select Enable register bit
	#define PGC_CNF     CNFBbits.CNFB4 // GPIO port change notification flag bit register bit
	#define PGC_RP      36 // Number of Remappable Pin
	#define PGC_SET     { asm volatile ("bset _LATB, #4 \n"); }
	#define PGC_CLEAR   { asm volatile ("bclr _LATB, #4 \n"); }
	#define PGC_TOGGLE  { asm volatile ("btg  _LATB, #4 \n"); }
	#define PGC_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define PGC_INIT_OUTPUT  {PGC_WR = PINSTATE_LOW; PGC_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define PGC_INIT_INPUT   {PGC_WR = PINSTATE_HIGH; PGC_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define SDA_TRIS    TRISBbits.TRISB5 // GPIO direction register bit
	#define SDA_WR      LATBbits.LATB5 // GPIO port latch register bit
	#define SDA_RD      PORTBbits.RB5 // GPIO port register bit
	#define SDA_ODC     ODCBbits.ODCB5 // GPIO port open drain configuration register bit
	#define SDA_CNPU    CNPUBbits.CNPUB5 // GPIO port pull-up resistor register bit
	#define SDA_CNPD    CNPDBbits.CNPDB5 // GPIO port pull-down resistor register bit
	#define SDA_CNEN0   CNEN0Bbits.CNEN0B5 // GPIO port change notification Enable register bit
	#define SDA_CNSTAT  CNSTATBbits.CNSTATB5 // GPIO port change notification Status register bit
	#define SDA_CNEN1   CNEN1Bbits.CNEN1B5 // GPIO port change notification Edge Select Enable register bit
	#define SDA_CNF     CNFBbits.CNFB5 // GPIO port change notification flag bit register bit
	#define SDA_RP      37 // Number of Remappable Pin
	#define SDA_SET     { asm volatile ("bset _LATB, #5 \n"); }
	#define SDA_CLEAR   { asm volatile ("bclr _LATB, #5 \n"); }
	#define SDA_TOGGLE  { asm volatile ("btg  _LATB, #5 \n"); }
	#define SDA_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define SDA_INIT_OUTPUT  {SDA_WR = PINSTATE_LOW; SDA_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define SDA_INIT_INPUT   {SDA_WR = PINSTATE_HIGH; SDA_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define SCL_TRIS    TRISBbits.TRISB6 // GPIO direction register bit
	#define SCL_WR      LATBbits.LATB6 // GPIO port latch register bit
	#define SCL_RD      PORTBbits.RB6 // GPIO port register bit
	#define SCL_ODC     ODCBbits.ODCB6 // GPIO port open drain configuration register bit
	#define SCL_CNPU    CNPUBbits.CNPUB6 // GPIO port pull-up resistor register bit
	#define SCL_CNPD    CNPDBbits.CNPDB6 // GPIO port pull-down resistor register bit
	#define SCL_CNEN0   CNEN0Bbits.CNEN0B6 // GPIO port change notification Enable register bit
	#define SCL_CNSTAT  CNSTATBbits.CNSTATB6 // GPIO port change notification Status register bit
	#define SCL_CNEN1   CNEN1Bbits.CNEN1B6 // GPIO port change notification Edge Select Enable register bit
	#define SCL_CNF     CNFBbits.CNFB6 // GPIO port change notification flag bit register bit
	#define SCL_RP      38 // Number of Remappable Pin
	#define SCL_SET     { asm volatile ("bset _LATB, #6 \n"); }
	#define SCL_CLEAR   { asm volatile ("bclr _LATB, #6 \n"); }
	#define SCL_TOGGLE  { asm volatile ("btg  _LATB, #6 \n"); }
	#define SCL_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define SCL_INIT_OUTPUT  {SCL_WR = PINSTATE_LOW; SCL_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define SCL_INIT_INPUT   {SCL_WR = PINSTATE_HIGH; SCL_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP47_TRIS    TRISBbits.TRISB7 // GPIO direction register bit
	#define DP47_WR      LATBbits.LATB7 // GPIO port latch register bit
	#define DP47_RD      PORTBbits.RB7 // GPIO port register bit
	#define DP47_ODC     ODCBbits.ODCB7 // GPIO port open drain configuration register bit
	#define DP47_CNPU    CNPUBbits.CNPUB7 // GPIO port pull-up resistor register bit
	#define DP47_CNPD    CNPDBbits.CNPDB7 // GPIO port pull-down resistor register bit
	#define DP47_CNEN0   CNEN0Bbits.CNEN0B7 // GPIO port change notification Enable register bit
	#define DP47_CNSTAT  CNSTATBbits.CNSTATB7 // GPIO port change notification Status register bit
	#define DP47_CNEN1   CNEN1Bbits.CNEN1B7 // GPIO port change notification Edge Select Enable register bit
	#define DP47_CNF     CNFBbits.CNFB7 // GPIO port change notification flag bit register bit
	#define DP47_RP      39 // Number of Remappable Pin
	#define DP47_SET     { asm volatile ("bset _LATB, #7 \n"); }
	#define DP47_CLEAR   { asm volatile ("bclr _LATB, #7 \n"); }
	#define DP47_TOGGLE  { asm volatile ("btg  _LATB, #7 \n"); }
	#define DP47_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP47_ANSEL   _ANSELB7 // analog/digital pin configuration register bit
	#define DP47_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP47_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP47_ADC_AN_INPUT 9   // ANx input pin number
	#define DP47_ADCBUF  ADCBUF9 // ADC buffer register for this input
	#define DP47_ADC_ANIE ADIELbits.IE9
	#define DP47_ADC_ANEIE ADEIELbits.EIEN9
	#define DP47_ADC_IF   _ADCAN9IF // interrupt flag bit
	#define DP47_ADC_IE   _ADCAN9IE // interrupt enable bit
	#define DP47_ADC_IP   _ADCAN9IP // interrupt priority for this analog input
	#define DP47_ADC_RDY  _AN9RDY // ADC buffer ready bit
	#define _DP47_ADC_Interrupt _ADCAN9Interrupt
	#define DP47_INIT_ANALOG	{DP47_ANSEL = 1; DP47_WR = PINSTATE_HIGH; DP47_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP47_INIT_OUTPUT  {DP47_WR = PINSTATE_LOW; DP47_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP47_INIT_INPUT   {DP47_WR = PINSTATE_HIGH; DP47_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP48_TRIS    TRISBbits.TRISB8 // GPIO direction register bit
	#define DP48_WR      LATBbits.LATB8 // GPIO port latch register bit
	#define DP48_RD      PORTBbits.RB8 // GPIO port register bit
	#define DP48_ODC     ODCBbits.ODCB8 // GPIO port open drain configuration register bit
	#define DP48_CNPU    CNPUBbits.CNPUB8 // GPIO port pull-up resistor register bit
	#define DP48_CNPD    CNPDBbits.CNPDB8 // GPIO port pull-down resistor register bit
	#define DP48_CNEN0   CNEN0Bbits.CNEN0B8 // GPIO port change notification Enable register bit
	#define DP48_CNSTAT  CNSTATBbits.CNSTATB8 // GPIO port change notification Status register bit
	#define DP48_CNEN1   CNEN1Bbits.CNEN1B8 // GPIO port change notification Edge Select Enable register bit
	#define DP48_CNF     CNFBbits.CNFB8 // GPIO port change notification flag bit register bit
	#define DP48_RP      40 // Number of Remappable Pin
	#define DP48_SET     { asm volatile ("bset _LATB, #8 \n"); }
	#define DP48_CLEAR   { asm volatile ("bclr _LATB, #8 \n"); }
	#define DP48_TOGGLE  { asm volatile ("btg  _LATB, #8 \n"); }
	#define DP48_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP48_ANSEL   _ANSELB8 // analog/digital pin configuration register bit
	#define DP48_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP48_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP48_ADC_AN_INPUT 10   // ANx input pin number
	#define DP48_ADCBUF  ADCBUF10 // ADC buffer register for this input
	#define DP48_ADC_ANIE ADIELbits.IE10
	#define DP48_ADC_ANEIE ADEIELbits.EIEN10
	#define DP48_ADC_IF   _ADCAN10IF // interrupt flag bit
	#define DP48_ADC_IE   _ADCAN10IE // interrupt enable bit
	#define DP48_ADC_IP   _ADCAN10IP // interrupt priority for this analog input
	#define DP48_ADC_RDY  _AN10RDY // ADC buffer ready bit
	#define _DP48_ADC_Interrupt _ADCAN10Interrupt
	#define DP48_INIT_ANALOG	{DP48_ANSEL = 1; DP48_WR = PINSTATE_HIGH; DP48_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP48_INIT_OUTPUT  {DP48_WR = PINSTATE_LOW; DP48_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP48_INIT_INPUT   {DP48_WR = PINSTATE_HIGH; DP48_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP49_TRIS    TRISBbits.TRISB9 // GPIO direction register bit
	#define DP49_WR      LATBbits.LATB9 // GPIO port latch register bit
	#define DP49_RD      PORTBbits.RB9 // GPIO port register bit
	#define DP49_ODC     ODCBbits.ODCB9 // GPIO port open drain configuration register bit
	#define DP49_CNPU    CNPUBbits.CNPUB9 // GPIO port pull-up resistor register bit
	#define DP49_CNPD    CNPDBbits.CNPDB9 // GPIO port pull-down resistor register bit
	#define DP49_CNEN0   CNEN0Bbits.CNEN0B9 // GPIO port change notification Enable register bit
	#define DP49_CNSTAT  CNSTATBbits.CNSTATB9 // GPIO port change notification Status register bit
	#define DP49_CNEN1   CNEN1Bbits.CNEN1B9 // GPIO port change notification Edge Select Enable register bit
	#define DP49_CNF     CNFBbits.CNFB9 // GPIO port change notification flag bit register bit
	#define DP49_RP      41 // Number of Remappable Pin
	#define DP49_SET     { asm volatile ("bset _LATB, #9 \n"); }
	#define DP49_CLEAR   { asm volatile ("bclr _LATB, #9 \n"); }
	#define DP49_TOGGLE  { asm volatile ("btg  _LATB, #9 \n"); }
	#define DP49_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP49_ANSEL   _ANSELB9 // analog/digital pin configuration register bit
	#define DP49_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP49_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP49_ADC_AN_INPUT 11   // ANx input pin number
	#define DP49_ADCBUF  ADCBUF11 // ADC buffer register for this input
	#define DP49_ADC_ANIE ADIELbits.IE11
	#define DP49_ADC_ANEIE ADEIELbits.EIEN11
	#define DP49_ADC_IF   _ADCAN11IF // interrupt flag bit
	#define DP49_ADC_IE   _ADCAN11IE // interrupt enable bit
	#define DP49_ADC_IP   _ADCAN11IP // interrupt priority for this analog input
	#define DP49_ADC_RDY  _AN11RDY // ADC buffer ready bit
	#define _DP49_ADC_Interrupt _ADCAN11Interrupt
	#define DP49_INIT_ANALOG	{DP49_ANSEL = 1; DP49_WR = PINSTATE_HIGH; DP49_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP49_INIT_OUTPUT  {DP49_WR = PINSTATE_LOW; DP49_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP49_INIT_INPUT   {DP49_WR = PINSTATE_HIGH; DP49_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP13_TRIS    TRISCbits.TRISC0 // GPIO direction register bit
	#define DP13_WR      LATCbits.LATC0 // GPIO port latch register bit
	#define DP13_RD      PORTCbits.RC0 // GPIO port register bit
	#define DP13_ODC     ODCCbits.ODCC0 // GPIO port open drain configuration register bit
	#define DP13_CNPU    CNPUCbits.CNPUC0 // GPIO port pull-up resistor register bit
	#define DP13_CNPD    CNPDCbits.CNPDC0 // GPIO port pull-down resistor register bit
	#define DP13_CNEN0   CNEN0Cbits.CNEN0C0 // GPIO port change notification Enable register bit
	#define DP13_CNSTAT  CNSTATCbits.CNSTATC0 // GPIO port change notification Status register bit
	#define DP13_CNEN1   CNEN1Cbits.CNEN1C0 // GPIO port change notification Edge Select Enable register bit
	#define DP13_CNF     CNFCbits.CNFC0 // GPIO port change notification flag bit register bit
	#define DP13_RP      48 // Number of Remappable Pin
	#define DP13_SET     { asm volatile ("bset _LATC, #0 \n"); }
	#define DP13_CLEAR   { asm volatile ("bclr _LATC, #0 \n"); }
	#define DP13_TOGGLE  { asm volatile ("btg  _LATC, #0 \n"); }
	#define DP13_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP13_ANSEL   _ANSELC0 // analog/digital pin configuration register bit
	#define DP13_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP13_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP13_ADC_AN_INPUT 12   // ANx input pin number
	#define DP13_ADCBUF  ADCBUF12 // ADC buffer register for this input
	#define DP13_ADC_ANIE ADIELbits.IE12
	#define DP13_ADC_ANEIE ADEIELbits.EIEN12
	#define DP13_ADC_IF   _ADCAN12IF // interrupt flag bit
	#define DP13_ADC_IE   _ADCAN12IE // interrupt enable bit
	#define DP13_ADC_IP   _ADCAN12IP // interrupt priority for this analog input
	#define DP13_ADC_RDY  _AN12RDY // ADC buffer ready bit
	#define _DP13_ADC_Interrupt _ADCAN12Interrupt
	#define DP13_INIT_ANALOG	{DP13_ANSEL = 1; DP13_WR = PINSTATE_HIGH; DP13_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP13_INIT_OUTPUT  {DP13_WR = PINSTATE_LOW; DP13_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP13_INIT_INPUT   {DP13_WR = PINSTATE_HIGH; DP13_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP22_TRIS    TRISCbits.TRISC1 // GPIO direction register bit
	#define DP22_WR      LATCbits.LATC1 // GPIO port latch register bit
	#define DP22_RD      PORTCbits.RC1 // GPIO port register bit
	#define DP22_ODC     ODCCbits.ODCC1 // GPIO port open drain configuration register bit
	#define DP22_CNPU    CNPUCbits.CNPUC1 // GPIO port pull-up resistor register bit
	#define DP22_CNPD    CNPDCbits.CNPDC1 // GPIO port pull-down resistor register bit
	#define DP22_CNEN0   CNEN0Cbits.CNEN0C1 // GPIO port change notification Enable register bit
	#define DP22_CNSTAT  CNSTATCbits.CNSTATC1 // GPIO port change notification Status register bit
	#define DP22_CNEN1   CNEN1Cbits.CNEN1C1 // GPIO port change notification Edge Select Enable register bit
	#define DP22_CNF     CNFCbits.CNFC1 // GPIO port change notification flag bit register bit
	#define DP22_RP      49 // Number of Remappable Pin
	#define DP22_SET     { asm volatile ("bset _LATC, #1 \n"); }
	#define DP22_CLEAR   { asm volatile ("bclr _LATC, #1 \n"); }
	#define DP22_TOGGLE  { asm volatile ("btg  _LATC, #1 \n"); }
	#define DP22_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP22_ANSEL   _ANSELC1 // analog/digital pin configuration register bit
	#define DP22_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP22_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP22_ADC_AN_INPUT 13   // ANx input pin number
	#define DP22_ADCBUF  ADCBUF13 // ADC buffer register for this input
	#define DP22_ADC_ANIE ADIELbits.IE13
	#define DP22_ADC_ANEIE ADEIELbits.EIEN13
	#define DP22_ADC_IF   _ADCAN13IF // interrupt flag bit
	#define DP22_ADC_IE   _ADCAN13IE // interrupt enable bit
	#define DP22_ADC_IP   _ADCAN13IP // interrupt priority for this analog input
	#define DP22_ADC_RDY  _AN13RDY // ADC buffer ready bit
	#define _DP22_ADC_Interrupt _ADCAN13Interrupt
	#define DP22_INIT_ANALOG	{DP22_ANSEL = 1; DP22_WR = PINSTATE_HIGH; DP22_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP22_INIT_OUTPUT  {DP22_WR = PINSTATE_LOW; DP22_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP22_INIT_INPUT   {DP22_WR = PINSTATE_HIGH; DP22_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP52_TRIS    TRISCbits.TRISC10 // GPIO direction register bit
	#define DP52_WR      LATCbits.LATC10 // GPIO port latch register bit
	#define DP52_RD      PORTCbits.RC10 // GPIO port register bit
	#define DP52_ODC     ODCCbits.ODCC10 // GPIO port open drain configuration register bit
	#define DP52_CNPU    CNPUCbits.CNPUC10 // GPIO port pull-up resistor register bit
	#define DP52_CNPD    CNPDCbits.CNPDC10 // GPIO port pull-down resistor register bit
	#define DP52_CNEN0   CNEN0Cbits.CNEN0C10 // GPIO port change notification Enable register bit
	#define DP52_CNSTAT  CNSTATCbits.CNSTATC10 // GPIO port change notification Status register bit
	#define DP52_CNEN1   CNEN1Cbits.CNEN1C10 // GPIO port change notification Edge Select Enable register bit
	#define DP52_CNF     CNFCbits.CNFC10 // GPIO port change notification flag bit register bit
	#define DP52_RP      58 // Number of Remappable Pin
	#define DP52_SET     { asm volatile ("bset _LATC, #10 \n"); }
	#define DP52_CLEAR   { asm volatile ("bclr _LATC, #10 \n"); }
	#define DP52_TOGGLE  { asm volatile ("btg  _LATC, #10 \n"); }
	#define DP52_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP52_INIT_OUTPUT  {DP52_WR = PINSTATE_LOW; DP52_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP52_INIT_INPUT   {DP52_WR = PINSTATE_HIGH; DP52_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP53_TRIS    TRISCbits.TRISC11 // GPIO direction register bit
	#define DP53_WR      LATCbits.LATC11 // GPIO port latch register bit
	#define DP53_RD      PORTCbits.RC11 // GPIO port register bit
	#define DP53_ODC     ODCCbits.ODCC11 // GPIO port open drain configuration register bit
	#define DP53_CNPU    CNPUCbits.CNPUC11 // GPIO port pull-up resistor register bit
	#define DP53_CNPD    CNPDCbits.CNPDC11 // GPIO port pull-down resistor register bit
	#define DP53_CNEN0   CNEN0Cbits.CNEN0C11 // GPIO port change notification Enable register bit
	#define DP53_CNSTAT  CNSTATCbits.CNSTATC11 // GPIO port change notification Status register bit
	#define DP53_CNEN1   CNEN1Cbits.CNEN1C11 // GPIO port change notification Edge Select Enable register bit
	#define DP53_CNF     CNFCbits.CNFC11 // GPIO port change notification flag bit register bit
	#define DP53_RP      59 // Number of Remappable Pin
	#define DP53_SET     { asm volatile ("bset _LATC, #11 \n"); }
	#define DP53_CLEAR   { asm volatile ("bclr _LATC, #11 \n"); }
	#define DP53_TOGGLE  { asm volatile ("btg  _LATC, #11 \n"); }
	#define DP53_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP53_INIT_OUTPUT  {DP53_WR = PINSTATE_LOW; DP53_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP53_INIT_INPUT   {DP53_WR = PINSTATE_HIGH; DP53_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP03_TRIS    TRISCbits.TRISC12 // GPIO direction register bit
	#define DP03_WR      LATCbits.LATC12 // GPIO port latch register bit
	#define DP03_RD      PORTCbits.RC12 // GPIO port register bit
	#define DP03_ODC     ODCCbits.ODCC12 // GPIO port open drain configuration register bit
	#define DP03_CNPU    CNPUCbits.CNPUC12 // GPIO port pull-up resistor register bit
	#define DP03_CNPD    CNPDCbits.CNPDC12 // GPIO port pull-down resistor register bit
	#define DP03_CNEN0   CNEN0Cbits.CNEN0C12 // GPIO port change notification Enable register bit
	#define DP03_CNSTAT  CNSTATCbits.CNSTATC12 // GPIO port change notification Status register bit
	#define DP03_CNEN1   CNEN1Cbits.CNEN1C12 // GPIO port change notification Edge Select Enable register bit
	#define DP03_CNF     CNFCbits.CNFC12 // GPIO port change notification flag bit register bit
	#define DP03_RP      60 // Number of Remappable Pin
	#define DP03_SET     { asm volatile ("bset _LATC, #12 \n"); }
	#define DP03_CLEAR   { asm volatile ("bclr _LATC, #12 \n"); }
	#define DP03_TOGGLE  { asm volatile ("btg  _LATC, #12 \n"); }
	#define DP03_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP03_INIT_OUTPUT  {DP03_WR = PINSTATE_LOW; DP03_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP03_INIT_INPUT   {DP03_WR = PINSTATE_HIGH; DP03_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP03_PGx_CHANNEL  4 // PWM channel index
	#define DP03_PGx_PER      PG4PER // PWM channel period register
	#define DP03_PGx_PHASE    PG4PHASE // PWM channel phase register
	#define DP03_PGx_DC       PG4DC // PWM channel duty cycle register
	#define DP03_PGx_OVRENH   PG4IOCONLbits.OVRENH // PWM channel IO config register override high control bit
	#define DP03_PGx_PENH     PG4IOCONLbits.PENH // PWM channel IO config register pin enable high control bit
	#define DP03_PGxUPDREQ    PG4STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP03_PGxTRIGA     PG4TRIGA // PWM channel ADC trigger A register
	#define DP03_PGxTRIGB     PG4TRIGB // PWM channel ADC trigger A register
	#define DP03_PGxTRIGC     PG4TRIGC // PWM channel ADC trigger A register

	#define DP04_TRIS    TRISCbits.TRISC13 // GPIO direction register bit
	#define DP04_WR      LATCbits.LATC13 // GPIO port latch register bit
	#define DP04_RD      PORTCbits.RC13 // GPIO port register bit
	#define DP04_ODC     ODCCbits.ODCC13 // GPIO port open drain configuration register bit
	#define DP04_CNPU    CNPUCbits.CNPUC13 // GPIO port pull-up resistor register bit
	#define DP04_CNPD    CNPDCbits.CNPDC13 // GPIO port pull-down resistor register bit
	#define DP04_CNEN0   CNEN0Cbits.CNEN0C13 // GPIO port change notification Enable register bit
	#define DP04_CNSTAT  CNSTATCbits.CNSTATC13 // GPIO port change notification Status register bit
	#define DP04_CNEN1   CNEN1Cbits.CNEN1C13 // GPIO port change notification Edge Select Enable register bit
	#define DP04_CNF     CNFCbits.CNFC13 // GPIO port change notification flag bit register bit
	#define DP04_RP      61 // Number of Remappable Pin
	#define DP04_SET     { asm volatile ("bset _LATC, #13 \n"); }
	#define DP04_CLEAR   { asm volatile ("bclr _LATC, #13 \n"); }
	#define DP04_TOGGLE  { asm volatile ("btg  _LATC, #13 \n"); }
	#define DP04_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP04_INIT_OUTPUT  {DP04_WR = PINSTATE_LOW; DP04_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP04_INIT_INPUT   {DP04_WR = PINSTATE_HIGH; DP04_TRIS = PINDIR_INPUT;} // initialization macro for digital input
	#define DP04_PGx_CHANNEL  4 // PWM channel index
	#define DP04_PGx_PER      PG4PER // PWM channel period register
	#define DP04_PGx_PHASE    PG4PHASE // PWM channel phase register
	#define DP04_PGx_DC       PG4DC // PWM channel duty cycle register
	#define DP04_PGx_OVRENL   PG4IOCONLbits.OVRENL // PWM channel IO config register override low control bit
	#define DP04_PGx_PENL     PG4IOCONLbits.PENL // PWM channel IO config register pin enable low control bit
	#define DP04_PGxUPDREQ    PG4STATbits.UPDREQ // PWM channel ADC trigger A register
	#define DP04_PGxTRIGA     PG4TRIGA // PWM channel ADC trigger A register
	#define DP04_PGxTRIGB     PG4TRIGB // PWM channel ADC trigger A register
	#define DP04_PGxTRIGC     PG4TRIGC // PWM channel ADC trigger A register

	#define UART_TX_TRIS    TRISCbits.TRISC14 // GPIO direction register bit
	#define UART_TX_WR      LATCbits.LATC14 // GPIO port latch register bit
	#define UART_TX_RD      PORTCbits.RC14 // GPIO port register bit
	#define UART_TX_ODC     ODCCbits.ODCC14 // GPIO port open drain configuration register bit
	#define UART_TX_CNPU    CNPUCbits.CNPUC14 // GPIO port pull-up resistor register bit
	#define UART_TX_CNPD    CNPDCbits.CNPDC14 // GPIO port pull-down resistor register bit
	#define UART_TX_CNEN0   CNEN0Cbits.CNEN0C14 // GPIO port change notification Enable register bit
	#define UART_TX_CNSTAT  CNSTATCbits.CNSTATC14 // GPIO port change notification Status register bit
	#define UART_TX_CNEN1   CNEN1Cbits.CNEN1C14 // GPIO port change notification Edge Select Enable register bit
	#define UART_TX_CNF     CNFCbits.CNFC14 // GPIO port change notification flag bit register bit
	#define UART_TX_RP      62 // Number of Remappable Pin
	#define UART_TX_SET     { asm volatile ("bset _LATC, #14 \n"); }
	#define UART_TX_CLEAR   { asm volatile ("bclr _LATC, #14 \n"); }
	#define UART_TX_TOGGLE  { asm volatile ("btg  _LATC, #14 \n"); }
	#define UART_TX_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define UART_TX_INIT_OUTPUT  {UART_TX_WR = PINSTATE_LOW; UART_TX_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define UART_TX_INIT_INPUT   {UART_TX_WR = PINSTATE_HIGH; UART_TX_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define UART_RX_TRIS    TRISCbits.TRISC15 // GPIO direction register bit
	#define UART_RX_WR      LATCbits.LATC15 // GPIO port latch register bit
	#define UART_RX_RD      PORTCbits.RC15 // GPIO port register bit
	#define UART_RX_ODC     ODCCbits.ODCC15 // GPIO port open drain configuration register bit
	#define UART_RX_CNPU    CNPUCbits.CNPUC15 // GPIO port pull-up resistor register bit
	#define UART_RX_CNPD    CNPDCbits.CNPDC15 // GPIO port pull-down resistor register bit
	#define UART_RX_CNEN0   CNEN0Cbits.CNEN0C15 // GPIO port change notification Enable register bit
	#define UART_RX_CNSTAT  CNSTATCbits.CNSTATC15 // GPIO port change notification Status register bit
	#define UART_RX_CNEN1   CNEN1Cbits.CNEN1C15 // GPIO port change notification Edge Select Enable register bit
	#define UART_RX_CNF     CNFCbits.CNFC15 // GPIO port change notification flag bit register bit
	#define UART_RX_RP      63 // Number of Remappable Pin
	#define UART_RX_SET     { asm volatile ("bset _LATC, #15 \n"); }
	#define UART_RX_CLEAR   { asm volatile ("bclr _LATC, #15 \n"); }
	#define UART_RX_TOGGLE  { asm volatile ("btg  _LATC, #15 \n"); }
	#define UART_RX_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define UART_RX_INIT_OUTPUT  {UART_RX_WR = PINSTATE_LOW; UART_RX_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define UART_RX_INIT_INPUT   {UART_RX_WR = PINSTATE_HIGH; UART_RX_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP23_TRIS    TRISCbits.TRISC2 // GPIO direction register bit
	#define DP23_WR      LATCbits.LATC2 // GPIO port latch register bit
	#define DP23_RD      PORTCbits.RC2 // GPIO port register bit
	#define DP23_ODC     ODCCbits.ODCC2 // GPIO port open drain configuration register bit
	#define DP23_CNPU    CNPUCbits.CNPUC2 // GPIO port pull-up resistor register bit
	#define DP23_CNPD    CNPDCbits.CNPDC2 // GPIO port pull-down resistor register bit
	#define DP23_CNEN0   CNEN0Cbits.CNEN0C2 // GPIO port change notification Enable register bit
	#define DP23_CNSTAT  CNSTATCbits.CNSTATC2 // GPIO port change notification Status register bit
	#define DP23_CNEN1   CNEN1Cbits.CNEN1C2 // GPIO port change notification Edge Select Enable register bit
	#define DP23_CNF     CNFCbits.CNFC2 // GPIO port change notification flag bit register bit
	#define DP23_RP      50 // Number of Remappable Pin
	#define DP23_SET     { asm volatile ("bset _LATC, #2 \n"); }
	#define DP23_CLEAR   { asm volatile ("bclr _LATC, #2 \n"); }
	#define DP23_TOGGLE  { asm volatile ("btg  _LATC, #2 \n"); }
	#define DP23_IS_ANALOG_INPUT  1 // Pin is/is not analog input 
	#define DP23_ANSEL   _ANSELC2 // analog/digital pin configuration register bit
	#define DP23_ADCCORE 0 // index starts from zero, last index indicated shared adC core
	#define DP23_IS_SHARED_CORE true // AN input is routed to a dedicated or shared ACD core
	#define DP23_ADC_AN_INPUT 14   // ANx input pin number
	#define DP23_ADCBUF  ADCBUF14 // ADC buffer register for this input
	#define DP23_ADC_ANIE ADIELbits.IE14
	#define DP23_ADC_ANEIE ADEIELbits.EIEN14
	#define DP23_ADC_IF   _ADCAN14IF // interrupt flag bit
	#define DP23_ADC_IE   _ADCAN14IE // interrupt enable bit
	#define DP23_ADC_IP   _ADCAN14IP // interrupt priority for this analog input
	#define DP23_ADC_RDY  _AN14RDY // ADC buffer ready bit
	#define _DP23_ADC_Interrupt _ADCAN14Interrupt
	#define DP23_INIT_ANALOG	{DP23_ANSEL = 1; DP23_WR = PINSTATE_HIGH; DP23_TRIS = PINDIR_INPUT;} // initialization macro for analog input
	#define DP23_INIT_OUTPUT  {DP23_WR = PINSTATE_LOW; DP23_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP23_INIT_INPUT   {DP23_WR = PINSTATE_HIGH; DP23_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP27_TRIS    TRISCbits.TRISC3 // GPIO direction register bit
	#define DP27_WR      LATCbits.LATC3 // GPIO port latch register bit
	#define DP27_RD      PORTCbits.RC3 // GPIO port register bit
	#define DP27_ODC     ODCCbits.ODCC3 // GPIO port open drain configuration register bit
	#define DP27_CNPU    CNPUCbits.CNPUC3 // GPIO port pull-up resistor register bit
	#define DP27_CNPD    CNPDCbits.CNPDC3 // GPIO port pull-down resistor register bit
	#define DP27_CNEN0   CNEN0Cbits.CNEN0C3 // GPIO port change notification Enable register bit
	#define DP27_CNSTAT  CNSTATCbits.CNSTATC3 // GPIO port change notification Status register bit
	#define DP27_CNEN1   CNEN1Cbits.CNEN1C3 // GPIO port change notification Edge Select Enable register bit
	#define DP27_CNF     CNFCbits.CNFC3 // GPIO port change notification flag bit register bit
	#define DP27_RP      51 // Number of Remappable Pin
	#define DP27_SET     { asm volatile ("bset _LATC, #3 \n"); }
	#define DP27_CLEAR   { asm volatile ("bclr _LATC, #3 \n"); }
	#define DP27_TOGGLE  { asm volatile ("btg  _LATC, #3 \n"); }
	#define DP27_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP27_INIT_OUTPUT  {DP27_WR = PINSTATE_LOW; DP27_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP27_INIT_INPUT   {DP27_WR = PINSTATE_HIGH; DP27_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP50_TRIS    TRISCbits.TRISC4 // GPIO direction register bit
	#define DP50_WR      LATCbits.LATC4 // GPIO port latch register bit
	#define DP50_RD      PORTCbits.RC4 // GPIO port register bit
	#define DP50_ODC     ODCCbits.ODCC4 // GPIO port open drain configuration register bit
	#define DP50_CNPU    CNPUCbits.CNPUC4 // GPIO port pull-up resistor register bit
	#define DP50_CNPD    CNPDCbits.CNPDC4 // GPIO port pull-down resistor register bit
	#define DP50_CNEN0   CNEN0Cbits.CNEN0C4 // GPIO port change notification Enable register bit
	#define DP50_CNSTAT  CNSTATCbits.CNSTATC4 // GPIO port change notification Status register bit
	#define DP50_CNEN1   CNEN1Cbits.CNEN1C4 // GPIO port change notification Edge Select Enable register bit
	#define DP50_CNF     CNFCbits.CNFC4 // GPIO port change notification flag bit register bit
	#define DP50_RP      52 // Number of Remappable Pin
	#define DP50_SET     { asm volatile ("bset _LATC, #4 \n"); }
	#define DP50_CLEAR   { asm volatile ("bclr _LATC, #4 \n"); }
	#define DP50_TOGGLE  { asm volatile ("btg  _LATC, #4 \n"); }
	#define DP50_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP50_INIT_OUTPUT  {DP50_WR = PINSTATE_LOW; DP50_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP50_INIT_INPUT   {DP50_WR = PINSTATE_HIGH; DP50_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP51_TRIS    TRISCbits.TRISC5 // GPIO direction register bit
	#define DP51_WR      LATCbits.LATC5 // GPIO port latch register bit
	#define DP51_RD      PORTCbits.RC5 // GPIO port register bit
	#define DP51_ODC     ODCCbits.ODCC5 // GPIO port open drain configuration register bit
	#define DP51_CNPU    CNPUCbits.CNPUC5 // GPIO port pull-up resistor register bit
	#define DP51_CNPD    CNPDCbits.CNPDC5 // GPIO port pull-down resistor register bit
	#define DP51_CNEN0   CNEN0Cbits.CNEN0C5 // GPIO port change notification Enable register bit
	#define DP51_CNSTAT  CNSTATCbits.CNSTATC5 // GPIO port change notification Status register bit
	#define DP51_CNEN1   CNEN1Cbits.CNEN1C5 // GPIO port change notification Edge Select Enable register bit
	#define DP51_CNF     CNFCbits.CNFC5 // GPIO port change notification flag bit register bit
	#define DP51_RP      53 // Number of Remappable Pin
	#define DP51_SET     { asm volatile ("bset _LATC, #5 \n"); }
	#define DP51_CLEAR   { asm volatile ("bclr _LATC, #5 \n"); }
	#define DP51_TOGGLE  { asm volatile ("btg  _LATC, #5 \n"); }
	#define DP51_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP51_INIT_OUTPUT  {DP51_WR = PINSTATE_LOW; DP51_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP51_INIT_INPUT   {DP51_WR = PINSTATE_HIGH; DP51_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP24_TRIS    TRISCbits.TRISC6 // GPIO direction register bit
	#define DP24_WR      LATCbits.LATC6 // GPIO port latch register bit
	#define DP24_RD      PORTCbits.RC6 // GPIO port register bit
	#define DP24_ODC     ODCCbits.ODCC6 // GPIO port open drain configuration register bit
	#define DP24_CNPU    CNPUCbits.CNPUC6 // GPIO port pull-up resistor register bit
	#define DP24_CNPD    CNPDCbits.CNPDC6 // GPIO port pull-down resistor register bit
	#define DP24_CNEN0   CNEN0Cbits.CNEN0C6 // GPIO port change notification Enable register bit
	#define DP24_CNSTAT  CNSTATCbits.CNSTATC6 // GPIO port change notification Status register bit
	#define DP24_CNEN1   CNEN1Cbits.CNEN1C6 // GPIO port change notification Edge Select Enable register bit
	#define DP24_CNF     CNFCbits.CNFC6 // GPIO port change notification flag bit register bit
	#define DP24_RP      54 // Number of Remappable Pin
	#define DP24_SET     { asm volatile ("bset _LATC, #6 \n"); }
	#define DP24_CLEAR   { asm volatile ("bclr _LATC, #6 \n"); }
	#define DP24_TOGGLE  { asm volatile ("btg  _LATC, #6 \n"); }
	#define DP24_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP24_INIT_OUTPUT  {DP24_WR = PINSTATE_LOW; DP24_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP24_INIT_INPUT   {DP24_WR = PINSTATE_HIGH; DP24_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP32_TRIS    TRISCbits.TRISC7 // GPIO direction register bit
	#define DP32_WR      LATCbits.LATC7 // GPIO port latch register bit
	#define DP32_RD      PORTCbits.RC7 // GPIO port register bit
	#define DP32_ODC     ODCCbits.ODCC7 // GPIO port open drain configuration register bit
	#define DP32_CNPU    CNPUCbits.CNPUC7 // GPIO port pull-up resistor register bit
	#define DP32_CNPD    CNPDCbits.CNPDC7 // GPIO port pull-down resistor register bit
	#define DP32_CNEN0   CNEN0Cbits.CNEN0C7 // GPIO port change notification Enable register bit
	#define DP32_CNSTAT  CNSTATCbits.CNSTATC7 // GPIO port change notification Status register bit
	#define DP32_CNEN1   CNEN1Cbits.CNEN1C7 // GPIO port change notification Edge Select Enable register bit
	#define DP32_CNF     CNFCbits.CNFC7 // GPIO port change notification flag bit register bit
	#define DP32_RP      55 // Number of Remappable Pin
	#define DP32_SET     { asm volatile ("bset _LATC, #7 \n"); }
	#define DP32_CLEAR   { asm volatile ("bclr _LATC, #7 \n"); }
	#define DP32_TOGGLE  { asm volatile ("btg  _LATC, #7 \n"); }
	#define DP32_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP32_INIT_OUTPUT  {DP32_WR = PINSTATE_LOW; DP32_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP32_INIT_INPUT   {DP32_WR = PINSTATE_HIGH; DP32_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP36_TRIS    TRISCbits.TRISC8 // GPIO direction register bit
	#define DP36_WR      LATCbits.LATC8 // GPIO port latch register bit
	#define DP36_RD      PORTCbits.RC8 // GPIO port register bit
	#define DP36_ODC     ODCCbits.ODCC8 // GPIO port open drain configuration register bit
	#define DP36_CNPU    CNPUCbits.CNPUC8 // GPIO port pull-up resistor register bit
	#define DP36_CNPD    CNPDCbits.CNPDC8 // GPIO port pull-down resistor register bit
	#define DP36_CNEN0   CNEN0Cbits.CNEN0C8 // GPIO port change notification Enable register bit
	#define DP36_CNSTAT  CNSTATCbits.CNSTATC8 // GPIO port change notification Status register bit
	#define DP36_CNEN1   CNEN1Cbits.CNEN1C8 // GPIO port change notification Edge Select Enable register bit
	#define DP36_CNF     CNFCbits.CNFC8 // GPIO port change notification flag bit register bit
	#define DP36_RP      56 // Number of Remappable Pin
	#define DP36_SET     { asm volatile ("bset _LATC, #8 \n"); }
	#define DP36_CLEAR   { asm volatile ("bclr _LATC, #8 \n"); }
	#define DP36_TOGGLE  { asm volatile ("btg  _LATC, #8 \n"); }
	#define DP36_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP36_INIT_OUTPUT  {DP36_WR = PINSTATE_LOW; DP36_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP36_INIT_INPUT   {DP36_WR = PINSTATE_HIGH; DP36_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP37_TRIS    TRISCbits.TRISC9 // GPIO direction register bit
	#define DP37_WR      LATCbits.LATC9 // GPIO port latch register bit
	#define DP37_RD      PORTCbits.RC9 // GPIO port register bit
	#define DP37_ODC     ODCCbits.ODCC9 // GPIO port open drain configuration register bit
	#define DP37_CNPU    CNPUCbits.CNPUC9 // GPIO port pull-up resistor register bit
	#define DP37_CNPD    CNPDCbits.CNPDC9 // GPIO port pull-down resistor register bit
	#define DP37_CNEN0   CNEN0Cbits.CNEN0C9 // GPIO port change notification Enable register bit
	#define DP37_CNSTAT  CNSTATCbits.CNSTATC9 // GPIO port change notification Status register bit
	#define DP37_CNEN1   CNEN1Cbits.CNEN1C9 // GPIO port change notification Edge Select Enable register bit
	#define DP37_CNF     CNFCbits.CNFC9 // GPIO port change notification flag bit register bit
	#define DP37_RP      57 // Number of Remappable Pin
	#define DP37_SET     { asm volatile ("bset _LATC, #9 \n"); }
	#define DP37_CLEAR   { asm volatile ("bclr _LATC, #9 \n"); }
	#define DP37_TOGGLE  { asm volatile ("btg  _LATC, #9 \n"); }
	#define DP37_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP37_INIT_OUTPUT  {DP37_WR = PINSTATE_LOW; DP37_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP37_INIT_INPUT   {DP37_WR = PINSTATE_HIGH; DP37_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP60_TRIS    TRISDbits.TRISD0 // GPIO direction register bit
	#define DP60_WR      LATDbits.LATD0 // GPIO port latch register bit
	#define DP60_RD      PORTDbits.RD0 // GPIO port register bit
	#define DP60_ODC     ODCDbits.ODCD0 // GPIO port open drain configuration register bit
	#define DP60_CNPU    CNPUDbits.CNPUD0 // GPIO port pull-up resistor register bit
	#define DP60_CNPD    CNPDDbits.CNPDD0 // GPIO port pull-down resistor register bit
	#define DP60_CNEN0   CNEN0Dbits.CNEN0D0 // GPIO port change notification Enable register bit
	#define DP60_CNSTAT  CNSTATDbits.CNSTATD0 // GPIO port change notification Status register bit
	#define DP60_CNEN1   CNEN1Dbits.CNEN1D0 // GPIO port change notification Edge Select Enable register bit
	#define DP60_CNF     CNFDbits.CNFD0 // GPIO port change notification flag bit register bit
	#define DP60_RP      64 // Number of Remappable Pin
	#define DP60_SET     { asm volatile ("bset _LATD, #0 \n"); }
	#define DP60_CLEAR   { asm volatile ("bclr _LATD, #0 \n"); }
	#define DP60_TOGGLE  { asm volatile ("btg  _LATD, #0 \n"); }
	#define DP60_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP60_INIT_OUTPUT  {DP60_WR = PINSTATE_LOW; DP60_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP60_INIT_INPUT   {DP60_WR = PINSTATE_HIGH; DP60_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP59_TRIS    TRISDbits.TRISD1 // GPIO direction register bit
	#define DP59_WR      LATDbits.LATD1 // GPIO port latch register bit
	#define DP59_RD      PORTDbits.RD1 // GPIO port register bit
	#define DP59_ODC     ODCDbits.ODCD1 // GPIO port open drain configuration register bit
	#define DP59_CNPU    CNPUDbits.CNPUD1 // GPIO port pull-up resistor register bit
	#define DP59_CNPD    CNPDDbits.CNPDD1 // GPIO port pull-down resistor register bit
	#define DP59_CNEN0   CNEN0Dbits.CNEN0D1 // GPIO port change notification Enable register bit
	#define DP59_CNSTAT  CNSTATDbits.CNSTATD1 // GPIO port change notification Status register bit
	#define DP59_CNEN1   CNEN1Dbits.CNEN1D1 // GPIO port change notification Edge Select Enable register bit
	#define DP59_CNF     CNFDbits.CNFD1 // GPIO port change notification flag bit register bit
	#define DP59_RP      65 // Number of Remappable Pin
	#define DP59_SET     { asm volatile ("bset _LATD, #1 \n"); }
	#define DP59_CLEAR   { asm volatile ("bclr _LATD, #1 \n"); }
	#define DP59_TOGGLE  { asm volatile ("btg  _LATD, #1 \n"); }
	#define DP59_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP59_INIT_OUTPUT  {DP59_WR = PINSTATE_LOW; DP59_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP59_INIT_INPUT   {DP59_WR = PINSTATE_HIGH; DP59_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP31_TRIS    TRISDbits.TRISD10 // GPIO direction register bit
	#define DP31_WR      LATDbits.LATD10 // GPIO port latch register bit
	#define DP31_RD      PORTDbits.RD10 // GPIO port register bit
	#define DP31_ODC     ODCDbits.ODCD10 // GPIO port open drain configuration register bit
	#define DP31_CNPU    CNPUDbits.CNPUD10 // GPIO port pull-up resistor register bit
	#define DP31_CNPD    CNPDDbits.CNPDD10 // GPIO port pull-down resistor register bit
	#define DP31_CNEN0   CNEN0Dbits.CNEN0D10 // GPIO port change notification Enable register bit
	#define DP31_CNSTAT  CNSTATDbits.CNSTATD10 // GPIO port change notification Status register bit
	#define DP31_CNEN1   CNEN1Dbits.CNEN1D10 // GPIO port change notification Edge Select Enable register bit
	#define DP31_CNF     CNFDbits.CNFD10 // GPIO port change notification flag bit register bit
	#define DP31_SET     { asm volatile ("bset _LATD, #10 \n"); }
	#define DP31_CLEAR   { asm volatile ("bclr _LATD, #10 \n"); }
	#define DP31_TOGGLE  { asm volatile ("btg  _LATD, #10 \n"); }
	#define DP31_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP31_INIT_OUTPUT  {DP31_WR = PINSTATE_LOW; DP31_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP31_INIT_INPUT   {DP31_WR = PINSTATE_HIGH; DP31_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP30_TRIS    TRISDbits.TRISD11 // GPIO direction register bit
	#define DP30_WR      LATDbits.LATD11 // GPIO port latch register bit
	#define DP30_RD      PORTDbits.RD11 // GPIO port register bit
	#define DP30_ODC     ODCDbits.ODCD11 // GPIO port open drain configuration register bit
	#define DP30_CNPU    CNPUDbits.CNPUD11 // GPIO port pull-up resistor register bit
	#define DP30_CNPD    CNPDDbits.CNPDD11 // GPIO port pull-down resistor register bit
	#define DP30_CNEN0   CNEN0Dbits.CNEN0D11 // GPIO port change notification Enable register bit
	#define DP30_CNSTAT  CNSTATDbits.CNSTATD11 // GPIO port change notification Status register bit
	#define DP30_CNEN1   CNEN1Dbits.CNEN1D11 // GPIO port change notification Edge Select Enable register bit
	#define DP30_CNF     CNFDbits.CNFD11 // GPIO port change notification flag bit register bit
	#define DP30_SET     { asm volatile ("bset _LATD, #11 \n"); }
	#define DP30_CLEAR   { asm volatile ("bclr _LATD, #11 \n"); }
	#define DP30_TOGGLE  { asm volatile ("btg  _LATD, #11 \n"); }
	#define DP30_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP30_INIT_OUTPUT  {DP30_WR = PINSTATE_LOW; DP30_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP30_INIT_INPUT   {DP30_WR = PINSTATE_HIGH; DP30_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP21_TRIS    TRISDbits.TRISD12 // GPIO direction register bit
	#define DP21_WR      LATDbits.LATD12 // GPIO port latch register bit
	#define DP21_RD      PORTDbits.RD12 // GPIO port register bit
	#define DP21_ODC     ODCDbits.ODCD12 // GPIO port open drain configuration register bit
	#define DP21_CNPU    CNPUDbits.CNPUD12 // GPIO port pull-up resistor register bit
	#define DP21_CNPD    CNPDDbits.CNPDD12 // GPIO port pull-down resistor register bit
	#define DP21_CNEN0   CNEN0Dbits.CNEN0D12 // GPIO port change notification Enable register bit
	#define DP21_CNSTAT  CNSTATDbits.CNSTATD12 // GPIO port change notification Status register bit
	#define DP21_CNEN1   CNEN1Dbits.CNEN1D12 // GPIO port change notification Edge Select Enable register bit
	#define DP21_CNF     CNFDbits.CNFD12 // GPIO port change notification flag bit register bit
	#define DP21_SET     { asm volatile ("bset _LATD, #12 \n"); }
	#define DP21_CLEAR   { asm volatile ("bclr _LATD, #12 \n"); }
	#define DP21_TOGGLE  { asm volatile ("btg  _LATD, #12 \n"); }
	#define DP21_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP21_INIT_OUTPUT  {DP21_WR = PINSTATE_LOW; DP21_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP21_INIT_INPUT   {DP21_WR = PINSTATE_HIGH; DP21_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DBGPIN_TRIS    TRISDbits.TRISD13 // GPIO direction register bit
	#define DBGPIN_WR      LATDbits.LATD13 // GPIO port latch register bit
	#define DBGPIN_RD      PORTDbits.RD13 // GPIO port register bit
	#define DBGPIN_ODC     ODCDbits.ODCD13 // GPIO port open drain configuration register bit
	#define DBGPIN_CNPU    CNPUDbits.CNPUD13 // GPIO port pull-up resistor register bit
	#define DBGPIN_CNPD    CNPDDbits.CNPDD13 // GPIO port pull-down resistor register bit
	#define DBGPIN_CNEN0   CNEN0Dbits.CNEN0D13 // GPIO port change notification Enable register bit
	#define DBGPIN_CNSTAT  CNSTATDbits.CNSTATD13 // GPIO port change notification Status register bit
	#define DBGPIN_CNEN1   CNEN1Dbits.CNEN1D13 // GPIO port change notification Edge Select Enable register bit
	#define DBGPIN_CNF     CNFDbits.CNFD13 // GPIO port change notification flag bit register bit
	#define DBGPIN_SET     { asm volatile ("bset _LATD, #13 \n"); }
	#define DBGPIN_CLEAR   { asm volatile ("bclr _LATD, #13 \n"); }
	#define DBGPIN_TOGGLE  { asm volatile ("btg  _LATD, #13 \n"); }
	#define DBGPIN_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DBGPIN_INIT_OUTPUT  {DBGPIN_WR = PINSTATE_LOW; DBGPIN_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DBGPIN_INIT_INPUT   {DBGPIN_WR = PINSTATE_HIGH; DBGPIN_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP11_TRIS    TRISDbits.TRISD14 // GPIO direction register bit
	#define DP11_WR      LATDbits.LATD14 // GPIO port latch register bit
	#define DP11_RD      PORTDbits.RD14 // GPIO port register bit
	#define DP11_ODC     ODCDbits.ODCD14 // GPIO port open drain configuration register bit
	#define DP11_CNPU    CNPUDbits.CNPUD14 // GPIO port pull-up resistor register bit
	#define DP11_CNPD    CNPDDbits.CNPDD14 // GPIO port pull-down resistor register bit
	#define DP11_CNEN0   CNEN0Dbits.CNEN0D14 // GPIO port change notification Enable register bit
	#define DP11_CNSTAT  CNSTATDbits.CNSTATD14 // GPIO port change notification Status register bit
	#define DP11_CNEN1   CNEN1Dbits.CNEN1D14 // GPIO port change notification Edge Select Enable register bit
	#define DP11_CNF     CNFDbits.CNFD14 // GPIO port change notification flag bit register bit
	#define DP11_SET     { asm volatile ("bset _LATD, #14 \n"); }
	#define DP11_CLEAR   { asm volatile ("bclr _LATD, #14 \n"); }
	#define DP11_TOGGLE  { asm volatile ("btg  _LATD, #14 \n"); }
	#define DP11_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP11_INIT_OUTPUT  {DP11_WR = PINSTATE_LOW; DP11_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP11_INIT_INPUT   {DP11_WR = PINSTATE_HIGH; DP11_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DBGLED_TRIS    TRISDbits.TRISD15 // GPIO direction register bit
	#define DBGLED_WR      LATDbits.LATD15 // GPIO port latch register bit
	#define DBGLED_RD      PORTDbits.RD15 // GPIO port register bit
	#define DBGLED_ODC     ODCDbits.ODCD15 // GPIO port open drain configuration register bit
	#define DBGLED_CNPU    CNPUDbits.CNPUD15 // GPIO port pull-up resistor register bit
	#define DBGLED_CNPD    CNPDDbits.CNPDD15 // GPIO port pull-down resistor register bit
	#define DBGLED_CNEN0   CNEN0Dbits.CNEN0D15 // GPIO port change notification Enable register bit
	#define DBGLED_CNSTAT  CNSTATDbits.CNSTATD15 // GPIO port change notification Status register bit
	#define DBGLED_CNEN1   CNEN1Dbits.CNEN1D15 // GPIO port change notification Edge Select Enable register bit
	#define DBGLED_CNF     CNFDbits.CNFD15 // GPIO port change notification flag bit register bit
	#define DBGLED_SET     { asm volatile ("bset _LATD, #15 \n"); }
	#define DBGLED_CLEAR   { asm volatile ("bclr _LATD, #15 \n"); }
	#define DBGLED_TOGGLE  { asm volatile ("btg  _LATD, #15 \n"); }
	#define DBGLED_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DBGLED_INIT_OUTPUT  {DBGLED_WR = PINSTATE_LOW; DBGLED_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DBGLED_INIT_INPUT   {DBGLED_WR = PINSTATE_HIGH; DBGLED_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP58_TRIS    TRISDbits.TRISD2 // GPIO direction register bit
	#define DP58_WR      LATDbits.LATD2 // GPIO port latch register bit
	#define DP58_RD      PORTDbits.RD2 // GPIO port register bit
	#define DP58_ODC     ODCDbits.ODCD2 // GPIO port open drain configuration register bit
	#define DP58_CNPU    CNPUDbits.CNPUD2 // GPIO port pull-up resistor register bit
	#define DP58_CNPD    CNPDDbits.CNPDD2 // GPIO port pull-down resistor register bit
	#define DP58_CNEN0   CNEN0Dbits.CNEN0D2 // GPIO port change notification Enable register bit
	#define DP58_CNSTAT  CNSTATDbits.CNSTATD2 // GPIO port change notification Status register bit
	#define DP58_CNEN1   CNEN1Dbits.CNEN1D2 // GPIO port change notification Edge Select Enable register bit
	#define DP58_CNF     CNFDbits.CNFD2 // GPIO port change notification flag bit register bit
	#define DP58_RP      66 // Number of Remappable Pin
	#define DP58_SET     { asm volatile ("bset _LATD, #2 \n"); }
	#define DP58_CLEAR   { asm volatile ("bclr _LATD, #2 \n"); }
	#define DP58_TOGGLE  { asm volatile ("btg  _LATD, #2 \n"); }
	#define DP58_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP58_INIT_OUTPUT  {DP58_WR = PINSTATE_LOW; DP58_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP58_INIT_INPUT   {DP58_WR = PINSTATE_HIGH; DP58_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP55_TRIS    TRISDbits.TRISD3 // GPIO direction register bit
	#define DP55_WR      LATDbits.LATD3 // GPIO port latch register bit
	#define DP55_RD      PORTDbits.RD3 // GPIO port register bit
	#define DP55_ODC     ODCDbits.ODCD3 // GPIO port open drain configuration register bit
	#define DP55_CNPU    CNPUDbits.CNPUD3 // GPIO port pull-up resistor register bit
	#define DP55_CNPD    CNPDDbits.CNPDD3 // GPIO port pull-down resistor register bit
	#define DP55_CNEN0   CNEN0Dbits.CNEN0D3 // GPIO port change notification Enable register bit
	#define DP55_CNSTAT  CNSTATDbits.CNSTATD3 // GPIO port change notification Status register bit
	#define DP55_CNEN1   CNEN1Dbits.CNEN1D3 // GPIO port change notification Edge Select Enable register bit
	#define DP55_CNF     CNFDbits.CNFD3 // GPIO port change notification flag bit register bit
	#define DP55_RP      67 // Number of Remappable Pin
	#define DP55_SET     { asm volatile ("bset _LATD, #3 \n"); }
	#define DP55_CLEAR   { asm volatile ("bclr _LATD, #3 \n"); }
	#define DP55_TOGGLE  { asm volatile ("btg  _LATD, #3 \n"); }
	#define DP55_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP55_INIT_OUTPUT  {DP55_WR = PINSTATE_LOW; DP55_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP55_INIT_INPUT   {DP55_WR = PINSTATE_HIGH; DP55_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP54_TRIS    TRISDbits.TRISD4 // GPIO direction register bit
	#define DP54_WR      LATDbits.LATD4 // GPIO port latch register bit
	#define DP54_RD      PORTDbits.RD4 // GPIO port register bit
	#define DP54_ODC     ODCDbits.ODCD4 // GPIO port open drain configuration register bit
	#define DP54_CNPU    CNPUDbits.CNPUD4 // GPIO port pull-up resistor register bit
	#define DP54_CNPD    CNPDDbits.CNPDD4 // GPIO port pull-down resistor register bit
	#define DP54_CNEN0   CNEN0Dbits.CNEN0D4 // GPIO port change notification Enable register bit
	#define DP54_CNSTAT  CNSTATDbits.CNSTATD4 // GPIO port change notification Status register bit
	#define DP54_CNEN1   CNEN1Dbits.CNEN1D4 // GPIO port change notification Edge Select Enable register bit
	#define DP54_CNF     CNFDbits.CNFD4 // GPIO port change notification flag bit register bit
	#define DP54_RP      68 // Number of Remappable Pin
	#define DP54_SET     { asm volatile ("bset _LATD, #4 \n"); }
	#define DP54_CLEAR   { asm volatile ("bclr _LATD, #4 \n"); }
	#define DP54_TOGGLE  { asm volatile ("btg  _LATD, #4 \n"); }
	#define DP54_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP54_INIT_OUTPUT  {DP54_WR = PINSTATE_LOW; DP54_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP54_INIT_INPUT   {DP54_WR = PINSTATE_HIGH; DP54_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP44_TRIS    TRISDbits.TRISD5 // GPIO direction register bit
	#define DP44_WR      LATDbits.LATD5 // GPIO port latch register bit
	#define DP44_RD      PORTDbits.RD5 // GPIO port register bit
	#define DP44_ODC     ODCDbits.ODCD5 // GPIO port open drain configuration register bit
	#define DP44_CNPU    CNPUDbits.CNPUD5 // GPIO port pull-up resistor register bit
	#define DP44_CNPD    CNPDDbits.CNPDD5 // GPIO port pull-down resistor register bit
	#define DP44_CNEN0   CNEN0Dbits.CNEN0D5 // GPIO port change notification Enable register bit
	#define DP44_CNSTAT  CNSTATDbits.CNSTATD5 // GPIO port change notification Status register bit
	#define DP44_CNEN1   CNEN1Dbits.CNEN1D5 // GPIO port change notification Edge Select Enable register bit
	#define DP44_CNF     CNFDbits.CNFD5 // GPIO port change notification flag bit register bit
	#define DP44_RP      69 // Number of Remappable Pin
	#define DP44_SET     { asm volatile ("bset _LATD, #5 \n"); }
	#define DP44_CLEAR   { asm volatile ("bclr _LATD, #5 \n"); }
	#define DP44_TOGGLE  { asm volatile ("btg  _LATD, #5 \n"); }
	#define DP44_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP44_INIT_OUTPUT  {DP44_WR = PINSTATE_LOW; DP44_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP44_INIT_INPUT   {DP44_WR = PINSTATE_HIGH; DP44_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP43_TRIS    TRISDbits.TRISD6 // GPIO direction register bit
	#define DP43_WR      LATDbits.LATD6 // GPIO port latch register bit
	#define DP43_RD      PORTDbits.RD6 // GPIO port register bit
	#define DP43_ODC     ODCDbits.ODCD6 // GPIO port open drain configuration register bit
	#define DP43_CNPU    CNPUDbits.CNPUD6 // GPIO port pull-up resistor register bit
	#define DP43_CNPD    CNPDDbits.CNPDD6 // GPIO port pull-down resistor register bit
	#define DP43_CNEN0   CNEN0Dbits.CNEN0D6 // GPIO port change notification Enable register bit
	#define DP43_CNSTAT  CNSTATDbits.CNSTATD6 // GPIO port change notification Status register bit
	#define DP43_CNEN1   CNEN1Dbits.CNEN1D6 // GPIO port change notification Edge Select Enable register bit
	#define DP43_CNF     CNFDbits.CNFD6 // GPIO port change notification flag bit register bit
	#define DP43_RP      70 // Number of Remappable Pin
	#define DP43_SET     { asm volatile ("bset _LATD, #6 \n"); }
	#define DP43_CLEAR   { asm volatile ("bclr _LATD, #6 \n"); }
	#define DP43_TOGGLE  { asm volatile ("btg  _LATD, #6 \n"); }
	#define DP43_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP43_INIT_OUTPUT  {DP43_WR = PINSTATE_LOW; DP43_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP43_INIT_INPUT   {DP43_WR = PINSTATE_HIGH; DP43_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP42_TRIS    TRISDbits.TRISD7 // GPIO direction register bit
	#define DP42_WR      LATDbits.LATD7 // GPIO port latch register bit
	#define DP42_RD      PORTDbits.RD7 // GPIO port register bit
	#define DP42_ODC     ODCDbits.ODCD7 // GPIO port open drain configuration register bit
	#define DP42_CNPU    CNPUDbits.CNPUD7 // GPIO port pull-up resistor register bit
	#define DP42_CNPD    CNPDDbits.CNPDD7 // GPIO port pull-down resistor register bit
	#define DP42_CNEN0   CNEN0Dbits.CNEN0D7 // GPIO port change notification Enable register bit
	#define DP42_CNSTAT  CNSTATDbits.CNSTATD7 // GPIO port change notification Status register bit
	#define DP42_CNEN1   CNEN1Dbits.CNEN1D7 // GPIO port change notification Edge Select Enable register bit
	#define DP42_CNF     CNFDbits.CNFD7 // GPIO port change notification flag bit register bit
	#define DP42_RP      71 // Number of Remappable Pin
	#define DP42_SET     { asm volatile ("bset _LATD, #7 \n"); }
	#define DP42_CLEAR   { asm volatile ("bclr _LATD, #7 \n"); }
	#define DP42_TOGGLE  { asm volatile ("btg  _LATD, #7 \n"); }
	#define DP42_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP42_INIT_OUTPUT  {DP42_WR = PINSTATE_LOW; DP42_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP42_INIT_INPUT   {DP42_WR = PINSTATE_HIGH; DP42_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP39_TRIS    TRISDbits.TRISD8 // GPIO direction register bit
	#define DP39_WR      LATDbits.LATD8 // GPIO port latch register bit
	#define DP39_RD      PORTDbits.RD8 // GPIO port register bit
	#define DP39_ODC     ODCDbits.ODCD8 // GPIO port open drain configuration register bit
	#define DP39_CNPU    CNPUDbits.CNPUD8 // GPIO port pull-up resistor register bit
	#define DP39_CNPD    CNPDDbits.CNPDD8 // GPIO port pull-down resistor register bit
	#define DP39_CNEN0   CNEN0Dbits.CNEN0D8 // GPIO port change notification Enable register bit
	#define DP39_CNSTAT  CNSTATDbits.CNSTATD8 // GPIO port change notification Status register bit
	#define DP39_CNEN1   CNEN1Dbits.CNEN1D8 // GPIO port change notification Edge Select Enable register bit
	#define DP39_CNF     CNFDbits.CNFD8 // GPIO port change notification flag bit register bit
	#define DP39_SET     { asm volatile ("bset _LATD, #8 \n"); }
	#define DP39_CLEAR   { asm volatile ("bclr _LATD, #8 \n"); }
	#define DP39_TOGGLE  { asm volatile ("btg  _LATD, #8 \n"); }
	#define DP39_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP39_INIT_OUTPUT  {DP39_WR = PINSTATE_LOW; DP39_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP39_INIT_INPUT   {DP39_WR = PINSTATE_HIGH; DP39_TRIS = PINDIR_INPUT;} // initialization macro for digital input

	#define DP38_TRIS    TRISDbits.TRISD9 // GPIO direction register bit
	#define DP38_WR      LATDbits.LATD9 // GPIO port latch register bit
	#define DP38_RD      PORTDbits.RD9 // GPIO port register bit
	#define DP38_ODC     ODCDbits.ODCD9 // GPIO port open drain configuration register bit
	#define DP38_CNPU    CNPUDbits.CNPUD9 // GPIO port pull-up resistor register bit
	#define DP38_CNPD    CNPDDbits.CNPDD9 // GPIO port pull-down resistor register bit
	#define DP38_CNEN0   CNEN0Dbits.CNEN0D9 // GPIO port change notification Enable register bit
	#define DP38_CNSTAT  CNSTATDbits.CNSTATD9 // GPIO port change notification Status register bit
	#define DP38_CNEN1   CNEN1Dbits.CNEN1D9 // GPIO port change notification Edge Select Enable register bit
	#define DP38_CNF     CNFDbits.CNFD9 // GPIO port change notification flag bit register bit
	#define DP38_SET     { asm volatile ("bset _LATD, #9 \n"); }
	#define DP38_CLEAR   { asm volatile ("bclr _LATD, #9 \n"); }
	#define DP38_TOGGLE  { asm volatile ("btg  _LATD, #9 \n"); }
	#define DP38_IS_ANALOG_INPUT  0 // Pin is/is not analog input 
	#define DP38_INIT_OUTPUT  {DP38_WR = PINSTATE_LOW; DP38_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
	#define DP38_INIT_INPUT   {DP38_WR = PINSTATE_HIGH; DP38_TRIS = PINDIR_INPUT;} // initialization macro for digital input

#elif defined (__P33SMPS_CH_SLV1__)



#endif

#endif/* _MYBOARD_RXX_PINMAP_H_ */

