#ifndef DATABASE_H
#define DATABASE_H

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


tCell* cellDataBase(void);
void insertCell(int x, int y, bool alive, tCell *a);
void toString(tCell *a);
void freeMemory(tCell *a);
void addCandidates(tCell *alive, tCell *candidates, int limitx, int limity); 
void deleteDeadCells(tCell *a, int ** lut);

//bool checkExistence(int x, int y, tCell &a);


#endif
