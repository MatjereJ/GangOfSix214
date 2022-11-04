#ifndef INDIVIDUALCOUNTRY_H
#define INDIVIDUALCOUNTRY_H
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IndividualCountry: Country {//ConcreteSubject
    public:
        IndividualCountry();
        IndividualCountry(string name, int level, bool sea)
        bool add(CountryObserver* c);
        bool remove(CountryObserver* c);
        void notify();
        int getHp() override;
        int getWeaponHP();
        int getSoldierHP();
        int getTransport();
        void setWeaponHP(int);
        void setSoldierHP(int);
        void setTransport(int);
        vector<WarParticipant*> getWarParticipants();
    private:
        vector<CountryObserver*> countryObservers;
        vector<IndividualCountry*> alliance;
        vector<WarParticipant *> warParticipants;
        int weaponHP;
        int soldierHP;
        int transport;
        int size;
        string name;
        
};
#endif