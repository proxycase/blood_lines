// this should have functions for recieving commands via serial

String inputString = "";
bool inputRecieved = false;

void setupComms() {
  Serial.begin(9600);
}

void loopComms() {
  if (inputRecieved) {
    
    // do something with the string
    Serial.println(inputString);
    int whichMotor = interpretString(inputString);

    // clear string
    inputString = "";
    inputRecieved = false;
  }
}

void serialEvent() {
  while(Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inChar == '\n') {
      inputRecieved = true;
    }
  }
}

//String charMap[] = {'0','1','2','3','4','5','6','7','8','9','10',.....?
int interpretString(String s) {
  // should match s from 0 - 7 and return an int.
  
  
  return 0;
}

void commandMotor(int m) {
  
}
