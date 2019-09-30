BL_Table blTable;

void setupTable() {
  blTable = new BL_Table();
  blTable.loadRow();
}

class BL_Table {
  Table table;
  TableRow row;
  int position;

  BL_Table() {
    table = loadTable("bl_timelinenotes.csv", "header");
    println(table.getRowCount() + " total rows in table");
    position = 0;

    row = table.getRow(position);
    println("loadRow row: " + position);
  }
  
  // loadRow grabs the current row for attention
  void loadRow() {
    row = table.getRow(position);
    println("loadRow row: " + position);
  }
  
  void next() {
    if (!(position >= table.getRowCount()-1)) {
      position++;
      this.loadRow();
      //return false;
    } else {
      println("reached end, resetting");
      position = 0;
      this.loadRow();
      
      // set flag so that we can reset time to 0
      reachedEnd = true;
    }
  }
  
  void prev() {
    if (!(position <= 0)) {
      position--;
      this.loadRow();
    } else {
      println("cant go further back");
    }
  }
  
  void printout() {
    println("wire: " + getWire() + " time: " + getTriggerTime() + " dur: " + getDuration());
  }
  
  int getWire() {
    return row.getInt("Wire");
  }
  
  int getTriggerTime() {
    return row.getInt("Time");
  }
  
  int getDuration() {
    return row.getInt("Duration");
  }
}
