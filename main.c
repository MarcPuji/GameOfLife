#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "config_ini.h"
#include "plotter.h"
#include "database.h"

int main(){

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
  config_ini(alive_cells, msizex, msizey);
  // Plot the initial configuration to the screen
  toPlot(alive_cells, mywin);
  wrefresh(mywin);
  sleep(2);

  while (true){
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
    wrefresh(mywin);
    sleep(1);
  }
  endwin();
  return 0;
}
  
  