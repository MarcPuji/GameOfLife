//Function for inserting the R-pentomino configuration
/*Info needed: location of the upper left cell in rows (y) and columns (x), database tCell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "database.h"

sizeX=5;
// sizeY=5;

void R_pentomino_insert (int locationX, int locationY, tCell *a){

  for(int i = 0; i < sizeX; i++){
      instertCell(locationX+i,locationY,0,a);
  }

  instertCell(locationX,locationY+1,0,a);
  instertCell(locationX+1,locationY+1,0,a);
  instertCell(locationX+2,locationY+1,1,a);
  instertCell(locationX+3,locationY+1,1,a);
  instertCell(locationX+4,locationY+1,0,a);

  instertCell(locationX,locationY+2,0,a);
  instertCell(locationX+1,locationY+2,1,a);
  instertCell(locationX+2,locationY+2,1,a);
  instertCell(locationX+3,locationY+2,0,a);
  instertCell(locationX+4,locationY+2,0,a);

  instertCell(locationX,locationY+3,0,a);
  instertCell(locationX+1,locationY+3,0,a);
  instertCell(locationX+2,locationY+3,1,a);
  instertCell(locationX+3,locationY+3,0,a);
  instertCell(locationX+4,locationY+3,0,a);

  for(int j = 0; j < sizeX; j++){
      instertCell(locationX+j,locationY+4,0,a);
  }

  // instertCell(locationX,locationY,0,a)
  // instertCell(locationX+1,locationY,0,a)
  // instertCell(locationX+2,locationY,0,a)
  // instertCell(locationX+3,locationY,0,a)
  // instertCell(locationX+4,locationY,0,a)
  // instertCell(locationX,locationY+1,0,a)
  // instertCell(locationX+1,locationY+1,0,a)
  // instertCell(locationX+2,locationY+1,0,a)
  // instertCell(locationX+3,locationY+1,0,a)
  // instertCell(locationX+4,locationY+1,0,a)
  // instertCell(locationX,locationY+2,0,a)
  // instertCell(locationX+1,locationY+2,0,a)
  // instertCell(locationX+2,locationY+2,0,a)
  // instertCell(locationX+3,locationY+2,0,a)
  // instertCell(locationX+4,locationY+2,0,a)
  // instertCell(locationX,locationY+3,0,a)
  // instertCell(locationX+1,locationY+3,0,a)
  // instertCell(locationX+2,locationY+3,0,a)
  // instertCell(locationX+3,locationY+3,0,a)
  // instertCell(locationX+4,locationY+3,0,a)
  // instertCell(locationX,locationY+4,0,a)
  // instertCell(locationX+1,locationY+4,0,a)
  // instertCell(locationX+2,locationY+4,0,a)
  // instertCell(locationX+3,locationY+4,0,a)
  // instertCell(locationX+4,locationY+4,0,a)

}
