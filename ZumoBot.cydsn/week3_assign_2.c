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
#include <stdlib.h>

void Distancesensor(void){
     // Ultra Sonic Start function
    pushButton(); //pushButton() function call from subash.c
   
    
    while(true) {
        int d = Ultra_GetDistance();
        // Print the detected distance (centimeters)
        printf("distance = %d\r\n", d);
        motor_forward(50,100);
        if(d < 10 && d !=0){
            motor_forward(0,0);
            motor_backward(35,2000);
            motor_turn(10,50,2000);
        }
    }
}
/* [] END OF FILE */
