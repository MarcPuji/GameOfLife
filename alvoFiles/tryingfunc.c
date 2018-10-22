#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "database.h"
#include "tryingfunc.h"


void toPlot(tCell *a){
    if(a->x != -1){
        printf("Coordinates (x, y) = (%d, %d), alive = %d, neighbours = %d\n",
            a->x,a->y,a->alive,a->neighbours);
        mvaddch(a->y, a->x, ACS_CKBOARD);
    }// This allows us to advance through to the cells within and accross columns.
    if(a->childy != NULL){
        toPlot(a->childy); // advance through the column
    }
    if(a->childx != NULL){
        toPlot(a->childx); // advance across columns (only possible in the top row 
                             // for the sake of simplicity.)
    }
}