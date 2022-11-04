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
    bool found = false;                                   // becomes true if the country is already in the list
    list<Country*>::iterator it = this->alliance.begin();
    while (it != alliance.end()) {
        if (*it == ally) {
            found = true;                               // country already in the list
            break;                                      // exit the loop
        }
        it++;                                           // move to the next position in the list
    }

    if (found) {
        cout << "This country is already in the alliance.\n";     // inform client that country is already in the list
    }
    else {
        this->alliance.push_back(ally);                 // country not in the list. Add it to the list
        cout << "This country was successfully added to the alliance.\n";           // inform user that is has been added to the list
    }
}

void Alliance::removeAlly(Country* ally){
  bool removed = false;
  list<Country *>::iterator it = this->alliance.begin();

  while( it != alliance.end() ){
    if (*it == ally){
      this->alliance.erase(it);
      removed = true;
      break;
    }
    it++;
  }
  if (removed){
    cout << "The country was successfully removed from the alliance.\n";
  }else{
    cout << "The country was not found in the alliance.\n";
  }

}

int Alliance::getHp(){
  return this->allianceHp;
}