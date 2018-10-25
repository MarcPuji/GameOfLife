#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "plotter.h"
#include "database.h"


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