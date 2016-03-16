#include "coordonnees.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void setXYcord_Cord (int x, int y, coordonnees * laCord){

	laCord->Xcord=x;
	laCord->Ycord=y;
}

int getXcord_Cord(coordonnees * laCord){
	return laCord->Xcord;
}

int getYcord_Cord(coordonnees * laCord){
	return laCord->Ycord;
}

float distanceEntreDeuxCoordonnees_Cord (coordonnees * cord1, coordonnees * cord2){
	return (float) (sqrt(pow((double)((cord1->Xcord)-(cord2->Xcord)),2)+pow((double)((cord1->Ycord)-(cord2->Ycord)),2)));
}

int sontEgale_Cord (coordonnees * cord1, coordonnees * cord2){
	int x1, x2, y1, y2;

	x1 = getXcord_Cord(cord1);
	x2 = getXcord_Cord(cord2);
	y1 = getYcord_Cord(cord1);
	y2 = getYcord_Cord(cord2);


	if((x1==x2)&&(y1==y2)){
		return 1;
	}
	else {
		return 0;
	}
}