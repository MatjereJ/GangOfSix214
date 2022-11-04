#include <iostream>
#include <string>
#include <vector>
#include "Medics.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
#include "Country.h"
using namespace std;

Medics::Medics(IndividualCountry* currentCountry){
    this->currentCountry=currentCountry;
    this->currentCountry->add(this);
}

void Medics::update(int weaponHP,int soldierHP,int transport){
    
    vector<WarParticipant*> wP= this->currentCountry->getWarParticipants();
      vector<WarParticipant*>::iterator it = wP.begin();
  for (it = wP.begin(); it != wP.end(); ++it){
    if((*it)->getType()=="MachineGunner" || ((*it)->getType()=="RifleMan"))
    {
        if(this->maxHeal<3){
            if((*it)->getDamage()<30)
            {
                cout<<"Soldier is injured and has "<<(*it)->getHP()<<" HP"<<endl;
                (*it)->setHP(this->healingHp);
                this->maxHeal++;
            
                cout<<"Medic Healing Soldier from "<<this->currentCountry->getName()<<endl;
                cout<<"Soldier HP now increased to "<<(*it)->getHP()<<" HP"<<endl;
                break;
             }
        }
         else
        {
                cout<<"Medic notified but unable to assist more than 3 times"<<endl;
        }
       
    }
  }
    
   
}