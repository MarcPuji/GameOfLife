#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "config_ini.h"
#include "database.h"


void config_ini(tCell *a, int msizex, int msizey){ // Load the initial configuration to the created matrix
	////// TODO: INSERTING PIECES FUNCTIONS /////
	// Glider
	insertCell(msizex/2, msizey/2 - 1, true, a);
	insertCell(msizex/2 + 1, msizey/2, true, a);
	insertCell(msizex/2, msizey/2 + 1, true, a);
	insertCell(msizex/2 + 1, msizey/2 + 1, true, a);
	insertCell(msizex/2 - 1, msizey/2 + 1, true, a);
}