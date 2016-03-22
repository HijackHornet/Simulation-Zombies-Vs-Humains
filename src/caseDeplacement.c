#include "caseDeplacement.h"

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

enum env getEnvCase(caseDeplacement * caseDep){
    return caseDep -> envCase;
}

Perso * getPersoCase(caseDeplacement * caseDep){
    return caseDep -> persoCase;
}

void setEnvCase(caseDeplacement * caseDep, enum env valeurEnv){
    caseDep -> envCase = valeurEnv;
}

void setPersoCase(caseDeplacement * caseDep, Perso * pPerso){
    caseDep -> persoCase = pPerso;
}
