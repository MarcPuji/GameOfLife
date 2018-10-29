#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "figure_insert.h"
#include "cellstruct.h"

//Function for inserting the R-pentomino configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */

void R_pentomino_insert_arr (int locationX, int locationY, myCell **matrix){
  	matrix[locationX+2][locationY+1].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+3][locationY+1].alive = 1;
	matrix[locationX+1][locationY+2].alive = 1;
	matrix[locationX+2][locationY+2].alive = 1;
  	matrix[locationX+2][locationY+3].alive = 1;

}

//Function for inserting the Diehard configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
void Diehard_insert_arr (int locationX, int locationY, myCell **matrix){
 	matrix[locationX+7][locationY+1].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+1][locationY+2].alive = 1;
	matrix[locationX+2][locationY+2].alive = 1;
	matrix[locationX+2][locationY+3].alive = 1;
  	matrix[locationX+6][locationY+3].alive = 1;
  	matrix[locationX+7][locationY+3].alive = 1;
  	matrix[locationX+8][locationY+3].alive = 1;

}

//Function for inserting the Acorn configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
void Acorn_insert_arr (int locationX, int locationY, myCell ** matrix){
  	matrix[locationX+2][locationY+1].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+4][locationY+2].alive = 1;
	matrix[locationX+1][locationY+3].alive = 1;
	matrix[locationX+2][locationY+3].alive = 1;
	matrix[locationX+5][locationY+3].alive = 1;
  	matrix[locationX+6][locationY+3].alive = 1;
  	matrix[locationX+7][locationY+3].alive = 1;

}

//Function for inserting the Spaceship configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
void Spaceship_insert_arr (int locationX, int locationY, myCell ** matrix){
  	matrix[locationX][locationY].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+1][locationY+1].alive = 1;
	matrix[locationX+1][locationY-1].alive = 1;
	matrix[locationX+2][locationY+2].alive = 1;
	matrix[locationX+2][locationY-2].alive = 1;
  	matrix[locationX+3][locationY].alive = 1;
  	matrix[locationX+3][locationY+1].alive = 1;
  	matrix[locationX+3][locationY-1].alive = 1;
  	matrix[locationX+4][locationY+2].alive = 1;
  	matrix[locationX+4][locationY+3].alive = 1;
  	matrix[locationX+4][locationY-2].alive = 1;
  	matrix[locationX+4][locationY-3].alive = 1;

}
//Function for inserting the Hat configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
void Hat_insert_arr (int locationX, int locationY, myCell ** matrix){
  	matrix[locationX][locationY].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+1][locationY].alive = 1;
	matrix[locationX+1][locationY+1].alive = 1;
	matrix[locationX+1][locationY-1].alive = 1;
  	matrix[locationX+2][locationY].alive = 1;
  	matrix[locationX+2][locationY+1].alive = 1;
  	matrix[locationX+2][locationY-1].alive = 1;
  	matrix[locationX+2][locationY+2].alive = 1;
  	matrix[locationX+2][locationY-2].alive = 1;
  	matrix[locationX+3][locationY+2].alive = 1;
  	matrix[locationX+3][locationY+3].alive = 1;
  	matrix[locationX+3][locationY-2].alive = 1;
  	matrix[locationX+3][locationY-3].alive = 1;
}

//Function for inserting the Block configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
void Block_insert_arr (int locationX, int locationY, myCell ** matrix){
  	matrix[locationX][locationY].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+1][locationY+1].alive = 1;
	matrix[locationX+1][locationY].alive = 1;
	matrix[locationX][locationY+1].alive = 1;

}

//Function for inserting the Rectangle configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), matrix myCell** */
void Rectangle_insert_arr (int locationX, int locationY, myCell ** matrix){
  	matrix[locationX][locationY].alive = 1; //changing the alive field value (of the myCell struct) to 1 in the appropiate position of the matrix of pointers 
	matrix[locationX+1][locationY].alive = 1;
	matrix[locationX][locationY+1].alive = 1;
	matrix[locationX+1][locationY+1].alive = 1;
	matrix[locationX][locationY+2].alive = 1;
	matrix[locationX+1][locationY+2].alive = 1;

}
