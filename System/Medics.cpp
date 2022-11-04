#include <iostream>
#include <string>
#include <vector>
#include "Medics.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

Medics::Medics(IndividualCountry* currentCountry){
    this->currentCountry=currentCountry;
    this->currentCountry->add(this);
}

void Medics::update(int weaponHP,int soldierHP,int transport){
    cout<<"HPs in Medic Update "<<weaponHP<<" "<<soldierHP<<" "<<transport<<endl;
    this->observedHP=weaponHP;
    this->observedS=soldierHP;
    this->observedT=transport;

    int total=0;
    if(this->maxHeal < 3)//removed boolean value medicObserved
    {
        this->observedS+=10;
        this->maxHeal++;
        total=(weaponHP+this->observedS)+transport;
        this->currentCountry->updateHp(total);//Updating actual Country that requested medical assistance
        cout<<"Soldier is injured and has "<<soldierHP<<" HP"<<endl;
        cout<<"Medic Healing Soldier from "<<this->currentCountry->getName()<<endl;
        cout<<"Soldier HP now increased to "<<this->observedS<<" HP"<<endl;
    }
    else
    {
        cout<<"Medic notified but unable to assist more than 3 times"<<endl;
    }
        
   
}