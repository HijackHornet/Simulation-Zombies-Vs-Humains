#include "simulation_ncurses.h"

void lanceSimulation(char * nomFic){
    srand(time(NULL));
    
    Simulation * pSim = creerSimulation_sim(20, 15, 30, nomFic);

    initscr();
    noecho();
    curs_set(FALSE);

    boucleSimulation(pSim);
    
    endwin();
}

void afficheGrille(Simulation * pSim){
    clear();
    Terrain * pTerrain = getTerrain_sim(pSim);
    mvprintw(0, 0, "Nombre de zombies : %d \t Nombre de citoyens : %d \t Nombre de policiers : %d \t", getNbZombies_sim(pSim), getNbCitoyens_sim(pSim), getNbPoliciers_sim(pSim));
    for(int i = 0; i < getDimY_terr(pTerrain); i++){
	for (int j = 0; j < getDimX_terr(pTerrain); j++) {
	    if(getPersoCase(getGrilleByXY_terr(j, i, pTerrain)) != NULL){
		if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == ZOMBIE){
		    mvprintw(getDimY_terr(pTerrain) - i, j, "Z");
		}
		else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == CITOYEN){
		    mvprintw(getDimY_terr(pTerrain) - i, j, "C");
		}
		else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == POLICIER){
		    mvprintw(getDimY_terr(pTerrain) - i, j, "P");
		}
	    }
	    else{
		if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == VIDE){
		    mvprintw(getDimY_terr(pTerrain) - i, j, " ");
		}
		else{
		    mvprintw(getDimY_terr(pTerrain) - i, j, "#");
		}
	    }
	}
    }
    refresh();
}

void boucleSimulation(Simulation * pSim){
    while(1){
	afficheGrille(pSim);
	sleep(1);	
	contaminations(pSim);
	afficheGrille(pSim);
	sleep(1);
	tirs(pSim);
	afficheGrille(pSim);
	sleep(1);
	deplacerPerso_sim(pSim);
    }
}
