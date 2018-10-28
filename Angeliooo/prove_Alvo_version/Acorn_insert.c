//Function for inserting the Acorn configuration
/*Inputs: location of the upper left cell in rows (y) and columns (x), database tCell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Acorn_insert.h"
#include "database.h"

void Acorn_insert (int locationX, int locationY, tCell *a){

  insertCell(locationX+2,locationY+1,1,a);  //insertCell is a function from database.h
  insertCell(locationX+4,locationY+2,1,a);
  insertCell(locationX+1,locationY+3,1,a);
  insertCell(locationX+2,locationY+3,1,a);
  insertCell(locationX+5,locationY+3,1,a);
  insertCell(locationX+6,locationY+3,1,a);
  insertCell(locationX+7,locationY+3,1,a);

}
