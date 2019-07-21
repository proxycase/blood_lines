#include <Wire.h>
#include <Adafruit_MotorShield.h>

/*
   Blood Lines - Motor Control
   Eight Adafruit Motorshields, 15 Motors
*/

Adafruit_MotorShield AFMS0(0x60), AFMS1(0x61),AFMS2(0x62), AFMS3(0x63), AFMS4(0x64), AFMS5(0x65), AFMS6(0x66), AFMS7(0x67); // 00111
Adafruit_MotorShield *AFMS[] = {&AFMS0, &AFMS1, &AFMS2, &AFMS3, &AFMS4, &AFMS5, &AFMS6, &AFMS7};
const int MOTOR_COUNT = 15, REV_STEPS = 200;
Adafruit_StepperMotor *steppers[MOTOR_COUNT];

void setupMotors() {
  for (int i = 0; i < 15; i++) {
    steppers[i] = AFMS[i]->getStepper(REV_STEPS, 1);
    steppers[++i] = AFMS[i]->getStepper(REV_STEPS, 2);
    AFMS[i]->begin();
  }
}

//// The above replaces this being repeated too many times...
//Adafruit_StepperMotor *s1 = AFMS0.getStepper(REV_STEPS, 1);
//Adafruit_StepperMotor *s2 = AFMS0.getStepper(REV_STEPS, 2);

void runMotor(int m) {
  steppers[m]->step(100, FORWARD, INTERLEAVE);
}
