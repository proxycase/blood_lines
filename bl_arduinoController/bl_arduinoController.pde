/*
* Blood Lines - Processing on Raspberry Pi
 * Reads through the notes in CSV format and sends
 * signal to an Arduino equipped with motors to play individual notes.
 */

boolean DEBUG = true;
boolean USE_SCHEDULER = true;

SystemTimeKeeper systime;

RuntimeScheduler rts;
final int SLEEP_TIME = 3000;

int[][] schedule = {
  {Calendar.TUESDAY,    11,  14},
  {Calendar.THURSDAY,   11,  14},
  {Calendar.FRIDAY,     11,  14},
  {Calendar.SATURDAY,   14,  16}
};

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

  // setup schedule
  rts = new RuntimeScheduler(3, schedule);
}

void draw() {
  drawConsole();

  rts.update();
  println("ACTIVE STATE: " + rts.active());

  if (USE_SCHEDULER) {
    
  } else if (rts.active()) {
    // update the system time
    systime.update();
    int curTimeSeconds = systime.getTimeSeconds();

    // check if it's time to trigger a motor
    checkTable(curTimeSeconds);
  } else {
    delay(SLEEP_TIME);
  }
}

void checkTable(int time) {
  int tableTriggerTime = blTable.getTriggerTime();

  if (tableTriggerTime <= time) {
    println("reached time");

    // send wire signal
    sendComms(blTable.getWire(), blTable.getDuration());

    // move to next row in table
    blTable.next();

    // reset if reached end of table
    if (blTable.finished) {
      systime.reset();
      blTable.finished = false;
    }
  } else {
    if (DEBUG) println("currently: " + systime.getTimeSeconds() + " waiting for: " + tableTriggerTime);
  }
}