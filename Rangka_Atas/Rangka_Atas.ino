#include <AccelStepper.h>

#define DIR_PIN 8
#define STEP_PIN 9
#define ENABLE_PIN 10

#define STEPS_PER_REV 200
#define MICROSTEPPING 16
#define PITCH (47.14 * 2)  // mm per putaran ulir
#define STEPS_PER_MM (STEPS_PER_REV * MICROSTEPPING / PITCH)
#define JARAK 100

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

#include <Servo.h>

// === Pin Configuration ===
#define SERVO_PIN 7     // Pin PWM untuk servo
#define TX2_PIN 18       // TX2 (output ke ESP, optional if ESP needs feedback)
#define RX2_PIN 19       // RX2 (input dari ESP)

#define RELAY_POMPA 35
#define RELAY_KATUP 37

Servo myservo;
String input = "";
int pos = 90; // posisi awal (tengah)

void setup() {
  myservo.attach(SERVO_PIN);  // Sambungkan servo
  myservo.write(pos);         // Set posisi awal

  Serial.begin(9600);         // Debugging via USB
  Serial2.begin(9600);        // Komunikasi dengan ESP

  Serial.println(">> Arduino Due siap mengontrol servo.");
  Serial2.println(">> Koneksi berhasil ke Arduino Due.");

  pinMode(RELAY_POMPA, OUTPUT);
  pinMode(RELAY_KATUP, OUTPUT);

  digitalWrite(RELAY_POMPA, 1); // 1 = matikan pompa
  digitalWrite(RELAY_KATUP, 1); // 0 = nyalakan

  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, HIGH);  // Matikan motor saat idle

  stepper.setMaxSpeed(500);
  stepper.setAcceleration(3000);
}

void gerakServo(String perintah) {
  if (perintah == "r1" && pos < 180) {
    for (int i = pos; i <= 180; i++) {
      myservo.write(i);
      delay(10);
    }
    pos = 180;
    Serial2.println("-> Servo ke kanan (180)");
  } else if (perintah == "l1" && pos > 0) {
    for (int i = pos; i >= 0; i--) {
      myservo.write(i);
      delay(10);
    }
    pos = 0;
    Serial2.println("-> Servo ke kiri (0)");
  } else {
    Serial2.println("! Posisi servo sudah di tempat.");
  }
}

void move_distance(float distance) {
    int steps = distance * STEPS_PER_MM;

    digitalWrite(ENABLE_PIN, HIGH);  // Aktifkan motor
    stepper.moveTo(steps);  //

    while (stepper.distanceToGo() != 0) {
        stepper.run();
    }

    digitalWrite(ENABLE_PIN, LOW);  // Matikan motor setelah selesai
}

void lengan(String perintah) {
  if (perintah == "r1" && "circle") {
    move_distance(JARAK);

    Serial2.println("-> Lengan maju");
  }
  else if (perintah == "l1" && "circle") {
    move_distance(-JARAK);

    Serial2.println("-> Lengan mundur");
  }
}

void vakumPompa(String perintah) {
  if (perintah == "r2") {
    digitalWrite(RELAY_POMPA, HIGH);
    delay(5000); // 5 detik
    digitalWrite(RELAY_POMPA, LOW);
    delay(2000); // jeda 2 detik

    Serial2.println("-> Vakum nyala");
  }
  else if (perintah == "l2") {
    digitalWrite(RELAY_KATUP, HIGH);
    delay(5000); // 5 detik
    digitalWrite(RELAY_KATUP, LOW);
    delay(2000); // jeda 2 detik
    
    Serial2.println("-> Vakum mati");
    }
}

void bacaSerial(HardwareSerial& port) {
  if (port.available()) {
    input = port.readStringUntil('\n');
    input.trim();  // Buang \r atau spasi
  }
    else if (input.length() > 0) {
      Serial.print("[Input ");
      Serial.print(&port == &Serial ? "USB" : "ESP");
      Serial.print("] ");
      Serial.println(input);
      gerakServo(input);
    }
  }

void loop() {
  bacaSerial(Serial);   // dari USB
  bacaSerial(Serial2);  // dari ESP
}
