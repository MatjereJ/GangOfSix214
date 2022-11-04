#include "Alliance.h"

using namespace std;

Alliance:: Alliance(){
    this->allianceHp = 0;
}

vector<Country*> Alliance::getAlliance(){
    return this->alliance;
}
void Alliance::setAlliance(vector<Country*> alliance){
    this->alliance = alliance;
}

void Alliance::addAlly(Country* ally){
    bool found = false;                                   // becomes true if the country is already in the list
    vector<Country*>::iterator it = this->alliance.begin();
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
    bool removed = false;                               // true if the country was successfully removed
    vector<Country *>::iterator it = this->alliance.begin();       // list iterator

    while( it != alliance.end() ){
        if (*it == ally){
            this->alliance.erase(it);                                // remove it from the list
            removed = true;
            break;
        }
        it++;
    }
    if (removed){
        cout << "The country was successfully removed from the alliance.\n";           // inform user that it has been removed from the list
    }else{
        cout << "The country was not found in the alliance.\n";           // inform user that it was not found in the list
    }

}

int Alliance::getHp(){
    vector<Country *>::iterator it;
    for ( it = this->alliance.begin(); it != this->alliance.end(); it++){
        Country* current = *it;
        allianceHp = allianceHp + current->getHp();
    }

    return this->allianceHp;
}