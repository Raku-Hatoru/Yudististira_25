#include "variabel.h"
#include "Arduino.h"
#include "Fuzzy.h"

// #define PI 3.14159265359
#define w_vel_max 0.70710678118654752440084436210485
#define rotary_radius 0.025
#define wheel_radius 0.05
#define diag_distc 0.26
#define straight_distc 0.225

// setup pin motor
const uint16_t EncMotora1 = PB12, EncMotorb1 = PB13; //pin encoder motor 1
const uint16_t EncMotora2 = PB14, EncMotorb2 = PB15;//pin encoder motor 2
const uint16_t EncMotora3 = PA2, EncMotorb3 = PA3; //pin encoder motor 3
const uint16_t EncMotora4 = PA4, EncMotorb4 = PA5; //pin encoder motor 4
// demux pin
const uint16_t sw_B1 = PA10, sw_C1 = PB5, sw_B2 = PC15, sw_C2 = PC14;
const uint16_t pwm1 = PA9, pwm2 = PA8, pwm3 = PB9, pwm4 = PB8;
/* 
* if sw_B == 0 -> Bx ON
* if sw_B == 1 -> By ON
* if sw_C == 0 -> Cx ON
* if sw_C == 1 -> Cy ON
*/

// setup pin external encoder
const uint16_t EncExta1 = PA0, EncExtb1 = PA_1;
const uint16_t EncExta2 = PA6, EncExtb2 = PA7;
const uint16_t EncExta3 = PB6, EncExtb3 = PB7;

Encoder wheel1, wheel2, wheel3, wheel4;
Encoder rotX, rotY1, rotY2;
Robot robot;

bool move_done = 0;
float a1 = 45, a2 = 135, a3 = 225, a4 = 315, psi = 0;

volatile long enc_Counter1 = 0, prev_enc_Counter1 = 0;
volatile long enc_Counter2 = 0, prev_enc_Counter2 = 0;
volatile long enc_Counter3 = 0, prev_enc_Counter3 = 0;
volatile long enc_Counter4 = 0, prev_enc_Counter4 = 0;
volatile long ext_enc_CounterX = 0, prev_ext_enc_CounterX = 0;
volatile long ext_enc_CounterY1 = 0, prev_ext_enc_CounterY1 = 0;
volatile long ext_enc_CounterY2 = 0, prev_ext_enc_CounterY2 = 0;

const float PPR = 7*15.5; //belum fix
const float kelilingRoda = PI*wheel_radius;
const float pulsePerMeter = PPR/kelilingRoda;

const float PPRex = 400;
const float kelilingRodaex = PI*rotary_radius;
const float pulsePerMeterex = PPRex/kelilingRodaex;

float V_glb_err, V_glb_derr[2], Vx_glb_err, Vy_glb_err, Vx_glb_derr, Vy_glb_derr;
float Vx_glb_act = 0, Vy_glb_act = 0, Vx_glb_aim, Vy_glb_aim, yaw_aim, yaw_act;
float omega1, omega2, omega3, omega4;
float X_glb, Y_glb, theta_glb, X_glb_old, Y_glb_old, theta_glb_old; //x, y dalam meter

long currT, dt, prevT = 0;

Fuzzy *fuzzy_wheel1 = new Fuzzy();
Fuzzy *fuzzy_wheel2 = new Fuzzy();
Fuzzy *fuzzy_wheel3 = new Fuzzy();
Fuzzy *fuzzy_wheel4 = new Fuzzy();

float input1, input2, input3, input4, setpoint1, setpoint2, setpoint3, setpoint4;
float output1, output2, output3, output4;
float kp = 3, ki = 0.2, kd = 0.2;

float prevError = 0;