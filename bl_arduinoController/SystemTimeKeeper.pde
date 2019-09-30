class SystemTimeKeeper {
  private
    long startTime, curTime, curDiff;

  SystemTimeKeeper() {
    reset();
  }

  void update() {
    curTime = System.currentTimeMillis();
    curDiff = calcDiff(curTime, startTime);
  }

  void reset() {
    startTime = currentTimeMillis();
  }

  long currentTimeMillis() {
    return System.currentTimeMillis();
  }

  long calcDiff(long a, long b) {
    return a-b;
  }

  public
    int getTime() {
    return (int) curDiff;
  }

  public
    int getTimeSeconds() {
    return (int) curDiff/1000;
  }
}
