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
/* @@main.c
 * ****************************************************************************
 * File:   main.c
 * Author: M91406
 *
 * Description:
 * This code example has been created to introduce the functionality of the
 * basic SMPS firmware framework v4. This project uses the basic function call
 * based scheduler to group, align and monitor user tasks. 
 * 
 * The procedure shown in this examples initializes the internal oscillator and 
 * the task scheduler and then immediately launches the scheduler. During the 
 * start-up phase of the controller, configuration of peripherals are also 
 * executed within the active scheduler monitoring & control scheme to be able
 * to respond to errors during the configuration process. This specific aspect
 * is only available if peripheral libraries are used. 
 * If MCC is used to set up the peripherals, the function call SYSTEM_Initialize()
 * will call the MCC generated configuration instead and the operating mode 
 * OP_MODE_BOOT used in this example project needs to be bypassed.
 * 
 * 
 * History:
 * Created on July 03, 2017, 09:32 PM
 ******************************************************************************/

#include "_root/config/globals.h"   // globals.h also include the 4-layer headers for 
                                    //   - Application Layer (APL)
                                    //   - Hardware Abstraction Layer (HAL)
                                    //   - Microcontroller Abstraction Layer (MCAL)
                                    //   - Special Function Layer (SFL)
#include "_root/generic/task_manager.h"
#include "apl/config/tasks.h"

int main(void) {

#if (USE_TASK_MANAGER_TIMING_DEBUG_ARRAYS == 1)
    volatile uint16_t cnt=0;
#endif
    volatile uint16_t fres = 0;
    

    // Right after system reset, first check for root-cause of previous device reset
    fres = CheckCPUResetRootCause();

    // Initialize essential chip features and peripheral modules to boot up system
    fres &= Device_Reset();

    // The User Startup Code might be required in some designs to enable 
    #if (EXECUTE_USER_STARTUP_CODE == 1)
    fres &= ExecuteUserStartupCode();
    #endif
    
    // Initialize essential chip features and peripheral modules to boot up system
    fres &= SYSTEM_Initialize();

    // Initialize software layers (scheduler and essential user tasks)
    fres &= OS_Initialize();

    // after the basic steps, the rest of the configuration runs as part of the scheduler,
    // where execution can be monitored and faults can be properly handled.
    while (run_main_loop) 
    {

        // Wait for timer to expire before calling the next task
        while (
           !(*task_mgr.reg_task_timer_irq_flag & task_mgr.task_timer_irq_flag_mask)
            && (task_mgr.cpu_load.ticks != task_mgr.task_time_ctrl.quota)
            )
        {
            // Increment CPU tick counter
            task_mgr.cpu_load.ticks++;
        }

#if (USE_TASK_EXECUTION_CLOCKOUT_PIN == 1)
#ifdef TS_CLOCKOUT_PIN_WR
    TS_CLOCKOUT_PIN_WR = PINSTATE_HIGH;                  // Drive debug pin high
#endif
#endif

        // CPU Meter Fault Trigger for CPU Load Lockout Check
        if(task_mgr.cpu_load.ticks >= task_mgr.task_time_ctrl.quota){
            // When this error condition has been detected, something went wrong with
            // the timer interrupt bit (oscillator, timer or interrupt controller is corrupted)
            // => Immediate reconfiguration and firmware initialization is required

            task_mgr.op_mode.mode = OP_MODE_BOOT;                               // Boot mode will force re-config
            task_mgr.task_queue_tick_index = (task_mgr.task_queue_ubound + 1);    // setting index to maximum will trip op_mode switch

        }
        else    // Task scheduling is running as expected => Continue with next task
        {   
            task_mgr.cpu_load.ticks *= task_mgr.cpu_load.loop_nomblk;    // Calculate the accumulated CPU cycles
            task_mgr.cpu_load.load  = (uint16_t)((task_mgr.cpu_load.ticks * task_mgr.cpu_load.load_factor)>>16);
            task_mgr.cpu_load.load_max_buffer |= task_mgr.cpu_load.load;
            task_mgr.cpu_load.ticks = 0; // Reset CPU tick counter

        }

        *task_mgr.reg_task_timer_irq_flag ^= task_mgr.task_timer_irq_flag_mask; // Reset timer ISR flag bit

        
#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
    TS_CLOCKOUT_PIN_WR = PINSTATE_LOW;                  // Drive debug pin low
#endif
#endif
        
        // Call most recent task with execution time measurement
        fres = task_manager_tick();     // Step through pre-defined task lists


#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
    TS_CLOCKOUT_PIN_WR = PINSTATE_HIGH;                 // Drive debug pin high
#endif
#endif

        // Capture the most recent system status to respond to changes in operating modes
        fres &= exec_CaptureSystemStatus();

#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
    TS_CLOCKOUT_PIN_WR = PINSTATE_LOW;                 // Drive debug pin low
#endif
#endif

        
        // call the fault handler to check all defined fault objects
        fres &= exec_FaultCheckAll();
        
#if ((USE_TASK_EXECUTION_CLOCKOUT_PIN == 1) && (USE_DETAILED_CLOCKOUT_PATTERN == 1))
#ifdef TS_CLOCKOUT_PIN_WR
    TS_CLOCKOUT_PIN_WR = PINSTATE_HIGH;                 // Drive debug pin high
#endif
#endif

        // Reset Watchdog Timer
        // ToDo: Move swdt_reset(); out to taks queues
        // ToDo: Add windowed WDT option to library
        //Remove: fres &= swdt_reset();
        
        // Increment task table pointer
        task_mgr.task_queue_tick_index++;

        // if the list index is at/beyond the recent list boundary, roll-over and/or switch task list
        if ( (task_mgr.task_queue_tick_index > (task_mgr.task_queue_ubound)) ||
             (task_mgr.pre_op_mode.mode != task_mgr.op_mode.mode) )
        // Check for list boundary
        {
            // at the roll-over point (one tick above the array size) the operation mode switch check
            // is executed by default

            fres &= task_CheckOperationModeStatus();
            task_mgr.task_queue_tick_index = 0; // If end of list has been reached, jump back to first item
        }

        
#if (USE_TASK_EXECUTION_CLOCKOUT_PIN == 1)
#ifdef TS_CLOCKOUT_PIN_WR
    TS_CLOCKOUT_PIN_WR = PINSTATE_LOW;                  // Drive debug pin low
#endif
#endif

        
        
#if (USE_TASK_MANAGER_TIMING_DEBUG_ARRAYS == 1)
// In debugging mode CPU load and task time is measured and logged in two arrays
// to examine the recent code execution profile
        if(cnt == CPU_LOAD_DEBUG_BUFFER_LENGTH)
        {
            Nop();  // place breakpoint here to hold firmware when arrays are filled
            Nop();
            Nop();
            cnt = 0;
        }
        else
        {
            task_time_buffer[cnt] = task_mgr.task_time_ctrl.task_time;   // Log task most recent time
            cpu_time_buffer[cnt] = task_mgr.cpu_load.load;    // Log most recent CPU Load
            cnt++;                                      // Increment array index
        }
#endif
        
    }   // End of main loop

    traplog.count++;  // increment the persistent soft-reset counter to stop restarting after certain number of restart attempts
    CPU_RESET;  // If the fault handler skips execution of the main loop, this line will reset the CPU  
    return(0);   // if this code line is ever reached, something really bad had happened...
    
}
