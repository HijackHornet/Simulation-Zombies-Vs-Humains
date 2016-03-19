#include "coordonnees.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    
    return 0;
}



void setXYCoord_Coord (int x, int y, Coordonnees * pCoord){

	pCoord->xCoord=x;
	pCoord->yCoord=y;
}

int getXCoord_Coord(Coordonnees * pCoord){
	return pCoord->xCoord;
}

int getYCoord_Coord(Coordonnees * pCoord){
	return pCoord->yCoord;
}

float distanceEntreDeuxCoordonnees_Coord (Coordonnees * coord1, Coordonnees * coord2){
	return (float) (sqrt(pow((double)((coord1->xCoord)-(coord2->xCoord)),2)+pow((double)((coord1->yCoord)-(coord2->yCoord)),2)));
}

int sontEgale_Coord (Coordonnees * coord1, Coordonnees * coord2){
	int x1, x2, y1, y2;

	x1 = getXCoord_Coord(coord1);
	x2 = getXCoord_Coord(coord2);
	y1 = getYCoord_Coord(coord1);
	y2 = getYCoord_Coord(coord2);


	if((x1==x2)&&(y1==y2)){
		return 1;
	}
	else {
		return 0;
	}
}
