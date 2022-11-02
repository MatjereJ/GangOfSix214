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
    (*it)->update(this->weaponHP,this->soldierHP,this->transport);
  }
}
string IndividualCountry::getName(){
    return this->name;
}
int IndividualCountry::getWeaponHP(){
    return this->weaponHP;
}
int IndividualCountry::getSoldierHP(){
    return this->soldierHP;
}
int IndividualCountry::getTransport(){
    return this->transport;
}
void IndividualCountry::setHP(int w,int s,int t){
    cout<<"HPs: "<<w<<" "<<s<<" "<<t<<" "<<endl;
    this->weaponHP=w;
    this->soldierHP=s;
    this->transport=t;
    if(this->soldierHP<10)
    {
     
      notify();
    }
        
}
