#ifndef MEDICS_H
#define MEDICS_H
#include "IndividualCountry.h"
#include "CountryObserver.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Medics : CountryObserver {//Concrete Observer
    public:
        //Medics();
        Medics(IndividualCountry*);
        virtual void update();
    private:
        IndividualCountry* currentCountry;
        
};
#endif