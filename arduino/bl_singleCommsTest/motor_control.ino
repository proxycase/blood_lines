

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
  }
}

// called from communication
void activateMotor(int i, int k) {
  // run motor i at k seconds
  accelStepper[i].setAcceleration(100.0);
  accelStepper[i].moveTo(24 * k); // need to still figure out what equates to an ~second in step-time
}

// end of loop to reset motors that have reached their targets
void resetTargetsReached() {
  // when motor targets have been met, reset the position to 0
  for (AccelStepper s : accelStepper) {
    if (s.distanceToGo() == 0 && s.currentPosition() != 0)
      s.setCurrentPosition(0);
  }
}
