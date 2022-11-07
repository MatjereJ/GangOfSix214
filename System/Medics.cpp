#include <iostream>
#include <string>
#include <vector>
#include "Medics.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
#include "Country.h"
using namespace std;

Medics::Medics(IndividualCountry* currentCountry){
    this->maxHeal = 0;
    this->healingHp = 20;
    this->currentCountry=currentCountry;
    this->currentCountry->add(this);
    name = "Medic";
}

string Medics::getName() {
    return name;
}

void Medics::update(){
    
  vector<WarParticipant*> wP= this->currentCountry->getArtillery();
  vector<WarParticipant*>::iterator it = wP.begin();
  cout<<"Medics" <<endl;
  for (it = wP.begin(); it != wP.end(); ++it){
    if((*it)->getType()=="MachineGunner" || ((*it)->getType()=="RifleMan"))
    {
        if(this->maxHeal<3){
            if((*it)->getHP()<30  && (*it)->getHP()!=0)//help if injured not dead
            {
                cout<<"Soldier is injured and has "<<(*it)->getHP()<<" HP"<<endl;
                (*it)->updateHP(this->healingHp);
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