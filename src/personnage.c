#include "personnage.h"

//////////////////////////////////////////////////////////////////////////////
//ACCESSEURS//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

Coordonnees * getCoordonneesPerso_perso(Perso * pPerso){
    return pPerso -> coord;
}

int getXPerso_perso(Perso * pPerso){
    return getXCoord_Coord(getCoordonneesPerso_perso(pPerso));
}

int getYPerso_perso(Perso * pPerso){
    return getYCoord_Coord(getCoordonneesPerso_perso(pPerso));
}

void setXPerso_perso(Perso * pPerso, int xPerso){
    setXCoord_Coord(xPerso, getCoordonneesPerso_perso(pPerso));
}

void setYPerso_perso(Perso * pPerso, int yPerso){
    setYCoord_Coord(yPerso, getCoordonneesPerso_perso (pPerso));
}

enum typePerso getTypePerso(Perso * pPerso){
    return pPerso -> type;
}


//////////////////////////////////////////////////////////////////////////////
//PARTIE ZOMBIE///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

/*ERREURS A CORRIGER : NE VERIFIE PAS LES BORDURES DE LA GRILLE
UTILISER VERIF DU DESSUS
*/

Perso * contaminationHumain(Perso * pHumain){ //retourne l'humain en mode zombie
    pHumain -> type = ZOMBIE;

    return pHumain;
}
