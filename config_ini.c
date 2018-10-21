#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "cellstruct.h"

void config_ini(myCell ** matrix, int msize){ // Load the initial configuration to the created matrix
	////// TODO: INSERTING PIECES FUNCTIONS /////
	// Let's add a Beehive figure
	matrix[msize/2][msize/2].alive = 1;
	matrix[msize/2 + 1][msize/2].alive = 1;
	matrix[msize/2 - 1][msize/2 + 1].alive = 1;
	matrix[msize/2 + 2][msize/2 + 1].alive = 1;
	matrix[msize/2][msize/2 + 2].alive = 1;
	matrix[msize/2 + 1][msize/2 + 2].alive = 1;

	matrix[msize/2][msize/2 + 1].alive = 1;
	matrix[msize/2 + 1][msize/2 +1].alive = 1;
}