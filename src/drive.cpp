#include<drive.h>

SmartMotor left = SmartMotor(LEFT_MOTOR_ADDR);
SmartMotor right = SmartMotor(RIGHT_MOTOR_ADDR);

void drive_init(){
    Serial.begin(serial_speed);
    Wire.begin();
}

void brake(){
    left.set_rpm(0);
    right.set_rpm(0);
}

int* drive(float velocity_input[2]){
    float linear_velocity = velocity_input[0];
    float angular_velocity = velocity_input[1];

    // calculate linear velocity 
    float angular_to_linear_velocity = angular_velocity * car_radius;      
    float left_velocity = linear_velocity - angular_to_linear_velocity;
    float right_velocity = linear_velocity + angular_to_linear_velocity; 
    
    float left_rpm = left_velocity / wheel_radius * LEFT_MOTOR_DIRECTION;
    float right_rpm = right_velocity / wheel_radius * RIGHT_MOTOR_DIRECTION;

    int* real_speed = (int*) malloc(sizeof(int) * 2);
    real_speed[0] = left_rpm;
    real_speed[1] = right_rpm;
    return real_speed;
}