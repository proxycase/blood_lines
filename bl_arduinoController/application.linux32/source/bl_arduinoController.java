import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class bl_arduinoController extends PApplet {

/*
* Blood Lines - Processing on Raspberry Pi
* Reads through the notes in CSV format and sends
* signal to an Arduino equipped with motors to play individual notes.
*/

float startTime;
boolean debug = false;

public void setup() 
{
  
  setupComms();
  setupTable();
  startTime = getCurrTime();
}

public void draw() {
  //checkComms();
  loopData();
}

public void loopData() {
  // current Time
  float triggerTime = blTable.getTime();
  float curTime = getTimeDiff();
  
  if (triggerTime <= curTime) {
    println("reached time");
    sendComms(blTable.getWire(), blTable.getDuration());
    if (blTable.next()) {resetCurrTime();}
  } else {
    if (debug) println("currently: " + curTime + " waiting for: " + triggerTime);
  }
}

public float getCurrTime() {
  return ((float)(hour()*100) + (float)minute() + (float)second()/60);
}

public float getTimeDiff() {
  return getCurrTime() - startTime;
}

public void resetCurrTime() {
  // needed for when time:60 is reached
  startTime = getCurrTime();
}


Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

public void setupComms() {
  String[] portNames = Serial.list();
  printArray(portNames);
  String portName = Serial.list()[0];
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

public void checkComms() {
  if(myPort.available() > 0) {
    String inputString = myPort.readStringUntil('\n');
    if (inputString != null) {
      println(inputString);
    }
  }
}

public void sendComms(int wire, int duration) {
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
public void keyPressed() {
  if (key == 'j') {
    blTable.prev();
  } else if (key == 'l') {
    blTable.next();
  } else if (key == 'k') {
    blTable.printout();
  }
}

// THIS IS USED FOR TESTING SIGNAL
public void mouseClicked() {
  println("clicked");
  myPort.write((int)random(10)+","+(int)random(2000)+"|");
  
}
BL_Table blTable;

public void setupTable() {
  blTable = new BL_Table();
  blTable.update();
}

class BL_Table {
  Table table;
  TableRow row;
  int position;

  BL_Table() {
    table = loadTable("bl_timelinenotes.csv", "header");
    println(table.getRowCount() + " total rows in table");
    position = 0;
  }
  public void update() {
    row = table.getRow(position);
    println("updated row: " + position);
  }
  
  public boolean next() {
    if (!(position >= table.getRowCount()-1)) {
      position++;
      this.update();
      return false;
    } else {
      println("reached end, resetting");
      position = 0;
      this.update();
      return true;
    }
  }
  
  public void prev() {
    if (!(position <= 0)) {
      position--;
      this.update();
    } else {
      println("cant go further back");
    }
  }
  
  public void printout() {
    println("wire: " + getWire() + " time: " + getTime() + " dur: " + getDuration());
  }
  
  public int getWire() {
    return row.getInt("Wire");
  }
  
  public float getTime() {
    return row.getFloat("Time");
  }
  
  public int getDuration() {
    return row.getInt("Duration");
  }
}
  public void settings() {  size(200, 200); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "bl_arduinoController" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
