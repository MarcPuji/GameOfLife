#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cellstruct.h"
#include "configuration_arr.h"
#include "R_pentomino_insert_arr.h"
#include "Diehard_insert_arr.h"
#include "Acorn_insert_arr.h"
#include "updater.h"


int main(){

  int msizey;
  int msizex;

  bool isAlive = true;

  // Initialize our screen with max resolution
  initscr();
  WINDOW * mywin = newwin(0,0,0,0);

  msizex = getmaxx(mywin);
  msizey = getmaxy(mywin);

  // Create an msize x msize matrix of cell pointers
  myCell ** matrix = (myCell **) malloc(msizex*sizeof(myCell *)); // 250 cell pointers
  for (int i = 0; i < msizex; i++){ // for each position, create 250 more
    matrix[i] = (myCell *) malloc(msizey*sizeof(myCell));
  }

  // Give each cell its own position
  for (int i = 0; i < msizex; i++){
  	for (int j = 0; j < msizey; j++){
  		matrix[i][j].pos_x = i;
  		matrix[i][j].pos_y = j;
  	}
  }

  // Let's load the initial configuration
  configuration_arr(matrix, msizex, msizey);
  // And plot the initial configuration
  for (int i = 0; i < msizex; i++){
    for (int j = 0; j < msizey; j++){
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive, mywin);
  	}
  }

  wrefresh(mywin); // Refresh the screen so it shows the added points
  sleep(2);

  while (isAlive){
  	// Clear the window before updating the image
  	wclear(mywin);
    // Get the neighbour information of the current status
    neighbours(matrix, msizex, msizey);
    // Update the screen
    isAlive = updater(matrix, msizex, msizey, mywin);
    // Refresh the screen so it shows updates
    wrefresh(mywin);
    sleep(1);
  }
  // If game is not alive, end the screen
  endwin();
  // Free the memory
  for (int i = 0; i < msizex; i++){
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}
