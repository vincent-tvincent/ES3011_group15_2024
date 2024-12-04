#include<drive.h>

SmartMotor left = SmartMotor(LEFT_MOTOR_ADDR);
SmartMotor right = SmartMotor(RIGHT_MOTOR_ADDR);

void drive_init(){
    Serial.begin(serial_speed);
    Wire.begin();
}

void brake(){
    left.set_velocity(0);
    right.set_velocity(0);
}

void drive(float linear_velocity, float angular_velocity){ 

    // calculate linear velocity 
    float angular_to_linear_velocity = angular_velocity * car_radius;      
    float left_velocity = linear_velocity - angular_to_linear_velocity;
    float right_velocity = linear_velocity + angular_to_linear_velocity; 
    
    // set speed 
    left.set_velocity(left_velocity * LEFT_MOTOR_DIRECTION);
    right.set_velocity(right_velocity * RIGHT_MOTOR_DIRECTION);
}