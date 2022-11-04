#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry:: IndividualCountry():Country(){
  
}

IndividualCountry:: IndividualCountry(string name, int level, bool sea):Country(name, sea){

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

vector<WarParticipant*> IndividualCountry::getWarParticipants(){
    return warParticipants;
}
