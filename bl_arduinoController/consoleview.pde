import at.mukprojects.console.*;

Console console;

void setupConsole() {
  console = new Console(this);

  // Start the console
  console.start();
}

void drawConsole() {
  background(200);

  // Draw the console to the screen.
  console.draw(0, 0, width, height);

  // Print the console to the system out.
  console.print();
}
