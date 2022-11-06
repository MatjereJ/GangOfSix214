#ifndef INDIVIDUALCOUNTRY_H
#define INDIVIDUALCOUNTRY_H
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>
#include "CountryObserverIterator.h"
#include "WarParticipantIterator.h"
using namespace std;

class IndividualCountry: public Country {//ConcreteSubject
    public:
        IndividualCountry();
    IndividualCountry(std::string);
    IndividualCountry(string name,int weaponHP,int soldierHP,int);
    bool add(CountryObserver* c) override;
    bool remove(CountryObserver* c) override;
    void notify() override;
        int getHp() override;
        int getWeaponHP();
        int getSoldierHP();
        void setWeaponHP(int);
        void setSoldierHP(int);
    IndividualCountry* pickOpposingCountry(vector<IndividualCountry*>);
    virtual void withdraw(){};
    void selectWarTheatre();
    void createWarParticipants();
    void attackOpposingCountry(IndividualCountry* c); // state.handleChange(this);
    CountryBackup* createBackup();//Memento
    void reinstateCountry(CountryBackup*);
    virtual WarParticipantIterator* createWarParticipantIterator();//Tseko Iterator
    virtual void addWarParticipant(WarParticipant*);
    virtual std::vector<CountryObserver*> getCountryObservers();
    virtual std::string getName();
    WarTheatre* getWarTheatre( );
    void InflictDamage(int dmg);  //Country BattleState
    IndividualCountry *getOpposingC();
    void setHp(int HP);
    vector<WarParticipant *>  getArtillery();
    State* getState();
    virtual ~IndividualCountry();

    private:
    vector<CountryObserver*> countryObservers;
    vector<IndividualCountry*> alliance;
    int weaponHP;
    int soldierHP;
    int size;
    string name;
    State* state;
    WarTheatre* warTheatre;
    vector<WarParticipant *> warParticipants;
    std::string cName;
    IndividualCountry* OpposingCountry;
    bool win=false;
    int hp=1000;
        
};
#endif