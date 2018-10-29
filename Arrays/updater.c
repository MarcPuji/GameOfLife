#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/cellstruct.h"

void neighbours(myCell ** matrix, int msizex, int msizey){
<<<<<<< HEAD:updater.c

=======
  // Count the number of neighbours for each cell
>>>>>>> juntando:Arrays/updater.c
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
<<<<<<< HEAD:updater.c

=======
  // Plot the alive cells
>>>>>>> juntando:Arrays/updater.c
  if(cell_status == 1){
    mvwaddch(mywin, y, x, ACS_CKBOARD);
  }
}

<<<<<<< HEAD:updater.c
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

=======
void updater(myCell ** matrix, int msizex, int msizey, WINDOW * mywin, int ** LUT){ // Function is recieving the matrix pointer and updating its content
  // Update the cells status
  for (int i = 0; i < msizex; i++){
    for (int j = 0; j < msizey; j++){
      // Using the Look-Up-Table
      matrix[i][j].alive = LUT[matrix[i][j].alive][matrix[i][j].neighbours];
>>>>>>> juntando:Arrays/updater.c
      // Afer updating the cell status, plot them
      plotter(matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].alive, mywin);
    }
  }

  return alive;
}