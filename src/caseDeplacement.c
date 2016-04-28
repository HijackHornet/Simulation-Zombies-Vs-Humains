#include "caseDeplacement.h"

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

enum env getEnvCase(caseDeplacement * caseDep){
    return caseDep -> envCase;
}

Perso * getPersoCase(caseDeplacement * caseDep){
    return caseDep -> persoCase;
}

void setEnvCase(caseDeplacement * caseDep, enum env valeurEnv){
    caseDep -> envCase = valeurEnv;
}

void setPersoCase(caseDeplacement * caseDep, Perso * pPerso){
    caseDep -> persoCase = pPerso;
}

caseDeplacement * initCase(enum env envCase, Perso * pPerso){
    caseDeplacement * caseDep = (caseDeplacement *)malloc(sizeof(caseDeplacement));

    setEnvCase(caseDep, envCase);
    setPersoCase(caseDep, pPerso);

    return caseDep;
}

void testamentCase(caseDeplacement * caseDep){
    free(caseDep);
    
    caseDep = NULL;
}

void setMarqueur(char valeur, caseDeplacement * caseDep){
    caseDep -> marqueur = valeur;
}

unsigned short getChamp(enum typePerso type, int idPerso, caseDeplacement * caseDep){
    if(type == ZOMBIE){
	return (caseDep -> champZombies)[idPerso];
    }

    else if(type == CITOYEN){
	return (caseDep -> champCitoyens)[idPerso];
    }

    else{
	return (caseDep -> champPoliciers)[idPerso];
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
