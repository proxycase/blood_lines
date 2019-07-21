
Adafruit_MotorShield AFMS0(0x60); // 00000 Default address, no jumpers
Adafruit_MotorShield *AFMS[] = {&AFMS0};
const int MOTOR_COUNT = 1, REV_STEPS = 200;
Adafruit_StepperMotor *steppers[MOTOR_COUNT];

void setupMotors() {
  for (int i = 0; i < MOTOR_COUNT; i++) {
    steppers[i] = AFMS[i]->getStepper(REV_STEPS, 1);
    steppers[++i] = AFMS[i]->getStepper(REV_STEPS, 2);
    AFMS[i]->begin();
  }
}

void runMotor(int m, int dur) {  
  Serial.println("run motor: " + (String)m + " for time: " + (String)dur);
//  steppers[m]->step(dur, FORWARD, INTERLEAVE);
}
