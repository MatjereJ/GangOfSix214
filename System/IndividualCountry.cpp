#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry:: IndividualCountry(string name){
    this->name=name;
}
bool IndividualCountry::add(CountryObserver* assistance){
    countryObservers.push_back(assistance); 
    cout<<"Added Observer"<<endl;
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
    (*it)->update(weaponHP,soldierHP,transport);
  }
}
int IndividualCountry::getWeaponHP(){
    return weaponHP;
}
void IndividualCountry::setWeaponHP(int w){
    this->weaponHP=w;
    if(this->weaponHP<10)
    {
     
      notify();
    }
        
}
