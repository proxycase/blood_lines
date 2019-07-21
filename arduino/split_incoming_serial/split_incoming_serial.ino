/* 
 *  This sketch exemplifies taking a specific 
 *  Serial message like "3,2000|"
 *  and splitting that up for use by a motor.
 */

#include <Wire.h>

String inputString = "";

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
}

void serialEvent() {
  if(Serial.available()) {
    inputString = Serial.readStringUntil('|');
  }
  Serial.println(inputString);
  parseInput(inputString);
}

void parseInput(String s) {
  int delimPos = s.indexOf(',');
  
  if (delimPos > -1) {
    String whichMotor = s.substring(0, delimPos);
    String duration = s.substring(delimPos+1);
    runMotor(whichMotor.toInt(), duration.toInt());
  } else {
    Serial.println("found nothing");
  }
}

void runMotor(int m, int t) {
  Serial.print("run motor: ");
  Serial.print(m);
  Serial.print(" for time: ");
  Serial.println(t);
}
