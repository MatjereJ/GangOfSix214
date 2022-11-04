#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry:: IndividualCountry():Country(){
  
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

int IndividualCountry::getHp() {
    return hp;
}

IndividualCountry:: IndividualCountry(string name,int weaponHP,int soldierHP,int transport,int s):Country(){
    this->name=name;
    this->weaponHP=weaponHP;
    this->soldierHP=soldierHP;
    this->transport=transport;
    this->size=s;
}
bool IndividualCountry::add(CountryObserver* assistance){
    countryObservers.push_back(assistance);
    cout<<"Added Country Observer"<<endl;
    return true;
}
bool IndividualCountry::remove(CountryObserver* assistance){
    bool found = false;

    vector<CountryObserver*>::iterator it = countryObservers.begin();
    while ((it != countryObservers.end()) && (! found)) {
        if (*it == assistance) {
            found = true;
            countryObservers.erase(it);
        }
        ++it;
    }
    return found;
}
void IndividualCountry::notify(){
    vector<CountryObserver*>::iterator it = countryObservers.begin();
    for (it = countryObservers.begin(); it != countryObservers.end(); ++it){
        (*it)->update();
    }
}

