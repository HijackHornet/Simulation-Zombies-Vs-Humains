#include "caseDeplacement.h"

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

enum env getEnvCase(caseDeplacement * pCaseDep){
    return pCaseDep -> envCase;
}

Perso * getPersoCase(caseDeplacement * pCaseDep){
    return pCaseDep -> persoCase;
}

void setEnvCase(caseDeplacement * pCaseDep, env valeurEnv){
    pCaseDep -> envCase = valeurEnv;
}

void setPersoCase(caseDeplacement * pCaseDep, Perso * pPerso){
    pCaseDep -> persoCase = pPerso;
}

unsigned short getChamp(enum typePerso type, int idPerso, caseDeplacement * pCaseDep){
    if(type == ZOMBIE){
	return (pCaseDep -> champZombies)[idPerso];
    }

    else if(type == CITOYEN){
	return (pCaseDep -> champCitoyens)[idPerso];
    }

    else{
	return (pCaseDep -> champPoliciers)[idPerso];
    }
}

void setChamp(unsigned short intensite, enum typePerso type, int idPerso, caseDeplacement * caseDep){
    if(type == ZOMBIE){
        (caseDep -> champZombies)[idPerso] = intensite;
    }

    else if(type == CITOYEN){
	(caseDep -> champCitoyens)[idPerso] = intensite;
    }

    else{
	(caseDep -> champPoliciers)[idPerso] = intensite;
    }
}

caseDeplacement * initCase(enum env envCase, Perso * pPerso){ //initialise l'environnement et le personnage d'une case
    caseDeplacement * caseDep = (caseDeplacement *)malloc(sizeof(caseDeplacement));

    setEnvCase(caseDep, envCase);
    setPersoCase(caseDep, pPerso);

    return caseDep;
}
/*
void initChamps(int nbZombies, int nbPoliciers, int nbCitoyens, caseDeplacement * caseDep){
  caseDep -> champZombies = (short *)malloc(sizeof(short)*(nbZombies + nbPoliciers + nbCitoyens));
  caseDep -> champCitoyens = (short *)malloc(sizeof(short)*nbCitoyens);
  caseDep -> champPoliciers = (short *)malloc(sizeof(short)*nbPoliciers);
}
*/

void testamentCase(caseDeplacement * caseDep){
    free(caseDep);

    caseDep = NULL;
}
