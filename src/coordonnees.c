#include "coordonnees.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void setXCoord_Coord(int x, Coordonnees * pCoord){
    pCoord -> xCoord = x;
}

void setYCoord_Coord(int y, Coordonnees * pCoord){
    pCoord -> yCoord = y;
}

void setXYCoord_Coord (int x, int y, Coordonnees * pCoord){
	assert(x>=0);
	assert(y>=0);

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

Coordonnees * initCoordonnees_coord(int x, int y){
    Coordonnees * pCoord = (Coordonnees *)malloc(sizeof(Coordonnees));

    pCoord -> xCoord = x;
    pCoord -> yCoord = y;

    return pCoord;
}

void testamentCoord(Coordonnees * coord){
    free(coord);

    coord = NULL;
}

void testFonctions_Coord(){
	int dimx, dimy, dimx2, dimy2;
	int egaleOuPas;
	float distance12;
	Coordonnees coord, coord2;

	dimx = 100; dimx2 = 104;
	dimy = 100; dimy2 = 24;
	setXYCoord_Coord(dimx,dimy, &coord);
	setXYCoord_Coord(dimx2,dimy2, &coord2);
	assert(getXCoord_Coord(&coord) == dimx);
	assert(getYCoord_Coord(&coord) == dimy);
	distance12 = distanceEntreDeuxCoordonnees_Coord(&coord, &coord2);
	assert(distance12>=0);
	egaleOuPas = sontEgale_Coord(&coord,&coord2);
	assert(egaleOuPas==0);
	printf("Execution du module coordonnees et de ses fonctions sans erreurs... \n");
}



