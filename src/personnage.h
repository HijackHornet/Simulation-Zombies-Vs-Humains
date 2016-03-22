#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "assert.h"
#include "time.h"

enum typePerso {POLICIER, ZOMBIE, CITOYEN};

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

Perso * contaminationHumain(Perso * pHumain);

#endif
