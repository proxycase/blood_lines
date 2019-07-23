import processing.serial.*;

Serial myPort;  // Create object from Serial class
boolean commsEnabled = false;
int val;        // Data received from the serial port

void setupComms() {
  String[] portNames = Serial.list();
  printArray(portNames);
  String portName = Serial.list()[10];
  println(portName);
  myPort = new Serial(this, portName, 9600);
  //try {
  //  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
  //  myPort.clear();
  //  commsEnabled = true;
  //} catch (RuntimeException r) {
  //  r.printStackTrace();
  //  return;
  //}
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
