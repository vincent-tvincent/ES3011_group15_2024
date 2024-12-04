#ifndef drive_h
#define drive_h
#include <Arduino.h>
#include <Wire.h>
#include<smartmotor.h>

//serial speed 
#define serial_speed 115200

// MOTOR PROPERTIES
#define GEAR_RATIO 150           // MOTOR GEAR RATIO
#define ENCODER_TICKS_PER_REV 12 // NO. OF HIGH PULSES PER ROTATION
const int32_t ENCODER_TICKS_PER_SHAFT_REV= ENCODER_TICKS_PER_REV * GEAR_RATIO;
#define DELAY_PERIOD 0 //7000
#define RIGHT_MOTOR_ADDR 0x0A
#define LEFT_MOTOR_ADDR 0x0B

// INIT SMART MOTORS
// SmartMotor motors[] = {0x05,0x06,0x07}; // INIT MOTORS
// SmartMotor motors[] = {0x0A, 0x0B};
// const int MOTOR_NUM = sizeof(motors)/sizeof(motors[0]);
void drive_init();
void drive(float velocity_input[2]); //TODO 
void brake(); //TODO
#endif