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


void pushButton(void){
    printf("\nMoving robot!\n");
    Ultra_Start();                          // Ultra Sonic Start function
    motor_start();      
    motor_forward(0,0);
    
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("\nLight off\n");
    BatteryLed_Write(0);
    vTaskDelay(1000);
<<<<<<< HEAD
    
    
    
    while (SW1_Read()==1){
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_backward(100,800);
            int angle = rand()%180 +90 ;
            tank_turn(angle);
            
        }
        
        motor_forward(200,50);
    }
    
    motor_stop();
}















=======
}

void tanketurn(int16 angle){
     uint8 left_wheel = 0,right_wheel =0;
    if (angle < 0 ){
        left_wheel = 0;
        right_wheel = 1;
    }
    else if(angle >= 0){
        left_wheel =1;
        right_wheel = 0;
    }
    uint16 correct_angle = (angle<0)? angle* -1:angle;
    uint32 delay =correct_angle % 360 *524 / 360;
    
    SetMotors(left_wheel,right_wheel, 200, 200, delay);
}
>>>>>>> f101daa8e05e5ad9dc82af3446afffff7eaedc0a




/* [] END OF FILE */
