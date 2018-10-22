

#include "database.h"
#include <stdio.h>
#include <stdlib.h>

// Standard initialization of the data structure

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


/*
 Function in order to insert another cell in a predefined data structure
 The needed parameters to define the cell are their coordinates and
 whether it is alive or dead. The cells in the database are sorted (incrementally) by their
 x-coordinate, when finding a draw in the x-coordinate, we sort (incrementally) using 
 the y-coordinate. The key (x,y) identifies unequivocally every possible cell in the game.
*/
void insertCell(int x, int y, bool alive, tCell *a){
    int neighbours = 1;
    if (alive == 1){        
    /* 
    If the cell is alive, it means it has
    been inserted as a candidate because it was
    an alive cell in the current timestep, not because
    it was somebody's neighbour and should be initialized
    with the number of neighbours to 0 instead of 1.
    */
        neighbours = 0;
    }

    //printf("Coordinates (x, y) = (%d, %d)\n",a->x,a->y);
    if(a->x == x){
        /*
         if the latter condition holds the new cell either must
         be inserted in the current column or has already been
         previously inserted in the current column.
        */
        if(a->y == y){
            /*
            If the latter condition holds, then the cell was already in
            the database. This means whether it has been called by an alive
            neighbour (case 1), or it has been called because it is alive.
            Case 1: we add 1 to the number of neighbours that cell has. 
            Case 2: we don't touch the number of neighbours of that cell, 
            but make sure it is noted it is alive.
            */
            if(alive == 1){
                a->alive = 1;
            }
            else{
                a->neighbours++;
            }
        }

        /*
        If the cell is not already in the database then it must be inserted.
        We create the cell pointer to a reserved memory allocation and rearrange
        the pointers so as to include this cell in the current database.
        CASE1:
            We arrive at the extreme of the database in the y-axis of that column,
            we must include the new cell at the end of the column.
        CASE 2:
            We find the spot where our new cell must be (between cells of lower and 
            greater y-coordinates). We rearrange the pointers so as to integrate the
            cell in the database.
        CASE 3:
            We are in neither of the previous cases and continue to go ahead to explore the
            current column.
        */
        // CASE 1:
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
        // CASE 2:
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
        // CASE 3:
        // if the next row is not the one where the cell must be inserted we move across rows.
        else{
            insertCell(x,y,alive,a->childy);
        }
    }
    /*
    If we were not in the right column, we must look if we should iterate through the
    next column (CASE 4), or insert it as/in the next column (CASE 1, CASE 2 / CASE 3).
    */

    /* CASE 1:
       We are at the extreme in x and have still not found a proper
       spot for the new cell, we create a new column containing just
       our cell and append it to our database.
    */
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

    /* CASE 2:
       We have found the spot where our cell x-coordinates is greater than
       the x-coordinates of the one preceeding it and lower than the one after it.
       We rearrange the pointers so as to include it between both columns. Conceptually,
       it is a new column included between the two commented columns with just one cell
       in it.
    */
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

    /* CASE 3:
       The new cell is to be put in the next column, but its why coordinate is lower than
       the top cell in that column. We rearrange the pointers so as to put the new cell at
       the top of the column followed in the y-axis by the former top cell.
    */    
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
    /* CASE 4:
       If the next column is not the column where we insert the cell we move across columns
    */
    else{
        insertCell(x,y,alive,a->childx);
    }
}

void toString(tCell *a){
    if(a->x != -1){
        printf("Coordinates (x, y) = (%d, %d), alive = %d, neighbours = %d\n",
            a->x,a->y,a->alive,a->neighbours);
    }// This allows us to advance through to the cells within and accross columns.
    if(a->childy != NULL){
        toString(a->childy); // advance through the column
    }
    if(a->childx != NULL){
        toString(a->childx); // advance across columns (only possible in the top row 
                             // for the sake of simplicity.)
    }
}

void freeMemory(tCell *a){
    if(a->x != -1){
        /*
        printf("Exploring (x, y) = (%d, %d), alive = %d, neighbours = %d\n",
            a->x,a->y,a->alive,a->neighbours);*/
    }
    // This allows us to advance through to the cells within and accross columns.
    if(a->childy != NULL){
        freeMemory(a->childy); // advance through the column
    }
    if(a->childx != NULL){
        freeMemory(a->childx); // advance across columns (only possible in the top row 
                               // for the sake of simplicity.)
    }
    free(a);
}

/*
Function used in order to create and expand a set data structure
containing all candidates to be alive cells in the next timestep
without repetitions. Each candidate contains information about
their coordinates, whether they are alive or dead and the number
of alive neighbouring cells.
*/
void addCandidates(tCell *alive, tCell *candidates, int limitx, int limity){
    //iterating through the alive cell data structure
    if(alive->x != -1){
        /*
         insert candidates in the candidates database if they are within 
         the limits of the game space.
        */
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
    
    // advance through the data structure of alive cells to the next cells in y and x
    if(alive->childy != NULL){
        addCandidates(alive->childy,candidates,limitx,limity);
    }
    if(alive->childx != NULL){
        addCandidates(alive->childx,candidates,limitx,limity);
    }
}


/*
Function used in order to determine if the cells in a database are alive or dead
according to their neighbours and deletes from the database all those cells that
result to be dead.
*/
void deleteDeadCells(tCell *candidates){
    // FEED FORWARD:
    // Check if the current cell deserves to be alive or not in the next iteration
    if(candidates->x != -1){
        if(candidates->neighbours == 3)candidates->alive = 1;
        else if(candidates->neighbours < 2 || candidates->neighbours > 3)candidates->alive = 0;
    }
   
    // Move move along the whole database first in the y, then in the x 
    if(candidates->childy != NULL){
        // FEED FORWARD:
        deleteDeadCells(candidates->childy);
        // BACKTRACKING:
        /*
        Look if child in y is alive, if not we delete it and restructure the database.
        To delete it we redirect the pointers so as to jump over the deleted cell.
        Then, we free the allocated memory that the deleted cell was ocupying.
        Though the backtracking section when deleting the x-child is a bit different
        the idea is the same: redirect pointers, then free the memory of the deleted cell.
        */
        if(candidates->childy->alive == 0){
            tCell *tempCell = candidates->childy;
            candidates->childy = candidates->childy->childy;
            free(tempCell);
        }
        
    }
    if(candidates->childx != NULL){
        // FEED FORWARD
        deleteDeadCells(candidates->childx);
        // BACTRACKING:
        /* 
         It is different than before in that if x-child is alive we let it be,
         otherwise we delete it. The difference in here is that we must consider
         if the resulting column after deleting x-child will be empty or not.

         If it becomes empty then we just have to redirect x-child's pointer to x-child's
         x-child. 

         Otherwise, we must redirect x-child's pointer to x-child's y-child, and
         the x-child pointer of that y-child must be redirected to x-child's x-child.
         */
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
        
    }
    /*
    Arriving to the end of the function means all dead cells below the cell in question
    have been eliminated from the list and their memory freed. I 
    */
}


