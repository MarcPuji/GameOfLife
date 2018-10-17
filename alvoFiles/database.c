

#include "database.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct Cell{
    int x;
    int y;
    int neighbours;
    int alive;
    Cell* childx; // The idea is to create a set data structure of cells
    Cell* childy; // so that we can keep track of alive cells and candidates alike.
                  // This data structure will be structured as a tree. The hierarchy
                  // of sorting cells will be done first by sorting them by their position
                  // in x and then by their position in y.
} tCell;

tCell* cellDataBase();
bool checkExistence(int x, int y, tCell *a);
void insertCell(int x, int y, bool alive, tCell *a);
void addCandidates(tCell *alive, tCell *candidates) 
void deleteDeadCells(tCell *a);
void freeMemory(tCell *a);
int explore(tCell *a)
*/

tCell* cellDataBase(void){
    tCell* aux = (tCell *) malloc(sizeof(tCell));
    aux->x = -1;
    aux->y =  0;
    aux->childx = NULL;
    aux->childy = NULL;
    aux->neighbours = 0;
    aux->alive = 0;
    return aux;
}

void insertCell(int x, int y, bool alive, tCell *a){
    int neighbours = 1;
    if (alive == 1){
        neighbours = 0;
    }
    //printf("Coordinates (x, y) = (%d, %d)\n",a->x,a->y);
    if(a->x == x){
        if(a->y == y){
            if(alive == 1){
                a->alive = 1;
            }
            else{
                a->neighbours++;
            }
        }
        else if(a->childy == NULL){
            tCell *newCell = (tCell *) malloc(sizeof(tCell));
            newCell->x = x;
            newCell->y = y;
            newCell->alive = alive;
            newCell->neighbours = neighbours;
            newCell->childx = NULL;
            newCell->childy = NULL;
            a->childy = newCell;
        }
        else if(a->childy->y > y){
            tCell *newCell = (tCell *) malloc(sizeof(tCell));
            newCell->x = x;
            newCell->y = y;
            newCell->alive = alive;
            newCell->neighbours = neighbours;
            newCell->childx = NULL;
            newCell->childy = a->childy;
            a->childy = newCell;    
        }
        else{
            insertCell(x,y,alive,a->childy);
        }
    }
    else if(a->childx == NULL){
        tCell *newCell = (tCell *) malloc(sizeof(tCell));
        newCell->x = x;
        newCell->y = y;
        newCell->alive = alive;
        newCell->neighbours = neighbours;
        newCell->childx = NULL;
        newCell->childy = NULL;
        a->childx = newCell;
    }
    else if(a->childx->x > x){
        tCell *newCell = (tCell *) malloc(sizeof(tCell));
        newCell->x = x;
        newCell->y = y;
        newCell->alive = alive;
        newCell->neighbours = neighbours;
        newCell->childx = a->childx;
        newCell->childy = NULL;
        a->childx = newCell;
    }
    else if(a->childx->x == x && a->childx->y > y){
        tCell *newCell = (tCell *) malloc(sizeof(tCell));
        newCell->x = x;
        newCell->y = y;
        newCell->alive = alive;
        newCell->neighbours = neighbours;
        newCell->childx = a->childx->childx;
        newCell->childy = a->childx;
        a->childx->childx = NULL;
        a->childx = newCell;
    }
    else{
        insertCell(x,y,alive,a->childx);
    }
}

void toString(tCell *a){
    if(a->x != -1){
        printf("Coordinates (x, y) = (%d, %d), alive = %d, neighbours = %d\n",
            a->x,a->y,a->alive,a->neighbours);
    }
    if(a->childy != NULL){
        toString(a->childy);
    }
    if(a->childx != NULL){
        toString(a->childx);
    }
}

void freeMemory(tCell *a){
    if(a->x != -1){
        /*
        printf("Exploring (x, y) = (%d, %d), alive = %d, neighbours = %d\n",
            a->x,a->y,a->alive,a->neighbours);*/
    }
    if(a->childy != NULL){
        freeMemory(a->childy);
    }
    if(a->childx != NULL){
        freeMemory(a->childx);
    }
    //printf("Memory freed at (x, y) = (%d, %d)\n",a->x,a->y);
    free(a);
}

void addCandidates(tCell *alive, tCell *candidates, int limitx, int limity){
    //iterating through the alive cell data structure
    if(alive->x != -1){
        insertCell(alive->x,alive->y,1,candidates);
        if(alive->x > 0)insertCell(alive->x-1,alive->y,0,candidates);
        if(alive->x > 0 && alive->y > 0)insertCell(alive->x-1,alive->y-1,0,candidates);
        if(alive->x > 0 && alive->y < limity-1)insertCell(alive->x-1,alive->y+1,0,candidates);

        if(alive->y > 0)insertCell(alive->x,alive->y-1,0,candidates);
        if(alive->y < limity-1)insertCell(alive->x,alive->y+1,0,candidates);

        if(alive->x < limitx-1)insertCell(alive->x+1,alive->y,0,candidates);
        if(alive->x < limitx-1 && alive->y > 0)insertCell(alive->x+1,alive->y-1,0,candidates);
        if(alive->x < limitx-1 && alive->y < limity-1)insertCell(alive->x+1,alive->y+1,0,candidates);
    }
    /*
    printf("STEP\n");
    printf("cell: (x, y) = (%d, %d)\n",alive->x,alive->y);
    toString(candidates);
    printf("END STEP\n");
    */
    if(alive->childy != NULL){
        addCandidates(alive->childy,candidates,limitx,limity);
    }
    if(alive->childx != NULL){
        addCandidates(alive->childx,candidates,limitx,limity);
    }
}

void deleteDeadCells(tCell *candidates){

    // Check if the current cell deserves to be alive or not in the next iteration
    if(candidates->x != -1){
        if(candidates->neighbours == 3)candidates->alive = 1;
        else if(candidates->neighbours < 2 || candidates->neighbours > 3)candidates->alive = 0;
        //if(candidates->alive == 1)printf("cell: (x, y) = (%d, %d)\n",candidates->x,candidates->y);
    }
   
    // This ensures that we move along the whole database
    if(candidates->childy != NULL){
        deleteDeadCells(candidates->childy);
        //look if child in y is alive, if not we delete it and restructure the database
        if(candidates->childy->alive == 0){
            tCell *tempCell = candidates->childy;
            candidates->childy = candidates->childy->childy;
            free(tempCell);
        }
        
        /*printf("STEPy\n");
        printf("cell: (x, y) = (%d, %d)\n",candidates->x,candidates->y);
        toString(candidates);
        printf("END STEP\n");*/
        
    }
    if(candidates->childx != NULL){
        deleteDeadCells(candidates->childx);
        // look if child in x is alive, otherwise delete it
        // the difference in here is that the next child should be
        // either the next cell in that column or the next column if
        // that column doesn't exist anymore
        if(candidates->childx->alive == 0){
            tCell *tempCell = candidates->childx;
            if(candidates->childx->childy != NULL){
                candidates->childx->childy->childx = candidates->childx->childx;
                candidates->childx = candidates->childx->childy;
            }
            else{
                candidates->childx = candidates->childx->childx;
            }
            free(tempCell);
        }
        /*printf("STEPx\n");
        printf("cell: (x, y) = (%d, %d)\n",candidates->x,candidates->y);
        toString(candidates);
        printf("END STEP\n");*/
    }
    //printf("cell: (x, y) = (%d, %d)\n",candidates->x,candidates->y);
}


int main(char* args){
    // initialize
    tCell* alive = cellDataBase();
    insertCell(1,0,1,alive);
    insertCell(0,1,1,alive);
    insertCell(1,2,1,alive);
    printf("ALIVE\n");
    toString(alive);
    // LOOP
    // STEP1: search candidates
    tCell* candidates = cellDataBase();
    printf("CANDIDATES\n");
    addCandidates(alive,candidates,3,3);
    toString(candidates);
    printf("NEW ALIVE CELLS\n");

    // STEP2: eliminate dead candidates
    deleteDeadCells(candidates);
    toString(candidates);
    freeMemory(alive);
    alive = candidates;
    // END LOOP

    freeMemory(alive);
    freeMemory(candidates);
    return 0;         
}


