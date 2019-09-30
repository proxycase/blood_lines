import java.util.Calendar;
import java.util.Date;
import java.text.SimpleDateFormat;

RuntimeScheduler rts;

// void setup() {
//   rts = new RuntimeScheduler();
// }

// void draw() {
//   println(rts.getDayOfWeek());
// }

/** Schedules when a sketch runs and when it doesn't */
class RuntimeScheduler {
  Date now;

  RuntimeScheduler() {
    today();
  }

  /** Sets date to today */
  void today() {
    now = new Date();
  }

  /** Get int day of week. 0 == Saturday */
  int getDayOfWeek() {
    Calendar calendar = Calendar.getInstance();
    calendar.setTime(now);

    return calendar.get(Calendar.DAY_OF_WEEK);
  }
  
  /** Extra function for verbose day of week: "Sun" and "Sunday" */
  void printDate() {
    SimpleDateFormat simpleDateformat = new SimpleDateFormat("E"); // the day of the week abbreviated
     println(simpleDateformat.format(now));

     simpleDateformat = new SimpleDateFormat("EEEE"); // the day of the week spelled out completely
     println(simpleDateformat.format(now));
  }
}

