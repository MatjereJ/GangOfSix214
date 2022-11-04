#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry::IndividualCountry(string n){
   this->initialHP=this->getHP();
    this->name=n;
    /* this->weaponHP=(int)(this->getHP()*0.5);//global x 0.50
    this->soldierHP=(int)(this->getHP()*0.3);
    this->transport=(int)(this->getHP()*0.2);*/
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
    (*it)->update(this->getWeaponHP(),this->getSoldierHP(),this->getTransport());
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
vector<IndividualCountry*> IndividualCountry::getAlliance(){
    return this->alliance;
}
void IndividualCountry::setAlliance(vector<IndividualCountry*> alliance){
  this->alliance= alliance;

}
void IndividualCountry::checkHp(){
    //cout<<"HPs: "<<w<<" "<<s<<" "<<t<<" "<<endl;
    cout<<"In CheckHP"<<endl;
    this->weaponHP=(int)(this->getHP()*0.5);//global x 0.50
    this->soldierHP=(int)(this->getHP()*0.3);
    this->transport=(int)(this->getHP()*0.2);
    int numSoldiers=(int)(this->getInitialHP()*0.3*0.4);//calculating 40% of country's soldiers
    if(this->soldierHP<10)
    {
        cout<<"Notifying"<<endl;
        notify();
    }
  
        
}

int IndividualCountry::getInitialHP(){
      return this->initialHP;
}

