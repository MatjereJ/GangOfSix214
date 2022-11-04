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
   cout<<"HPs in Observer Update "<<weaponHP<<" "<<soldierHP<<" "<<transport<<endl;
    int total=0;
   this->observedH=weaponHP;
   this->observedH+=100;
   int weaponAssist=0;
   int soldierAssist=0;
   int transportAssist=0;
   int currWeaponAssist=0;
   int currSoldierAssist=0;
   int currTransportAssist=0;
   int initial=this->currentCountry->getInitialHP()*0.5;
   cout<<"Allies sharing resources with "<<this->currentCountry->getName()<<endl;
   
  //vector<IndividualCountry*>::iterator it = this->currentCountry->getAlliance().begin();
  //
   vector<IndividualCountry*> alliance= this->currentCountry->getAlliance();
   vector<IndividualCountry*>::iterator it = alliance.begin();
  //cout<<"Observing alliance country"<<(*it)->getName()<<endl;
  //cout<<"Observing alliance country: "<<(*it)->getName()<<endl;
     //int halfWeapons=(int)(this->currentCountry->getInitialHP()*0.5)*0.5;
     //int halfSoldiers=(int)(this->currentCountry->getInitialHP()*0.3)*0.5;
     //int halfTransport=(int)(this->currentCountry->getInitialHP()*0.2)*0.5;
  //check if country has half of its specific resource
  if(weaponHP<10||soldierHP<10 || transport<10){
       for(it = alliance.begin(); it != alliance.end(); ++it){
            currWeaponAssist=(int)((*it)->getWeaponHP()-(*it)->getWeaponHP()*0.40);
            weaponAssist+=(int)((*it)->getWeaponHP()-(*it)->getWeaponHP()*0.40);
            
            currTransportAssist=(int)((*it)->getTransport()-(*it)->getTransport()*0.30);
            transportAssist+=(int)((*it)->getTransport()-(*it)->getTransport()*0.30);
            currSoldierAssist=(int)((*it)->getSoldierHP()-(*it)->getSoldierHP()*0.25);
            soldierAssist+=(int)((*it)->getSoldierHP()-(*it)->getSoldierHP()*0.25);
            total=(weaponAssist+soldierAssist)+transportAssist;
            this->currentCountry->updateHp(total);
            cout<<(*it)->getName()<<" gives "<<currWeaponAssist<<" Weapons, "<<currSoldierAssist<<" Soldiers, "<<currTransportAssist<<" Transport vehicles to "<<this->currentCountry->getName()<<endl;
       }
  }
 
    cout<<"--------------------------------------------------------------------------------------"<<endl;
   //select group of allies containing current country
   //iterate through group,transfer resources to current country
   
}