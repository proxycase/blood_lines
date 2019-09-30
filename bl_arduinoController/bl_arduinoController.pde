/*
* Blood Lines - Processing on Raspberry Pi
 * Reads through the notes in CSV format and sends
 * signal to an Arduino equipped with motors to play individual notes.
 */

boolean DEBUG = true;
boolean reachedEnd = false;

SystemTimeKeeper systime;

void setup() 
{
  size(600, 600);
  frameRate(2);

  // initiate communications to arduino
  setupComms();

  // initiate table reader
  setupTable();

  // initiate timekeeper
  systime = new SystemTimeKeeper();

  // setup console to screen printer
  setupConsole();
}

void draw() {
  drawConsole();

  // update the system time
  systime.update();
  int curTimeSeconds = systime.getTimeSeconds();

  // check if it's time to trigger a motor
  checkTable(curTimeSeconds);
}

void checkTable(int time) {
  int tableTriggerTime = blTable.getTriggerTime();

  if (tableTriggerTime <= time) {
    println("reached time");

    // send wire signal
    sendComms(blTable.getWire(), blTable.getDuration());

    // move to next row in table
    blTable.next();


    // -- TODO: move function to inside blTable
    // reset if reached end of table
    if (reachedEnd) {
      systime.reset();
      reachedEnd = false;
    }
  } else {
    if (DEBUG) println("currently: " + systime.getTimeSeconds() + " waiting for: " + tableTriggerTime);
  }
}