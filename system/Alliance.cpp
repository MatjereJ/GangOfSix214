#include "Alliance.h"

using namespace std;

Alliance:: Alliance(){ 
   this->allianceHp = 0;
}

list<Country*> Alliance::getAlliance(){
    return this->alliance;
}
void Alliance::setAlliance(list<Country*> alliance){
  this->alliance = alliance;
}

void Alliance::addAlly(Country* ally){
  this->alliance.push_back(ally);
}

void Alliance::removeAlly(Country* ally){
  this->alliance.erase(ally);
}

int Alliance::getHp(){
  return this->allianceHp;
}