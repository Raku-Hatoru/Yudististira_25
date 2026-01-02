#include <Ps3Controller.h>
#include <HardwareSerial.h>

// UART objects (ESP32)
HardwareSerial SerialSTM(2);      // UART2 (contoh: RX=16, TX=17) -> ke STM32
HardwareSerial SerialArduino(1);  // UART1 (contoh: RX=25, TX=27) -> ke Arduino

void notify() {
  // --- Baca stick kiri (L3) ---
  int lx = Ps3.data.analog.stick.lx;   // contoh rentang -128..+127
  int ly = Ps3.data.analog.stick.ly;

  // Normalisasi: invert Y agar "atas" = positif
  int sx = lx;    // kanan = +, kiri = -
  int sy = -ly;   // sekarang atas = +, bawah = -

  const int DEADZONE = 15;
  if (abs(sx) < DEADZONE) sx = 0;
  if (abs(sy) < DEADZONE) sy = 0;

  // // Tentukan arah — cek diagonal dulu
  // if (sx > 0 && sy > 0) {
  //   Serial.println("kanan_atas");
  //   SerialSTM.println("kanan_atas");
  // }
  // else if (sx > 0 && sy < 0) {
  //   Serial.println("kanan_bawah");
  //   SerialSTM.println("kanan_bawah");
  // }
  // else if (sx < 0 && sy > 0) {
  //   Serial.println("kiri_atas");
  //   SerialSTM.println("kiri_atas");
  // }
  // else if (sx < 0 && sy < 0) {
  //   Serial.println("kiri_bawah");
  //   SerialSTM.println("kiri_bawah");
  // }
  // else if (sx > 0 && sy == 0) {
  //   Serial.println("kanan");
  //   SerialSTM.println("kanan");
  // }
  // else if (sx < 0 && sy == 0) {
  //   Serial.println("kiri");
  //   SerialSTM.println("kiri");
  // }
  // else if (sx == 0 && sy > 0) {
  //   Serial.println("atas");
  //   SerialSTM.println("atas");
  // }
  // else if (sx == 0 && sy < 0) {
  //   Serial.println("bawah");
  //   SerialSTM.println("bawah");
  // }
  // else sx==0 && sy==0 -> tidak bergerak

  // --- Tombol (gunakan event.button_down untuk deteksi tekanan) ---
  if (Ps3.event.button_down.up) {
    Serial.println("atas");
    SerialArduino.println("atas");
  }
  if (Ps3.event.button_down.right) {
    Serial.println("kanan");
    SerialArduino.println("kanan");
  }
  if (Ps3.event.button_down.down) {
    Serial.println("bawah");
    SerialArduino.println("bawah");
  }
  if (Ps3.event.button_down.left) {
    Serial.println("kiri");
    SerialArduino.println("kiri");
  }
  if (Ps3.event.button_down.r1) {
    Serial.println("r1");
    SerialArduino.println("r1");
  }
  if (Ps3.event.button_down.l1) {
    Serial.println("l1");
    SerialArduino.println("l1");
  }
  if (Ps3.event.button_down.r2) {
    Serial.println("r2");
    SerialArduino.println("r2");
  }
  if (Ps3.event.button_down.l2) {
    Serial.println("l2");
    SerialArduino.println("l2");
  }
  if (Ps3.event.button_down.triangle) {
    Serial.println("segitiga");
    SerialArduino.println("segitiga");
  }
  if (Ps3.event.button_down.circle) {
    Serial.println("bulat");
    SerialArduino.println("bulat");
  }
}

void onConnect(){
  Serial.println("PS3 Connected.");
}

void setup() {
  Serial.begin(9600);                    // Serial monitor USB
  // Inisialisasi UART: sesuaikan pin RX/TX yang kamu pakai pada board
  SerialSTM.begin(9600, SERIAL_8N1, 16, 17);   // contoh RX=16, TX=17 untuk UART2
  SerialArduino.begin(9600, SERIAL_8N1, 34, 32); // contoh RX=25, TX=27 untuk UART1

  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin("00:00:00:00:00:01");

  Serial.println("ESP32 siap, kirim data ke STM & Arduino...");
  SerialSTM.println("ESP32 -> STM siap");
  SerialArduino.println("ESP32 -> Arduino siap");
}

void loop() {
  if (!Ps3.isConnected()) return;
  Ps3.setPlayer(1);
  delay(100);
}
