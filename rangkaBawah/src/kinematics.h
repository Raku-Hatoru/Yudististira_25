#include <Arduino.h>
#include <string>
#include "variabel.h"
#include "math.h"
#include "control_signal2.h"
#include "QuickPID.h"

using namespace std;

void set_pid() {
}

 void use_pid() {
}

float convertTo(float x, string choice){
	if(choice == "RAD") { return x*PI/180; }
	else if(choice == "DEG") { return x*180/PI; }
	else return x;
}

void readEnc() {
	noInterrupts();
	enc_Counter1 = wheel1.counter;
	enc_Counter2 = wheel2.counter;
	enc_Counter3 = wheel3.counter;
	enc_Counter4 = wheel4.counter;
	interrupts();

	noInterrupts();
	ext_enc_CounterX = rotX.counter;
	ext_enc_CounterY1 = rotY1.counter;
	ext_enc_CounterY2 = rotY2.counter;
	interrupts();

	wheel1.lin_vel_act = (enc_Counter1*kelilingRoda)/((dt/10e-6)*PPR);
	wheel2.lin_vel_act = (enc_Counter2*kelilingRoda)/((dt/10e-6)*PPR);
	wheel3.lin_vel_act = (enc_Counter3*kelilingRoda)/((dt/10e-6)*PPR);
	wheel4.lin_vel_act = (enc_Counter4*kelilingRoda)/((dt/10e-6)*PPR);

	wheel1.ang_vel_act = wheel1.lin_vel_act/wheel_radius;
	wheel2.ang_vel_act = wheel2.lin_vel_act/wheel_radius;
	wheel3.ang_vel_act = wheel3.lin_vel_act/wheel_radius;
	wheel4.ang_vel_act = wheel4.lin_vel_act/wheel_radius;

	wheel1.rpm = (enc_Counter1*(dt*10e-6))/(60*PPR);
	wheel2.rpm = (enc_Counter2*(dt*10e-6))/(60*PPR);
	wheel3.rpm = (enc_Counter3*(dt*10e-6))/(60*PPR);
	wheel4.rpm = (enc_Counter4*(dt*10e-6))/(60*PPR);

	input1 = wheel1.rpm;
	input2 = wheel2.rpm;
	input3 = wheel3.rpm;
	input4 = wheel4.rpm;

	prev_enc_Counter1 = enc_Counter1;
	prev_enc_Counter2 = enc_Counter2;
	prev_enc_Counter3 = enc_Counter3;
	prev_enc_Counter4 = enc_Counter4;
	prev_ext_enc_CounterX = ext_enc_CounterX;
	prev_ext_enc_CounterY1 = ext_enc_CounterY1;
	prev_ext_enc_CounterY2 = ext_enc_CounterY2;
}

void resetEnc() {
	wheel1.counter = 0;
	wheel2.counter = 0;
	wheel3.counter = 0;
	wheel4.counter = 0;
	rotX.counter = 0;
	rotY1.counter = 0;
	rotY2.counter = 0;

	enc_Counter1 = 0;
	enc_Counter2 = 0;
	enc_Counter3 = 0;
	enc_Counter4 = 0;
	ext_enc_CounterX = 0;
	ext_enc_CounterY1 = 0;
	ext_enc_CounterY2 = 0;
}

void inverse_kinematic(float vx_glb, float vy_glb, float omega, float psi) {
    a1 = convertTo(a1, "RAD");
	a2 = convertTo(a2, "RAD");
	a3 = convertTo(a3, "RAD");
	a4 = convertTo(a4, "RAD");
	psi = convertTo(psi, "RAD");

	/*
	ini sudah sesuai dengan logika pergerakan robot
	jika nilai (-) maka roda CCW, jika nilai (+) maka roda CW
	(masih butuh convert ke PWM, harusnya sih begitu)
	*/
    wheel1.lin_vel_aim = -sin(psi+a1)*vx_glb + cos(psi+a1)*vy_glb + omega;
	wheel2.lin_vel_aim = -sin(psi+a2)*vx_glb + cos(psi+a2)*vy_glb + omega;
	wheel3.lin_vel_aim = -sin(psi+a3)*vx_glb + cos(psi+a3)*vy_glb + omega;
	wheel4.lin_vel_aim = -sin(psi+a4)*vx_glb + cos(psi+a4)*vy_glb + omega;

	setpoint1 = wheel1.lin_vel_aim * 60 / kelilingRoda; // in RPM
	setpoint2 = wheel2.lin_vel_aim * 60 / kelilingRoda;
	setpoint3 = wheel3.lin_vel_aim * 60 / kelilingRoda;
	setpoint4 = wheel4.lin_vel_aim * 60 / kelilingRoda;

	// wheel1.pwmff = fabs(wheel1.lin_vel_aim) / w_vel_max * 255;
    // wheel2.pwmff = fabs(wheel2.lin_vel_aim) / w_vel_max * 255;
    // wheel3.pwmff = fabs(wheel3.lin_vel_aim) / w_vel_max * 255;
    // wheel4.pwmff = fabs(wheel4.lin_vel_aim) / w_vel_max * 255;

	if(wheel1.lin_vel_aim < 0) wheel1.direction = -1;
	else if(wheel1.lin_vel_aim == 0) wheel1.direction = 0;
	else wheel1.direction = 1;

	if(wheel2.lin_vel_aim < 0) wheel2.direction = -1;
	else if(wheel2.lin_vel_aim == 0) wheel2.direction = 0;
	else wheel2.direction = 1;

	if(wheel3.lin_vel_aim < 0) wheel3.direction = -1;
	else if(wheel3.lin_vel_aim == 0) wheel3.direction = 0;
	else wheel3.direction = 1;

	if(wheel4.lin_vel_aim < 0) wheel4.direction = -1;
	else if(wheel4.lin_vel_aim == 0) wheel4.direction = 0;
	else wheel4.direction = 1;

    a1 = convertTo(a1, "DEG");
	a2 = convertTo(a2, "DEG");
	a3 = convertTo(a3, "DEG");
	a4 = convertTo(a4, "DEG");
	psi = convertTo(psi, "DEG");
}

void forward_kinematic(float v1, float v2, float v3, float v4, float psi) {
    a1 = convertTo(a1, "RAD");
	a2 = convertTo(a2, "RAD");
	a3 = convertTo(a3, "RAD");
	a4 = convertTo(a4, "RAD");
	psi = convertTo(psi, "RAD");

    Vx_glb_act = (-sin(psi+a1)*v1 - sin(psi+a2)*v2 - sin(psi+a3)*v3 - sin(psi+a4)*v4);
	Vy_glb_act = (cos(psi+a1)*v1 + cos(psi+a2)*v2 + cos(psi+a3)*v3 + cos(psi+a4)*v4);
	yaw_act = (v1+v2+v3+v4);

	// Odometry
    robot.xDistEnc = ext_enc_CounterX*kelilingRodaex/PPRex;
	robot.yDistEnc = ext_enc_CounterY1*kelilingRodaex/PPRex;
	robot.heading = (robot.yDistEnc+(ext_enc_CounterY2*kelilingRodaex/PPRex)) / 2*straight_distc; //in radian
	robot.xDistReal = robot.xDistEnc*sin(robot.heading) + robot.yDistEnc*cos(robot.heading);
	robot.yDistReal = robot.yDistEnc*cos(robot.heading) - robot.xDistEnc*sin(robot.heading);

    a1 = convertTo(a1, "DEG");
	a2 = convertTo(a2, "DEG");
	a3 = convertTo(a3, "DEG");
	a4 = convertTo(a4, "DEG");
	psi = convertTo(psi, "DEG");
}

void moveRobot(float speedX, float speedY, float yw) {
	// set speed here (max Vx_glb dan Vy_glb = 1 m/s)
	Vx_glb_aim = speedX;
	Vy_glb_aim = speedY;
	yaw_aim = yw;

	inverse_kinematic(Vx_glb_aim, Vy_glb_aim, yaw_aim, psi);
	
	// Signal Controller
	// Vx_glb_err = Vx_glb_aim - Vx_glb_act;
	// Vy_glb_err = Vy_glb_aim - Vy_glb_act;
	// V_glb_err = sqrt(pow(Vx_glb_err,2) + pow(Vy_glb_err,2));
	// V_glb_derr[1] = V_glb_err - V_glb_derr[0];
	// V_glb_derr[0] = V_glb_derr[1];
	// fuzzy_process(fuzzy_wheel1, wheel1, V_glb_err, V_glb_derr[1]);
	
	readEnc();

	forward_kinematic(wheel1.lin_vel_act, wheel2.lin_vel_act, wheel3.lin_vel_act, wheel4.lin_vel_act, psi);

	float err_dist = sqrt(pow((X_glb-X_glb_old),2) + pow((Y_glb-Y_glb_old),2));
	float err_theta = theta_glb - theta_glb_old;
	// err_dist = 0;
	// err_theta = 0;
	move_done = (err_dist <= 0.5 && err_theta <= 5) ? 1 : 0;
	// if(move_done) resetEnc();
}