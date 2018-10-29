//Function for requesting the configuration to the user
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell. All specified in the 'structures.txt' file*/
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
//Opening and reading the .txt file from where the data will be obtained. Also variable declaration. 
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
//Defining locations array and counter
	int loc_config_x_r[numero_r];
	int loc_config_y_r[numero_r];
	int cont_r;

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.
	for(int i=0;i<numero_r;i++){
		cont_r = i+1;
		fscanf(miarchivo,"%i",&loc_config_x_r[i]);
		fscanf(miarchivo,"%i",&loc_config_y_r[i]);
		if(((loc_config_x_r[i]+4)>msizex) || (loc_config_x_r[i]<1) || ((loc_config_y_r[i]+4)>msizey) || (loc_config_y_r[i]<1)){
		printf("Error: In R-pentomino, the %iº coordinates are not allowed\n",cont_r);
		}else{
		R_pentomino_insert(loc_config_x_r[i],loc_config_y_r[i],a);
	}
	}
//Diehard
	//Scanning the data from .txt file.
	fscanf(miarchivo,"%s",&lectura_d);
	fscanf(miarchivo,"%i",&numero_d);
	printf("Number of confg. of Diehard: %i\n",numero_d);
	int loc_config_x_d[numero_d];
	int loc_config_y_d[numero_d];
	int cont_d;

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.
	for(int i=0;i<numero_d;i++){
		cont_d = i+1;
		fscanf(miarchivo,"%i",&loc_config_x_d[i]);
		fscanf(miarchivo,"%i",&loc_config_y_d[i]);;
		if(((loc_config_x_d[i]+4)>msizex) || (loc_config_x_d[i]<1) || ((loc_config_y_d[i]+4)>msizey) || (loc_config_y_d[i]<1)){
		printf("Error: In Diehard, the %iº coordinates are not allowed\n",cont_d);
		}else{
      		Diehard_insert(loc_config_x_d[i],loc_config_y_d[i],a); 
	}
	}
//Acorn
	//Scanning the data from .txt file.
	fscanf(miarchivo,"%s",&lectura_a);
	fscanf(miarchivo,"%i",&numero_a);
	printf("Number of confg. of Diehard: %i\n",numero_a);
	int loc_config_x_a[numero_a];
	int loc_config_y_a[numero_a];
	int cont_a;

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.	
	for(int i=0;i<numero_a;i++){
		cont_a = i+1;
		fscanf(miarchivo,"%i",&loc_config_x_a[i]);
		fscanf(miarchivo,"%i",&loc_config_y_a[i]);
		if(((loc_config_x_a[i]+4)>msizex) || (loc_config_x_a[i]<1) || ((loc_config_y_a[i]+4)>msizey) || (loc_config_y_a[i]<1)){
		printf("Error: In Acorn, the %iº coordinates are not allowed\n",cont_a);
		}else{
      		Acorn_insert(loc_config_x_a[i],loc_config_y_a[i],a); 
	}
	}
	free(FILE);
	free(char);
  return;
}
