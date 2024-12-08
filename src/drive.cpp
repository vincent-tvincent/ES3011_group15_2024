#include<drive.h>

float* scalar_velocity = (float*) malloc(sizeof(float) * 2);

SensorData* left_sensor_data = (SensorData*) malloc(sizeof(SensorData));
SensorData* right_sensor_data = (SensorData*) malloc(sizeof(SensorData));

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

    // convernt to linear velocity of each motor
    float angular_to_linear_velocity = angular_velocity * car_radius;      
    float left_velocity = linear_velocity - angular_to_linear_velocity;
    float right_velocity = linear_velocity + angular_to_linear_velocity; 
    
    // set speed 
    left.set_velocity(left_velocity * LEFT_MOTOR_DIRECTION);
    right.set_velocity(right_velocity * RIGHT_MOTOR_DIRECTION);
    
}

void read_sensor(){
    left_sensor_data = simc_read(LEFT_MOTOR_ADDR);
    right_sensor_data = simc_read(RIGHT_MOTOR_ADDR);
}

void update_values(){
    scalar_velocity = get_scalar_velocity();
}

float* get_scalar_velocity(){
    // convert from rpm to mm/s 
    float left_velocity = left_sensor_data -> rpm / ENCODER_TICKS_PER_SHAFT_REV * wheel_radius * LEFT_MOTOR_DIRECTION;
    float right_velocity = right_sensor_data -> rpm / ENCODER_TICKS_PER_SHAFT_REV * wheel_radius * RIGHT_MOTOR_DIRECTION;

    // calculate velocity 
    float angular_velocity = (right_velocity - left_velocity) / 2 / car_radius;
    float linear_velocity = min(right_velocity, left_velocity);

    float* return_value = (float*) malloc(sizeof(float) * 2);
    return_value[0] = linear_velocity;
    return_value[1] = angular_velocity;
    return return_value;
} 






