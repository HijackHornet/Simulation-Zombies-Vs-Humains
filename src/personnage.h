#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "assert.h"
#include "time.h"

#include <stdlib.h>
#include <stdio.h>

enum typePerso {LIBRE, POLICIER, ZOMBIE, CITOYEN};

typedef struct MPerso {
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

Perso * initPerso(Coordonnees * coord, enum typePerso typePerso);

void testamentPerso(Perso * pPerso);

void testFonctions_perso();


#endif
