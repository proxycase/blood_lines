//#include <Scheduler.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>
const int BOARD_COUNT = 8, MOTOR_COUNT = 15, REV_STEPS = 200;

void setup() {
  setupMotors();
  setupComms();
}

void loop() {
  // todo: need to make sure comms is non-blocking. Otherwise start a separate thread for it.
  loopComms();
  runMotors();

  resetTargetsReached();
}
