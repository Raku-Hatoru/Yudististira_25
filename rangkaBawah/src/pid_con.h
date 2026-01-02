#include "variabel.h"

void pid1(float sp, float ip, float DT){
    float error = sp - ip;
    float integral += error * DT;
    float derivative = (error - prevError) / DT;
    float op = kp * (error + (ki * integral) + (kd * derivative));
}