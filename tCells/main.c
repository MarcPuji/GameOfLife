/*
TEAM-WORK STRATEGY:

The work has been divided in the following parts:
- Coder 1: He was charged with getting to know and work with the performance profiling tools.
           Then he did the performance tests. He contributed to make the code that charges the
           predefined cell initial configurations into the system from a .txt file.

- Coder 2: He was the main person in charge of coding the predefined configurations of cells
           so that they can be put in any place on the 2D plane. Then, he coded a way to insert
           the cell initial configurations from the terminal shell (placed in "terminal shell configuration"
	   folder). He also did final performance test with profiling tools and made the profiling report.

- Coder 3: He was initially in charge of designing and code the data structure. A data structure
           that was required to optimize the memory used (that was our priority as in embedded systems
           that's the main ressource limitation) while using as little time as possible. Then, he coded
           the engine of the game, meaning the functions needed to get the alive cells from timestep t+1,
           given the alive cells from timestep t. Then, he helped rearranging the code and check and correct
           memory leakage issues.

- Coder 4: He was in charge of building the main file using the initilalization functions to give the initial
           conditions of the cell configurations in the 2D plane, then using the engine functions in order to
           advance and obtain the new alive cells at every timestep; all this while plotting the alive cells
           across every timestep. Then, he implemented the vanilla version of the Game of Life using 2D arrays
           containing the whole 2D plane of dead and alive cells. This implementation was done in order to be
           able to compare our memory optimal version of the Game of Life with the vanilla version that we define
           as the Control Version.
           
*/



// Author: Coder 4

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/database.h"
#include "configuration_v2.h"


// Function that recursively advances through the tCell and plots the cells to the screen
void toPlot(tCell *a, WINDOW *mywin){
    if(a->x != -1){
        mvwaddch(mywin, a->y, a->x, ACS_CKBOARD);
    }// This allows us to advance through to the cells within and accross columns.
    if(a->childy != NULL){
        toPlot(a->childy, mywin); // advance through the column
    }
    if(a->childx != NULL){
        toPlot(a->childx, mywin); // advance across columns (only possible in the top row 
                             // for the sake of simplicity.)
    }
}


int main(){
  	// Initialize max screen size constants
  	int msizey;
  	int msizex;

  	// Initialize our screen with max resolution
  	initscr();
  	WINDOW * mywin = newwin(0,0,0,0);
  	// Get the screen resolution
  	msizex = getmaxx(mywin);
  	msizey = getmaxy(mywin);

  	// Initialize the database
  	tCell* alive_cells = cellDataBase();
  	// Load the initial configuration to the database
  	configuration_v2(msizex, msizey,alive_cells);
  	// Plot the initial configuration to the screen
  	toPlot(alive_cells, mywin);
  	// Refresh the screen so it shows the added points
  	wrefresh(mywin);
  	// Pause for a while so we can see the initial configuration
  	sleep(2);

  	// Number of loops
  	int loops = 0;

  	while (loops < 1000){
    	// Hide cursor
    	curs_set(0);
    	// In each timestep we have to:
    	// STEP1: Look for candidates to be alive the next timestep
    	tCell* candidate_cells = cellDataBase();
    	addCandidates(alive_cells, candidate_cells, msizex, msizey);
    	// STEP2: Check which candidates make it through the next generation
    	//        and delete the dead cells
    	deleteDeadCells(candidate_cells);
    	// We have the new alive cells in the candidates database, so
    	// STEP3: Free the unneeded memory and make alive pointer
    	//        point to the new alive cells database
    	freeMemory(alive_cells);
    	alive_cells = candidate_cells;
    	// STEP4: Plot the new alive cells  
  		// Clear the window before updating the image
  		wclear(mywin);
    	// Plot the alive cells
    	toPlot(alive_cells, mywin);
    	// Refresh the screen so it shows updates
    	wrefresh(mywin);
    	usleep(100000);
    	// New Loop
    	loops += 1;
    }
    // Close the window
  	endwin();
  	// Free the tCell
  	freeMemory(alive_cells);
  	return 0;
}
  
  
