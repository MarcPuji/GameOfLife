//Function for requesting the configuration to the user
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "configuration_v2.h"
#include "R_pentomino_insert.h"
#include "Diehard_insert.h"
#include "Acorn_insert.h"
#include "database.h"

int confs;

void configuration_v2(int msizex, int msizey, tCell *a){

  printf("Welcome to GameOfLife");
  printf("Enter number of configurations");
  scanf("%u", &confs);

  int loc_config_x[confs],loc_config_y[confs],configType[confs];

  //Initialize variables (to enter the while loops)
  for (int k = 0; k < confs; k++){
    loc_config_x[k]=-1;   //out of screen
    loc_config_y[k]=-1;   //out of screen
    configType[k]=4;      //none of the configurations
  }

  for (int i = 0; i < confs; i++){

    while (configType[i]!=1 && configType[i]!=2 && configType[i]!=3){
      printf("Select configuration to prove (1:R-pentomino, 2:Diehard and 3:Acorn) for configuration %i\n",i+1);
      scanf("%u", &configType[i]);

      if (configType[i]!=1 && configType[i]!=2 && configType[i]!=3) printf("error: Configuration not found\n");
      else printf("configuration found\n");
    }

    if (configType[i]==1){
      printf("R-pentomino selected for configuration %i\n",i+1);
      while ((loc_config_x[i]<0 || loc_config_x[i]+4>msizex)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey)){
        printf("Enter location R-pentomino config %i upper left cell in x(columns) and y(rows)\n",i+1);
        scanf("%u %u", &loc_config_x[i], &loc_config_y[i]);
        if ((loc_config_x[i]<0 || loc_config_x[i]+4>msizex)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey)) printf("error: Out of screen\n");
        else printf("location accepted\n");
      }
      R_pentomino_insert(loc_config_x[i],loc_config_y[i],a); //a is a type tCell pointer
    }

    else if (configType[i]==2){
      printf("Diehard selected for configuration %i\n",i+1);
      while ((loc_config_x[i]<0 || loc_config_x[i]+9>msizex)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey)){
        printf("Enter location Diehard config %i upper left cell in x(columns) and y(rows)\n",i+1);
        scanf("%u %u", &loc_config_x[i], &loc_config_y[i]);
        if ((loc_config_x[i]<0 || loc_config_x[i]+9>msizex)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey)) printf("error: Out of screen\n");
        else printf("location accepted\n");
      }
      Diehard_insert(loc_config_x[i],loc_config_y[i],a); //a is a type tCell pointer
    }

    else if (configType[i]==3){
      printf("Acorn selected for configuration %i\n",i+1);
      while ((loc_config_x[i]<0 || loc_config_x[i]+8>msizex)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey)){
        printf("Enter location Acorn config %i upper left cell in x(columns) and y(rows)\n",i+1);
        scanf("%u %u", &loc_config_x[i], &loc_config_y[i]);
        if ((loc_config_x[i]<0 || loc_config_x[i]+8>msizex)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey)) printf("error: Out of screen\n");
        else printf("location accepted\n");
      }
      Acorn_insert(loc_config_x[i],loc_config_y[i],a); //a is a type tCell pointer
    }
  }
  return;
}
