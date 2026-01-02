#ifndef VARIABEL_H
#define VARIABEL_H

#include "Arduino.h"
#include "Fuzzy.h"

// #define PI 3.14159265359
#define w_vel_max 0.70710678118654752440084436210485
#define rotary_radius 0.025
#define wheel_radius 0.05
#define diag_distc 0.26
#define straight_distc 0.225

// setup pin motor
extern const uint16_t EncMotora1, EncMotorb1; //pin encoder motor 1
extern const uint16_t EncMotora2, EncMotorb2;//pin encoder motor 2
extern const uint16_t EncMotora3, EncMotorb3; //pin encoder motor 3
extern const uint16_t EncMotora4, EncMotorb4; //pin encoder motor 4
// demux pin
extern const uint16_t sw_B1, sw_C1, sw_B2, sw_C2;
extern const uint16_t pwm1, pwm2, pwm3, pwm4;
/* 
* if sw_B == 0 -> Bx ON
* if sw_B == 1 -> By ON
* if sw_C == 0 -> Cx ON
* if sw_C == 1 -> Cy ON
*/

// setup pin external encoder
extern const uint16_t EncExta1, EncExtb1;
extern const uint16_t EncExta2, EncExtb2;
extern const uint16_t EncExta3, EncExtb3;

struct Encoder {
    volatile long counter;
	float ang_vel_act;
	float lin_vel_act;
	float ang_vel_aim;
	float lin_vel_aim;
	short direction;
	float rpm;
	int dpwm;
	int pwm;
	int pwmff;
};

struct Robot {
    float xDistEnc;
	float yDistEnc;
	float xDistReal;
	float yDistReal;
	float heading;
};

extern Encoder wheel1, wheel2, wheel3, wheel4;
extern Encoder rotX, rotY1, rotY2;
extern Robot robot;

extern bool move_done;
extern float a1, a2, a3, a4, psi;

extern volatile long enc_Counter1, prev_enc_Counter1;
extern volatile long enc_Counter2, prev_enc_Counter2;
extern volatile long enc_Counter3, prev_enc_Counter3;
extern volatile long enc_Counter4, prev_enc_Counter4;
extern volatile long ext_enc_CounterX, prev_ext_enc_CounterX;
extern volatile long ext_enc_CounterY1, prev_ext_enc_CounterY1;
extern volatile long ext_enc_CounterY2, prev_ext_enc_CounterY2;

extern const float PPR;
extern const float kelilingRoda;
extern const float pulsePerMeter;

extern const float PPRex;
extern const float kelilingRodaex;
extern const float pulsePerMeterex;

extern float V_glb_err, V_glb_derr[2], Vx_glb_err, Vy_glb_err, Vx_glb_act, Vy_glb_act, Vx_glb_aim, Vy_glb_aim, yaw_aim, yaw_act;
extern float omega1, omega2, omega3, omega4;
extern float X_glb, Y_glb, theta_glb, X_glb_old, Y_glb_old, theta_glb_old; //x, y dalam meter

extern long currT, dt, prevT;

extern Fuzzy *fuzzy_wheel1;
extern Fuzzy *fuzzy_wheel2;
extern Fuzzy *fuzzy_wheel3;
extern Fuzzy *fuzzy_wheel4;

// Variabel parameter PID
extern float input1, input2, input3, input4, setpoint1, setpoint2, setpoint3, setpoint4;
extern float output1, output2, output3, output4;
extern float kp, ki, kd;

extern float prevError;

#endif