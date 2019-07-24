void (*motorFunction[MOTOR_COUNT * 2])(void) = {
  &mf0, &mb0,
  &mf1, &mb1,
  &mf2, &mb2,
  &mf3, &mb3,
  &mf4, &mb4,
  &mf5, &mb5,
  &mf6, &mb6,
  &mf7, &mb7,
  &mf8, &mb8,
  &mf9, &mb9,
  &mf10, &mb10,
  &mf11, &mb11,
  &mf12, &mb12,
  &mf13, &mb13,
  &mf14, &mb14,
};

void mf0() {
  stepper[0]->onestep(FORWARD,  DOUBLE);
}
void mb0() {
  stepper[0]->onestep(BACKWARD, DOUBLE);
}
void mf1() {
  stepper[1]->onestep(FORWARD,  DOUBLE);
}
void mb1() {
  stepper[1]->onestep(BACKWARD, DOUBLE);
}
void mf2() {
  stepper[2]->onestep(FORWARD,  DOUBLE);
}
void mb2() {
  stepper[2]->onestep(BACKWARD, DOUBLE);
}
void mf3() {
  stepper[3]->onestep(FORWARD,  DOUBLE);
}
void mb3() {
  stepper[3]->onestep(BACKWARD, DOUBLE);
}
void mf4() {
  stepper[4]->onestep(FORWARD,  DOUBLE);
}
void mb4() {
  stepper[4]->onestep(BACKWARD, DOUBLE);
}
void mf5() {
  stepper[5]->onestep(FORWARD,  DOUBLE);
}
void mb5() {
  stepper[5]->onestep(BACKWARD, DOUBLE);
}
void mf6() {
  stepper[6]->onestep(FORWARD,  DOUBLE);
}
void mb6() {
  stepper[6]->onestep(BACKWARD, DOUBLE);
}
void mf7() {
  stepper[7]->onestep(FORWARD,  DOUBLE);
}
void mb7() {
  stepper[7]->onestep(BACKWARD, DOUBLE);
}
void mf8() {
  stepper[8]->onestep(FORWARD,  DOUBLE);
}
void mb8() {
  stepper[8]->onestep(BACKWARD, DOUBLE);
}
void mf9() {
  stepper[9]->onestep(FORWARD,  DOUBLE);
}
void mb9() {
  stepper[9]->onestep(BACKWARD, DOUBLE);
}
void mf10() {
  stepper[10]->onestep(FORWARD,  DOUBLE);
}
void mb10() {
  stepper[10]->onestep(BACKWARD, DOUBLE);
}
void mf11() {
  stepper[11]->onestep(FORWARD,  DOUBLE);
}
void mb11() {
  stepper[11]->onestep(BACKWARD, DOUBLE);
}
void mf12() {
  stepper[12]->onestep(FORWARD,  DOUBLE);
}
void mb12() {
  stepper[12]->onestep(BACKWARD, DOUBLE);
}
void mf13() {
  stepper[13]->onestep(FORWARD,  DOUBLE);
}
void mb13() {
  stepper[13]->onestep(BACKWARD, DOUBLE);
}
void mf14() {
  stepper[14]->onestep(FORWARD,  DOUBLE);
}
void mb14() {
  stepper[14]->onestep(BACKWARD, DOUBLE);
}
