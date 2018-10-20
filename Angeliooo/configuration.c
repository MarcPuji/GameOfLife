//Function for requesting the configuration to the user
/*Info needed: # of conf, size (in rows and columns), location of the upper left cell,
number of alive cells, location of alive cells*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//unsigned int confs,size_rows,size_columns,loc_config_row,loc_config_column,alive_cells,row_alive,column_alive;
unsigned int confs;

void main(void){

  printf("Welcome to GameOfLife\n");
  printf("Enter number of configurations\n");
  scanf("%u", &confs);

  unsigned int size_rows[confs],size_columns[confs],loc_config_row[confs],loc_config_column[confs],alive_cells[confs];

  for (int i = 0; i < confs; i++){

    printf("Enter size configuration %i in rows and columns\n",i+1);
    scanf("%u %u", &size_rows[i], &size_columns[i]);
    printf("Enter location configuration %i upper left cell in rows and columns\n",i+1);
    scanf("%u %u", &loc_config_row[i], &loc_config_column[i]);
    printf("Enter number of alive cells in configuration %i\n",i+1);
    scanf("%u", &alive_cells[i]);

  /*  for (int j = 0; j < alive_cells; j++){

      printf("Enter location configuration %i alive cell %i in rows and columns\n",i+1,j+1);
      scanf("%u %u", &row_alive, &column_alive);

    }*/
  }

  return confs;
}
