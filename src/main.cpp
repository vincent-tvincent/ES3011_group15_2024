#include<drive.h>
//#include<Arduino.h>
void setup(){
    drive_init();
    brake();
    delay(3000);
    drive(10,0); 
}

void loop(){
    read_sensor();
    
}