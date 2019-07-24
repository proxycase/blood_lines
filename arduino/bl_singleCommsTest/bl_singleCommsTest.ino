#include <Scheduler.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <AccelStepper.h>

#define BOARD_COUNT 8
#define MOTOR_COUNT 15
#define REV_STEPS 200

Adafruit_MotorShield AFMS0(0x60), AFMS1(0x61), AFMS2(0x62), AFMS3(0x63), AFMS4(0x64), AFMS5(0x65), AFMS6(0x66), AFMS7(0x67);
Adafruit_MotorShield *AFMS[] = {&AFMS0, &AFMS1, &AFMS2, &AFMS3, &AFMS4, &AFMS5, &AFMS6, &AFMS7};

Adafruit_StepperMotor *stepper[MOTOR_COUNT];
AccelStepper accelStepper[MOTOR_COUNT];



void setup() {
  setupMotors();
  setupComms();

  Scheduler.startLoop(loopComms);
}

void loop() {
  // todo: need to make sure comms is non-blocking. Otherwise start a separate thread for it.
  
  runMotors();

  resetTargetsReached();
}
