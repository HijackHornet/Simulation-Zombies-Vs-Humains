/**
   @file caseDeplacement.h
   @brief  Définit une case sur lesquels les personnages vont pouvoir se déplacer
*/

#ifndef CASE_H
#define CASE_H

#include "coordonnees.h"

enum env {VIDE, MUR} ;
enum perso {LIBRE, POLICIER, ZOMBIE, CITOYEN};

typedef struct McaseDeplacement{
    enum env envCase;
    enum perso persoCase;
} caseDeplacement;

#endif
