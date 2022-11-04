#ifndef OBSERVINGALLIES_H
#define OBSERVINGALLIES_H
#include "BattleState.h"
#include "IndividualCountry.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class ObservingAllies : public CountryObserver{//Concrete Observers
    public:
        ObservingAllies(IndividualCountry* currentCountry);
        void  update(int weaponHP,int soldierHP,int transport);
    private:
        int observedH;
        IndividualCountry* currentCountry;
};
#endif