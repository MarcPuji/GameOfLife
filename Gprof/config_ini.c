#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "cellstruct.h"

void config_ini(myCell ** matrix, int msizex, int msizey){ // Load the initial configuration to the created matrix
	////// TODO: INSERTING PIECES FUNCTIONS /////

	// Beehive figure
	//matrix[msizex/2][msizey/2].alive = 1;
	//matrix[msizex/2 + 1][msizey/2].alive = 1;
	//matrix[msizex/2 - 1][msizey/2 + 1].alive = 1;
	//matrix[msizex/2 + 2][msizey/2 + 1].alive = 1;
	//matrix[msizex/2][msizey/2 + 2].alive = 1;
	//matrix[msizex/2 + 1][msizey/2 + 2].alive = 1;
	// Beehive figure

	// R-pentomino
	// matrix[msizex/2][msizey/2].alive = 1;
	// matrix[msizex/2][msizey/2 - 1].alive = 1;
	// matrix[msizex/2 + 1][msizey/2 - 1].alive = 1;
	//matrix[msizex/2][msizey/2 + 1].alive = 1;
	//matrix[msizex/2 - 1][msizey/2].alive = 1;
	// R-pentomino

	// Glider
	matrix[msizex/2][msizey/2 - 1].alive = 1;
	matrix[msizex/2 + 1][msizey/2].alive = 1;
	matrix[msizex/2][msizey/2 + 1].alive = 1;
	matrix[msizex/2 + 1][msizey/2 + 1].alive = 1;
	matrix[msizex/2 - 1][msizey/2 + 1].alive = 1;
}