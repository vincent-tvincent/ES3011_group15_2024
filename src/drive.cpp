#include<drive.h>

void drive_init(){
    Serial.begin(serial_speed);
    Wire.begin();
}