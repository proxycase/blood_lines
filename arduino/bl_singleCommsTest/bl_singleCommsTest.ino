//#include <Scheduler.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>

void setup() {
  setupMotors();
  setupComms();
}

void loop() {
  loopComms();
}
