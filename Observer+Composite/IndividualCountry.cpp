#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry:: IndividualCountry(){
  
}
int IndividualCountry::getWeaponHP(){
    return weaponHP;
}
int IndividualCountry::getSoldierHP(){
    return soldierHP;
}
void IndividualCountry::setWeaponHP(int w){
    this->weaponHP=w;
}
void IndividualCountry::setSoldierHP(int s){
    this->soldierHP=s;
}