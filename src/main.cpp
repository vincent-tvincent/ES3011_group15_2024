#include <Arduino.h>
#include <Wire.h>
#include <smartmotor.h>

// MOTOR PROPERTIES
#define GEAR_RATIO 150           // MOTOR GEAR RATIO
#define ENCODER_TICKS_PER_REV 12 // NO. OF HIGH PULSES PER ROTATION
const int32_t ENCODER_TICKS_PER_SHAFT_REV= ENCODER_TICKS_PER_REV * GEAR_RATIO;
#define DELAY_PERIOD 0 //7000

// INIT SMART MOTORS
// SmartMotor motors[] = {0x05,0x06,0x07}; // INIT MOTORS
SmartMotor motors[] = {0x0A, 0x0B};
const int MOTOR_NUM = sizeof(motors)/sizeof(motors[0]);

void setup() {
    Serial.begin(115200);
    Wire.begin(); // INIT DEVICE AS I2C CONTROLLER
}

float target_vel= 10; // INIT TARGET VELOCITY
void loop() {
    //bruh bababoi 
    delay(DELAY_PERIOD);
}