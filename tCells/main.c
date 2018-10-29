#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/database.h"
#include "configuration_v2.h"
#include "plotter.h"

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
  sleep(2);

  // Number of loops
  int loops = 0;

  while (loops < 100){
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
    sleep(1);
    // Loop passed
    loops += 1;
  }
  endwin();

  free(LUT[0]);
  free(LUT[1]);
  free(LUT);

  return 0;
}
  
  