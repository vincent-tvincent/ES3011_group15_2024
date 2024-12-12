#include<drive.h>
//#include<Arduino.h>
double a = 0;
double a_th = 0;
double t = 0;
double t_th = 0;
double v_max = 200;
double w_max = PI;
double d = 500;
double th = PI/2;
double acc_per_s = 20;
int d_t = 43;
void setup(){
    drive_init();
    brake();
    a = square(v_max) / (2 * d);
    t = v_max / a;
    a_th = square(w_max) / (2 * th);
    t_th = w_max / a_th; 
    delay(3000); 
}
long unsigned t_i = millis();
double v = 0;
double w = 0;
void loop(){ 
    read_sensor();
    for(int i = 0; i < t * acc_per_s; i++){
        v += a/acc_per_s;
        drive(v,0);
        delay(d_t);
    }     
    for(int i = 0; i < t * acc_per_s; i++){
        v -= a/acc_per_s;
        drive(v,0);
        delay(d_t);
    }
    drive(0,PI/2);
    delay(1000);
    brake();
    for(int i = 0; i < t * acc_per_s; i++){
        v += a/acc_per_s;
        drive(v,0);
        delay(d_t);
    }     
    for(int i = 0; i < t * acc_per_s; i++){
        v -= a/acc_per_s;
        drive(v,0);
        delay(d_t);
    }
    while(1);
}