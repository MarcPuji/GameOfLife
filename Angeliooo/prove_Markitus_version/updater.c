#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "cellstruct.h"

void neighbours(myCell ** matrix, int msizex, int msizey){

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

  if(cell_status == 1){
    mvwaddch(mywin, y, x, ACS_CKBOARD);
  }
}

bool updater(myCell ** matrix, int msizex, int msizey, WINDOW * mywin){ // Function is recieving the matrix pointer and updating its content

  bool alive = false;

  for (int i = 0; i < msizex; i++){
    for (int j = 0; j < msizey; j++){

      if (matrix[i][j].alive == 1){ // If the cell is alive
        if (matrix[i][j].neighbours < 2 || matrix[i][j].neighbours > 3){ // It dies by under- or over- population
          matrix[i][j].alive = 0;
        }
        else{
          alive = true;
        }
      }
      else{ // If the cell is dead
        if (matrix[i][j].neighbours == 3){ // It becomes alive by reproduction
          matrix[i][j].alive = 1;
          alive = true;
        }
      }

      // Afer updating the cell status, plot them
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive, mywin);
    }
  }

  return alive;
}