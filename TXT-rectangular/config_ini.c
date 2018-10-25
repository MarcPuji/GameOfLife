#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "cellstruct.h"

void config_ini(myCell ** matrix, int msizex, int msizey){ // Load the initial configuration to the created matrix
	////// TODO: INSERTING PIECES FUNCTIONS /////

	// Beehive figure
	//matrix[msizex/2][msizey/2].alive = 1;
	//matrix[msizex/2 + 1][msizey/2].alive = 1;
	//matrix[msizex/2 - 1][msizey/2 + 1].alive = 1;
	//matrix[msizex/2 + 2][msizey/2 + 1].alive = 1;
	//matrix[msizex/2][msizey/2 + 2].alive = 1;
	//matrix[msizex/2 + 1][msizey/2 + 2].alive = 1;
	// Beehive figure

	// R-pentomino
	// matrix[msizex/2][msizey/2].alive = 1;
	// matrix[msizex/2][msizey/2 - 1].alive = 1;
	// matrix[msizex/2 + 1][msizey/2 - 1].alive = 1;
	//matrix[msizex/2][msizey/2 + 1].alive = 1;
	//matrix[msizex/2 - 1][msizey/2].alive = 1;
	// R-pentomino

	// Glider
	/*matrix[msizex/2][msizey/2 - 1].alive = 1;
	matrix[msizex/2 + 1][msizey/2].alive = 1;
	matrix[msizex/2][msizey/2 + 1].alive = 1;
	matrix[msizex/2 + 1][msizey/2 + 1].alive = 1;
	matrix[msizex/2 - 1][msizey/2 + 1].alive = 1;
//}{*/
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
	int loc_x_r[numero_r];
	int loc_y_r[numero_r];

	
	for(int i=0;i<numero_r;i++){
		int cont_r;
		cont_r = i;
		fscanf(miarchivo,"%i",&loc_x_r[i]);
		fscanf(miarchivo,"%i",&loc_y_r[i]);
		if(((loc_x_r[i]+4)>msizex) || (loc_x_r[i]<1) || ((loc_y_r[i]+4)>msizey) || (loc_y_r[i]<1)){
		printf("Error: In R-pentomino, the %iº coordinates are not allowed\n",cont_r+1);
		}else{
		//printf("numero %i\n",loc_x_r[i]);
		matrix[loc_x_r[i]+2][loc_y_r[i]+1].alive = 1;
		matrix[loc_x_r[i]+3][loc_y_r[i]+1].alive = 1;
		matrix[loc_x_r[i]+1][loc_y_r[i]+2].alive = 1;
		matrix[loc_x_r[i]+2][loc_y_r[i]+2].alive = 1;
		matrix[loc_x_r[i]+2][loc_y_r[i]+3].alive = 1;
		}
		}			
//Diehard
	fscanf(miarchivo,"%s",&lectura_d);
	fscanf(miarchivo,"%i",&numero_d);
	printf("Number of confg. of Diehard: %i\n",numero_d);
	//printf("%s: %i\n",lectura_d,numero_d);
	int loc_x_d[numero_d];
	int loc_y_d[numero_d];

	
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
//Acorn
	fscanf(miarchivo,"%s",&lectura_a);
	fscanf(miarchivo,"%i",&numero_a);
	//printf("%s,%i\n",lectura_a,numero_a);
	printf("Number of confg. of Acorn: %i\n",numero_a);
	int loc_x_a[numero_a];
	int loc_y_a[numero_a];

	
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
	fclose(miarchivo);
  return;
}
