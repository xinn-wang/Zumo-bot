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

#include <miguel.h>
#define STOP 5

//week 3, assignment 1
void make3_1(void)
{
    printf("\nMr.Zumo first steps\n");
    motor_start();      
    motor_forward(0,0);
    vTaskDelay(1500);
    
    BatteryLed();  // Turns blue LED on and when press waits for the IR signal to start motor and move forward. 
    
    motor_forward(170,2000);
    motor_turn(26,0,2010);
    
    motor_forward(129,2000);  
    motor_turn(26,0,2010);
    
    motor_forward(135,2000);  
    motor_turn(28,0,2000);
    motor_turn(122,100,2000);
    motor_turn(15,0,350);
    
    motor_forward(55,2000);
    
    motor_forward(0,0);  
    motor_stop();             
}   
//week 3, assignment 2
void make3_2(void)
{
   printf("Robot starts!\n");
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed();
     
    while (SW1_Read()==1){
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_forward(0,0);
            motor_backward(100,800);
            motor_turn(250,0,350);
        }
        
        motor_forward(200,50);
    }
    motor_stop();

    while(true){

        vTaskDelay(100);

    }
}
//week 3, assignment 3
void make3_3(void) 
{
    printf("\nMr.Zumo starts!\n");
    Ultra_Start();                          
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed();  // Turns blue LED on and when press waits for the IR signal to start motor and move forward.
    
    while (SW1_Read()==1){
        
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_backward(100,800);
            int angle = rand()%180 +90 ;
            tank_turns(angle);
        }

        motor_forward(200,50);
    }
    motor_stop();
}
//week 4, assignment 1    
void make4_1(void)  
{
    printf("\nMr. Zumo learns how to count to 5\n");
    struct sensors_ dig;
    int count = 0;
    int first = 0;
    
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    MotorReflexs();  // starts reflectance, IR, motor and to go forward. 
    
    BatteryLed();  // turns blue LED on and when press waits for the IR signal to start motor and move forward.
    
    reflectance_digital(&dig);
    motor_forward(100,0);
    
    while(count < STOP){ 
        reflectance_digital(&dig);
        if(dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1){
            count++;
            if (count == 1) {
                first = 1;
            }
            while((dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1) && count < STOP){
                reflectance_digital(&dig);
            }
        }
        if(first == 1) {
            motor_forward(0, 0);
            motor_forward(100, 0);
            first = 0;
        }
    }
    motor_forward(0,0);
    motor_stop();
    while(true) { 
        
        vTaskDelay(100);
    }
}
//week 4, assignment 2
void make4_2(void)
{
    printf("Place Mr.Zumo at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    MotorReflexs();  // starts reflectance, IR, motor and to go forward. 
    
    BatteryLed();  // turns blue LED on and when press waits for the IR signal to start motor and move forward.
    
    int count = 0;
    
    reflectance_digital(&dig);
    motor_forward(60,0);
    
    while(count < 2) {
        reflectance_digital(&dig);
        if ((dig.L3 == 1)&&(dig.R3 == 1)) {
            count++;
            if (count == 1) {
               
            }
            while (dig.L3== 1 && dig.R3 == 1){
                reflectance_digital(&dig);
                motor_forward(60,10);
            }
        }
        
        if(dig. L2 == 0){
            motor_turn(60,0,10);
        }
        if(dig.R2 == 0){
            motor_turn(0,60,10);
        }
        if((dig.L1 == 1)&&(dig.R1 == 1))
           motor_forward(60,0);
        
    }
    
    motor_forward(0,0);
    motor_stop();
    while(true) {
        vTaskDelay(100);
    }
}
//week 4, assignment 3
void make4_3(void) {
    
    printf("\nMr.Zumo stops on the first line\n");
    struct sensors_ dig;
    int count = 0;
    
    reflectance_set_threshold(15000, 15000, 15000, 15000, 15000, 15000);
    
    MotorReflexs();  // starts reflectance, IR, motor and to go forward. 
    
    BatteryLed(); // turns blue LED on and when press waits for the IR signal to start motor and move forward.
    
    reflectance_digital(&dig);
    
    while(count < STOP){
        reflectance_digital(&dig);
        
        while (dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1){
            motor_forward(100, 10);
            reflectance_digital(&dig);
        
        }
        
        while (!(dig.L3 == 1 && dig.L2 == 1 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 1 &&dig.R3 == 1)){
            while (dig.L2 == 1 && dig.R2 == 0){
                tank_turns(1);
                reflectance_digital(&dig);
            }
            while (dig.L2 == 0 && dig.R2 == 1){
                tank_turns(-1);
                reflectance_digital(&dig);
            }
            
            motor_forward(100, 10);
            reflectance_digital(&dig);
        }
        
        count++;
        printf("count is %d\n", count);
        
        if (count == 1){
            motor_forward(0, 0);
            IR_wait();
        }
        
        if (count == 2){
             while (!(dig.L3 == 0 && dig.L2 == 0 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 0 &&dig.R3 == 0)){
            motor_turn(0,100,10);
            reflectance_digital(&dig);
            }

        }
        if (count == 3 || count == 4){
            
            while (!(dig.L3 == 0 && dig.L2 == 0 &&dig.L1 == 1 &&dig.R1 == 1 &&dig.R2 == 0 &&dig.R3 == 0)){
            motor_turn(100,0,10);
            reflectance_digital(&dig);
            }
           
        }
        if (count == 5){
            printf("motor cools down");
            motor_forward(0,0);
           motor_stop ();
           break;
       }
     }
    
    while(true){
    vTaskDelay(1000);
    }
}
//week 5, assignment 1  
void make5_a1(void){
    send_mqtt("\nMr.Zumo10/turn\n","Time recorder\n");
    
    TickType_t time0;
    TickType_t time1;
    
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed();  // Turns blue LED on and when press waits for the IR signal to start motor and move forward.
    
    time0 = xTaskGetTickCount();
    
    while(true){
        while (SW1_Read() == 1);
        time1 = xTaskGetTickCount();
        int t = time1 - time0;
        print_mqtt("\nMr.Zumo10/button\n", "since last button pressed: %d s.\n", t/1000);
        while (SW1_Read() ==0);
        time0 = time1;
    }
}
//week 5, assignment 2    
void make5_a2(void){
    send_mqtt("\nMr.Zumo10/turn\n","\nTurning\n");
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed();  // Turns blue LED on and when press waits for the IR signal to start motor and move forward.
    
    while (SW1_Read()==1){
        
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_backward(100,800);
            int t = rand()%2;
            if(t == 1){
            tank_turns(90);
            print_mqtt("\nMr.Zumo10/turn\n","\nTurns left 90 degrees\n");
            }
            else if (t == 0){
            tank_turns(-90);
            print_mqtt("\nMr.Zumo/turn\n","\nTurns right 90 degrees\n");
            }
        }

        motor_forward(200,50);
    }
    motor_stop();
}
//week 5, assignment 3
void make5_a3(void){
    send_mqtt("\nMr.Zumo10/lap\n","\nTimer starts\n");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    MotorReflexs();  // starts reflectance, IR, motor and to go forward. 
   
    BatteryLed();  // Turns blue LED on and when press waits for the IR signal to start motor and move forward.
    print_mqtt("\nMr.Zumo10/lap\n","\nNow moving\n");
  
    int count = 0;
    int touching = 0;
    TickType_t time;
    
    while(count < 2){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                motor_forward(0, 0);
                print_mqtt("\nMr.Zumo10/lap\n","\nWaiting for IR signal\n");
                IR_wait();
                time = xTaskGetTickCount();
                print_mqtt("\nMr.Zumo10/lap\n","Timer starts");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        
        motor_forward(100, 0);
        
    }
    motor_stop();
    print_mqtt("\nMr.Zumo10/lap\n","\nTime costs %d s", time/1000);

}

void project_1(void){
    
    
}

void project_2(void){
    
    
}

void project_3(void){
    
    
    printf("Robot starts!\n");
    reflectance_start();
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    struct sensors_ dig;
    
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    BatteryLed_Write(1);
    while (SW1_Read()== 1);
    vTaskDelay(1000);
    BatteryLed_Write(0);
    
    int count = 0;
    int touching = 0;
    
    while(true){
        reflectance_digital(&dig);
        int d = Ultra_GetDistance();
        printf("distance is %d\n", d);
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                motor_forward(0, 0);
                IR_wait();
            }
        }
        
        if(touching == 1 && d <= 12){
            motor_forward(0,0);
            reflectance_digital(&dig);
            while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
            motor_turn(5,160,0);
            reflectance_digital(&dig);
            }
            
        }
        
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        if ((dig.L1 == 0 && dig.R1 == 1) || (dig.R1 == 0 && dig.L1 == 1)){
           
            
            while(dig.L1 == 1 && dig.R1 == 0){
            tank_turns(1);
            reflectance_digital(&dig);
            }
            while(dig.L1 == 0 && dig.R1 == 1){
            tank_turns(-1);
            reflectance_digital(&dig);
            }
        }
        while(dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1){
             if(count == 3){
                motor_turn(160,5,0);
                motor_forward(0,0);
                reflectance_digital(&dig);
            
            }
            
        
        
        }
        
        motor_forward(50, 0);
    } 
    motor_forward(0,0);
    motor_stop();
}


//functions for Mr.Zumo
void tank_turns(int16 angle){
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

void BatteryLed(){  
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("\nPress the blue LED\n");
    IR_wait();
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
}

void MotorReflexs(){
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
}
   
