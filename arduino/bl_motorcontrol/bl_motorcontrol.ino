const int ARDUINO_ID = 0; // either 0 or 1

void setup() {
  setupComms();
  establishContact();
  setupMotors();
}

void loop() {
  loopComms();
  loopMotors();
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.write(ARDUINO_ID);
    Serial.write('\n');
    delay(300);
  }
}
