//Function for inserting the R-pentomino configuration
/*Info needed: location of the upper left cell in rows (y) and columns (x), database tCell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "database.h"

void R_pentomino_insert (int locationX, int locationY, tCell *a){

  instertCell(locationX+2,locationY+1,1,a);
  instertCell(locationX+3,locationY+1,1,a);
  instertCell(locationX+1,locationY+2,1,a);
  instertCell(locationX+2,locationY+2,1,a);
  instertCell(locationX+2,locationY+3,1,a);

}
