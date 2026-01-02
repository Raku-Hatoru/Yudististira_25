#include <Arduino.h>
#include "variabel.h"

void readEnc1() {
    bool a = digitalRead(EncMotora1);
    bool b = digitalRead(EncMotorb1);
    if(a) {
        if(b) wheel1.counter--;
        else wheel1.counter++;
    }
    else {
        if(b) wheel1.counter++;
        else wheel1.counter--;
    }
}

void readEnc2() {
    bool a = digitalRead(EncMotora2);
    bool b = digitalRead(EncMotorb2);
    if(a) {
        if(b) wheel1.counter--;
        else wheel1.counter++;
    }
    else {
        if(b) wheel1.counter++;
        else wheel1.counter--;
    }
}

void readEnc3() {
    bool a = digitalRead(EncMotora3);
    bool b = digitalRead(EncMotorb3);
    if(a) {
        if(b) wheel1.counter--;
        else wheel1.counter++;
    }
    else {
        if(b) wheel1.counter++;
        else wheel1.counter--;
    }
}

void readEnc4() {
    bool a = digitalRead(EncMotora4);
    bool b = digitalRead(EncMotorb4);
    if(a) {
        if(b) wheel1.counter--;
        else wheel1.counter++;
    }
    else {
        if(b) wheel1.counter++;
        else wheel1.counter--;
    }
}

void readEncExtX() {
    bool a = digitalRead(EncExta1);
    bool b = digitalRead(EncExtb1);
    if(a) {
        if(b) rotX.counter--;
        else rotX.counter++;
    }
    else {
        if(b) rotX.counter++;
        else rotX.counter--;
    }
}

void readEncExtY1() {
    bool a = digitalRead(EncExta2);
    bool b = digitalRead(EncExtb2);
    if(a) {
        if(b) rotY1.counter--;
        else rotY1.counter++;
    }
    else {
        if(b) rotY1.counter++;
        else rotY1.counter--;
    }
}

void readEncExtY2() {
    bool a = digitalRead(EncExta3);
    bool b = digitalRead(EncExtb3);
    if(a) {
        if(b) rotY2.counter--;
        else rotY2.counter++;
    }
    else {
        if(b) rotY2.counter++;
        else rotY2.counter--;
    }
}

void set_motor() {
    pinMode(sw_B1, OUTPUT);
    pinMode(sw_C1, OUTPUT);
    pinMode(sw_B2, OUTPUT);
    pinMode(sw_C2, OUTPUT);

    pinMode(pwm1, OUTPUT);
    pinMode(pwm2, OUTPUT);
    pinMode(pwm3, OUTPUT);
    pinMode(pwm4, OUTPUT);

    pinMode(EncMotora1, INPUT);
    pinMode(EncMotorb1, INPUT);
    pinMode(EncMotora2, INPUT);
    pinMode(EncMotorb2, INPUT);
    pinMode(EncMotora3, INPUT);
    pinMode(EncMotorb3, INPUT);
    pinMode(EncMotora4, INPUT);
    pinMode(EncMotorb4, INPUT);

    attachInterrupt(digitalPinToInterrupt(EncMotora1),readEnc1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncMotora2),readEnc2, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncMotora3),readEnc3, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncMotora4),readEnc4, CHANGE);

    attachInterrupt(digitalPinToInterrupt(EncExta1),readEncExtX, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncExta2),readEncExtY1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(EncExta3),readEncExtY2, CHANGE);

    wheel1.pwm = 0;
    wheel2.pwm = 0;
    wheel3.pwm = 0;
    wheel4.pwm = 0;

    wheel1.pwmff = 0;
    wheel2.pwmff = 0;
    wheel3.pwmff = 0;
    wheel4.pwmff = 0;

    Vx_glb_act = 0;
	Vy_glb_act = 0;
	V_glb_derr[0] = 0;
}

void motor_treat(uint16_t motor_num, int16_t direction, uint16_t pwm_power) {
	// direction: 1 -> CW, -1 -> CCW, 0 -> STOP
	// pwm power: 0-255

    if(motor_num == 1) {
		if(direction==1) {
            analogWrite(pwm1, pwm_power);
			digitalWrite(sw_B1, 1);
		} else if(direction==-1){
            analogWrite(pwm1, pwm_power);
			digitalWrite(sw_B1, 0);
		} else {
            analogWrite(pwm1, 0);
			digitalWrite(sw_B1, 0);
		}
	}
	else if(motor_num == 2) {
		if(direction==1) {
            analogWrite(pwm2, pwm_power);
			digitalWrite(sw_C1, 1);
		} else if(direction==-1){
            analogWrite(pwm2, pwm_power);
			digitalWrite(sw_C1, 0);
		} else {
            analogWrite(pwm2, 0);
			digitalWrite(sw_C1, 0);
		}
	}
	else if(motor_num == 3) {
		if(direction==1) {
            analogWrite(pwm3, pwm_power);
			digitalWrite(sw_B2, 1);
		} else if(direction==-1){
            analogWrite(pwm3, pwm_power);
			digitalWrite(sw_B2, 0);
		} else {
            analogWrite(pwm3, 0);
			digitalWrite(sw_B2, 0);
		}
	}
	else if(motor_num == 4) {
		if(direction==1) {
            analogWrite(pwm4, pwm_power);
			digitalWrite(sw_C2, 1);
		} else if(direction==-1){
            analogWrite(pwm4, pwm_power);
			digitalWrite(sw_C2, 0);
		} else {
            analogWrite(pwm4, 0);
			digitalWrite(sw_C2, 0);
		}
	}
}