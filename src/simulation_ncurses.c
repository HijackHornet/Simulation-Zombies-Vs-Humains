#include "simulation_ncurses.h"

void lanceSimulation(char * nomFic){
    srand(time(NULL));
    
    Simulation * pSim = creerSimulation_sim(10, 10, 0, nomFic);

    
    initscr();
    start_color();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    noecho();
    curs_set(FALSE);

    boucleSimulation(pSim);
    
    endwin();
}

void afficheGrille(Simulation * pSim){
    clear();
    Terrain * pTerrain = getTerrain_sim(pSim);
    mvprintw(0, 0, "Nombre de zombies : %d \t Nombre de citoyens : %d \t Nombre de policiers : %d \t Valeur du champ sur la case (10, 10) : %d", getNbZombies_sim(pSim), getNbCitoyens_sim(pSim), getNbPoliciers_sim(pSim), ((pSim -> pTerrain -> grille)[10][10].champZombies)[0]);
    for(int i = 0; i < getDimY_terr(pTerrain); i++){
	for (int j = 0; j < getDimX_terr(pTerrain); j++) {
	    if(getPersoCase(getGrilleByXY_terr(j, i, pTerrain)) != NULL){
		if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == ZOMBIE){
		    attron(COLOR_PAIR(1));
		    mvprintw(getDimY_terr(pTerrain) - i, j, "Z");
		}
		else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == CITOYEN){
		    attron(COLOR_PAIR(2));
		    mvprintw(getDimY_terr(pTerrain) - i, j, "C");
		}
		else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == POLICIER){
		    attron(COLOR_PAIR(3));
		    mvprintw(getDimY_terr(pTerrain) - i, j, "P");
		}
	    }
	    else{
		if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == VIDE){
		    attron(COLOR_PAIR(4));
		    mvprintw(getDimY_terr(pTerrain) - i, j, " ");
		}
		else{
		    attron(COLOR_PAIR(4));
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
	//afficheGrille(pSim);
	//sleep(1);
	//tirs(pSim);
	//afficheGrille(pSim);
	//sleep(1);
	propagerChampsPersos(pSim);
	//afficherChamps(pSim -> pTerrain);
	sleep(1);
	deplacementIntelZombies_sim(pSim);
	//deplacerCitoyens_sim(pSim);
	//deplacerPoliciers_sim(pSim);
	
    }
}
