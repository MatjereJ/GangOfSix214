#ifndef ALLIANCE_H
#define ALLIANCE_H
#include "Country.h"
#include <iostream>
#include <string>
#include <list>

class CountryObservers;
class  Alliance: public Country{
public:
    Alliance();
    void setAlliance(vector<Country*> alliance);
    vector<Country*> getAlliance();
    void addAlly(Country* ally);
    void removeAlly(Country* ally);
    int getHp();
private:
    int allianceHp;
    vector<Country*> alliance;

};
#endif