//Function for requesting the configuration to the user
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int confs;

void main(void){

  printf("Welcome to GameOfLife\n");
  printf("Enter number of configurations\n");
  scanf("%u", &confs);

  unsigned int loc_config_row[confs],loc_config_column[confs],configType[confs];

  for (int i = 0; i < confs; i++){

    printf("Select configuration to prove (1:R-pentomino, 2:Diehard and 3:Acorn) for configuration %i\n",i+1);
    scanf("%u", &configType[i]);

    if (configType==1){
      printf("R-pentomino selected for configuration %i\n",i+1);
      //R-pentomino instert function
    }
    else if (configType==2){
      printf("Diehard selected for configuration %i\n",i+1);
      //Diehard instert function
    }
    else if (configType==3){
      printf("Acorn selected for configuration %i\n",i+1);
      //Acorn instert function
    }
    else{
      printf("configuration not found");
    }

    printf("Enter location configuration %i upper left cell in rows and columns\n",i+1);
    scanf("%u %u", &loc_config_row[i], &loc_config_column[i]);

  }

  return confs;
}
