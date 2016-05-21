/**
   @file caseDeplacement.h
   @brief  Définit une case sur lesquels les personnages vont pouvoir se déplacer
*/

#ifndef _CASE_H
#define _CASE_H


#include "coordonnees.h"
#include "personnage.h"


enum env {VIDE, MUR};

typedef struct McaseDeplacement{
    enum env envCase;
    struct MPerso * persoCase;
    short champZombies[250];
    short champCitoyens[250];
    short champPoliciers[250];
} caseDeplacement;

enum env getEnvCase(caseDeplacement * caseDep);

Perso * getPersoCase(caseDeplacement * caseDep);

void setEnvCase(caseDeplacement * caseDep, enum env valeurEnv);

void setPersoCase(caseDeplacement * caseDep, Perso * pPerso);

caseDeplacement * initCase(enum env envCase, Perso * pPerso);

void testamentCase(caseDeplacement * caseDep);

unsigned short getChamp(enum typePerso type, int idPerso, caseDeplacement * caseDep);

void setChamp(unsigned short intensite, enum typePerso type, int idPerso, caseDeplacement * caseDep);

void initChamps(int nbZombies, int nbCitoyens, int nbPoliciers, caseDeplacement * caseDep);

#endif
