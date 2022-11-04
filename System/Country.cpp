//
// Created by JOHANES MATSEBA on 2022/10/19.
//

#include "Country.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Country(string name, bool sea){
    cName=name;
    ocean=sea;
}

Country::Country(BattleState* state){
    this->battlestate=state;
}

Country::Country() {}

void Country::selectWarTheatre() {
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

Country* Country::pickOpposingCountry(vector<Country*> enemies) {

    srand(time(0));
    int random=rand()% enemies.size();
    OpposingCountry=enemies.at(random);

    return OpposingCountry;

}

void Country::createWarParticipants() {


}

BattleState* Country::getBattleState() {
    return battlestate;
}

void Country::setBattleState(BattleState *s) {
    battlestate=s;
}

int Country::getHp() {
    return hp;
}

void Country::attackOpposingCountry(Country *opp) {
    battlestate->handleChange(this);
}


CountryBackup* Country::createBackup() {
    return new CountryBackup(hp,battlestate,warTheatre,warParticipants,countryObservers,OpposingCountry,win);
}



void Country::reinstateCountry(CountryBackup *backup) {
    State* s=backup->state;
    hp=s->getHP();
    battlestate=s->getBattleState();
    warTheatre=s->getWarTheatre();
    warParticipants=s->getWarParticipants();
    countryObservers=s->getCountryObservers();
    OpposingCountry=s->getOppCountry();
    win=s->getW();
}


//Mokoena
Country::Country(std::string name)
{
	cName = name;
}


Country::~Country()
{
	warParticipants.clear();
	std::cout<<"Parent of "<<cName <<" deleted.\n";
}



void Country::addWarParticipant(WarParticipant* warPtc)
{
	warParticipants.push_back(warPtc);
}



std::vector<CountryObserver*> Country::getCountryObservers()
{
	return countryObservers;
}




WarTheatre* Country::getWarTheatre()
{
	return warTheatre;
}



WarParticipantIterator* Country::createWarParticipantIterator()
{
	return new WarParticipantIterator(this);
}



std::string Country::getName()
{
	return cName;
}

//Areyeng Observer

bool Country::add(CountryObserver* assistance){
    countryObservers.push_back(assistance);
    return true;
}
bool Country::remove(CountryObserver* assistance){
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
void Country::notify(){
    vector<CountryObserver*>::iterator it = countryObservers.begin();
    for (it = countryObservers.begin(); it != countryObservers.end(); ++it){
        (*it)->update();
    }
}

vector<WarParticipant*> Country::getArtillery() {
    return warParticipants;
}