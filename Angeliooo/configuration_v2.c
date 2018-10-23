//Function for requesting the configuration to the user
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "database.h"

unsigned int confs;

void configuration_v2(tCell *a){

  printf("Welcome to GameOfLife\n");
  printf("Enter number of configurations\n");
  scanf("%u", &confs);

  unsigned int loc_config_x[confs],loc_config_y[confs],configType[confs];

  for (int i = 0; i < confs; i++){

    while (configType[i]!=1 && configType[i]!=2 && configType[i]!=3){
      printf("Select configuration to prove (1:R-pentomino, 2:Diehard and 3:Acorn) for configuration %i\n",i+1);
      scanf("%u", &configType[i]);

      if (configType[i]!=1 && configType[i]!=2 && configType[i]!=3) printf("configuration not found\n");
      else printf("configuration found\n");
    }

    if (configType[i]==1){
      printf("R-pentomino selected for configuration %i\n",i+1);
      printf("Enter location R-pentomino config %i upper left cell in x(columns) and y(rows)\n",i+1);
      scanf("%u %u", &loc_config_x[i], &loc_config_y[i]);
      R_pentomino_insert(loc_config_x[i],loc_config_y[i],a); //a es un puntero tipo tCell (LLAMARLO ASI EN EL MAIN, NO ALIVE QUE CREA CONFUSION PORQUE TAMBIEN SE INSERTAN CELDAS MUERTAS)
    }

    else if (configType[i]==2){
      printf("Diehard selected for configuration %i\n",i+1);
      printf("Enter location Diehard config %i upper left cell in x(columns) and y(rows)\n",i+1);
      scanf("%u %u", &loc_config_x[i], &loc_config_y[i]);
      //Diehard instert function
    }

    else if (configType[i]==3){
      printf("Acorn selected for configuration %i\n",i+1);
      printf("Enter location Acorn config %i upper left cell in x(columns) and y(rows)\n",i+1);
      scanf("%u %u", &loc_config_x[i], &loc_config_y[i]);
      //Acorn instert function
    }
  }
  return confs;
}
