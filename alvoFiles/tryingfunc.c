#include <stdio.h>
#include <stdlib.h>

#include "database.h"
#include "tryingfunc.h"

toPlotCells* toArray(tCell *a, toPlotCells *plot){
    if(a->x != -1){
        printf("Coordinates (x, y) = (%d, %d), alive = %d, neighbours = %d\n",
            a->x,a->y,a->alive,a->neighbours);
        
        int cellslength = sizeof(plot)/sizeof(plot[0]);
        if(cellslength == 1){
        	plot[0].x = a->x;
        	plot[0].y = a->y;
        }
        else{
        	toPlotCells * newplot = (toPlotCells *) malloc((cellslength + 1)*sizeof(toPlotCells *));
        	for (int i = 0; i < cellslength - 1; i++){
        		newplot[i].x = plot[i].x;
        		newplot[i].y = plot[i].y;
        	}
        	newplot[cellslength].x = a->x;
        	newplot[cellslength].y = a->y;

        	free(plot);
        	plot = newplot;
        }
    }// This allows us to advance through to the cells within and accross columns.
    if(a->childy != NULL){
        toPlotCells(a->childy, plot); // advance through the column
    }
    if(a->childx != NULL){
        toPlotCells(a->childx, plot); // advance across columns (only possible in the top row 
                             // for the sake of simplicity.)
    }
    return(plot);
}