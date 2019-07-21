import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(200, 200);
  String[] portNames = Serial.list();
  printArray(portNames);
  String portName = Serial.list()[10];
  println(portName);
  myPort = new Serial(this, portName, 9600);
  myPort.clear();
}

void draw() {
  if(myPort.available() > 0) {
    String inputString = myPort.readStringUntil('\n');
    if (inputString != null) {
      println(inputString);
    }
  }
}

void mouseClicked() {
  println("clicked");
  myPort.write((int)random(10)+","+(int)random(2000)+"|");
  
}

//void serialEvent(Serial myPort) {
//  if (myPort.available() > 0) {
//    String inputString = myPort.readStringUntil(10);
//    if (inputString != null) {
//      println(inputString);
//    }
//  }
//}
