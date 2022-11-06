#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry::IndividualCountry(string n){
   this->initialHP=this->getHP();
   this->name=n;
  
=======
IndividualCountry:: IndividualCountry(string name,int weaponHP,int soldierHP,int transport) {
    this->name = name;
    this->weaponHP = weaponHP;
    this->soldierHP = soldierHP;
    this->transport = transport;
}

IndividualCountry::IndividualCountry(string name, int level, bool sea){
    cName=name;
    ocean=sea;
    SoldierFactory* soldierFactory=new SoldierFactory();
    ExplosiveFactory* explosiveFactory=new ExplosiveFactory();
    WarTransportFactory* warTransportFactory=new WarTransportFactory();
    if(level==1){
        for(int i=0; i<rand()%100+51; i++){
            wP.push_back(soldierFactory->createMachineGunner(50));
        }
        for(int i=0; i<rand()%100+51; i++){
            wP.push_back(soldierFactory->createRifleman(60));
        }
        for(int i=0; i<rand()%40+21; i++){
            wP.push_back(explosiveFactory->createBomb(100));
        }
        for(int i=0; i<rand()%40+21; i++){
            wP.push_back(explosiveFactory->createMissile(70));
        }
        for(int i=0; i<rand()%10+11; i++){
            wP.push_back(warTransportFactory->createAirCraft(300));
        }
        if(sea==true) {
            for (int i = 0; i < rand()%10+11; i++) {
                wP.push_back(warTransportFactory->createWarShip(250));
            }
        }
    }else if(level==2){
        for(int i=0; i<rand()%150+51; i++){
            wP.push_back(soldierFactory->createMachineGunner(50));
        }
        for(int i=0; i<rand()%150+51; i++){
            wP.push_back(soldierFactory->createRifleman(60));
        }
        for(int i=0; i<rand()%40+31; i++){
            wP.push_back(explosiveFactory->createBomb(100));
        }
        for(int i=0; i<rand()%40+31; i++){
            wP.push_back(explosiveFactory->createMissile(70));
        }
        for(int i=0; i<rand()%10+16; i++){
            wP.push_back(warTransportFactory->createAirCraft(300));
        }
        if(sea==true) {
            for (int i = 0; i < rand() %%10+16; i++) {
                wP.push_back(warTransportFactory->createWarShip(250));
            }
        }
    }else if(level==3){
        for(int i=0; i<rand()%200+51; i++){
            wP.push_back(soldierFactory->createMachineGunner(50));
        }
        for(int i=0; i<rand()%200+51; i++){
            wP.push_back(soldierFactory->createRifleman(60));
        }
        for(int i=0; i<rand()%40+41; i++){
            wP.push_back(explosiveFactory->createBomb(100));
        }
        for(int i=0; i<rand()%40+41; i++){
            wP.push_back(explosiveFactory->createMissile(70));
        }
        for(int i=0; i<rand()%10+21; i++){
            wP.push_back(warTransportFactory->createAirCraft(300));
        }
        if(sea==true) {
            for (int i = 0; i < rand() %%10+21; i++) {
                wP.push_back(warTransportFactory->createWarShip(250));
            }
        }
    }
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
    notify();
}

int IndividualCountry::getInitialHP(){
      return this->initialHP;
}

vector<WarParticipant*> IndividualCountry::getWarParticipants(){
    return this->wP;
}


