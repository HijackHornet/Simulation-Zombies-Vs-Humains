#include "simulation.h"

////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

Terrain * getTerrain_sim(Simulation * pSim){
  return pSim -> pTerrain;
}

void setTerrain_sim(Terrain * pTerrain, Simulation * pSim){
  pSim -> pTerrain = pTerrain;
}

int getNbZombies_sim(Simulation * pSim){
  return pSim -> zombies -> len;
}

int getNbCitoyens_sim(Simulation * pSim){
  return pSim -> citoyens -> len;
}

int getNbPoliciers_sim(Simulation * pSim){
  return pSim -> policiers -> len;
}

GArray * getZombies_sim(Simulation * pSim){
  return pSim -> zombies;
}

GArray * getCitoyens_sim(Simulation * pSim){
  return pSim -> citoyens;
}

GArray * getPoliciers_sim(Simulation * pSim){
  return pSim -> policiers;
}

////////////////////////////////////////////////////////////////////
//CREATION-INITALISATION////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void zombiesInit_sim(int nbZombies, Simulation * pSim){
  GArray * tabZombies = g_array_new(FALSE, FALSE, sizeof(Perso));
  pSim -> zombies = tabZombies;
  for (int i = 0; i < nbZombies; i++){
    Perso * pZombie = creePersoTerrainRand(getTerrain_sim(pSim), ZOMBIE, i);
    g_array_append_val(tabZombies, *pZombie);
  }
}


void citoyensInit_sim(int nbCitoyens, Simulation * pSim){
  GArray * tabCitoyens = g_array_new(FALSE, FALSE, sizeof(Perso));
  pSim -> citoyens = tabCitoyens;
  for (int i = 0; i < nbCitoyens; i++){
    Perso * pCitoyen = creePersoTerrainRand(getTerrain_sim(pSim), CITOYEN, i);
    g_array_append_val(tabCitoyens, *pCitoyen);
  }
}

void policiersInit_sim(int nbPoliciers, Simulation * pSim){
  GArray * tabPoliciers = g_array_new(FALSE, FALSE, sizeof(Perso));
  pSim -> policiers = tabPoliciers;
  for (int i = 0; i < nbPoliciers; i++){
    Perso * pPolicier = creePersoTerrainRand(getTerrain_sim(pSim), POLICIER, i);
    g_array_append_val(tabPoliciers, *pPolicier);
  }
}

void terrainInit_sim(char * nomFic, Simulation * pSim){
  pSim -> pTerrain = (Terrain *)malloc(sizeof(Terrain));
    
  pSim -> pTerrain = terrainLireFichier_terr(nomFic);
}

void initSimulation_sim(Simulation * pSim, int nbZombies, int nbPoliciers, int nbCitoyens, char * nomFic){
  terrainInit_sim(nomFic, pSim);
    
  zombiesInit_sim(nbZombies, pSim);

  citoyensInit_sim(nbCitoyens, pSim);

  policiersInit_sim(nbPoliciers, pSim);

  //initChampsTerrain(nbZombies, nbPoliciers, nbCitoyens, getTerrain_sim(pSim));
}

Simulation * creerSimulation_sim(int nbZombies, int nbPoliciers, int nbCitoyens, char * nomFic){
  Simulation * pSim = (Simulation *)malloc(sizeof(Simulation));

  initSimulation_sim(pSim, nbZombies, nbPoliciers, nbCitoyens, nomFic);
    
  return pSim;
}

void testamentSim(Simulation * pSim){
  testamentTerrain_terr(getTerrain_sim(pSim));

  GArray * tabZombies = getZombies_sim(pSim);
  GArray * tabCitoyens = getCitoyens_sim(pSim);
  GArray * tabPoliciers = getPoliciers_sim(pSim);
	
  g_array_free(tabZombies, FALSE);
  g_array_free(tabCitoyens, FALSE);
  g_array_free(tabPoliciers, FALSE);

  free(pSim);
}

void ajouterPerso(Coordonnees * pCoord, enum typePerso type, Simulation * pSim){
  GArray * tabPersos;
  int nbPersos;

  Perso nouveauPerso;
  Perso * pNouveauPersoTab;

  caseDeplacement * caseNouveauPerso;

  Terrain * pTerrain;

  if(type == ZOMBIE){
    tabPersos = getZombies_sim(pSim);
    nbPersos = getNbZombies_sim(pSim);
  }
  
  else if(type == CITOYEN){
    tabPersos = getCitoyens_sim(pSim);
    nbPersos = getNbCitoyens_sim(pSim);
  }

  else{
    tabPersos = getPoliciers_sim(pSim);
    nbPersos = getNbPoliciers_sim(pSim);
  }

  setCoordPerso_perso(pCoord, &nouveauPerso);
  setIdPerso(nbPersos, &nouveauPerso);
  setTypePerso_perso(type, &nouveauPerso);
  
  g_array_append_val(tabPersos, nouveauPerso);

  pNouveauPersoTab = &g_array_index(tabPersos, Perso, nbPersos);
  pTerrain = getTerrain_sim(pSim);
  caseNouveauPerso = getGrilleByCoord_terr(pCoord, pTerrain);
  setPersoCase(caseNouveauPerso, pNouveauPersoTab);
}


void supprimerPerso(Perso * pPerso, Simulation * pSim){
  caseDeplacement * pCasePerso;
  Coordonnees * pCoordPerso;
  enum typePerso typePerso;
  int idPerso;

  GArray * tabPerso; //ce tableau peut être le tableau citoyens ou policiers
  int iTabPerso;
  int nbPersoTab;
  Perso * pPersoTemp; //perso temporaire lors du parcours du tableau
  Coordonnees * pCoordPersoTemp;
  caseDeplacement * casePersoTemp;

  Terrain * pTerrain;

  pCoordPerso = getCoordPerso(pPerso);
  pTerrain = getTerrain_sim(pSim);
  pCasePerso = getGrilleByCoord_terr(pCoordPerso, pTerrain);
  
  setPersoCase(pCasePerso, NULL);

  idPerso = getIdPerso(pPerso);
  typePerso = getTypePerso(pPerso);

  if(typePerso == ZOMBIE){ //sélection du tableau correspondant (citoyen, zombie...)
    tabPerso = getZombies_sim(pSim);
    nbPersoTab = getNbZombies_sim(pSim);
  }
  
  else if(typePerso == CITOYEN){
    tabPerso = getCitoyens_sim(pSim);
    nbPersoTab = getNbCitoyens_sim(pSim);
  }

  else{
    tabPerso = getPoliciers_sim(pSim);
    nbPersoTab = getNbPoliciers_sim(pSim);
  }

  g_array_remove_index(tabPerso, idPerso);
  
  for(iTabPerso = 0; iTabPerso < nbPersoTab - 1; iTabPerso++){ //on réindexe les personnages
    pPersoTemp = &g_array_index(tabPerso, Perso, iTabPerso);
    
    pCoordPersoTemp = getCoordPerso(pPersoTemp); // on réassocie la nouvelle adresse du perso à sa case actuelle
    casePersoTemp = getGrilleByCoord_terr(pCoordPersoTemp, pTerrain);
    setPersoCase(casePersoTemp, pPersoTemp);
    
    setIdPerso(iTabPerso, pPersoTemp);	  
  }
}


////////////////////////////////////////////////////////////////////////////
//EXECUTION/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void deplacerZombies_sim(Simulation * pSim){
  int nbZombies = getNbZombies_sim(pSim);
  GArray * tabZombies = getZombies_sim(pSim);
  for(int i = 0; i < nbZombies; i++){
    Perso * pZombie = &g_array_index(tabZombies, Perso, i);
    deplacementAleatoire_perso(pZombie, getTerrain_sim(pSim));
  }
}

void deplacerCitoyens_sim(Simulation * pSim){
  int nbCitoyens = getNbCitoyens_sim(pSim);
  GArray * tabCitoyens = getCitoyens_sim(pSim);
  for(int i = 0; i < nbCitoyens; i++){
    Perso * pCitoyen = &g_array_index(tabCitoyens, Perso, i);
    deplacementAleatoire_perso(pCitoyen, getTerrain_sim(pSim));
  }
}

void deplacerPoliciers_sim(Simulation * pSim){
  int nbPoliciers = getNbPoliciers_sim(pSim);
  GArray * tabPoliciers = getPoliciers_sim(pSim);
  for(int i = 0; i < nbPoliciers; i++){
    Perso * pPolicier = &g_array_index(tabPoliciers, Perso, i);
    deplacementAleatoire_perso(pPolicier, getTerrain_sim(pSim));
  }
}

void deplacementIntelZombies_sim(Simulation * pSim){
  int nbZombies = getNbZombies_sim(pSim);
  GArray * tabZombies = getZombies_sim(pSim);
  for(int i = 0; i < nbZombies; i++){
    Perso * pZombie = &g_array_index(tabZombies, Perso, i);
    deplacementIntelZombie(pZombie, pSim);
  }
}

void deplacementIntelCitoyens_sim(Simulation * pSim){
  int nbCitoyens = getNbCitoyens_sim(pSim);
  GArray * tabCitoyens = getCitoyens_sim(pSim);
  for(int i = 0; i < nbCitoyens; i++){
    Perso * pCitoyen = &g_array_index(tabCitoyens, Perso, i);
    deplacementIntelCitoyen(pCitoyen, pSim);
  }
}

void deplacementIntelPoliciers_sim(Simulation * pSim){
  int nbPoliciers = getNbPoliciers_sim(pSim);
  GArray * tabPoliciers = getPoliciers_sim(pSim);
  for(int i = 0; i < nbPoliciers; i++){
    Perso * pPolicier = &g_array_index(tabPoliciers, Perso, i);
    deplacementIntelPolicier(pPolicier, pSim);
  }
}

void deplacerPerso_sim(Simulation * pSim){
  deplacerZombies_sim(pSim);
  deplacerPoliciers_sim(pSim);
  deplacerCitoyens_sim(pSim);
}


////////////////////////////////////////////////////////////////////////////
//INTERACTIONS//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void contaminations(Simulation * pSim){
  int nbZombies = getNbZombies_sim(pSim);

  GArray * tabZombies = getZombies_sim(pSim);
  Perso * pZombieTab;
  
  Perso * pPersoAContaminer;
  Coordonnees * pCoordPersoAContaminer;

  for(int i = 0; i < nbZombies; i++){
    pZombieTab = &g_array_index(tabZombies, Perso, i);
    assert(pZombieTab -> id == i);
    pPersoAContaminer = zombieContamineHumain(pZombieTab, getTerrain_sim(pSim));
    if(pPersoAContaminer != NULL){
      pCoordPersoAContaminer = getCoordPerso(pPersoAContaminer);
      supprimerPerso(pPersoAContaminer, pSim);
      ajouterPerso(pCoordPersoAContaminer, ZOMBIE, pSim);
    }
  }
}

void tirs(Simulation * pSim){
  int nbPoliciers = getNbPoliciers_sim(pSim);
  GArray * tabPoliciers = getPoliciers_sim(pSim);
  Perso * zombieAPortee = NULL;

  for (int i = 0; i < nbPoliciers; i++) {
    Perso * pPolicier = &g_array_index(tabPoliciers, Perso, i);
    zombieAPortee = policierTueZombie(pPolicier, getTerrain_sim(pSim));
    if(zombieAPortee != NULL){
      supprimerPerso(zombieAPortee, pSim);
    }
  }
}


////////////////////////////////////////////////////////////////////////////
//CHAMPS////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void propagerChampsPersos(Simulation * pSim){
  Terrain * pTerrain = getTerrain_sim(pSim);
    
  GArray * tabZombies = getZombies_sim(pSim);
  for(int i = 0; i < getNbZombies_sim(pSim); i++){
    Perso * pZombie = &g_array_index(tabZombies, Perso, i);
    Coordonnees * pCoordZombie = getCoordonneesPerso_perso(pZombie);
    propagationChamp(ZOMBIE, i, pCoordZombie, pTerrain);
  }

  GArray * tabPoliciers = getPoliciers_sim(pSim);
  for (int i = 0; i < getNbPoliciers_sim(pSim); i++) {
    Perso * pPolicier = &g_array_index(tabPoliciers, Perso, i);
    Coordonnees * pCoordPolicier = getCoordonneesPerso_perso(pPolicier);
    propagationChamp(POLICIER, i, pCoordPolicier, pTerrain);
  }

  GArray * tabCitoyens = getCitoyens_sim(pSim);
  for (int i = 0; i < getNbCitoyens_sim(pSim); i++) {
    Perso * pCitoyen = &g_array_index(tabCitoyens, Perso, i);
    Coordonnees * pCoordCitoyen = getCoordonneesPerso_perso(pCitoyen);
    propagationChamp(CITOYEN, i, pCoordCitoyen, pTerrain);
  }

}

void deplacementIntelZombie(Perso * pPerso, Simulation * pSim){
  Coordonnees * coordPerso = getCoordonneesPerso_perso(pPerso);

  int sommesChampsCitoyens[4][2]; //bas, haut, gauche, droite - stocke l'id dans la 2eme case
  int sommesChampsPoliciers[4][2]; //bas, haut, gauche, droite - stocke l'id dans la 2eme case

  int sommesChamps[4][2]; //bas, haut, gauche, droite - stocke l'id dans la 2eme case
    
  for (int i = 0; i < 4; i++) { //initialisation des champs
    sommesChampsCitoyens[i][0] = 0;
    sommesChampsPoliciers[i][0] = 0;
  }
    
  caseDeplacement * caseBas = getCaseBasByCoord(coordPerso, getTerrain_sim(pSim));

  sommesChampsCitoyens[0][1] = 0;
  for (int i = 0; i < getNbCitoyens_sim(pSim); i++) {
    sommesChampsCitoyens[0][0] += (int)getChamp(CITOYEN, i, caseBas);
  }
  
  sommesChampsPoliciers[0][1] = 0;
  for (int i = 0; i < getNbPoliciers_sim(pSim); i++) {
    sommesChampsPoliciers[0][0] += (int)getChamp(POLICIER, i, caseBas);
  }

  sommesChamps[0][1] = 0;
  sommesChamps[0][0] = sommesChampsCitoyens[0][0] + sommesChampsPoliciers[0][0];
    

  sommesChampsCitoyens[1][1] = 1;
  caseDeplacement * caseHaut = getCaseHautByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbCitoyens_sim(pSim); i++) {
    sommesChampsCitoyens[1][0] += (int)getChamp(CITOYEN, i, caseHaut);
  }

  sommesChampsPoliciers[1][1] = 1;
  for (int i = 0; i < getNbPoliciers_sim(pSim); i++) {
    sommesChampsPoliciers[1][0] += (int)getChamp(POLICIER, i, caseHaut);
  }

  sommesChamps[1][1] = 1;
  sommesChamps[1][0] = sommesChampsCitoyens[1][0] + sommesChampsPoliciers[1][0];

    
  sommesChampsCitoyens[2][1] = 2;
  caseDeplacement * caseGauche = getCaseGaucheByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbCitoyens_sim(pSim); i++) {
    sommesChampsCitoyens[2][0] += (int)getChamp(CITOYEN, i, caseGauche);
  }
    
  sommesChampsPoliciers[2][1] = 2;
  for (int i = 0; i < getNbPoliciers_sim(pSim); i++) {
    sommesChampsPoliciers[2][0] += (int)getChamp(POLICIER, i, caseGauche);
  }

  sommesChamps[2][1] = 2;
  sommesChamps[2][0] = sommesChampsCitoyens[2][0] + sommesChampsPoliciers[2][0];

    
  sommesChampsCitoyens[3][1] = 3;
  caseDeplacement * caseDroite = getCaseDroiteByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbCitoyens_sim(pSim); i++) {
    sommesChampsCitoyens[3][0] += (int)getChamp(CITOYEN, i, caseDroite);
  }

  sommesChampsPoliciers[3][1] = 3;
  for (int i = 0; i < getNbPoliciers_sim(pSim); i++) {
    sommesChampsPoliciers[3][0] += (int)getChamp(POLICIER, i, caseDroite);
  }

  sommesChamps[3][1] = 3;
  sommesChamps[3][0] = sommesChampsCitoyens[3][0] + sommesChampsPoliciers[3][0];
    
  qsort (sommesChamps, 4, 2*sizeof(int), compareTab2D);

  Terrain * pTerrain = getTerrain_sim(pSim);

  char deplacementEffectue = 0;
  int i = 0;
  do{
    switch (sommesChamps[i][1]) {
    case 0: {
      verifDeplacementBas_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementBas_perso(pPerso, pTerrain);
      i++;
      break;
    }

    case 1: {
      verifDeplacementHaut_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementHaut_perso(pPerso, pTerrain);
      i++;
      break;
    }

    case 2: {
      verifDeplacementGauche_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementGauche_perso(pPerso, pTerrain);
      i++;
      break;
    }

    case 3: {
      verifDeplacementDroite_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementDroite_perso(pPerso, pTerrain);
      i++;
      break;
    }
	    
    default:
      i++;
      break;
    }
  } while(!deplacementEffectue && i < 4);
}

void deplacementIntelCitoyen(Perso * pPerso, Simulation * pSim){
  Coordonnees * coordPerso = getCoordonneesPerso_perso(pPerso);

  int sommesChampsZombies[4][2]; //bas, haut, gauche, droite - stocke l'id dans la 2eme case

  for (int i = 0; i < 4; i++) { //initialisation des champs
    sommesChampsZombies[i][0] = 0;
  }
    
  caseDeplacement * caseBas = getCaseBasByCoord(coordPerso, getTerrain_sim(pSim));

  sommesChampsZombies[0][1] = 0;
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[0][0] += (int)getChamp(ZOMBIE, i, caseBas);
  }

  sommesChampsZombies[1][1] = 1;
  caseDeplacement * caseHaut = getCaseHautByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[1][0] += (int)getChamp(ZOMBIE, i, caseHaut);
  }

  sommesChampsZombies[2][1] = 2;
  caseDeplacement * caseGauche = getCaseGaucheByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[2][0] += (int)getChamp(ZOMBIE, i, caseGauche);
  }

  sommesChampsZombies[3][1] = 3;
  caseDeplacement * caseDroite = getCaseDroiteByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[3][0] += (int)getChamp(ZOMBIE, i, caseDroite);
  }

  qsort (sommesChampsZombies, 4, 2*sizeof(int), compareTab2D);

  Terrain * pTerrain = getTerrain_sim(pSim);

  char deplacementEffectue = 0;
  int i = 3;
  do{
    switch (sommesChampsZombies[i][1]) {
    case 0: {
      verifDeplacementBas_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementBas_perso(pPerso, pTerrain);
      i--;
      break;
    }

    case 1: {
      verifDeplacementHaut_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementHaut_perso(pPerso, pTerrain);
      i--;
      break;
    }

    case 2: {
      verifDeplacementGauche_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementGauche_perso(pPerso, pTerrain);
      i--;
      break;
    }

    case 3: {
      verifDeplacementDroite_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementDroite_perso(pPerso, pTerrain);
      i--;
      break;
    }
	    
    default:
      i--;
      break;
    }
  } while(!deplacementEffectue && i >= 0);
}

void deplacementIntelPolicier(Perso * pPerso, Simulation * pSim){
  Coordonnees * coordPerso = getCoordonneesPerso_perso(pPerso);

  int sommesChampsZombies[4][2]; //bas, haut, gauche, droite - stocke l'id dans la 2eme case

  for (int i = 0; i < 4; i++) { //initialisation des champs
    sommesChampsZombies[i][0] = 0;
  }
    
  caseDeplacement * caseBas = getCaseBasByCoord(coordPerso, getTerrain_sim(pSim));

  sommesChampsZombies[0][1] = 0;
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[0][0] += (int)getChamp(ZOMBIE, i, caseBas);
  }

  sommesChampsZombies[1][1] = 1;
  caseDeplacement * caseHaut = getCaseHautByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[1][0] += (int)getChamp(ZOMBIE, i, caseHaut);
  }

  sommesChampsZombies[2][1] = 2;
  caseDeplacement * caseGauche = getCaseGaucheByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[2][0] += (int)getChamp(ZOMBIE, i, caseGauche);
  }

  sommesChampsZombies[3][1] = 3;
  caseDeplacement * caseDroite = getCaseDroiteByCoord(coordPerso, getTerrain_sim(pSim));
  for (int i = 0; i < getNbZombies_sim(pSim); i++) {
    sommesChampsZombies[3][0] += (int)getChamp(ZOMBIE, i, caseDroite);
  }

  qsort (sommesChampsZombies, 4, 2*sizeof(int), compareTab2D);

  Terrain * pTerrain = getTerrain_sim(pSim);

  char deplacementEffectue = 0;
  int i = 0;
  do{
    switch (sommesChampsZombies[i][1]) {
    case 0: {
      verifDeplacementBas_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementBas_perso(pPerso, pTerrain);
      i++;
      break;
    }

    case 1: {
      verifDeplacementHaut_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementHaut_perso(pPerso, pTerrain);
      i++;
      break;
    }

    case 2: {
      verifDeplacementGauche_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementGauche_perso(pPerso, pTerrain);
      i++;
      break;
    }

    case 3: {
      verifDeplacementDroite_perso(pPerso, getTerrain_sim(pSim));
      deplacementEffectue = deplacementDroite_perso(pPerso, pTerrain);
      i++;
      break;
    }
	    
    default:
      i++;
      break;
    }
  } while(!deplacementEffectue && i < 4);
}



////////////////////////////////////////////////////////////////////////////
//TEST//////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void testFonctions_sim(){
  srand(time(NULL));
  char * nomFic = "FichierTestLecture";

  Simulation * pSim = creerSimulation_sim(100, 30, 30, nomFic);

  afficherGrilleConsole(getTerrain_sim(pSim));

  contaminations(pSim);
  deplacerPerso_sim(pSim);
  contaminations(pSim);
  deplacerPerso_sim(pSim);
  contaminations(pSim);

  afficherGrilleConsole(getTerrain_sim(pSim));

  printf("%d %d %d", getNbZombies_sim(pSim), getNbCitoyens_sim(pSim), getNbPoliciers_sim(pSim));

  testamentSim(pSim);
}

////////////////////////////////////////////////////////////////////////////
//AUTRES////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
int compareTab2D(const void * a, const void * b)
{
  int * pa = (int *)a;
  int * pb = (int *)b;

  return pa[0]-pb[0];
}
