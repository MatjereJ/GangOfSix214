#ifndef MEDICS_H
#define MEDICS_H
#include "IndividualCountry.h"
#include "CountryObserver.h"
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Medics : public CountryObserver {//Concrete Observer
    public:
        Medics(IndividualCountry* currentCountry);
        void  update();
    private:
        int observedHP;
        int observedS;
        int observedT;
        int maxHeal=0;
        int healingHp=90;
        bool medicObserved=false;//set to false if true, when Allies send medics
        IndividualCountry* currentCountry;
        vector<WarParticipant*> warParticipants;
};
#endif