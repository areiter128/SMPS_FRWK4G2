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
/* @@UserStartupCode.c
 *****************************************************************************
 * File:   UserStartupCode.c
 *
 * Summary:
 * Highly application and hardware specific user startup-code extension
 *
 * Description:	
 * Some designs require immediate actions after device reset like fast recovery
 * after power brown-out or to set a state of a certain, external peripheral circuit
 * such as an auxiliary power supply, before any other function can be enabled.
 * 
 * This code module will be called right after the DEVICE_Reset function call and only
 * if the user option EXECUTE_USER_STARTUP_CODE in the header file apl.h is set to 1 
 *
 * References:
 * -
 *
 * See also:
 * 
 * Revision history: 
 * 04/10/19     Initial version
 * Author: M91406
 * Comments:
 *****************************************************************************/


#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "apl/apl.h"
#include "hal/hal.h"
#include "mcal/mcal.h"

uint16_t ExecuteUserStartupCode(void) {


    /* *********************************************************************************
     * Place user code required for a proper system startup here
     * Please make sure any polling functions are protected.
     * The following example turns on an auxiliary power supply and 
     * waits until the POWER GOOD output is set
     * *********************************************************************************

    volatile uint16_t timeout = 0;

    
    // Power Supply Converter control signals
    AUXPWR_OK_DETECT_INIT_INPUT; // configure AUXPWR_OK_DETECT control pin as input
    EN_AUXPWR_INIT_OUTPUT; // configure EN_AUXPWR control pin as output
    EN_AUXPWR_CNPU = 1;    // enable/disable internal weak pull-up resistor
    EN_AUXPWR_ODC = 1;     // enable/disable open drain configuration

    // Enable Aux Power Supply
    EN_AUXPWR_SET;          // Set IC enable pin HIGH

    // Poll for POWER_GOOD signal to be set by external auxiliary power circuit
    while(AUXPWR_OK_DETECT_RD == 0 && EN_AUXPWR_RD == 1 && timeout < AUX_POWER_GOOD_TIMEOUT)
    {
        timeout++;  // Increment timeout counter
    };


    if ((timeout >= AUXPWR_OK_TIMEOUT) || (AUXPWR_OK_DETECT_RD == 0))
    {
        return(0);  // auxiliary power supply did not start as expected = failure
    }
    else{
        return(1);  // auxiliary power supply did start as expected = success
    }
    */
    
    return(1);
}
