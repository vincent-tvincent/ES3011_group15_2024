#include<drive.h>
//#include<Arduino.h>
void setup(){
    drive_init();
    brake();
    delay(3000);
    drive(10,0); 
}
SmartMotor motor = SmartMotor(LEFT_MOTOR_ADDR);
void loop(){
   Serial.println(motor.get_position());
}