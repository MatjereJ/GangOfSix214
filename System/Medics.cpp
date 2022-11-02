#include <iostream>
#include <string>
#include <vector>
#include "Medics.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

Medics::Medics(IndividualCountry* currentCountry){
    this->currentCountry=currentCountry;
    this->currentCountry->add(this);
}

void Medics::update(int weaponHP,int soldierHP,int transport){
   observedWeapons=weaponHP;
   observedWeapons+=10;
   this->currentCountry->setWeaponHP(observedWeapons);
   cout<<"Soldier is injured and has "<<weaponHP<<" HP"<<endl;
   cout<<"Medic Healing Soldier..."<<endl;
   cout<<"Soldier HP now increased to "<<observedWeapons<<" HP"<<endl;
}