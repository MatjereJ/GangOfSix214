#ifndef INDIVIDUALCOUNTRY_H
#define INDIVIDUALCOUNTRY_H
#include "Country.h"
#include "CountryObserver.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CountryObservers;
class IndividualCountry : public Country
{
public:
    IndividualCountry(string n);
    IndividualCountry(string c, int level, bool sea);
    bool add(CountryObserver *c);
    bool remove(CountryObserver *c);
    void notify();
    string getName();
    int getWeaponHP();
    int getSoldierHP();
    int getTransport();
    int getSize();
    void checkHp();
    int getInitialHP();
    void setInitial();
    void setAlliance(vector<IndividualCountry *> alliance);
    vector<IndividualCountry *> getAlliance();

private:
    vector<CountryObserver *> countryObservers;
    vector<IndividualCountry *> alliance;
    int weaponHP;
    int soldierHP;
    int transport;
    int currWeaponHP;
    int initialHP;
    int classofC;
    string name;
};
#endif