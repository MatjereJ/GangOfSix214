#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
#include "WarTransportFactory.h"


IndividualCountry:: IndividualCountry():Country(){
  
}



void IndividualCountry::setWeaponHP(int w){
    this->weaponHP=w;
}
void IndividualCountry::setSoldierHP(int s){
    this->soldierHP=s;
}


using namespace std;



IndividualCountry::IndividualCountry(std::string name, int level, bool sea){
    this->name=name;
    ocean=sea;
    SoldierFactory* soldierFactory=new SoldierFactory();
    ExplosiveFactory* explosiveFactory=new ExplosiveFactory();
    WarTransportFactory* warTransportFactory=new WarTransportFactory();
    if(level==3){
        for(int i=0; i<rand()%100+51; i++){
            wP.push_back(soldierFactory->createMachineGunner(25,50));
        }
        for(int i=0; i<rand()%100+51; i++){
            wP.push_back(soldierFactory->createRifleman(30, 60));
        }
        for(int i=0; i<rand()%40+21; i++){
            wP.push_back(explosiveFactory->createBomb(50));
        }
        for(int i=0; i<rand()%40+21; i++){
            wP.push_back(explosiveFactory->createMissile(70));
        }
        for(int i=0; i<rand()%10+11; i++){
            wP.push_back(warTransportFactory->createAirCraft(300));
        }
        if(sea==true) {
            for (int i = 0; i < rand()%10+11; i++) {
                wP.push_back(warTransportFactory->createWarShip(90));
            }
        }
    }else if(level==2){
        for(int i=0; i<rand()%150+51; i++){
            wP.push_back(soldierFactory->createMachineGunner(50,20));
        }
        for(int i=0; i<rand()%150+51; i++){
            wP.push_back(soldierFactory->createRifleman(60,30));
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
    }else if(level==1){
        for(int i=0; i<rand()%200+51; i++){ 
            wP.push_back(soldierFactory->createMachineGunner(50,15));
        }
        for(int i=0; i<rand()%200+51; i++){
            wP.push_back(soldierFactory->createRifleman(60,25));
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
    initializeHp();
}

bool IndividualCountry::add(CountryObserver* assistance){
    countryObservers.push_back(assistance); 
    cout<<"Added Country Observer"<<endl;
    return true;
}

IndividualCountry* IndividualCountry::getOpposingC() {
    return OpposingCountry;
}

void IndividualCountry:: setHp(int HP){
    hp=HP;
}

State* IndividualCountry:: getState(){
    return state;
}

void IndividualCountry::initializeHp() {
    vector<WarParticipant*>::iterator it = wP.begin();
    int total=0;
    for(it=wP.begin(); it!=wP.end(); it++){
        total+=(*it)->getHP();
    }
    this->hp=total;
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



void IndividualCountry::addWarParticipant(WarParticipant* warPtc)
{
    wP.push_back(warPtc);
}



std::vector<CountryObserver*> IndividualCountry::getCountryObservers()
{
    return countryObservers;
}




WarTheatre* IndividualCountry::getWarTheatre()
{
    return warTheatre;
}



WarParticipantIterator* IndividualCountry::createWarParticipantIterator()
{
    return new WarParticipantIterator(this->getArtillery());
}





vector<WarParticipant*> IndividualCountry::getArtillery() {
    return wP;
}

void IndividualCountry::selectWarTheatre() {
    bool correctInput=false;
    char x;

    cout<<"Choose your most Lethal Theatre!! "<<"Is it:"<<endl;
    cout<<"A-AirSpace"<<endl<<"B-Land"<<endl<<"C-Sea"<<endl;
    cout<<"Enter A,B or C"<<endl;
    cin>>x;

    while (!correctInput) {
        if (x == 'A' || x == 'a') {
            warTheatre = new AirSpace();
            correctInput = true;
        } else if (x == 'B' || x == 'b') {
            warTheatre = new Land();
            correctInput = true;
        } else if (x == 'C' || x == 'c') {
            warTheatre = new Sea();
            correctInput = true;
        } else {
            cout<<"Invalid input. Enter A,B or C"<<endl;
            correctInput= false;
        }
    }
}

IndividualCountry* IndividualCountry::pickOpposingCountry(vector<IndividualCountry*> enemies) {

    srand(time(0));
    int random=rand()% enemies.size();
    OpposingCountry=enemies.at(random);

    return OpposingCountry;

}

void IndividualCountry::createWarParticipants() {


}


void IndividualCountry::attackOpposingCountry(IndividualCountry *opp) {

}


CountryBackup* IndividualCountry::createBackup() {
    return new CountryBackup(hp,warTheatre,wP,countryObservers,OpposingCountry,lose);
}



void IndividualCountry::reinstateCountry(CountryBackup *backup) {
    State* s=backup->getState();
    hp=s->getHP();
    warTheatre=s->getWarTheatre();
    wP=s->getWarParticipants();
    countryObservers=s->getCountryObservers();
    OpposingCountry=s->getOppCountry();
    lose=s->getW();
}

IndividualCountry::~IndividualCountry()
{
    wP.clear();
    std::cout<<"Parent of "<<cName <<" deleted.\n";
}

void IndividualCountry::setWarParticipants(vector<WarParticipant *> participants) {
    wP=participants;
}

void IndividualCountry::InflictDamage(int dmg)
{
    this->hp = hp - dmg;
    vector<WarParticipant *>::iterator it = wP.begin();
    int totalSoldiers = 0;
    for (it = wP.begin(); it != wP.end(); it++)
    {
        if ((*it)->getType() == "Rifleman" || (*it)->getType() == "MachineGunner")
        {
            totalSoldiers++;
        }
    }
    int SoldierD = dmg / totalSoldiers;
    for (it = wP.begin(); it != wP.end(); it++)
    {
        if ((*it)->getType() == "Rifleman" || (*it)->getType() == "MachineGunner")
        {
            if ((*it)->getHP() < SoldierD)
            {
                (*it)->setHp(0);
            }
            else
                (*it)->setHp((*it)->getHP() - SoldierD);
        }
    }
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

vector<Country*> IndividualCountry::getAlliance(){
    return this->alliance;
}

void IndividualCountry::setAlliance(vector<Country*> alliance){
  this->alliance= alliance;

}
int IndividualCountry::getHp(){

     return hp;
}

void IndividualCountry::setOpposingC(IndividualCountry *C) {
    OpposingCountry = C;
}



void IndividualCountry::setLose() {
    lose=true;
}




