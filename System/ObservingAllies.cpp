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
void ObservingAllies::update(){
  vector<WarParticipant*> wP= this->currentCountry->getWarParticipants();
  vector<WarParticipant*>::iterator it = wP.begin();
  for (it = wP.begin(); it != wP.end(); ++it){
    if((*it)->getType()=="Missile" || (*it)->getType()=="Bomb" && (*it)->getHP()<50)
     {    
          vector<IndividualCountry*> alliance= this->currentCountry->getAlliance();
          vector<IndividualCountry*>::iterator it2 = alliance.begin();
           for(it2 = alliance.begin(); it2 != alliance.end(); ++it2){
              cout<<this->currentCountry->getName()<<" is running low on weapon power"<<endl;
              int weaponAssist=((*it2)->getHP()*50)*50;
              (*it)->setHP(weaponAssist);
              cout<<(*it2)->getName()<<" increases weapon power with"<<weaponAssist<<" HP to"<<this->currentCountry->getName()<<endl;
              cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
          
          }
     }
      if((*it)->getType()=="WarShip" && (*it)->getHP()<90)
     {
          vector<IndividualCountry*> alliance= this->currentCountry->getAlliance();
          vector<IndividualCountry*>::iterator it2 = alliance.begin();
           for(it2 = alliance.begin(); it2 != alliance.end(); ++it2){
            cout<<this->currentCountry->getName()<<" is running low on transport"<<endl;
              int transAssist=((*it2)->getHP()*50)*30;
              (*it)->setHP(transAssist);
              cout<<(*it2)->getName()<<" increases transport with"<<transAssist<<" HP to"<<this->currentCountry->getName()<<endl;
          }
     }

  }
   

    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
   //select group of allies containing current country
   //iterate through group,transfer resources to current country
   
}