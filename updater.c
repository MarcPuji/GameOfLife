#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "cellstruct.h"

void neighbours(cell ** matrix, int msize){

  for (int i = 0; i < msize; i++){
    for (int j = 0; j < msize; j++){

      if ((j-1) >= 0){ // If there is a row above
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrx[i][j-1].alive;

        if ((i-1) >= 0){ // If there is a column to the left
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i-1][j-1].alive;
        }

        if ((i+1) < msize){ // If there is a column to the right
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i+1][j-1].alive;
        }
      }

      if ((j+1) < msize){ // If there is a row below
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i][j+1].alive;

        if ((i-1) >= 0){ // If there is a column to the left
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i-1][j+1].alive;
        }

        if ((i+1) < msize){ // If there is a column to the right
          matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i+1][j+1].alive;
        }
      }

      if ((i-1) >= 0){ // If there is a column to the left
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i-1][j].alive;
      }

      if ((i+1) < msize){ // If there is a column to the right
        matrix[i][j].neighbours = matrix[i][j].neighbours + matrix[i+1][j].alive;
      }
    }
  }
}

void plotter(int x, int y int cell_status){

  if(cell_status == 1){
    mvaddch(y, x, ACS_DIAMOND);
  }
  else{
    mvaddch(y, x, ACS_HLINE);
  }
}

void updater(cell ** matrix, int msize){ // Function is recieving the matrix pointer and updating its content

  for (int i = 0; i < msize; i++){
    for (int j = 0; j < msize; j++){

      if (matrix[i][j].alive == 1){ // If the cell is alive
        if (matrix[i][j].neighbours < 2 || matrix[i][j].neighbours > 3){ // It dies by under- or over- population
          matrix[i][j] = 0;
        }
      }
      else{ // If the cell is dead
        if (matrix[i][j].neighbours == 3){ // It becomes alive by reproduction
          matrix[i][j] = 1;
        }
      }

      // Afer updating the cell status, plot them
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive);
    }
  }
}