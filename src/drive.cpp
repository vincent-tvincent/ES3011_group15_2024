#include<drive.h>

unsigned long start_time = 0;
float* scalar_velocity = (float*) malloc(sizeof(float) * 2);
SensorData* pre_left_sensor_data = (SensorData*) malloc(sizeof(SensorData));
SensorData* pre_right_sensor_data = (SensorData*) malloc(sizeof(SensorData));
SensorData* left_sensor_data = (SensorData*) malloc(sizeof(SensorData));
SensorData* right_sensor_data = (SensorData*) malloc(sizeof(SensorData));
//float left_velocity = 0;
//float right_velocity = 0;

SmartMotor left = SmartMotor(LEFT_MOTOR_ADDR);
SmartMotor right = SmartMotor(RIGHT_MOTOR_ADDR);

void drive_init(){
    Serial.begin(serial_speed);
    Wire.begin();
    start_time = millis();
    reset_motor();
    left.tune_vel_pid(pv,iv,dv);
    right.tune_vel_pid(pv,iv,dv);
}

void reset_motor(){
    left.reset();
    right.reset();
}

void brake(){
    left.set_rpm(0);
    right.set_rpm(0);
}

void drive(float linear_velocity, float angular_velocity){ 

    // convernt to linear velocity of each motor
    float angular_to_linear_velocity = angular_velocity * car_radius;      
    float left_velocity = linear_velocity - angular_to_linear_velocity;
    float right_velocity = linear_velocity + angular_to_linear_velocity; 
    float left_rpm = left_velocity / (wheel_radius * 2 * PI) * 60 / 0.66;
    float right_rpm = right_velocity / (wheel_radius * 2 * PI) * 60 / 0.66;
    // set speed 
    Serial.print(left_rpm);
    left.set_rpm(left_rpm * LEFT_MOTOR_DIRECTION);
    right.set_rpm(right_rpm * RIGHT_MOTOR_DIRECTION);
    
}

void read_sensor(){
    long unsigned t = millis() - start_time;
    left_sensor_data = simc_read(LEFT_MOTOR_ADDR);
    right_sensor_data = simc_read(RIGHT_MOTOR_ADDR); 
}

void update_values(){
    scalar_velocity = get_scalar_velocity();
}

float* get_scalar_velocity(){
    // convert from rpm to mm/s 
    //Serial.print(left_sensor_data -> rpm); 
    //Serial.print(',');
    //Serial.print(right_sensor_data -> rpm);
    Serial.println();
    float left_velocity = left_sensor_data -> rpm / 60  * wheel_radius * 2 * PI * LEFT_MOTOR_DIRECTION;
    float right_velocity = right_sensor_data -> rpm / 60 * wheel_radius * 2 * PI *  RIGHT_MOTOR_DIRECTION;

    // calculate velocity 
    float angular_velocity = (right_velocity - left_velocity) / 2 / car_radius;
    float linear_velocity = min(right_velocity, left_velocity);
    float* return_value = (float*) malloc(sizeof(float) * 2);
    return_value[0] = linear_velocity;
    return_value[1] = angular_velocity;    
    //Serial.print(',');
    return return_value;
} 







