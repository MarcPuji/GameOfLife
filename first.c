
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
 
 ////////// THIS PART HAS TO BE DONE ONLY ONCE //////////

 // Initializing the cell structure
	typedef struct{
		int alive;
		int pos_x;
		int pos_y;
	} cell;

  int msize = 250;
  // Create an msize x msize matrix of cell pointers
  cell ** matrix = (cell **) malloc(msize*sizeof(cell)); // 250 cell pointers
  for (int i = 0; i < msize; i++){ // for each position, create 250 more
    matrix[i] = (cell *) malloc(msize*sizeof(cell));
  }

  // Give each cell its own position
  for (int i = 0; i < msize; i++){
  	for (int j = 0; j < msize; j++){
  		matrix[i][j].pos_x = i;
  		matrix[i][j].pos_y = j;
  	}
  }
  ///////////////////


  // Let's make alive some cells
  matrix[10][10].alive = 1;
  matrix[20][10].alive = 1;
  matrix[30][10].alive = 1;

  initscr(); // Init the screen

  // Check which cells are alive
  for (int i = 0; i < msize; i++){
  	for (int j = 0; j < msize; j++){
  		if(matrix[i][j].alive == true){
  			mvaddch(matrix[i][j].pos_y, matrix[i][j].pos_x, ACS_DIAMOND);
  		}
  		else{
  			mvaddch(matrix[i][j].pos_y, matrix[i][j].pos_x, ACS_HLINE);
  		}
  	}
  }

  refresh(); // Refresh the screen so it shows the added points

  getch(); // Wait for the user to click the keyboard (otherwise the program shuts down)
  
  endwin(); // End the screen
  
  
  return 0;
}
  
  
