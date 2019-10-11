#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);
#define BOARD_COUNT 8
#define MOTOR_COUNT 15
#define REV_STEPS 200

void setup() {
  Serial.begin(9600);

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(10);  // 10 rpm   
}

void loop() {
  // check communication for new lines and bring it in
  checkCommunications();

  // run motors
  runActiveMotors();
}

void runActiveMotors() {
  // for motors in array

  // check if it has time left to run
    // run if so
}

void oneStep(Adafruit_StepperMotor *motor) {
  motor->onestep(FORWARD, DOUBLE);
}

