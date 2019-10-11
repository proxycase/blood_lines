String inputString = "";
bool stringComplete = false;

void setupComms() {
  Serial.begin(9600);
  inputString.reserve(200);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loopComms() {
  if(stringComplete) {
    Serial.println(inputString);
    parseInput(inputString);
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '|' || inChar == '\n') {
      stringComplete = true;
    }
  }
}

void parseInput(String s) {
  int delimAt = s.indexOf(',');

  if (delimAt > -1) {
    activateMotor(
      s.substring(0, delimAt).toInt(), 
      s.substring(delimAt+1).toInt()
    );
  } else {
    Serial.println("wrong message format, please mimic: 1,1000|");
    Serial.flush();
  }
}
