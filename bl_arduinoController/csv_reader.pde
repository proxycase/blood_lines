BL_Table blTable;

void setupTable() {
  blTable = new BL_Table();
  blTable.update();
}

class BL_Table {
  Table table;
  TableRow row;
  int position;

  BL_Table() {
    table = loadTable("bl_timelinenotes.csv", "header");
    println(table.getRowCount() + " total rows in table");
    position = 0;
  }
  
  // update grabs the current row for attention
  void update() {
    row = table.getRow(position);
    println("updated row: " + position);
  }
  
  void next() {
    if (!(position >= table.getRowCount()-1)) {
      position++;
      this.update();
      //return false;
    } else {
      println("reached end, resetting");
      position = 0;
      this.update();
      
      // set flag so that we can reset time to 0
      reachedEnd = true;
    }
  }
  
  void prev() {
    if (!(position <= 0)) {
      position--;
      this.update();
    } else {
      println("cant go further back");
    }
  }
  
  void printout() {
    println("wire: " + getWire() + " time: " + getTime() + " dur: " + getDuration());
  }
  
  int getWire() {
    return row.getInt("Wire");
  }
  
  float getTime() {
    return row.getFloat("Time");
  }
  
  int getDuration() {
    return row.getInt("Duration");
  }
}
