#include <Servo.h>

// === PIN CONFIGURATION ===
const int servoPin = 13;     // Servo control pin
const int motorPin = 26;     // DC motor control pin

// === SERVO POSITIONS ===
const int ANGLE_RIPE = 30;
const int ANGLE_UNRIPE = 90;
const int ANGLE_ROTTEN = 150;
const int ANGLE_DEFAULT = 90;

// === GLOBAL VARIABLES ===
Servo sorterServo;
bool conveyorRunning = false;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}  // Wait for Serial Monitor / connection

  // Setup servo and motor pin
  sorterServo.attach(servoPin);
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);  // Conveyor off by default

  sorterServo.write(ANGLE_DEFAULT);  // Center the servo

  Serial.println("✅ ESP32 Lemon Sorter Ready");
}

void loop() {
  if (Serial.available()) {
    String incomingData = Serial.readStringUntil('\n');
    incomingData.trim();

    // Start conveyor when command received
    if (incomingData == "START_CONVEYOR") {
      conveyorRunning = true;
      digitalWrite(motorPin, HIGH);
      Serial.println("🛠️ Conveyor Belt Started");
    }
    
    // If conveyor is running, handle object sorting
    else if (conveyorRunning) {
      Serial.print("📦 Object Detected: ");
      Serial.println(incomingData);

      if (incomingData == "ripe_lemon") {
        sorterServo.write(ANGLE_RIPE);
        Serial.println("🍋 Ripe → Servo to 30°");
      } 
      else if (incomingData == "unripe_lemon") {
        sorterServo.write(ANGLE_UNRIPE);
        Serial.println("🟢 Unripe → Servo to 90°");
      } 
      else if (incomingData == "rotten_lemon") {
        sorterServo.write(ANGLE_ROTTEN);
        Serial.println("🤢 Rotten → Servo to 150°");
      } 
      else {
        sorterServo.write(ANGLE_DEFAULT);
        Serial.println("⚠️ Unknown class → Resetting Servo");
      }

      delay(1000);  // Allow time to divert lemon
      sorterServo.write(ANGLE_DEFAULT);  // Reset position
    }
  }
}
