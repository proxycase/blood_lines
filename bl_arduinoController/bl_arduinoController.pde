/*
* Blood Lines - Processing on Raspberry Pi
* Reads through the notes in CSV format and sends
* signal to an Arduino equipped with motors to play individual notes.
*/

float startTime;

void setup() 
{
  size(200, 200);
  setupComms();
  setupTable();
  startTime = getCurrTime();
}

void draw() {
  //checkComms();
  loopData();
}

void loopData() {
  // current Time
  float triggerTime = blTable.getTime();
  float curTime = getTimeDiff();
  
  if (triggerTime <= curTime) {
    println("reached time");
    sendComms(blTable.getWire(), blTable.getDuration());
    if (blTable.next()) {resetCurrTime();}
  } else {
    println("currently: " + curTime + " waiting for: " + triggerTime);
  }
}

float getCurrTime() {
  return ((float)(hour()*100) + (float)minute() + (float)second()/60);
}

float getTimeDiff() {
  return getCurrTime() - startTime;
}

void resetCurrTime() {
  // needed for when time:60 is reached
  startTime = getCurrTime();
}
