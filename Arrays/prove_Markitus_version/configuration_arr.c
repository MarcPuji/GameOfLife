//Function for requesting the initial configurations to the user through terminal
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "configuration_arr.h"
#include "R_pentomino_insert_arr.h"
#include "Diehard_insert_arr.h"
#include "Acorn_insert_arr.h"
#include "cellstruct.h"

int confs;

//msizex and msizey are the display window dimensions and **matrix is the myCell type (struct) matrix of pointers defined in the main program
void configuration_arr(myCell ** matrix, int msizex, int msizey){

  //To request and read the number of configurations to prove
  printf("Welcome to GameOfLife\r\n");
  printf("Enter number of configurations\r\n");
  scanf("%i", &confs);
  printf("%i configurations selected\r\n",confs);

  int loc_config_x[confs],loc_config_y[confs],configType[confs];

  //Initialize variables (to enter the while loops)
  //Assigned configType 1 for R-pentomino, 2 for Diehard and 3 for Acorn
  for (int k = 0; k < confs; k++){
    loc_config_x[k]=-1;   //out of screen
    loc_config_y[k]=-1;   //out of screen
    configType[k]=4;      //none of the configurations
  }

  for (int i = 0; i < confs; i++){  //For all configurations

    while (configType[i]!=1 && configType[i]!=2 && configType[i]!=3){ //requests for a configuration until a correct number is insert
      printf("Select configuration to prove (1:R-pentomino, 2:Diehard and 3:Acorn) for configuration %i\r\n",i+1);
      scanf("%i", &configType[i]);

      if (configType[i]!=1 && configType[i]!=2 && configType[i]!=3) printf("error: Configuration not found\r\n");
      else printf("configuration found\r\n");
    }
    //Checking for each type, if the location is inside the window
    if (configType[i]==1){
      printf("R-pentomino selected for configuration %i\r\n",i+1);
      while ((loc_config_x[i]<0 || loc_config_x[i]+4>msizex-1)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey-1)){ //requests a location until the location inserted is inside the window
        //loc_config_x[i]+4 is the upper left cell. msizex-1 is the maximum column allowed according to the size
        printf("Enter location R-pentomino config %i upper left cell in x(columns) and y(rows)\r\n",i+1);
        scanf("%i %i", &loc_config_x[i], &loc_config_y[i]);
        if ((loc_config_x[i]<0 || loc_config_x[i]+4>msizex-1)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey-1)) printf("error: Out of screen\r\n");
        else printf("location accepted: x=%i y=%i\r\n",loc_config_x[i],loc_config_y[i]);
      }
      R_pentomino_insert_arr(loc_config_x[i],loc_config_y[i],matrix); //function to insert the R-pentomino in the matrix of pointers
    }

    else if (configType[i]==2){
      printf("Diehard selected for configuration %i\r\n",i+1);
      while ((loc_config_x[i]<0 || loc_config_x[i]+9>msizex-1)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey-1)){
        printf("Enter location Diehard config %i upper left cell in x(columns) and y(rows)\r\n",i+1);
        scanf("%i %i", &loc_config_x[i], &loc_config_y[i]);
        if ((loc_config_x[i]<0 || loc_config_x[i]+9>msizex-1)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey-1)) printf("error: Out of screen\r\n");
        else printf("location accepted: x=%i y=%i\r\n",loc_config_x[i],loc_config_y[i]);
      }
      Diehard_insert_arr(loc_config_x[i],loc_config_y[i],matrix);
    }

    else if (configType[i]==3){
      printf("Acorn selected for configuration %i\r\n",i+1);
      while ((loc_config_x[i]<0 || loc_config_x[i]+8>msizex-1)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey-1)){
        printf("Enter location Acorn config %i upper left cell in x(columns) and y(rows)\r\n",i+1);
        scanf("%i %i", &loc_config_x[i], &loc_config_y[i]);
        if ((loc_config_x[i]<0 || loc_config_x[i]+8>msizex-1)||(loc_config_y[i]<0 || loc_config_y[i]+4>msizey-1)) printf("error: Out of screen\r\n");
        else printf("location accepted: x=%i y=%i\r\n",loc_config_x[i],loc_config_y[i]);
      }
      Acorn_insert_arr(loc_config_x[i],loc_config_y[i],matrix); 
    }
  }
  return;
}
