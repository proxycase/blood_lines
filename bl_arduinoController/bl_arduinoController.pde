import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(200, 200);
  String portName = Serial.list()[1];
  println(portName);
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
}

void draw() {
  while(myPort.available() > 0) {
    String inputString = myPort.readStringUntil(10);
    if (inputString != null) {
      println(inputString);
    }
  }
}

void mouseClicked() {
  println("clicked");
  myPort.write("2,2000|");
}

//void serialEvent(Serial myPort) {
//  if (myPort.available() > 0) {
//    String inputString = myPort.readStringUntil(10);
//    if (inputString != null) {
//      println(inputString);
//    }
//  }
//}
