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
    this->healingHp = 2000;
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
    this->currentCountry->UpdateHP(healingHp);
    int TtlSoldiers = 0;

    for (it = wP.begin(); it != wP.end(); ++it) {
        if ((*it)->getType() == "MachineGunner" || ((*it)->getType() == "RifleMan")) {
            TtlSoldiers++;
        }
    }

    int Healing = healingHp/TtlSoldiers;

    for(it=wP.begin(); it != wP.end(); ++it)
    {
        if((*it)->getType()=="MachineGunner" || ((*it)->getType()=="RifleMan"))
        {
            cout<<"Soldiers are injured and have an Hp of " << (*it)->getHP() <<endl;
            cout<<" They will be healed by Medics by "<< Healing <<" to soldiers of "<< this->currentCountry->getName()<<endl;
            cout<<"Soldiers Hp has increased to "<< (*it)->getHP() + Healing<<endl;
            break;

        }

    }

  for (it = wP.begin(); it != wP.end(); ++it){
    if((*it)->getType()=="MachineGunner" || ((*it)->getType()=="RifleMan"))
    {
        if(this->maxHeal<3){
            if((*it)->getHP()<80  && (*it)->getHP()!=0)//help if injured not dead
            {
                (*it)->updateHP(Healing);
            }
        }
         else
        {
                cout<<"Medic notified but unable to assist more than 3 times"<<endl;
        }
       
    }
  }
  this->maxHeal++;
    
   
}