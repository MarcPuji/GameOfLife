#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/cellstruct.h"
#include "include/configuration_arr.h"
#include "updater.h"


int main(){

	// Max screen size constants
	int msizey;
	int msizex;

	// Initialize our screen with max resolution
  	initscr();
  	WINDOW * mywin = newwin(0,0,0,0);

  	msizex = getmaxx(mywin);
  	msizey = getmaxy(mywin);


  	// Initialize the LUTs used to update the cells status
  	int ** LUT = (int **) malloc(2*sizeof(int *));
	LUT[0] = (int *) malloc(9*sizeof(int));
  	LUT[1] = (int *) malloc(9*sizeof(int));

  	LUT[0][3] = 1; 	// Dead cells with 3 neighbours become alive
  	LUT[1][2] = 1;	// Alive cells with 2
  	LUT[1][3] = 1;	// 					or 3 neighbours remain alive. Rest dead.

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

  	// Number of loops
  	int loops = 0;

  	// Main Loop
  	while (loops < 100){
      // Hide cursor
      curs_set(0);
  		// Clear the window before updating the image
  		wclear(mywin);
    	// Get the neighbour information of the current status
    	neighbours(matrix, msizex, msizey);
    	// Update the screen
    	updater(matrix, msizex, msizey, mywin, LUT);
    	// Refresh the screen so it shows updates
    	wrefresh(mywin);
    	sleep(1);

    	loops += 1;
  	}

  	// End the screen
  	endwin();
  	// Free the memory
  	for (int i = 0; i < msizex; i++){
    	free(matrix[i]);
  	}
  	free(matrix);

  	free(LUT[0]);
  	free(LUT[1]);
  	free(LUT);

  	return 0;
}
  
  