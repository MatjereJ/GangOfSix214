#ifndef MEDICS_H
#define MEDICS_H
#include "IndividualCountry.h"
#include "CountryObserver.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Medics : public CountryObserver {//Concrete Observer
    public:
        Medics(IndividualCountry* currentCountry);
        void  update(int weaponHP,int soldierHP,int transport);
    private:
        int observedHP;
        int observedS;
        int observedT;
        int maxHeal=0;
        bool medicObserved=false;//set to false if true, when Allies send medics
        IndividualCountry* currentCountry;
        
};
#endif