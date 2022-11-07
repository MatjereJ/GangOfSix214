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
#include "CountryObserverIterator.h"
#include "WarParticipantIterator.h"
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
        bool add(CountryObserver* c)override;
        /**
        *@brief Deregisters received obsever to current country.
        *@author Areyeng Mphahlele
        *@param c Country observer to deregister from current country.
        *@return true or false
        *@date  27/10/2022 
     
        */
        bool remove(CountryObserver* c)override;
        /**
        *@brief Notifies the Medics and ObservingAllies during war about any changes in resource availability and soldier health.
        *@author Areyeng Mphahlele
        *@return true or false
        *@date  27/10/2022 
     
        */
        void notify()override;
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
        int getWeaponHP() ;
        /**
        *@brief Add all of the weapon HP inside current's country's war participant vector and returns it as a integer value.
        *@author Areyeng Mphahlele 
        *@return amount of soldiers available
        *@date  27/10/2022 
     
        */
        int getSoldierHP();

        void setWeaponHP(int);
        void setSoldierHP(int);
    IndividualCountry* pickOpposingCountry(vector<IndividualCountry*>);
    void setOpposingC(IndividualCountry *C);
    virtual void withdraw(){};
    void selectWarTheatre();
    void createWarParticipants();
    void attackOpposingCountry(IndividualCountry* c); // state.handleChange(this);
    CountryBackup* createBackup();//Memento
    void reinstateCountry(CountryBackup*);
    virtual WarParticipantIterator* createWarParticipantIterator();//Tseko Iterator
    virtual void addWarParticipant(WarParticipant*);
    virtual std::vector<CountryObserver*> getCountryObservers();
    WarTheatre* getWarTheatre( );
    void InflictDamage(int dmg);  //Country BattleState
    IndividualCountry *getOpposingC();
    void setHp(int HP);
    vector<WarParticipant *>  getArtillery();
    State* getState();
    void setWarParticipants(vector<WarParticipant*>);
    void initializeHp();
    int getInitialHP();
    /**
    *@brief Add the amount of transport inside current's country's  war participant vector and returns it as a integer value.
    *@author Areyeng Mphahlele
    *@return amount of transport available
    *@date  27/10/2022

    */
    int getTransport();
    /**
    *@brief Gets total of all HP each resource has and returns it as an integer value.
    *@author Areyeng Mphahlele
    *@return void
    *@date  29/10/2022

    */
    int getHp() override;
    /**
    *@brief Sets the parameter alliance as the current country's alliance.
    *@author Areyeng Mphahlele
    *@param alliance a vector of individual countries which are set to the current country's alliance variable.
    *@return void
    *@date  29/10/2022

    */
    void setAlliance(vector<Country*> alliance);
    /**
    *@brief Returns the current country's alliance.
    *@author Areyeng Mphahlele
    *@return the current alliance assisting the country at war.
    *@date  29/10/2022

    */
    vector<Country*> getAlliance();
    /**
    *@brief Returns the combined resources the current country has at its disposal.
    *@author Areyeng Mphahlele
    *@return void
    *@date  29/10/2022

    */
    void setLose();
    virtual ~IndividualCountry();

    private:
    int weaponHP;
    int soldierHP;
    int size;
    int initialHP;
    State* state;
    WarTheatre* warTheatre;
    std::string cName;
    IndividualCountry* OpposingCountry;
    bool lose=false;
    int hp=1000;

         /**
         * @brief A vector containing all registered war observers.
         * 
         */
        vector<CountryObserver*> countryObservers;
         /**
         * @brief The current country's alliance.
         * 
         */
        vector<Country*> alliance;
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