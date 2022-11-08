#ifndef MEDICS_H
#define MEDICS_H
#include "IndividualCountry.h"
#include "CountryObserver.h"
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Medics : public CountryObserver {//Concrete Observer
    public:
        string getName();
        /**
        *@brief Current Country variable is initialized and Medics registers as an observer to it
        *@author Areyeng Mphahlele
        *@return void
        *@date  27/10/2022 
     
        */

        Medics(IndividualCountry* currentCountry);
        /**
        *@brief Iterates through current country's war participants vector searching for an injured 
                soldier(a soldier with an HP less than a safe amount) and heals them (increases HP) if found.
        *@author Areyeng Mphahlele
        *@return void
        *@date  27/10/2022 
     
        */
        void  update();
    private:
        /**
         * @brief The maximum amount of times a medic can heal an injured soldier. 
         * 
         */
        int maxHeal=0;
        /**
         * @brief The amount of HP which the Medics can heal an injured soldier with. 
         * 
         */
        int healingHp=250;
        /**
         * @brief The current country to update when soldiers is injured/is running low on resources
         * 
         */
        IndividualCountry* currentCountry;

        string name;
        /**
         * @brief The current country resources 
         * 
         */
        vector<WarParticipant*> warParticipants;
};
#endif