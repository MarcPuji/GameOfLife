//Function for inserting the R-pentomino configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include"R_pentomino_insert_arr.h"
#include "cellstruct.h"

void R_pentomino_insert_arr (int locationX, int locationY, myCell **matrix){

  matrix[locationX+2][locationY+1].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+3][locationY+1].alive = 1;
	matrix[locationX+1][locationY+2].alive = 1;
	matrix[locationX+2][locationY+2].alive = 1;
  matrix[locationX+2][locationY+3].alive = 1;

}
