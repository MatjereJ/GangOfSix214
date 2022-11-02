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
        //Medics();
        Medics(IndividualCountry* currentCountry);
        void  update(int weaponHP,int soldierHP,int transport);
    private:
        int observedWeapons;
        IndividualCountry* currentCountry;
        
};
#endif