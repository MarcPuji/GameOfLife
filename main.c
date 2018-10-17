#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cellstruct.h"
#include "config_ini.h"
#include "updater.h"


int main(){

  int msize = 250;
  // Create an msize x msize matrix of cell pointers
  myCell ** matrix = (myCell **) malloc(msize*sizeof(myCell *)); // 250 cell pointers
  for (int i = 0; i < msize; i++){ // for each position, create 250 more
    matrix[i] = (myCell *) malloc(msize*sizeof(myCell));
  }

  // Give each cell its own position
  for (int i = 0; i < msize; i++){
  	for (int j = 0; j < msize; j++){
  		matrix[i][j].pos_x = i;
  		matrix[i][j].pos_y = j;
  	}
  }

  // Initialize the screen
  //initscr();
  // Let's load the initial configuration
  config_ini(matrix, msize);
  // And plot the initial configuration
  for (int i = 0; i < msize; i++){
    for (int j = 0; j < msize; j++){
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive);
  	}
  }
  
  refresh(); // Refresh the screen so it shows the added points

  while (true){
    // Get the neighbour information of the current status
    neighbours(matrix, msize);
    // Update the screen
    updater(matrix, msize);
    // Refresh the screen so it shows updates
    getch();
    refresh();
  }
  
  endwin(); // End the screen
  
  return 0;
}
  
  