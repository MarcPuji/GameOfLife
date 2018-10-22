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

int main(char* args){
	initscr();
	// initialize
    tCell* alive = cellDataBase();
    insertCell(1,0,1,alive);
    insertCell(0,1,1,alive);
    insertCell(1,2,1,alive);
    int mapLimitx = 3;
    int mapLimity = 3;
    printf("ALIVE\n");
    toPlot(alive);
    refresh();
    getch();
    printf("hola sinior\n");
    // LOOP
    // STEP1: search candidates
    tCell* candidates = cellDataBase();
    printf("CANDIDATES\n");
    addCandidates(alive,candidates,mapLimitx,mapLimity);
    printf("NEW ALIVE CELLS\n");

    // STEP2: eliminate dead candidates
    
    deleteDeadCells(candidates);
    freeMemory(alive);
    alive = candidates;
    toPlot(alive);
    printf("before refresh\n");
    refresh();
    printf("manigga\n");
    // END LOOP
    freeMemory(alive);
    printf("lele");
    getch();
    endwin();
    return 0;   
}