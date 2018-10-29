//Function for requesting the configuration to the user
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell. All specified in the 'structures.txt' file*/
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "configuration_v2.h"
#include "R_pentomino_insert.h"
#include "Diehard_insert.h"
#include "Acorn_insert.h"
#include "database.h"

void configuration_v2(int msizex, int msizey, tCell *a){
//Opening and reading the .txt file from where the data will be obtained. Also variable declaration.
	FILE* miarchivo=NULL;
	char* nombrearchivo = "structures.txt";
	char lectura[80];   //strings for reading the structure names
	int numero_r;    //Int for reading the number of each structure
	int numero_d;
	int numero_a;
	int numero_w;
	int n_struct=3;
	miarchivo = fopen(nombrearchivo,"r");	//Opening the txt file

//Scanning the data from .txt file.
//The function fscanf reads the data from the txt file string by string. So it is needed to know where the txt file user will write the locations and the structure numbers. The scanf function reads the name of the structure and the number of this structure.
for(int j=0;j<n_struct;j++){

//Reading the name of the strcuture
fscanf(miarchivo,"%s",&lectura);

	if(strcmp(lectura,"Rpentomino")==0){
	fscanf(miarchivo,"%i",&numero_r); //Reading number of this structure
	printf("Number of confg. of R-pentomino: %i\n",numero_r);
//Defining locations array and counter
	int loc_config_x_r[numero_r];
	int loc_config_y_r[numero_r];
	int cont_r;

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.
	for(int i=0;i<numero_r;i++){
		cont_r = i+1;	//The locations are counted in order to notice to the user in case there were any wrong coordinate.
		fscanf(miarchivo,"%i",&loc_config_x_r[i]);
		fscanf(miarchivo,"%i",&loc_config_y_r[i]);
		if(((loc_config_x_r[i]+4)>msizex) || (loc_config_x_r[i]<1) || ((loc_config_y_r[i]+4)>msizey) || (loc_config_y_r[i]<1)){
		printf("Error: In R-pentomino, the %iº coordinates are not allowed\n",cont_r);
		}else{
		R_pentomino_insert(loc_config_x_r[i],loc_config_y_r[i],a);
	}
	}
//Scanning the data from .txt file.
//The function fscanf reads the data from the txt file string by string. So it is needed to know where the txt file user will write the locations and the structure numbers. The scanf function reads the name of the structure and the number of this structure.

//Diehard
	//fscanf(miarchivo,"%s",&lectura_d);
}else if(strcmp(lectura,"Diehard")==0){
	fscanf(miarchivo,"%i",&numero_d); //Reading number of this structure
	printf("Number of confg. of Diehard: %i\n",numero_d);
	//Defining locations array and counter
	int loc_config_x_d[numero_d];
	int loc_config_y_d[numero_d];
	int cont_d;

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.
	for(int i=0;i<numero_d;i++){
		cont_d = i+1; 	//The locations are counted in order to notice to the user in case there were any wrong coordinate.
		fscanf(miarchivo,"%i",&loc_config_x_d[i]);
		fscanf(miarchivo,"%i",&loc_config_y_d[i]);;
		if(((loc_config_x_d[i]+4)>msizex) || (loc_config_x_d[i]<1) || ((loc_config_y_d[i]+4)>msizey) || (loc_config_y_d[i]<1)){
		printf("Error: In Diehard, the %iº coordinates are not allowed\n",cont_d);
		}else{
      		Diehard_insert(loc_config_x_d[i],loc_config_y_d[i],a);
	}
	}

//Scanning the data from .txt file.
//The function fscanf reads the data from the txt file string by string. So it is needed to know where the txt file user will write the locations and the structure numbers. The scanf function reads the name of the structure and the number of this structure.

//Acorn
	//Scanning the data from .txt file.
	//fscanf(miarchivo,"%s",&lectura_a);
}else if(strcmp(lectura,"Acorn")==0){
	fscanf(miarchivo,"%i",&numero_a); //Reading number of this structure
	printf("Number of confg. of Diehard: %i\n",numero_a);
	//Defining locations array and counter
	int loc_config_x_a[numero_a];
	int loc_config_y_a[numero_a];
	int cont_a;

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.
	for(int i=0;i<numero_a;i++){
		cont_a = i+1;	//The locations are counted in order to notice to the user in case there were any wrong coordinate.
		fscanf(miarchivo,"%i",&loc_config_x_a[i]);
		fscanf(miarchivo,"%i",&loc_config_y_a[i]);
		if(((loc_config_x_a[i]+4)>msizex) || (loc_config_x_a[i]<1) || ((loc_config_y_a[i]+4)>msizey) || (loc_config_y_a[i]<1)){
		printf("Error: In Acorn, the %iº coordinates are not allowed\n",cont_a);
		}else{
      		Acorn_insert(loc_config_x_a[i],loc_config_y_a[i],a);
	}
	}

	}else{
		printf("%s: Structure not found or wrong name\n",lectura);
		fscanf(miarchivo,"%i",&numero_w);
	//Defining locations array and counter
		int loc_config_x_w[numero_w];
		int loc_config_y_w[numero_w];
		int cont_w;

		//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the 		function "struct_insert" is called.
		for(int i=0;i<numero_w;i++){
			cont_w = i+1;
			fscanf(miarchivo,"%i",&loc_config_x_w[i]);
			fscanf(miarchivo,"%i",&loc_config_y_w[i]);
		}
		}
	}

	//Once everything have finsihed, the txt file is closed
	fclose(miarchivo);

  return;
	//Freeing the pointers
	free(miarchivo);
	free(nombrearchivo);
}
