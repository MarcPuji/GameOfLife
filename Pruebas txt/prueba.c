#include <stdio.h>
#include <stdlib.h>


int main(){

	printf("\n Bienvenidos al Lector\n");

	FILE* miarchivo=NULL;
	char* nombrearchivo = "structures.txt";
	char lectura[80];
	int numero_r;
	miarchivo = fopen(nombrearchivo,"r");
	if(miarchivo==NULL)return -1;

	fscanf(miarchivo,"%s",&lectura);
	//printf("Lectura: %s\n",lectura);
	fscanf(miarchivo,"%i",&numero_r);
	printf("Number of confg. of R-pentomino: %i\n",numero_r);
	int col_r[numero_r];
	int fil_r[numero_r];
	for(int i=0;i<numero_r;i++){
		fscanf(miarchivo,"%i",&col_r[i]);
		fscanf(miarchivo,"%i",&fil_r[i]);
		printf("col %i fil %i\n", col_r[i],fil_r[i]);
	}
	//for(int i=0 ; i<2*numero_r;i++){
	//	fscanf(miarchivo,"%i",&col_r[i]);
	//	fscanf(miarchivo,"%i",&fil_r[i]);
 	//}
	//for(int i=1 ; i<numero_r;i++){
	//	printf("fila %i col %i\n",fil_r[i],col_r[i]);
	//}
return 0;
}
