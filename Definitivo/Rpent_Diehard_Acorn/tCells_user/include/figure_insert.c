#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "figure_insert.h"
#include "database.h"

//Function for inserting the Diehard configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void Diehard_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX+7,locationY+1,1,a);  //insertCell is a function from database.h
  insertCell(locationX+1,locationY+2,1,a);
  insertCell(locationX+2,locationY+2,1,a);
  insertCell(locationX+2,locationY+3,1,a);
  insertCell(locationX+6,locationY+3,1,a);
  insertCell(locationX+7,locationY+3,1,a);
  insertCell(locationX+8,locationY+3,1,a);

}

//Function for inserting the R-pentomino configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void R_pentomino_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX+2,locationY+1,1,a);  //insertCell is a function from database.h
  insertCell(locationX+3,locationY+1,1,a);
  insertCell(locationX+1,locationY+2,1,a);
  insertCell(locationX+2,locationY+2,1,a);
  insertCell(locationX+2,locationY+3,1,a);

}

//Function for inserting the Acorn configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void Acorn_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX+2,locationY+1,1,a);  //insertCell is a function from database.h
  insertCell(locationX+4,locationY+2,1,a);
  insertCell(locationX+1,locationY+3,1,a);
  insertCell(locationX+2,locationY+3,1,a);
  insertCell(locationX+5,locationY+3,1,a);
  insertCell(locationX+6,locationY+3,1,a);
  insertCell(locationX+7,locationY+3,1,a);

}

//Function for inserting the Block configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void Block_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX,locationY,1,a);  //insertCell is a function from database.h
  insertCell(locationX+1,locationY,1,a);
  insertCell(locationX,locationY+1,1,a);
  insertCell(locationX+1,locationY+1,1,a);
}

//Function for inserting the Rectangle configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void Rectangle_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX,locationY,1,a);  //insertCell is a function from database.h
  insertCell(locationX+1,locationY,1,a);
  insertCell(locationX,locationY+1,1,a);
  insertCell(locationX+1,locationY+1,1,a);
  insertCell(locationX,locationY+2,1,a);
  insertCell(locationX+1,locationY+2,1,a);
}

//Function for inserting the Rectangle configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void Hat_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX,locationY,1,a);  //insertCell is a function from database.h
  insertCell(locationX+1,locationY,1,a);
  insertCell(locationX+1,locationY+1,1,a);
  insertCell(locationX+1,locationY-1,1,a);

  insertCell(locationX+2,locationY,1,a);
  insertCell(locationX+2,locationY+1,1,a);
  insertCell(locationX+2,locationY-1,1,a);
  insertCell(locationX+2,locationY+2,1,a);
  insertCell(locationX+2,locationY-2,1,a);

  insertCell(locationX+3,locationY+2,1,a);
  insertCell(locationX+3,locationY+3,1,a);
  insertCell(locationX+3,locationY-2,1,a);
  insertCell(locationX+3,locationY-3,1,a);
}

//Function for inserting the Spaceship configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
void Spaceship_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX,locationY,1,a);  //insertCell is a function from database.h
  insertCell(locationX+1,locationY+1,1,a);
  insertCell(locationX+1,locationY-1,1,a);

  insertCell(locationX+2,locationY+2,1,a);
  insertCell(locationX+2,locationY-2,1,a);

  insertCell(locationX+3,locationY,1,a);
  insertCell(locationX+3,locationY+1,1,a);
  insertCell(locationX+3,locationY-1,1,a);

  insertCell(locationX+4,locationY+2,1,a);
  insertCell(locationX+4,locationY+3,1,a);
  insertCell(locationX+4,locationY-2,1,a);
  insertCell(locationX+4,locationY-3,1,a);
}


