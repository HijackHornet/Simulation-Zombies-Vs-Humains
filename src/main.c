#include "defs.h"
//#include "simulation_ncurses.h"

int main(int argc, char* argv[]){
    //testFonctions_Coord();
    //testFonctions_terr();
    //testFonctions_perso();
    //testFonctions_sim();
    lanceSimulation("FichierTestEcriture");
    /*
    srand(time(NULL));
    Simulation * pSim = creerSimulation_sim(1, 0, 0, "FichierTestLectureLOL");
    propagerChampsPersos(pSim);
    afficherGrilleConsole(getTerrain_sim(pSim));
    afficherChamps(getTerrain_sim(pSim));
    */
    //lancerSimulationSDL2(pSim);
}
