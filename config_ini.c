
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int alive;
  int pos_x;
  int pos_y;
  int neighbours;
} cell;

void config_ini(cell ** matrix, int msize){ // Load the initial configuration to the created matrix
	////// TODO: INSERTING PIECES FUNCTIONS /////
}