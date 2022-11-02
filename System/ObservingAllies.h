#ifndef OBSERVINGALLIES_H
#define OBSERVINGALLIES_H
#include "BattleState.h"
#include "IndividualCountry.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class ObservingAllies {//Concrete Observers
    public:
        ObservingAllies(IndividualCountry* c);
        void update();
    private:
        IndividualCountry* currentCountry;
};
#endif