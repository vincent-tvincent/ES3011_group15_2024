#include<drive.h>
//#include<Arduino.h>
void setup(){
    drive_init();
    
}
SmartMotor motor1 = SmartMotor(RIGHT_MOTOR_ADDR);
SmartMotor motor2 = SmartMotor(LEFT_MOTOR_ADDR);
void loop(){
    // demo, this make it drive forward, one motor is mounted reversely, which we need add offset 
    motor1.set_rpm(-10);
    motor2.set_rpm(10);
    delay(1000);
    motor1.set_rpm(0);
    motor2.set_rpm(0);jj
    delay(DELAY_PERIOD);
}