#ifndef OBSERVINGALLIES_H
#define OBSERVINGALLIES_H
#include "BattleState.h"
#include "IndividualCountry.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class ObservingAllies : public CountryObserver{//Concrete Observers
    public:
       /**
        *@brief Current Country variable is initialized and ObservingAllies register as observers to it.
        *@author Areyeng Mphahlele
        *@return void
        *@date  27/10/2022 
     
        */
        ObservingAllies(IndividualCountry* currentCountry);
          /**
        *@brief Iterates through the current country's war participants and checks how much it has of each resource.
                Allies share resources which are running low. 
        *@author Areyeng Mphahlele
        *@return void
        *@date  27/10/2022 
     
        */
        void update();
    private:
    
        /**
         * @brief The current country at war.
         * 
         */
        IndividualCountry* currentCountry;
        /**
         * @brief The combined resources the current country has.
         * 
         */
        vector<WarParticipant*> warParticipants;
};
#endif