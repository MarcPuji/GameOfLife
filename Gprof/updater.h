#include "cellstruct.h"
#include "ncurses.h"

void neighbours(myCell **, int, int);
void plotter(int, int, int, WINDOW *);
bool updater(myCell **, int, int, WINDOW *);
