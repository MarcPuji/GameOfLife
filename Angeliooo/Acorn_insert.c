//Function for inserting the R-pentomino configuration
/*Info needed: location of the upper left cell in rows (y) and columns (x), database tCell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Acorn_insert.h"
#include "database.h"

void Acorn_insert (int locationX, int locationY, tCell *a){

  instertCell(locationX+2,locationY+1,1,a);
  instertCell(locationX+4,locationY+2,1,a);
  instertCell(locationX+1,locationY+3,1,a);
  instertCell(locationX+2,locationY+3,1,a);
  instertCell(locationX+5,locationY+3,1,a);
  instertCell(locationX+6,locationY+3,1,a);
  instertCell(locationX+7,locationY+3,1,a);

}
