#include <iostream>
#include <string>
#include <vector>
#include "ObservingAllies.h"
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

ObservingAllies::ObservingAllies(IndividualCountry* currentCountry){
     this->currentCountry=currentCountry;
    this->currentCountry->add(this);
}
void ObservingAllies::update(int weaponHP,int soldierHP,int transport){
   //get current country's resources and accumulate it
   observedH=weaponHP;
   observedH+=100;
   cout<<"Allies sharing resources"<<endl;
 
   //select group of allies containing current country
   //iterate through group,transfer resources to current country
   
}