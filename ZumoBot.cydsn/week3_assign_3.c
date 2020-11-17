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
#include "stdlib.h"


void randomTurn(void){
    pushButton();
    
    while (SW1_Read()==1){
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_backward(100,800);
            int angle = rand()%180 +90 ;
            tanketurn(angle);   //function call from subash.c
            
        }
        
        motor_forward(200,50);
    }
}

/* [] END OF FILE */
