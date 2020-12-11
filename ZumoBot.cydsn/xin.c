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

#include "xin.h"
#define STOP 5

//Week3_assignment_1
void w3_a1(void){
    printf("Please put the robort to the start line\n");
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Moving starts\n");
    BatteryLed_Write(0);
    vTaskDelay(1000);
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


void w3_a2(void){
    printf("Robot starts!\n");
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Light off\n");
    BatteryLed_Write(0);
    vTaskDelay(1000);
     
    
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
}


void w3_a3(void){
    printf("Robot starts!\n");
    Ultra_Start();                          
    motor_start();      
    motor_forward(0,0);
    
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Light off\n");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    
    
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




void w4_a1(void){
    printf("\n Count to five Mr. Zumo\n");
    struct sensors_ dig;
    int count = 0;
    int first = 0;
    
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    while (SW1_Read()== 1);
    BatteryLed_Write(1);
    vTaskDelay(1000);
    BatteryLed_Write(0);
    
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
            IR_wait();
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

void w4_a2(void){
    printf("Please put the robort at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Move starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int touching = 0;
    
    while(count < 2){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                printf("\nWaiting for IR signal.\n");
                motor_forward(0, 0);
                IR_wait();
                printf("\nIR signal received.\n");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        while (dig.L2 == 1 && dig.R2 == 0){
            tank_turn(1);
            reflectance_digital(&dig);
        }
        
        while (dig.R2 == 1 && dig.L2 == 0){
            tank_turn(-1);
            reflectance_digital(&dig);
        }
        
        
        
        
        motor_forward(255, 0);
        
    }
    motor_stop();
    printf("\nHappy Birthday!");

}

void w4_a3(void){
    printf("Please put the robort at the start line\n");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Move starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int touching =0;
    
     while(count < 5){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                printf("\nWaiting for IR signal.\n");
                motor_forward(0, 0);
                IR_wait();
                printf("\nIR signal received.\n");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        if (count == 2){
            while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
            motor_turn(5,160,0);
            reflectance_digital(&dig);
            }
            motor_forward(255, 0);
        }
        if(count == 3 || count == 4){
            while(!(dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
            motor_turn(160,5,0);
            reflectance_digital(&dig);
            }
            motor_forward(255, 0);
        }
        motor_forward(255, 0);
    }      
    motor_stop();
    printf("\nHappy Birthday!");
}

void w5_a1(void){
    send_mqtt("Zumo10/turn","Time recording");
    
    TickType_t time0;
    TickType_t time1;
    
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Light off");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    time0 = xTaskGetTickCount();
    
    while(true){
        while (SW1_Read() == 1);
        time1 = xTaskGetTickCount();
        int t = time1 - time0;
        print_mqtt("Zumo10/button", "since last button push: %d s.\n", t/1000);
        while (SW1_Read() ==0);
        time0 = time1;
    }
}
    


void w5_a2(void){
    send_mqtt("Zumo10/turn","Turning");
    Ultra_Start();                         
    motor_start();      
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    printf("Light off");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    while (SW1_Read()==1){
        
        int d = Ultra_GetDistance();
        if (d < 10){
            motor_backward(100,800);
            int t = rand()%2;
            if(t == 1){
            tank_turn(90);
            print_mqtt("Zumo10/turn","Turn left 90 degrees");
            }
            else if (t == 0){
            tank_turn(-90);
            print_mqtt("Zumo10/turn","Turn right 90 degrees");
            }
        }

        motor_forward(200,50);
    }
    motor_stop();
}
void w5_a3(void){
    send_mqtt("Zumo10/lap","Count time");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    
    motor_start();
    motor_forward(0,0);
    
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    print_mqtt("Zumo10/lap","Move starts");
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
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
                print_mqtt("Zumo10/lap","Waiting to IR signal");
                IR_wait();
                time = xTaskGetTickCount();
                print_mqtt("Zumo10/lap","Time counting starts");
            }
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        
        motor_forward(100, 0);
        
    }
    motor_stop();
    print_mqtt("Zumo10/lap","Time costs %d s", time/1000);

}


void line_follower(void){
    send_mqtt("Zumo10/ready","line");
    struct sensors_ dig;
    reflectance_set_threshold(15000, 15000, 18000, 18000, 15000, 15000);
    
    reflectance_start();
    IR_Start();
    motor_start();
    motor_forward(0,0);
    TickType_t t0;
    TickType_t t1;
    TickType_t t2;
    TickType_t t3;
    BatteryLed_Write(1);
    while (SW1_Read()==1);
    
    BatteryLed_Write(0);
    vTaskDelay(1000);
    
    int count = 0;
    int touching = 0;
    
    while(count < 3){
        reflectance_digital(&dig);
        
        if (touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1) {
            count++;
            touching = 1;
            if (count == 1) {
                motor_forward(0, 0);
                IR_wait();
                t0 = xTaskGetTickCount();
                print_mqtt("Zumo10/start", "%d", t0);
                
            }
        }
        if ((dig.L1 == 0 && dig.R1 == 1) || (dig.R1 == 0 && dig.L1 == 1)){
            t1 = xTaskGetTickCount();
            print_mqtt("Zumo10/miss", "%d", t1);
            while(dig.L1 == 1 && dig.R1 == 0){
            tank_turn(1);
            reflectance_digital(&dig);
            }
            while(dig.L1 == 0 && dig.R1 == 1){
            tank_turn(-1);
            reflectance_digital(&dig);
            }
            t2 = xTaskGetTickCount();
            print_mqtt("Zumo10/line", "%d", t2);
        
        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
//        while (dig.L2 == 1 && dig.R2 == 0){
//            tank_turn(1);
//            reflectance_digital(&dig);
//        }
//        while (dig.R2 == 1 && dig.L2 == 0){
//            tank_turn(-1);
//            reflectance_digital(&dig);
//        }
        motor_forward(255, 0);
        
    }
    motor_forward(0,0);
    motor_stop();
    t3 = xTaskGetTickCount();
    print_mqtt("Zumo10/stop","%d", t3);
    
    int t = t3 - t0;
    print_mqtt("Zumo10/time","%d", t);
    

}

void maze_xin(void){
    printf("Robot starts!\n");
    reflectance_start();
    Ultra_Start();  
    IR_Start();
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
    int count_now;
    int round = 0;
    
    while(true){
        reflectance_digital(&dig);
        int d = Ultra_GetDistance();
       // printf("distance is %d\n", d);
        if ((touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1)||(touching == 0 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1)||(touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0)) {
            count++;
            touching = 1;
            if (count == 1) {
                motor_forward(0, 0);
                IR_wait();
            }
        }
        
        if (touching == 1){
            if( d <= 12){
                round++;
                motor_forward(0,0);
                count_now = count;
                printf("round is %d\n", round);
            }
            if (round == 1 && d <= 12){
                reflectance_digital(&dig);
                while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
                    motor_turn(5,160,0);
                    reflectance_digital(&dig);
                }   
            }
            int b = count - count_now;
            if (b == 2 && round == 1){
                reflectance_digital(&dig);
                while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
                    motor_turn(160,5,0);
                    reflectance_digital(&dig);
                }   
            }
            if (round == 2 && d <= 12){
                reflectance_digital(&dig);
                while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
                    motor_turn(160,5,0);
                    reflectance_digital(&dig);
                }  
            }
            if (b == 2 && round == 2){
                reflectance_digital(&dig);
                while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
                    motor_turn(5,160,0);
                    reflectance_digital(&dig);
                }  
            }
        }
        
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        
        if ((dig.L1 == 0 && dig.R1 == 1) || (dig.R1 == 0 && dig.L1 == 1)){
            while(dig.L1 == 1 && dig.R1 == 0){
            tank_turn(1);
            reflectance_digital(&dig);
            }
            while(dig.L1 == 0 && dig.R1 == 1){
            tank_turn(-1);
            reflectance_digital(&dig);
            }
        }
        motor_forward(50, 10);
        if ( dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 0 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0){
        motor_forward(0,0);
    motor_stop();
        }
    } 
    
}
/////////////MAZE-START-FROM-HERE/////////////
#define north 1
#define east 1
#define west -1
#define south -1

struct robot{
    int x;
    int y;
    int direction;
};

void maze_test(void){
    struct sensors_ dig;
    struct robot robot_coordinate ={ .x = 0, .y = 0, .direction = 0};
 
    reflectance_start();
    Ultra_Start();  
    IR_Start();
    motor_start();      
    motor_forward(0,0);
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    
    BatteryLed_Write(1);
    while (SW1_Read()== 1);
    vTaskDelay(1000);
    BatteryLed_Write(0);
    printf("Robot starts!\n");
    
    int count = 0;
    int touching = 0;
    int round = 0;
    
    while(true){
        reflectance_digital(&dig);
        int d = Ultra_GetDistance();
       
        if ((touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1)||(touching == 0 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 1 && dig.R3 == 1)||(touching == 0 && dig.L3 == 1 && dig.L2 == 1 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0)) {
            count++;
            touching = 1;
            if (count == 1) {
                motor_forward(0, 0);
                robot_coordinate.x = 0;
                robot_coordinate.y = -1;
                robot_coordinate.direction = north;
                IR_wait();
            }
        }
        if(robot_coordinate.y < 13 && robot_coordinate.x >= -3 && robot_coordinate.x <= 3) {
            
            if(robot_coordinate.x == -3 && robot_coordinate.direction == west) {
                right_turn();
                robot_coordinate.direction = north;
            } 
            else if(robot_coordinate.x == 3 && robot_coordinate.direction == west) {
                left_turn();
                robot_coordinate.direction = north;
            }
        }    
        
//        if (robot_coordinate.x == 0){
//            correct_direction(robot_coordinate.direction);
//        }
        if (touching == 1 && dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 1 && dig.R1 == 1 && dig.R2 == 0 && dig.R3 == 0) {
            touching = 0;
        }
        
        if ((dig.L1 == 0 && dig.R1 == 1) || (dig.R1 == 0 && dig.L1 == 1)){
            track_line();
        }
       
        if ( dig.L3 == 0 && dig.L2 == 0 && dig.L1 == 0 && dig.R1 == 0 && dig.R2 == 0 && dig.R3 == 0){
        motor_forward(0,0);
        motor_stop();
        }
        motor_forward(50, 10);
    } 
    while (touching == 1){
        reflectance_digital(&dig);
        int d = Ultra_GetDistance();
        if(robot_coordinate.direction == north || robot_coordinate.direction == south){
             robot_coordinate.y += robot_coordinate.direction;
        }
        if(robot_coordinate.direction == west || robot_coordinate.direction == east){
            robot_coordinate.x += robot_coordinate.direction;
        }
        print_mqtt("Zumo10/position", "(%d, %d)",robot_coordinate.x,robot_coordinate.y);
        if( d <= 12){
            round++;
            motor_forward(0,0);
            printf("round is %d\n", round);
            print_mqtt("Zumo10/position", "(%d, %d)",robot_coordinate.x,robot_coordinate.y);
        }
        if (round == 1 && d <= 12){
            left_turn(); 
        }
        
    }
    
}

void tank_turn(int16 angle){
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
void left_turn(void){
    struct sensors_ dig;
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    reflectance_digital(&dig);
    while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
        motor_turn(5,160,0);
        reflectance_digital(&dig);
    }   
}
void right_turn(void){
    struct sensors_ dig;
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    reflectance_digital(&dig);
    while(! (dig.L2 == 0 && dig.L1 == 1 && dig.R1 ==1 && dig.R2 == 0)){
        motor_turn(160,5,0);
        reflectance_digital(&dig);
    } 
}
void track_line(void){
    struct sensors_ dig;
    reflectance_start();
    reflectance_set_threshold(9000, 9000, 11000, 11000, 9000, 9000);
    reflectance_digital(&dig);
    while(dig.L1 == 1 && dig.R1 == 0){
        tank_turn(1);
        reflectance_digital(&dig);
        }
    while(dig.L1 == 0 && dig.R1 == 1){
        tank_turn(-1);
        reflectance_digital(&dig);
        }

}
void correct_direction(int direction){
    if (direction == east){
        left_turn();
        direction = north;
    }
    else if(direction == west){
        right_turn();
        direction = north;
  
}
}















    

/* [] END OF FILE */
