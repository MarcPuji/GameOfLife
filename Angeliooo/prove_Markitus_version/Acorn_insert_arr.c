//Function for inserting the R-pentomino configuration
/*Info needed: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Acorn_insert_arr.h"
#include "cellstruct.h"

void Acorn_insert_arr (int msizex, int msizey, myCell ** matrix){

  matrix[msizex+2][msizey+1].alive = 1;
	matrix[msizex+4][msizey+2].alive = 1;
	matrix[msizex+1][msizey+3].alive = 1;
	matrix[msizex+2][msizey+3].alive = 1;
  matrix[msizex+5][msizey+3].alive = 1;
  matrix[msizex+6][msizey+3].alive = 1;
  matrix[msizex+7][msizey+3].alive = 1;

}
