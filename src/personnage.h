#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "assert.h"
#include "time.h"

#include <stdlib.h>
#include <stdio.h>

enum typePerso {POLICIER, ZOMBIE, CITOYEN};

typedef struct MPerso {
    int id;
    Coordonnees * coord;
    enum typePerso type;
} Perso;

Coordonnees * getCoordonneesPerso_perso(Perso * pPerso);

int getXPerso_perso(Perso * pPerso);

int getYPerso_perso(Perso * pPerso);

void setXPerso_perso(Perso * pPerso, int xPerso);

void setYPerso_perso(Perso * pPerso, int yPerso);

enum typePerso getTypePerso(Perso * pPerso);

void setTypePerso_perso(enum typePerso type, Perso * pPerso);

void setCoordPerso_perso(Coordonnees * coord, Perso * pPerso);

Perso * initPerso(Coordonnees * coord, enum typePerso typePerso, int idPerso);

void testamentPerso(Perso * pPerso);

void testFonctions_perso();

int getIdPerso(Perso * pPerso);

void setIdPerso(int idPerso, Perso * pPerso);

#endif
