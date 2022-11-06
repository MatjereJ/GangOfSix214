#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
#include "WarTransportFactory.h"


using namespace std;

IndividualCountry::IndividualCountry(std::string name, int level, bool sea){
    this->name=name;
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
            for (int i = 0; i < rand() %10+16; i++) {
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
            for (int i = 0; i < rand() %10+21; i++) {
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
   //add all weaponHP's in warparticipants vector
    int weaponHp=0;
     vector<WarParticipant*> warP= this->getWarParticipants();
     vector<WarParticipant*>::iterator it2 = warP.begin();
     for(it2 = warP.begin(); it2 != warP.end(); ++it2){
          if((*it2)->getType()=="Missile" || (*it2)->getType()=="Bomb") 
              weaponHp+=(*it2)->getHP();
     }
     return weaponHp;
}

int IndividualCountry::getSoldierHP(){
    int soldierHp=0;
     vector<WarParticipant*> warP= this->getWarParticipants();
     vector<WarParticipant*>::iterator it2 = warP.begin();
     for(it2 = warP.begin(); it2 != warP.end(); ++it2){
         if((*it2)->getType()=="MachineGunner" || (*it2)->getType()=="Rifleman")
                soldierHp+=(*it2)->getHP();
     }  
     return soldierHp;
}

int IndividualCountry::getTransport(){
  int numTransport=0;
     vector<WarParticipant*> warP= this->getWarParticipants();
     vector<WarParticipant*>::iterator it2 = warP.begin();
     for(it2 = warP.begin(); it2 != warP.end(); ++it2){
          if((*it2)->getType()=="WarShip" || (*it2)->getType()=="AirCraft")
                numTransport++;
     }  
     return numTransport;
}

vector<IndividualCountry*> IndividualCountry::getAlliance(){
    return this->alliance;
}

void IndividualCountry::setAlliance(vector<IndividualCountry*> alliance){
  this->alliance= alliance;

}

void IndividualCountry::observeHp(){
    notify();
}

int IndividualCountry::getHP(){
    int totalHp=0;
     vector<WarParticipant*> warP= this->getWarParticipants();
     vector<WarParticipant*>::iterator it2 = warP.begin();
     for(it2 = warP.begin(); it2 != warP.end(); ++it2){
        totalHp+=(*it2)->getHP();
     }
     return totalHp;
}

vector<WarParticipant*> IndividualCountry::getWarParticipants(){
    return this->wP;
}



