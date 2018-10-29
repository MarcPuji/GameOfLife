//Function for inserting the R-pentomino configuration
/*Info needed: location of the upper left cell in rows (y) and columns (x), database tCell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Diehard_insert.h"
#include "database.h"

void Diehard_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX+7,locationY+1,1,a);
  insertCell(locationX+1,locationY+2,1,a);
  insertCell(locationX+2,locationY+2,1,a);
  insertCell(locationX+2,locationY+3,1,a);
  insertCell(locationX+6,locationY+3,1,a);
  insertCell(locationX+7,locationY+3,1,a);
  insertCell(locationX+8,locationY+3,1,a);

}
