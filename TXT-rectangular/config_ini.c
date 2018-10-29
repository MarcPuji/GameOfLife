#include <ncurses.h>
#include <stdio.h>
//Function for requesting the configuration to the user
/*Info needed: # of conf, type of config (R-pentomino, Diehard and Acorn), location of the upper left cell. All specified in the 'structures.txt' file*/
#include <stdlib.h>
#include "cellstruct.h"

void config_ini(myCell ** matrix, int msizex, int msizey){ 
//Opening and reading the .txt file from where the data will be obtained. Also variable declaration. 
	FILE* miarchivo=NULL;
	char* nombrearchivo = "structures.txt";
	char lectura_r[80];   //strings for reading the structure names
	char lectura_d[80];
	char lectura_a[80];	
	int numero_r;    //Int for reading the number of each structure
	int numero_d;
	int numero_a;
	miarchivo = fopen(nombrearchivo,"r");	//Opening the txt file

//Scanning the data from .txt file.
//The function fscanf reads the data from the txt file string by string. So it is needed to know where the txt file user will write the locations and the structure numbers. The scanf function reads the name of the structure and the number of this structure.

//R-pentomino
	fscanf(miarchivo,"%s",&lectura_r);
	fscanf(miarchivo,"%i",&numero_r);
	printf("Number of confg. of R-pentomino: %i\n",numero_r);
	//Defining locations array and counter
	int loc_x_r[numero_r];
	int loc_y_r[numero_r];

	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the cell in 		the respective locations are alive (1). The loop is for number 		of the structures given by the txt file.
	for(int i=0;i<numero_r;i++){
		int cont_r;
		cont_r = i;
		fscanf(miarchivo,"%i",&loc_x_r[i]);
		fscanf(miarchivo,"%i",&loc_y_r[i]);
		if(((loc_x_r[i]+4)>msizex) || (loc_x_r[i]<1) || ((loc_y_r[i]+4)>msizey) || (loc_y_r[i]<1)){
		printf("Error: In R-pentomino, the %iº coordinates are not allowed\n",cont_r+1);
		}else{
		matrix[loc_x_r[i]+2][loc_y_r[i]+1].alive = 1;
		matrix[loc_x_r[i]+3][loc_y_r[i]+1].alive = 1;
		matrix[loc_x_r[i]+1][loc_y_r[i]+2].alive = 1;
		matrix[loc_x_r[i]+2][loc_y_r[i]+2].alive = 1;
		matrix[loc_x_r[i]+2][loc_y_r[i]+3].alive = 1;
		}
		}	
//Scanning the data from .txt file.
//The function fscanf reads the data from the txt file string by string. So it is needed to know where the txt file user will write the locations and the structure numbers. The scanf function reads the name of the structure and the number of this structure.
		
//Diehard
	fscanf(miarchivo,"%s",&lectura_d);
	fscanf(miarchivo,"%i",&numero_d);
	printf("Number of confg. of Diehard: %i\n",numero_d);
	//Defining locations array and counter
	int loc_x_d[numero_d];
	int loc_y_d[numero_d];

	
	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the cell in 		the respective locations are alive (1). The loop is for number 		of the structures given by the txt file.	
	for(int i=0;i<numero_d;i++){
		int cont_d;
		cont_d = i;
		fscanf(miarchivo,"%i",&loc_x_d[i]);
		fscanf(miarchivo,"%i",&loc_y_d[i]);
		if(((loc_x_d[i]+4)>msizex) || (loc_x_d[i]<1) || ((loc_y_d[i]+4)>msizey) || (loc_y_d[i]<1)){
		printf("Error: In Diehard, the %iº coordinates are not allowed\n",cont_d+1);
		}else{
		matrix[loc_x_d[i]+2][loc_y_d[i]+1].alive = 1;
		matrix[loc_x_d[i]+4][loc_y_d[i]+2].alive = 1;
		matrix[loc_x_d[i]+1][loc_y_d[i]+3].alive = 1;
		matrix[loc_x_d[i]+2][loc_y_d[i]+3].alive = 1;
		matrix[loc_x_d[i]+5][loc_y_d[i]+3].alive = 1;
		matrix[loc_x_d[i]+6][loc_y_d[i]+3].alive = 1;
		matrix[loc_x_d[i]+7][loc_y_d[i]+3].alive = 1;
		}
		}
//Scanning the data from .txt file.
//The function fscanf reads the data from the txt file string by string. So it is needed to know where the txt file user will write the locations and the structure numbers. The scanf function reads the name of the structure and the number of this structure.

//Acorn
	fscanf(miarchivo,"%s",&lectura_a);
	fscanf(miarchivo,"%i",&numero_a);
	printf("Number of confg. of Acorn: %i\n",numero_a);
	//Defining locations array and counter
	int loc_x_a[numero_a];
	int loc_y_a[numero_a];


	//First it is obtanined the data from the txt file (locations 		and number of configurations). Then, it is checked if the 	locations are bounded (inside the window), and then, the cell in 		the respective locations are alive (1). The loop is for number 		of the structures given by the txt file.
	for(int i=0;i<numero_a;i++){
		int cont_a;
		cont_a = i;
		fscanf(miarchivo,"%i",&loc_x_a[i]);
		fscanf(miarchivo,"%i",&loc_y_a[i]);
		if(((loc_x_a[i]+4)>msizex) || (loc_x_a[i]<1) || ((loc_y_a[i]+4)>msizey) || (loc_y_a[i]<1)){
		printf("Error: In Acorn, the %iº coordinates are not allowed\n",cont_a+1);
		}else{
		matrix[loc_x_a[i]+2][loc_y_a[i]+1].alive = 1;
		matrix[loc_x_a[i]+4][loc_y_a[i]+2].alive = 1;
		matrix[loc_x_a[i]+1][loc_y_a[i]+3].alive = 1;
		matrix[loc_x_a[i]+2][loc_y_a[i]+3].alive = 1;
		matrix[loc_x_a[i]+5][loc_y_a[i]+3].alive = 1;
		matrix[loc_x_a[i]+6][loc_y_a[i]+3].alive = 1;
		matrix[loc_x_a[i]+7][loc_y_a[i]+3].alive = 1;
		}
		}
	//Closing the txt file
	fclose(miarchivo);
  return;	
	//Freeing the pointers
	free(miarchivo);
	free(nombrearchivo);
}
