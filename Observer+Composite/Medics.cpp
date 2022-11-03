#include <string>
#include <vector>
#include "Medics.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
#include <iostream>
using namespace std;

Medics::Medics(IndividualCountry* currentCountry){
    this->currentCountry=currentCountry;
}
void Medics::update(){
   int currentHP=this->currentCountry->getSoldierHP();
   currentHP+=10;
   this->currentCountry->setSoldierHP(currentHP);
}