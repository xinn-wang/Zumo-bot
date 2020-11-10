/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "subash.h"

void test(void){
    
    IR_Start();
    IR_flush();
    IR_wait();
    
    printf("test\n");
    motor_start();
    motor_forward(0,0);
    
    vTaskDelay(3000);
   
    motor_forward(100,2000);     // moving forward
    motor_turn(200,50,2000);     // turn
    motor_turn(50,200,2000);     // turn
    motor_backward(100,2000);    // moving backward
     
    motor_forward(0,0);         // stop motors

    motor_stop();               // disable motor controller

    
    
    while(true)
    {
        vTaskDelay(100);
    }
}



/* [] END OF FILE */
