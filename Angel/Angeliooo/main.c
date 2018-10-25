#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#include "cellstruct.h"
//#include "config_ini.h"
#include "updater.h"
#include "configuration_v2.h"
#include "database.h"


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
  tCell ** matrix = (tCell **) malloc(msizex*sizeof(tCell)); // 250 cell pointers
  for (int i = 0; i < msizex; i++){ // for each position, create 250 more
    matrix[i] = (tCell *) malloc(msizey*sizeof(tCell));
  }

  // Give each cell its own position
  for (int i = 0; i < msizex; i++){
  	for (int j = 0; j < msizey; j++){
  		matrix[i][j].x = i;
  		matrix[i][j].y = j;
  	}
  }
  // Let's load the initial configuration
  configuration_v2(msizex, msizey, tCell **);
  // And plot the initial configuration
  for (int i = 0; i < msizex; i++){
    for (int j = 0; j < msizey; j++){
      plotter(matrix[i][j].x, matrix[i][j].y, matrix[i][j].alive, mywin);
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
  
  
