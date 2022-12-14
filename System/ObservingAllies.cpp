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
    name = "Ally Observer";
}

string ObservingAllies::getName() {
    return name;
}
void ObservingAllies::update(){
  int weaponAssist=0,soldierAssist=0,transAssist=0,numWeapons=0,numSoldiers=0,numTransport=0,maxAssist=0;
  vector<WarParticipant*> warParticipants= this->currentCountry->getArtillery();
  vector<WarParticipant*>::iterator it = warParticipants.begin();
  //checking sum of each resource in order to assist if necessary
     for (it = warParticipants.begin(); it != warParticipants.end(); ++it){
          if((*it)->getType()=="Missile" || (*it)->getType()=="Bomb")  
               numWeapons++;
          if((*it)->getType()=="WarShip" || (*it)->getType()=="AirCraft")
               numTransport++;
          if((*it)->getType()=="MachineGunner" || (*it)->getType()=="Rifleman")
               numSoldiers++;
     }
    vector<Country*> all= this->currentCountry->getAlliance();
    vector<Country*>::iterator it2 = all.begin();
    for(it2 = all.begin(); it2 != all.end(); ++it2) {
        cout<<this->currentCountry->getName()<<" is running low on supplies and is currently being assisted by "<<(*it2)->getName() << endl;
    }
     if(numWeapons<100)
     {
               vector<Country*> alliance= this->currentCountry->getAlliance();
               vector<Country*>::iterator it2 = alliance.begin();
               for(it2 = alliance.begin(); it2 != alliance.end(); ++it2){
               //cout<<this->currentCountry->getName()<<" is running low on weapon power and is currently being assisted by"<< (*it2)->getName()<<endl;
               vector<WarParticipant*> wP= (*it2)->getWarParticipants();//getting allies iterating and moving each resource to country in need.
               vector<WarParticipant*>::iterator it = wP.begin();
               //each country contributing 50% of their weapons
               maxAssist=(int)((*it2)->getHp()*0.5)*0.5;//assuming 50% of global HP is reserved for weapons
               for (it = wP.begin(); it != wP.end(); ++it){
                    if((*it)->getType()=="Missile" || (*it)->getType()=="Bomb" && maxAssist>0){//only assist with a limited amount
                         warParticipants.push_back(*it); //sharing resources
                        (*it2)->removeWarParticipant(*it);
                         maxAssist--;
                         numWeapons++;
                         //cout<<(*it2)->getName()<<" gave "<<maxAssist<<" weapons to "<<this->currentCountry->getName()<<endl;
                         //cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    }
                    if(maxAssist<=0)
                    {
                         this->currentCountry->setWarParticipants(warParticipants);
                         break;  
                    }
                        
                        
                 }
               }
             
     }  
     
     if(numTransport<100)
     {         //iterating through war participant vector of each country in alliance
               vector<Country*> alliance= this->currentCountry->getAlliance();
               vector<Country*>::iterator it2 = alliance.begin();
               for(it2 = alliance.begin(); it2 != alliance.end(); ++it2){
               //cout<<this->currentCountry->getName()<<" is running low on transport and is currently being assisted by its alliance..."<<endl;
               vector<WarParticipant*> wPs= (*it2)->getWarParticipants();//getting allies iterating and moving each resource to ICountry's WarParticipants.
               vector<WarParticipant*>::iterator it = wPs.begin();
               //each country contributing 50% of their weapons
               maxAssist=(int)((*it2)->getHp()*0.5)*0.5;
               for (it = wPs.begin(); it != wPs.end(); ++it){
                    if((*it)->getType()=="WarShip" || (*it)->getType()=="AirCraft"){//only assist with a limited amount
                         warParticipants.push_back(*it);
                        (*it2)->removeWarParticipant(*it);
                         maxAssist--;
                         //cout<<(*it2)->getName()<<"gave "<<maxAssist<<" war transports to"<<this->currentCountry->getName()<<endl;
                         //cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    }
                    if(maxAssist<=0)
                    {
                         this->currentCountry->setWarParticipants(warParticipants);
                         break;  
                    }
                        
                 }
               }
             
     }
     if(numSoldiers<100)
     {
               vector<Country*> alliance= this->currentCountry->getAlliance();
               vector<Country*>::iterator it2 = alliance.begin();
               for(it2 = alliance.begin(); it2 != alliance.end(); ++it2){
               //cout<<this->currentCountry->getName()<<" is running low on soldiers and is currently being assisted by its alliance..."<<endl;
               vector<WarParticipant*> wP2= (*it2)->getWarParticipants();//getting allies iterating and moving each resource to country in need.
               vector<WarParticipant*>::iterator it = wP2.begin();
               //each country contributing 50% of their weapons
               maxAssist=(int)((*it2)->getHp()*0.5)*0.5;
               for (it = wP2.begin(); it != wP2.end(); ++it){
                   if((*it)->getType()=="MachineGunner" || (*it)->getType()=="Rifleman"){//only assist with a limited amount
                         warParticipants.push_back(*it);
                       (*it2)->removeWarParticipant(*it);
                         maxAssist--;
                         //cout<<(*it2)->getName()<<" shared "<<maxAssist<<" with"<<this->currentCountry->getName()<<endl;
                         //cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    }
                        
                    }
                    if(maxAssist<=0)
                    {
                         this->currentCountry->setWarParticipants(warParticipants);
                         break;  
                    }  
                        
                 }
              
     }
    

    
   
}