#ifndef INDIVIDUALCOUNTRY_H
#define  INDIVIDUALCOUNTRY_H
#include "Country.h"
#include "CountryObserver.h"
#include "SoldierFactory.h"
#include "ExplosiveFactory.h"
#include "WarTransportFactory.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CountryObservers;
class  IndividualCountry: public Country{
     public:
        IndividualCountry(string n);
        IndividualCountry();
        IndividualCountry(string name,int weaponHP,int soldiierHP,int transport);
        IndividualCountry(string name, int level, bool sea);
        bool add(CountryObserver* c);
        bool remove(CountryObserver* c);
        void notify();
        string getName();
        int getWeaponHP();
        int getSoldierHP();
        int getTransport();
        int getSize();
        void checkHp();
        int getInitialHP();
        void setInitial();
        void setAlliance(vector<IndividualCountry*> alliance);
        vector<IndividualCountry*> getAlliance();
        vector<WarParticipant*> getWarParticipants();
    private:
        vector<CountryObserver*> countryObservers;
        vector<IndividualCountry*> alliance;
        vector<WarParticipant*> wP;
        int weaponHP;
        int soldierHP;
        int transport;
        int currWeaponHP;
        int initialHP;
        string name;
        int size;
        bool ocean;
};
#endif