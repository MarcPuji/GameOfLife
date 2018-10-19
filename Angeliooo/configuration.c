//Function for requesting the configuration to the user
/*Info needed: # of conf, size (in rows and columns), location of the upper left cell,
number of alive cells, location of alive cells*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int confs,rows,columns,location_row,location_column;

void main(void){

  printf("Welcome to GameOfLife\n");
  printf("Enter number of configurations\n");
  scanf("%u", &confs);

  for (int i = 0; i < confs; i++){
    printf("Enter size configuration %i in rows and columns\n",i+1);
    scanf("%u %u", &rows, &columns);
    printf("Enter location configuration %i upper left cell in rows and columns\n",i+1);
    scanf("%u %u", &location_row, &location_column);
  }

  return confs;
}
