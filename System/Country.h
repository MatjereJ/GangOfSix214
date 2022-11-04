//
// Created by JOHANES MATSEBA on 2022/10/19.
//

#ifndef PROJECTASSIGNMENT_COUNTRY_H
#define PROJECTASSIGNMENT_COUNTRY_H
#include <list>
#include "WarParticipant.h"
#include "WarTheatre.h"
#include "BattleState.h"
#include "CountryObserver.h"
#include "Sea.h"
#include "AirSpace.h"
#include "Land.h"
#include <iostream>
#include <cstdlib>
#include "time.h"
#include "CountryBackup.h"
#include <vector>
#include <string>
#include "CountryObserverIterator.h"
#include "WarParticipantIterator.h"
using namespace std;
#include <string>

class BattleState;
class WarTheatre;
class CountryObserverIterator;
class WarParticipantIterator;
class CountryIterator;

class Country {


public:
    Country(std::string, bool);
    Country(BattleState* state);
    Country(Country *C);
    Country();
    BattleState* getBattleState();
    Country* pickOpposingCountry(vector<Country*>);
    virtual void withdraw(){}
    void setBattleState(BattleState* );
    void selectWarTheatre();
    void createWarParticipants();
    void attackOpposingCountry(Country* c); // state.handleChange(this);
    virtual int getHp()=0;
    CountryBackup* createBackup();//Memento
    void reinstateCountry(CountryBackup*);
    virtual WarParticipantIterator* createWarParticipantIterator();//Tseko Iterator
    virtual void addWarParticipant(WarParticipant*);
    virtual std::vector<CountryObserver*> getCountryObservers();
    virtual std::string getName();
    WarTheatre* getWarTheatre();
    virtual bool add(CountryObserver* c);   //Country Observer
    virtual bool remove(CountryObserver* c);
    virtual void notify();
    void InflictDamage(int dmg);  //Country BattleState
    Country *getOpposingC();
    void setHp(int HP);
    vector<WarParticipant *>  getArtillery();
    void addArtillery(WarParticipant *W);
    virtual ~Country();

private:
    State* state;
    BattleState* battlestate;
    WarTheatre* warTheatre;
    std::string cName;
    vector<CountryObserver *> countryObservers;
    Country* OpposingCountry;
    bool win=false;
    bool ocean;

protected:
    int hp=1000;
};


#endif //PROJECTASSIGNMENT_COUNTRY_H
