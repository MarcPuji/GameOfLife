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

unsigned int confs;

void configuration_v2(int msizex, int msizey, tCell *a){
//Opening and reading the .txt file from where the data will be obtained. Also variable declaration. Return -1 in case of file not found or wrong name.
	FILE* miarchivo=NULL;
	char* nombrearchivo = "structures.txt";
	char lectura_r[80];
	char lectura_d[80];
	char lectura_a[80];	
	int numero_r;
	int numero_d;
	int numero_a;
	miarchivo = fopen(nombrearchivo,"r");
	//if(miarchivo==NULL)return -1;

//Scanning the data from .txt file.
//R-pentomino
	fscanf(miarchivo,"%s",&lectura_r);
	fscanf(miarchivo,"%i",&numero_r);
	printf("Number of confg. of R-pentomino: %i\n",numero_r);
	int loc_config_x_r[numero_r];
	int loc_config_y_r[numero_r];

	for(int i=0;i<numero_r;i++){
		fscanf(miarchivo,"%i",&loc_config_x_r[i]);
		fscanf(miarchivo,"%i",&loc_config_y_r[i]);
		//printf("col %i fil %i\n",loc_config_x_r[i],loc_config_y_r[i]);
		R_pentomino_insert(loc_config_x_r[i],loc_config_y_r[i],a);
	}	
//Diehard
	fscanf(miarchivo,"%s",&lectura_d);
	fscanf(miarchivo,"%i",&numero_d);
	printf("Number of confg. of Diehard: %i\n",numero_d);
	int loc_config_x_d[numero_d];
	int loc_config_y_d[numero_d];

	for(int i=0;i<numero_d;i++){
		fscanf(miarchivo,"%i",&loc_config_x_d[i]);
		fscanf(miarchivo,"%i",&loc_config_y_d[i]);
		//printf("col %i fil %i\n",loc_config_x_d[i],loc_config_y_d[i]);
      		Diehard_insert(loc_config_x_d[i],loc_config_y_d[i],a); 
	}
//Acorn
	fscanf(miarchivo,"%s",&lectura_a);
	fscanf(miarchivo,"%i",&numero_a);
	printf("Number of confg. of Diehard: %i\n",numero_a);
	int loc_config_x_a[numero_a];
	int loc_config_y_a[numero_a];

	for(int i=0;i<numero_a;i++){
		fscanf(miarchivo,"%i",&loc_config_x_a[i]);
		fscanf(miarchivo,"%i",&loc_config_y_a[i]);
		//printf("col %i fil %i\n",loc_config_x_a[i],loc_config_y_a[i]);
      		Acorn_insert(loc_config_x_a[i],loc_config_y_a[i],a); 
	}
  return;
}
