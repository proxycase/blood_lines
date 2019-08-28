/*
* Blood Lines - Processing on Raspberry Pi
 * Reads through the notes in CSV format and sends
 * signal to an Arduino equipped with motors to play individual notes.
 */

float startTime;
boolean debug = true;
boolean reachedEnd = false;

void setup() 
{
  size(600, 600);
  frameRate(2);
  setupComms();
  setupTable();
  startTime = getCurrTime();
  setupConsole();
}

void draw() {
  drawConsole();
  loopData();
}

void loopData() {
  // current Time
  float triggerTime = blTable.getTime();
  float curTime = getTimeDiff();

  if (triggerTime <= curTime) {
    println("reached time");
    sendComms(blTable.getWire(), blTable.getDuration());
    blTable.next();
    if (reachedEnd) {
      resetCurrTime();
      reachedEnd = false;
    }
  } else {
    if (debug) println("currently: " + curTime + " waiting for: " + triggerTime);
  }
}

float getCurrTime() {
  float k = millis()/1000;
  return k;
}

float getTimeDiff() {
  return getCurrTime() - startTime;
}

void resetCurrTime() {
  // needed for when time:60 is reached
  startTime = getCurrTime();
}
