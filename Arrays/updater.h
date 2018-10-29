#include "include/cellstruct.h"
#include "ncurses.h"

void neighbours(myCell **, int, int);
void plotter(int, int, int, WINDOW *);
void updater(myCell **, int, int, WINDOW *, int **);
