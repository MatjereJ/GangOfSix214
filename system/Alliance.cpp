#include "Alliance.h"

using namespace std;

Alliance:: Alliance(){ 
   this->allianceHp = 0;
}

list<Country*> Alliance::getAlliance(){
    return this->alliance;
}
void Alliance::setAlliance(list<Country*> alliance){
  
}

void Alliance::addAlly(Country* ally){
  this->alliance.push_back(ally);
}

void Alliance::removeAlly(Country* ally){
  
}

int Alliance::getHp(){
  return 0;
}