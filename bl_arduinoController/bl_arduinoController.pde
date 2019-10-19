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

int DAY_COUNT = 5;

int[][] MAIN_SCHEDULE = {
  {Calendar.TUESDAY,    11,  14},
  {Calendar.THURSDAY,   11,  14},
  {Calendar.FRIDAY,     11,  14},
  {Calendar.SATURDAY,   10,  16},
  {Calendar.SUNDAY,   12,  17}
};

void setup() 
{  
  size(600, 600);
  frameRate(2);

  // initiate communications to arduino
  setupComms();

  // initiate table reader
  setupTable();

  // setup console to screen printer
  setupConsole();

  // initiate timekeeper
  systime = new SystemTimeKeeper();

  // setup schedule
  rts = new RuntimeScheduler(MAIN_SCHEDULE);
  
  delay(3000);
}

void draw() {
  drawConsole();

  rts.update();
  
  if (rts.active()) {
    print("active: ");
  } else {
    print("inactive: ");
  }

  if (USE_SCHEDULER && rts.active()) {
    runSystem();
  } else if (!USE_SCHEDULER) {
    runSystem();
  } else {
    println("ACTIVE STATE: " + rts.active());
    delay(SLEEP_TIME);
  }
}

void runSystem() {
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

    // reset if reached end of table
    if (blTable.finished) {
      systime.reset();
      blTable.finished = false;
    }
  } else {
    println("now: " + systime.getTimeSeconds() + " next: " + tableTriggerTime);
  }
}
