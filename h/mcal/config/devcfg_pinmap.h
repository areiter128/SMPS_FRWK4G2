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

/* 
 * File:        devcfg_pinmap.h
 * Author:      M91406
 * Comments:    Hardware abstraction layer for various daughter cards
 * Revision history: 1.0    (initial release)
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef _DEVICE_CONFIGURATION_PINMAP_H
#define	_DEVICE_CONFIGURATION_PINMAP_H

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef __00124_R02_EP806__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 0.2
  #include "00124_R02_EP806_pinmap.h"
#endif
#ifdef __00124_R10_EP806__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 1.0
  #include "00124_R10_EP806_pinmap.h"
#endif
#ifdef __00124_R11_EP806__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 1.1
  #include "00124_R11_EP806_pinmap.h"
#endif
#ifdef __00133_R30_MP506__
// dsPIC33CH128MP506 Digital Power Plug-In Module, Version 3.0
  #include "00133_R30_MP506_pinmap.h"
#endif
#ifdef __00146_R10_MP506__
// dsPIC33EP128GS806 Digital Power Plug-In Module, Version 0.2
  #include "00124_R02_EP806_pinmap.h"
#endif


#endif	/* _DEVICE_CONFIGURATION_PINMAP_H */

