/**
   @file caseDeplacement.h
   @brief  Définit une case sur lesquels les personnages vont pouvoir se déplacer
*/

#ifndef CASE_H
#define CASE_H

#include "coordonnees.h"
#include "personnage.h"

enum env {VIDE, MUR};

typedef struct McaseDeplacement{
    enum env envCase;
    struct MPerso * persoCase;
} caseDeplacement;

#endif
