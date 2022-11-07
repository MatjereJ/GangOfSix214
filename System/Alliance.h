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
     /**
    *@brief Returns the combined resources a country has at its disposal.
    *@author Areyeng Mphahlele
    *@return void
    *@date  29/10/2022

    */
   // vector<WarParticipant*> getWarParticipants();
     /**
    *@brief returns name of current country
    *@author Areyeng Mphahlele 
    *@return name of current country
    *@date  27/10/2022 
    */
      //  string getName();

private:
    int allianceHp;
    /**
    * @brief The current country's name.
    * 
    */
     string name;
    vector<Country*> alliance;
    vector<WarParticipant *> warParticipants;
};
#endif