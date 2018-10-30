// Author: Coder 4

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/cellstruct.h"

void neighbours(myCell ** matrix, int msizex, int msizey){

  // Count the number of neighbours for each cell
  for (int i = 0; i < msizex; i++){
    for (int j = 0; j < msizey; j++){
      matrix[i][j].neighbours = 0;
      if ((j-1) >= 0){ // If there is a row above
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i][j-1].alive;

        if ((i-1) >= 0){ // If there is a column to the left
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i-1][j-1].alive;
        }

        if ((i+1) < msizex){ // If there is a column to the right
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i+1][j-1].alive;
        }
      }

      if ((j+1) < msizey){ // If there is a row below
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i][j+1].alive;

        if ((i-1) >= 0){ // If there is a column to the left
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i-1][j+1].alive;
        }

        if ((i+1) < msizex){ // If there is a column to the right
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i+1][j+1].alive;
        }
      }

      if ((i-1) >= 0){ // If there is a column to the left
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i-1][j].alive;
      }

      if ((i+1) < msizex){ // If there is a column to the right
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i+1][j].alive;
      }
    }
  }
}

void plotter(int x, int y, int cell_status, WINDOW * mywin){

  // Plot the alive cells
  if(cell_status == 1){
    mvwaddch(mywin, y, x, ACS_CKBOARD);
  }
}

void updater(myCell ** matrix, int msizex, int msizey, WINDOW * mywin, int ** LUT){ // Function is recieving the matrix pointer and updating its content
	
  // Update the cells status
  for (int i = 0; i < msizex; i++){
    for (int j = 0; j < msizey; j++){
      // Using the Look-Up-Table
      matrix[i][j].alive = LUT[matrix[i][j].alive][matrix[i][j].neighbours];
      // Afer updating the cell status, plot them
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive, mywin);
    }
  }
}