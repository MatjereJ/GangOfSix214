#ifndef ALLIANCE_H
#define ALLIANCE_H
#include "Country.h"
#include "CountryIterator.h"
#include <iostream>
#include <string>
#include <list>

class CountryObservers;
class  Alliance: public Country{
public:
    Alliance();
    virtual CountryIterator* createCountryIterator();
    void setAlliance(vector<Country*> alliance);
    vector<Country*> getAlliance();
    void addAlly(Country* ally);
    void removeAlly(Country* ally);
    int getHp();
    bool contains(Country* cCountry);

private:
    int allianceHp;
    vector<Country*> alliance;

};
#endif