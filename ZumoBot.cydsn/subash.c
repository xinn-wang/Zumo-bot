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

void W3A1(void){
    
    printf("\nHello, World!\n");
    motor_start();      
    motor_forward(0,0);
    vTaskDelay(1500);
    
    motor_forward(167,2000);
    motor_turn(26,0,2010);
    
    motor_forward(129,2000);  
    motor_turn(26,0,2010);
    
    motor_forward(135,2000);  
    motor_turn(28,0,2000);
    motor_turn(122,100,2000);
    motor_turn(15,0,350);
    
    motor_forward(50,1600);
    
    motor_forward(0,0);  
    motor_stop();             
}

void W3A2(void){
    
    Ultra_Start();                          // Ultra Sonic Start function
    motor_start();      
    motor_forward(0,0);
    vTaskDelay(1500);
    
    motor_forward(167,2000);
    motor_turn(26,0,2010);
    
        int d = Ultra_GetDistance();
        printf("distance = %d\r\n", d);
        vTaskDelay(200);






}



/* [] END OF FILE */
