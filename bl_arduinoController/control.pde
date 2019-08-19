void keyPressed() {
  if (key == 'j') {
    blTable.prev();
  } else if (key == 'l') {
    blTable.next();
  } else if (key == 'k') {
    blTable.printout();
  }
}
