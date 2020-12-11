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

#include <project.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Motor.h"
#include "Ultra.h"
#include "Nunchuk.h"
#include "Reflectance.h"
#include "Gyro.h"
#include "Accel_magnet.h"
#include "LSM303D.h"
#include "IR.h"
#include "Beep.h"
#include "mqtt_sender.h"
#include <time.h>
#include <sys/time.h>
#include "serial1.h"
#include <unistd.h>
#include <stdlib.h>
void w3_a1(void);
void w3_a2(void);
void w3_a3(void);
void w4_a1(void);
void w4_a2(void);
void w4_a3(void);
void w5_a1(void);
void w5_a2(void);
void w5_a3(void);
void line_follower(void);
void maze_xin(void);
void maze_test(void);
void tank_turn(int16 angle);
void track_line(void);
void left_turn(void);
void right_turn(void);
void correct_direction(int direction);

/* [] END OF FILE */