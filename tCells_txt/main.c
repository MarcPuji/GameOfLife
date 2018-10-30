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

  // Initialize the LUTs used to update the cells status
  int ** LUT = (int **) malloc(2*sizeof(int *));
  LUT[0] = (int *) malloc(9*sizeof(int));
  LUT[1] = (int *) malloc(9*sizeof(int));

  LUT[0][3] = 1;
  LUT[1][2] = 1;
  LUT[1][3] = 1;

  // Initialize the database
  tCell* alive_cells = cellDataBase();
  // Load the initial configuration to the database
  configuration_v2(msizex, msizey,alive_cells);
  // Plot the initial configuration to the screen
  toPlot(alive_cells, mywin);
  wrefresh(mywin);
  usleep(200000);

  // Number of loops
  int loops = 0;

  while (loops < 100){
    // Hide cursor
    curs_set(0);
    // In each timestep we have to:
    // STEP1: Look for candidates to be alive the next timestep
    tCell* candidate_cells = cellDataBase();
    addCandidates(alive_cells, candidate_cells, msizex, msizey);
    // STEP2: Check which candidates make it through the next generation
    //        and delete the dead cells
    deleteDeadCells(candidate_cells, LUT);
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
    wrefresh(mywin);
    usleep(100000);
    // Loop passed
    loops += 1;
  }
  endwin();

  free(alive_cells);
  free(LUT[0]);
  free(LUT[1]);
  free(LUT);

  return 0;
}
  
  
