
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "config_ini.h"
#include "updater.h"

int main(){

 // Initializing the cell structure
	typedef struct{
		int alive;
		int pos_x;
		int pos_y;
		int neighbours;
	} cell;

  int msize = 250;
  // Create an msize x msize matrix of cell pointers
  cell ** matrix = (cell **) malloc(msize*sizeof(cell)); // 250 cell pointers
  for (int i = 0; i < msize; i++){ // for each position, create 250 more
    matrix[i] = (cell *) malloc(msize*sizeof(cell));
  }

  // Give each cell its own position
  for (int i = 0; i < msize; i++){
  	for (int j = 0; j < msize; j++){
  		matrix[i][j].pos_x = i;
  		matrix[i][j].pos_y = j;
  	}
  }

  // Let's load the initial configuration
  config_ini(matrix, msize);
  // Initialize the screen
  initscr();
  // And plot the initial configuration
  for (int i = 0; i < msize; i++){
    for (int j = 0; j < msize; j++){
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive);
    }
  }
  refresh(); // Refresh the screen so it shows the added points

  while (! getch()){
    // Get the neighbour information of the current status
    neighbours(matrix, msize);
    // Update the screen
    updater(matrix, msize);
    // Refresh the screen so it shows updates
    refresh();
  }
  
  endwin(); // End the screen
  
  return 0;
}
  
  