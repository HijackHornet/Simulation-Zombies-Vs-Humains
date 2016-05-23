#include "coordonnees.h"

///////////////////////////////////////////////////////////////////////
//ACCESSEURS///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

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

Coordonnees getCoordCaseDroiteByXY_terr(int x, int y){
    return (Coordonnees){x + 1, y};
}

Coordonnees getCoordCaseGaucheByXY_terr(int x, int y){
    return (Coordonnees){x - 1, y};
}

Coordonnees getCoordCaseHautByXY_terr(int x, int y){
    return (Coordonnees){x, y + 1};
}

Coordonnees getCoordCaseBasByXY_terr(int x, int y){
    return (Coordonnees){x, y - 1};
}

Coordonnees getCoordCase2DroiteByXY_terr(int x, int y){
    return (Coordonnees){x + 2, y};
}

Coordonnees getCoordCase2GaucheByXY_terr(int x, int y){
    return (Coordonnees){x - 2, y};
}

Coordonnees getCoordCase2HautByXY_terr(int x, int y){
    return (Coordonnees){x, y + 2};
}

Coordonnees getCoordCase2BasByXY_terr(int x, int y){
    return (Coordonnees){x, y - 2};
}

Coordonnees getCoordCaseHDByXY_terr(int x, int y){
  return (Coordonnees){x + 1, y + 1};
}

Coordonnees getCoordCaseBDByXY_terr(int x, int y){
  return (Coordonnees){x + 1, y - 1};
}

Coordonnees getCoordCaseBGByXY_terr(int x, int y){
  return (Coordonnees){x - 1, y - 1};
}

Coordonnees getCoordCaseHGByXY_terr(int x, int y){
  return (Coordonnees){x - 1, y + 1};
}

Coordonnees getCoordCaseBasByCoord_terr(Coordonnees * pCoord){
    return getCoordCaseBasByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCaseHautByCoord_terr(Coordonnees * pCoord){
    return getCoordCaseHautByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCaseDroiteByCoord_terr(Coordonnees * pCoord){
    return getCoordCaseDroiteByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCaseGaucheByCoord_terr(Coordonnees * pCoord){
    return getCoordCaseGaucheByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCase2BasByCoord_terr(Coordonnees * pCoord){
    return getCoordCase2BasByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCase2HautByCoord_terr(Coordonnees * pCoord){
    return getCoordCase2HautByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCase2DroiteByCoord_terr(Coordonnees * pCoord){
    return getCoordCase2DroiteByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCase2GaucheByCoord_terr(Coordonnees * pCoord){
    return getCoordCase2GaucheByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}


Coordonnees getCoordCaseHDByCoord_terr(Coordonnees * pCoord){
  return getCoordCaseHDByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCaseBDByCoord_terr(Coordonnees * pCoord){
  return getCoordCaseBDByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCaseBGByCoord_terr(Coordonnees * pCoord){
  return getCoordCaseBGByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}

Coordonnees getCoordCaseHGByCoord_terr(Coordonnees * pCoord){
  return getCoordCaseHGByXY_terr(getXCoord_Coord(pCoord), getYCoord_Coord(pCoord));
}



/////////////////////////////////////////////////////////////////////////
//INITIALISATIONS-TESTAMENTS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

Coordonnees * initCoordonnees_coord(int x, int y){
    Coordonnees * pCoord = (Coordonnees *)malloc(sizeof(Coordonnees));

    pCoord -> xCoord = x;
    pCoord -> yCoord = y;

    return pCoord;
}

void testamentCoord(Coordonnees * pCoord){
    free(pCoord);

    pCoord = NULL;
}

/////////////////////////////////////////////////////////////////////////
//CALCULS////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

float distanceEntreDeuxCoordonnees_Coord (Coordonnees * pCoord1, Coordonnees * pCoord2){
	return (float) (sqrt(pow((double)((pCoord1->xCoord)-(pCoord2->xCoord)),2)+pow((double)((pCoord1->yCoord)-(pCoord2->yCoord)),2)));
}

int sontEgale_Coord (Coordonnees * pCoord1, Coordonnees * pCoord2){
	int x1, x2, y1, y2;

	x1 = getXCoord_Coord(pCoord1);
	x2 = getXCoord_Coord(pCoord2);
	y1 = getYCoord_Coord(pCoord1);
	y2 = getYCoord_Coord(pCoord2);


	if((x1==x2)&&(y1==y2)){
		return 1;
	}
	else {
		return 0;
	}
}


///////////////////////////////////////////////////////////////////////////
//NON REGRESSION///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

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



