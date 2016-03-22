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
} caseDeplacement;

enum env getEnvCase(caseDeplacement * caseDep);

Perso * getPersoCase(caseDeplacement * caseDep);

void setEnvCase(caseDeplacement * caseDep, enum env valeurEnv);

void setPersoCase(caseDeplacement * caseDep, Perso * pPerso);

#endif
