import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setupComms() {
  String[] portNames = Serial.list();
  printArray(portNames);
  myPort = new Serial(this, "/dev/ttyACM0", 9600);

}

void checkComms() {
  if(myPort.available() > 0) {
    String inputString = myPort.readStringUntil('\n');
    if (inputString != null) {
      println(inputString);
    }
  }
}

void sendComms(int wire, int duration) {
  myPort.write(wire + "," + duration + "|");
}

//void serialEvent(Serial myPort) {
//  if (myPort.available() > 0) {
//    String inputString = myPort.readStringUntil(10);
//    if (inputString != null) {
//      println(inputString);
//    }
//  }
//}
