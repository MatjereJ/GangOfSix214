#include <iostream>
#include <string>
#include <vector>
#include "ObservingAllies.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

ObservingAllies::ObservingAllies(IndividualCountry* currentCountry){
    this->currentCountry=currentCountry;
}
void ObservingAllies::update(){
   //get current country's resources and accumulate it
   int currentWeapons=this->currentCountry->getWeaponHP();
   int currentTransport=this->currentCountry->getTransport();
   //select group of allies containing current country
   //iterate through group,transfer resources to current country
   
}