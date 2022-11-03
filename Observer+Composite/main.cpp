#include <iostream>
#include <string>
#include <vector>
#include "Country.h"
#include "Country.cpp"
#include "IndividualCountry.h"
#include "IndividualCountry.cpp"
#include "CountryObserver.h"
#include "CountryObserver.cpp"
#include "Medics.h"
#include "Medics.cpp"
#include "ObservingAllies.h"
#include "ObservingAllies.cpp"
using namespace std;

int main(){
   
    Country* china = new Country();
    CountryObserver* redCross = new CountryObserver();
    CountryObserver* brics = new CountryObserver();
    china->add(redCross);
    china->add(brics);


    return 0;
}