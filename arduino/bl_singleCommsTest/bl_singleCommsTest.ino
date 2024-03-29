#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>

#define BOARD_COUNT 8
#define MOTOR_COUNT 15
#define REV_STEPS 200


void setup() {
  setupComms();
  setupMotors();
}

void loop() {
  // todo: need to make sure comms is non-blocking. Otherwise start a separate thread for it.
  loopComms();
  runMotors();
}
