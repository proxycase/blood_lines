Adafruit_MotorShield AFMS0(0x60), AFMS1(0x61), AFMS2(0x62), AFMS3(0x63), AFMS4(0x64), AFMS5(0x65), AFMS6(0x66), AFMS7(0x67);
Adafruit_MotorShield *AFMS[] = {&AFMS0, &AFMS1, &AFMS2, &AFMS3, &AFMS4, &AFMS5, &AFMS6, &AFMS7};

Adafruit_StepperMotor *stepper[MOTOR_COUNT];

void mf0() {
  stepper[0]->onestep(FORWARD,  DOUBLE);
}
void mf1() {
  stepper[1]->onestep(FORWARD,  DOUBLE);
}
void mf2() {
  stepper[2]->onestep(FORWARD,  DOUBLE);
}
void mf3() {
  stepper[3]->onestep(FORWARD,  DOUBLE);
}
void mf4() {
  stepper[4]->onestep(FORWARD,  DOUBLE);
}
void mf5() {
  stepper[5]->onestep(FORWARD,  DOUBLE);
}
void mf6() {
  stepper[6]->onestep(FORWARD,  DOUBLE);
}
void mf7() {
  stepper[7]->onestep(FORWARD,  DOUBLE);
}
void mf8() {
  stepper[8]->onestep(FORWARD,  DOUBLE);
}
void mf9() {
  stepper[9]->onestep(FORWARD,  DOUBLE);
}
void mf10() {
  stepper[10]->onestep(FORWARD,  DOUBLE);
}
void mf11() {
  stepper[11]->onestep(FORWARD,  DOUBLE);
}
void mf12() {
  stepper[12]->onestep(FORWARD,  DOUBLE);
}
void mf13() {
  stepper[13]->onestep(FORWARD,  DOUBLE);
}
void mf14() {
  stepper[14]->onestep(FORWARD,  DOUBLE);
}

void (*motorFunction[MOTOR_COUNT * 2])(void) = {
  &mf0,
  &mf1,
  &mf2,
  &mf3,
  &mf4,
  &mf5,
  &mf6,
  &mf7,
  &mf8,
  &mf9,
  &mf10,
  &mf11,
  &mf12,
  &mf13,
  &mf14
};