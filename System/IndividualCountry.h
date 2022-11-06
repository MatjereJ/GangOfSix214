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
       
        IndividualCountry();
    
        IndividualCountry(string name, int level, bool sea);
        /**
        *@brief Registers received observer to current country.
        *@author Areyeng Mphahlele
        *@param c Country observer to register to current country.
        *@return bool
        *@date  27/10/2022 
     
        */
        bool add(CountryObserver* c);
        /**
        *@brief Deregisters received obsever to current country.
        *@author Areyeng Mphahlele
        *@param c Country observer to deregister from current country.
        *@return true or false
        *@date  27/10/2022 
     
        */
        bool remove(CountryObserver* c);
        /**
        *@brief Notifies the Medics and ObservingAllies during war about any changes in resource availability and soldier health.
        *@author Areyeng Mphahlele
        *@return true or false
        *@date  27/10/2022 
     
        */
        void notify();
        /**
        *@brief returns name of current country
        *@author Areyeng Mphahlele 
        *@return name of current country
        *@date  27/10/2022 
     
        */
        string getName();
        /**
        *@brief Add all of the weapon HP inside the war participant vector and returns it as a integer value.
        *@author Areyeng Mphahlele 
        *@return amount of weapons available
        *@date  27/10/2022 
     
        */
        int getWeaponHP();
        /**
        *@brief Add all of the weapon HP inside current's country's war participant vector and returns it as a integer value.
        *@author Areyeng Mphahlele 
        *@return amount of soldiers available
        *@date  27/10/2022 
     
        */
        int getSoldierHP();
        /**
        *@brief Add the amount of transport inside current's country's war participant vector and returns it as a integer value.
        *@author Areyeng Mphahlele 
        *@return amount of transport available
        *@date  27/10/2022 
     
        */
        /**
        *@brief Add the amount of transport inside current's country's  war participant vector and returns it as a integer value.
        *@author Areyeng Mphahlele 
        *@return amount of transport available
        *@date  27/10/2022 
     
        */
        int getTransport();
         /**
        *@brief Calls current's country notify function which updates all observers of the war.
        *@author Areyeng Mphahlele 
        *@return void
        *@date  27/10/2022 
     
        */
        void observeHp();
        /**
        *@brief Gets total of all HP each resource has and returns it as an integer value.
        *@author Areyeng Mphahlele 
        *@return void
        *@date  29/10/2022 
     
        */
        int getHP();
        /**
        *@brief Sets the parameter alliance as the current country's alliance.
        *@author Areyeng Mphahlele 
        *@param alliance a vector of individual countries which are set to the current country's alliance variable.
        *@return void
        *@date  29/10/2022 
     
        */
        void setAlliance(vector<IndividualCountry*> alliance);
        /**
        *@brief Returns the current country's alliance.
        *@author Areyeng Mphahlele 
        *@return the current alliance assisting the country at war.
        *@date  29/10/2022 
     
        */
        vector<IndividualCountry*> getAlliance();
        /**
        *@brief Returns the combined resources the current country has at its disposal.
        *@author Areyeng Mphahlele 
        *@return void
        *@date  29/10/2022 
     
        */
        vector<WarParticipant*> getWarParticipants();
    private:
         /**
         * @brief A vector containing all registered war observers.
         * 
         */
        vector<CountryObserver*> countryObservers;
         /**
         * @brief The current country's alliance.
         * 
         */
        vector<IndividualCountry*> alliance;
         /**
         * @brief The current country's combined war participants.
         * 
         */
        vector<WarParticipant*> wP;
         /**
         * @brief The current country's name.
         * 
         */
        string name;
         /**
         * @brief The current country decision to fight on sea or not.
         * 
         */
        bool ocean;
};
#endif