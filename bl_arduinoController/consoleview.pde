import at.mukprojects.console.*;

Console console;

void setupConsole() {
  console = new Console(this);
  console.start();
}

void drawConsole() {
  background(200);
  console.draw(0, 0, width, height);
  console.print();
}
