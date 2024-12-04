#ifndef drive_h
#define drive_h
#include <Arduino.h>
#include <Wire.h>
#include<smartmotor.h>
#include<math.h>

// car dimentions (mm)
#define wheel_radius 29 
#define wheel_distance 115
#define car_radius wheel_distance / 2

//serial speed 
#define serial_speed 115200

// MOTOR PROPERTIES
#define GEAR_RATIO 150           // MOTOR GEAR RATIO
#define ENCODER_TICKS_PER_REV 12 // NO. OF HIGH PULSES PER ROTATION
const int32_t ENCODER_TICKS_PER_SHAFT_REV= ENCODER_TICKS_PER_REV * GEAR_RATIO;
#define DELAY_PERIOD 0 //7000
#define RIGHT_MOTOR_ADDR 0x0A
#define LEFT_MOTOR_ADDR 0x0B
#define LEFT_MOTOR_DIRECTION 1 
#define RIGHT_MOTOR_DIRECTION -1
void drive_init();
void drive(float linear_velocy, float angular_velocity); 
void brake(); 
#endif