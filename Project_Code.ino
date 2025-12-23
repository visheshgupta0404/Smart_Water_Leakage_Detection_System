int LEAKAGE_PIN = A0;
int CONTROL_PIN = 3;
int THRESHOLD = 1000;
bool flag = false;
unsigned long returnTime = 0;
unsigned long start = 0;
int l = 0;

void setup() {
  Serial.begin(9600);
  pinMode(CONTROL_PIN, OUTPUT);
  pinMode(LEAKAGE_PIN, INPUT);
  pinMode(13, OUTPUT); // Red LED
  pinMode(12, OUTPUT); // Yellow LED
  digitalWrite(CONTROL_PIN, LOW);
  Serial.println("Leakage Detection System Initialized.");
  Serial.println("Waiting for sensor readings...");
}

void loop() {
  digitalWrite(CONTROL_PIN, HIGH);
  delay(100);

  float sensorValue = analogRead(LEAKAGE_PIN);
  Serial.print("Sensor Voltage: ");
  Serial.println(sensorValue);

  if (sensorValue < THRESHOLD) {
    if (!flag) {
      flag = true;
      start = micros();
      Serial.println("Leakage Detected");
    }

    returnTime = micros();

    Serial.print("Leak Duration: ");
    Serial.print((returnTime - start) / 1000000.0);
    Serial.println(" seconds");

    // Severity Indication
    if (sensorValue > 600) {
      digitalWrite(13, HIGH); // Red LED for High severity
      digitalWrite(12, LOW);
    } else {
      digitalWrite(12, HIGH); // Yellow LED for Low severity
      digitalWrite(13, LOW);
    }

    // Serial Command Handling
    if (Serial.available() > 0) {
      char command = Serial.read();
      if (command == 'r') {
        Serial.println("Resetting system...");
        flag = false;
        start = 0;
      } else if (command == 't') {
        Serial.println("Current Threshold Value:");
        Serial.println(THRESHOLD);
      }
    }

    digitalWrite(CONTROL_PIN, LOW);
    delay(1000);
  } else {
    Serial.println("No Leakage Detected");
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    flag = false;
    start = 0;
    delay(1000);
  }
}
