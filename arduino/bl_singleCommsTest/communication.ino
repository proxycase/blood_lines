String inputString;
void setupComms() {
  Serial.begin(9600);
  inputString = "";
}

void loopComms() {
  if(Serial.available()) {
    inputString = Serial.readStringUntil('|');
    Serial.println("got: " + inputString); 
    
    parseInput(inputString);
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
