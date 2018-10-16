

#include "database.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct Cell{
    int x;
    int y;
    int neighbors;
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
    aux->neighbors = 0;
    aux->alive = 0;
    return aux;
}

void insertCell(int x, int y, bool alive, tCell *a){
    int neighbors = 1;
    if (alive == 1){
        neighbors = 0;
    }
    //printf("Coordinates (x, y) = (%d, %d)\n",a->x,a->y);
    if(a->x == x){
        if(a->y == y){
            if(alive == 1){
                a->alive = 1;
            }
            else{
                a->neighbors++;
            }
        }
        else if(a->childy == NULL){
            tCell *newCell = (tCell *) malloc(sizeof(tCell));
            newCell->x = x;
            newCell->y = y;
            newCell->alive = alive;
            newCell->neighbors = neighbors;
            newCell->childx = NULL;
            newCell->childy = NULL;
            a->childy = newCell;
        }
        else if(a->childy->y > y){
            tCell *newCell = (tCell *) malloc(sizeof(tCell));
            newCell->x = x;
            newCell->y = y;
            newCell->alive = alive;
            newCell->neighbors = neighbors;
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
        newCell->neighbors = neighbors;
        newCell->childx = NULL;
        newCell->childy = NULL;
        a->childx = newCell;
    }
    else if(a->childx->x > x){
        tCell *newCell = (tCell *) malloc(sizeof(tCell));
        newCell->x = x;
        newCell->y = y;
        newCell->alive = alive;
        newCell->neighbors = neighbors;
        newCell->childx = a->childx;
        newCell->childy = NULL;
        a->childx = newCell;
    }
    else if(a->childx->x == x && a->childx->y > y){
        tCell *newCell = (tCell *) malloc(sizeof(tCell));
        newCell->x = x;
        newCell->y = y;
        newCell->alive = alive;
        newCell->neighbors = neighbors;
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
        printf("Coordinates (x, y) = (%d, %d), alive = %d, neighbors = %d\n",
            a->x,a->y,a->alive,a->neighbors);
    }
    if(a->childy != NULL){
        toString(a->childy);
    }
    if(a->childx != NULL){
        toString(a->childx);
    }
}

int main(char* args){
    tCell* db = cellDataBase();
    insertCell(0,0,0,db);
    insertCell(0,1,0,db);
    insertCell(2,1,0,db);
    insertCell(1,0,0,db);
    insertCell(1,1,0,db);
    insertCell(2,0,0,db);
    toString(db);
    return 0;         
}