import java.util.Calendar;
import java.util.Date;
import java.text.SimpleDateFormat;

/**
A single example: Fridays from 9am to 5pm
[[7, 9, 17]]

A multiple example: Fridays, 9a - 5p | Sat, 10a - 7p | Sun, 1p - 4p
[[7,9,17],[0,10,19],[1,13,15]]
*/

class RuntimeScheduler {
  int dayCount; // how many days in the schedule
  int[][] schedule;
  Calendar calendar;

  RuntimeScheduler(int _count, int[][] _schedule) {
    dayCount = _count;
    schedule = _schedule;
    calendar = Calendar.getInstance();
    this.update();
  }

  void update() {
    calendar = Calendar.getInstance();
  }

  /** Returns true if current time is within stated running times */
  boolean active() {    
    for (int i = 0; i < this.dayCount; i++) {
      if (matchDay(this.getDayOfWeek(), schedule[i][0])) {
        return matchHours(this.getHour(), schedule[i][1], schedule[i][2]);
      }
    }
    return false;
  }

  int getDayOfWeek() {
    return calendar.get(Calendar.DAY_OF_WEEK);
  }
  
  int getHour() {
    return calendar.get(Calendar.HOUR_OF_DAY);
  }
  
  boolean matchDay(int day1, int day2) {
    return (day1 == day2);
  }
  
  boolean matchHours(int comparator, int _startTime, int _endTime) {
    return (comparator >= _startTime && comparator < _endTime);
  }
}
