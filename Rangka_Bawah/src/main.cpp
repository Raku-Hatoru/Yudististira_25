#include <Arduino.h>
#include "variabel.h"
#include "motor.h"
#include "kinematics.h"
#include <HardwareSerial.h>
#include <Servo.h>

Servo myservo;
HardwareSerial MySerial(PB3, PA15);  // Gunakan pin UART yang sesuai board

int Awal = 0;
int Akhir = 90;
bool kanan, kiri, atas, bawah, kiri_atas, kanan_atas, kiri_bawah, kanan_bawah,segitiga,bulat;

void setup() {
  MySerial.begin(9600);            // Inisialisasi UART manual
  set_motor();
  delay(500);
  myservo.attach(PA1);
  myservo.write(Awal);
}

void resetArah() {
  kanan = kiri = atas = bawah = kiri_atas = kanan_atas = kiri_bawah = kanan_bawah = segitiga = bulat = false ;
}

void loop() {

  if (MySerial.available()) {
    String strData = MySerial.readStringUntil('\n');
    strData.trim();  // Hapus spasi, newline

    if (strData == "kanan") kanan = true;
    else if (strData == "kiri") kiri = true;
    else if (strData == "kanan_atas") kanan_atas = true;
    else if (strData == "kiri_atas") kiri_atas = true;
    else if (strData == "kanan_bawah") kanan_bawah = true;
    else if (strData == "kiri_bawah") kiri_bawah = true;
    else if (strData == "atas") atas = true;
    else if (strData == "bawah") bawah = true;
    else if (strData == "segitiga") segitiga = true;
    else if (strData == "bulat") bulat = true;
  }

  if (kanan) {
    motor_treat(1, 1, 150);
    motor_treat(2, 1, 150);
    motor_treat(3, -1, 150);
    motor_treat(4, -1, 150);
	delay(1000);
    motor_treat(1, 1, 0);
    motor_treat(2, 1, 0);
    motor_treat(3, 1, 0);
    motor_treat(4, 1, 0);
	resetArah();
  }
  else if (kiri) {
    motor_treat(1, -1, 150);
    motor_treat(2, -1, 150);
    motor_treat(3, 1, 150);
    motor_treat(4, 1, 150);
	delay(1000);
    motor_treat(1, 1, 0);
    motor_treat(2, 1, 0);
    motor_treat(3, 1, 0);
    motor_treat(4, 1, 0);
	resetArah();
  }
  else if (atas) {
    motor_treat(1, -1, 150);
    motor_treat(2, 1, 150);
    motor_treat(3, 1, 150);
    motor_treat(4, -1, 150);
	delay(1000);
    motor_treat(1, 1, 0);
    motor_treat(2, 1, 0);
    motor_treat(3, 1, 0);
    motor_treat(4, 1, 0);
	resetArah();

  }
  else if (segitiga) {
    motor_treat(1, -1, 50);
    motor_treat(2, -1, 50);
    motor_treat(3, -1, 50);
    motor_treat(4, -1, 50);
	delay(1000);
    motor_treat(1, 1, 0);
    motor_treat(2, 1, 0);
    motor_treat(3, 1, 0);
    motor_treat(4, 1, 0);
	resetArah();
  }
  else if (bulat) {
    motor_treat(1, 1, 50);
    motor_treat(2, 1, 50);
    motor_treat(3, 1, 50);
    motor_treat(4, 1, 50);
	delay(1000);
    motor_treat(1, 1, 0);
    motor_treat(2, 1, 0);
    motor_treat(3, 1, 0);
    motor_treat(4, 1, 0);
	resetArah();
  }
  // else if (kanan_atas) {
  //   motor_treat(1, 0, 0);
  //   motor_treat(2, 1, 180);
  //   motor_treat(3, 0, 0);
  //   motor_treat(4, -1, 180);
	// delay(1000);
	// resetArah();
  // }
  // else if (kiri_atas) {
  //   motor_treat(1, -1, 180);
  //   motor_treat(2, 0, 0);
  //   motor_treat(3, 1, 180);
  //   motor_treat(4, 0, 0);
	// delay(1000);
	// resetArah();
  // }
  else if (bawah) {
    motor_treat(1, 1, 150);
    motor_treat(2, -1, 150);
    motor_treat(3, -1, 150);
    motor_treat(4, 1, 150);
	delay(1000);
    motor_treat(1, 1, 0);
    motor_treat(2, 1, 0);
    motor_treat(3, 1, 0);
    motor_treat(4, 1, 0);
	resetArah();
  }
  // else if (kanan_bawah) {
  //   motor_treat(1, 1, 180);
  //   motor_treat(2, 0, 0);
  //   motor_treat(3, -1, 180);
  //   motor_treat(4, 0, 0);
	// delay(1000);
	// resetArah();
  // }
  // else if (kiri_bawah) {
  //   motor_treat(1, 0, 0);
  //   motor_treat(2, -1, 180);
  //   motor_treat(3, 0, 0);
  //   motor_treat(4, 1, 180);
	// delay(1000);
	// resetArah();
  // }
  // else {
  //   // Standby atau idle
  //   motor_treat(1, 1, 70);
  //   motor_treat(2, -1, 70);
  //   motor_treat(3, 1, 70);
  //   motor_treat(4, -1, 70);
  // }
}
