Adafruit_MotorShield AFMS0(0x60), AFMS1(0x61), AFMS2(0x62), AFMS3(0x63), AFMS4(0x64), AFMS5(0x65), AFMS6(0x66), AFMS7(0x67);
Adafruit_MotorShield *AFMS[] = {&AFMS0, &AFMS1, &AFMS2, &AFMS3, &AFMS4, &AFMS5, &AFMS6, &AFMS7};

Adafruit_StepperMotor *stepper[MOTOR_COUNT];
AccelStepper accelStepper[MOTOR_COUNT];

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

void setupMotors() {
  for (int i = 0; i < MOTOR_COUNT; i++ ) {
    int board = i / 2;
    int motor_num = i % 2 + 1;
    stepper[i] = AFMS[board]->getStepper(REV_STEPS, motor_num);
    accelStepper[i] = AccelStepper(motorFunction[i * 2], motorFunction[i * 2 + 1]);
  }

  for ( int i = 0; i < BOARD_COUNT; i++ ) {
    AFMS[i]->begin();
    Serial.print( F("board[") ); Serial.print(i); Serial.print( F("] = ") ); Serial.println((unsigned long)AFMS[i], HEX);
    Serial.print( F("  motor[") ); Serial.print(i * 2); Serial.print( F("] = ") ); Serial.println((unsigned long) & (accelStepper[i * 2]), HEX);
    Serial.print( F("  motor[") ); Serial.print(i * 2 + 1); Serial.print( F("] = ") ); Serial.println((unsigned long) & (accelStepper[i * 2 + 1]), HEX);
  }

  for (AccelStepper k : accelStepper) {
    k.setMaxSpeed(100.0);
    k.setAcceleration(100.0);
    k.moveTo(0);
  }
}

// looped function
void runMotors() {
  for (int i = 0; i < MOTOR_COUNT; i++) {
    accelStepper[i].run();
    checkTargetReached(&accelStepper[i]);
  }
}

// called from communication
void activateMotor(int i, int k) {
  // run motor i at k seconds
  accelStepper[i].setAcceleration(100.0);
  accelStepper[i].moveTo(24 * k); // need to still figure out what equates to an ~second in step-time
}

// end of loop to reset motors that have reached their targets
void checkTargetReached(AccelStepper * as) {
  // when motor targets have been met, reset the position to 0
    if (as->distanceToGo() == 0 && as->currentPosition() != 0) {
      as->setCurrentPosition(0);
      Serial.println("reset pos");
    }
}
