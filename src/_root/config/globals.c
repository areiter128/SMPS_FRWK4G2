/*LICENSE ********************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
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
 * ***************************************************************************/

/*@@globals.c
 * ***********************************************************************************************
 * File:   globals.c
 * Author: M91406
 * 
 * Summary:
 * Global variables are declared here
 * 
 * Description:
 * Global variables, function prototypes and other declarations are declared in this file. These
 * declarations will be referenced in globals.h to make them accessible by other parts of the 
 * firmware.
 * 
 * History:
 * 08/11/2015	File created				
 * ***********************************************************************************************/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "_root/config/globals.h"


/* ***********************************************************************************************
 * DECLARATIONS
 * ***********************************************************************************************/
volatile uint16_t run_main_loop = 1;     // Flag used to reset the main loop, forcing a warm reset when set != 1

#if __DEBUG
volatile uint16_t task_time_buffer[CPU_LOAD_DEBUG_BUFFER_LENGTH];
volatile uint16_t cpu_time_buffer[CPU_LOAD_DEBUG_BUFFER_LENGTH];
#endif

/* ***********************************************************************************************
 * PROTOTYPES
 * ***********************************************************************************************/


// EOF
