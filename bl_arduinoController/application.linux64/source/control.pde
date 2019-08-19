void keyPressed() {
  if (key == 'j') {
    blTable.prev();
  } else if (key == 'l') {
    blTable.next();
  } else if (key == 'k') {
    blTable.printout();
  }
}

// THIS IS USED FOR TESTING SIGNAL
void mouseClicked() {
  println("clicked");
  myPort.write((int)random(10)+","+(int)random(2000)+"|");
  
}
