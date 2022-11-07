#include "Alliance.h"
#include "IndividualCountry.h"
#include "WarParticipant.h"
#include "AirCraft.h"
#include "AirSpace.h"
#include "Attack.h"
#include "AttackStrategy.h"
#include "BattleState.h"
#include "Bomb.h"
#include "Context.h"
#include "Country.h"
#include "CountryBackup.h"
#include "CountryMemory.h"
#include "CountryObserver.h"
#include "CountryObserverIterator.h"
#include "Defend.h"
#include "DetonateExplosives.h"
#include "ExplosiveFactory.h"
#include "Surrender.h"

#include <iostream>
using namespace std;

void initializeCountries();
void pickCountry();
void fight();
void selectOpposingCountry();
void getCountryStats(int cNum);
void endGame();

IndividualCountry *country[10];
Alliance *alliances[2];
IndividualCountry *myCountry;
IndividualCountry *myOpposingCountry;
int countryNum, countrySize = 10;

int main()
{
    cout << "*************    Game Simulation    ***************\n";
    initializeCountries();

    IndividualCountry *warringCountries[2];
    warringCountries[0] = country[0];
    warringCountries[1] = country[5];
    int i = 0;
//    while (true)
//    {
//        if (warringCountries[i % 2]->getHp() > 0)
//        {
//
//            cout << warringCountries[i % 2]->getHp() << endl;
//            warringCountries[i % 2]->attackOpposingCountry(warringCountries[i % 2 + 1]);
//            i++;
//        }
//        else
//        {
//            warringCountries[i % 2]->setLose();
//            cout << warringCountries[i % 2]->getName() << " has lost the War with all of it's soldiers Dead" << endl;
//            break;
//        }
//    }

    pickCountry();
    selectOpposingCountry();
    fight();
    // endGame();
    delete alliances[0];
    delete alliances[1];
    return 0;
}

void initializeCountries()
{

    country[0] = new IndividualCountry("Brazil", 2, false);
    country[1] = new IndividualCountry("Russia", 1, false);
    country[2] = new IndividualCountry("India", 2, false);
    country[3] = new IndividualCountry("China", 1, false);
    country[4] = new IndividualCountry("South Africa", 3, false);
    country[5] = new IndividualCountry("Canada", 2, false);
    country[6] = new IndividualCountry("Germany", 1, false);
    country[7] = new IndividualCountry("France", 2, false);
    country[8] = new IndividualCountry("United States", 1, false);
    country[9] = new IndividualCountry("Australia", 3, false);
    alliances[0] = new Alliance();
    alliances[0]->addAlly(country[0]);
    alliances[0]->addAlly(country[1]);
    alliances[0]->addAlly(country[2]);
    alliances[0]->addAlly(country[3]);
    alliances[0]->addAlly(country[4]);
    alliances[1] = new Alliance();
    alliances[1]->addAlly(country[5]);
    alliances[1]->addAlly(country[6]);
    alliances[1]->addAlly(country[7]);
    alliances[1]->addAlly(country[8]);
}

void pickCountry()
{
    cout << "Select a Country from the list below by entering it's number" << endl;
    for (int i = 0; i < countrySize; i++)
    {
        cout << i << ": " << country[i]->getName() << endl;
    }
    cin >> countryNum;
    myCountry = country[countryNum];
    cout<<"You have selected "<<myCountry->getName()<<" as your Fighter!"<<endl;
}

void fight()
{
    BattleState *States = new BattleState();
    Attack *att = new Attack();
    Defend *def = new Defend();
    Surrender *surr = new Surrender();

    States->Add(att);
    States->Add(def);
    States->Add(surr);
    cout<<"Its coming"<<endl;
    IndividualCountry *Opps = myCountry->getOpposingC();
    while (Opps->getHp() > 0 && myCountry->getHp() > 0)
    {
        cout<<"Inside"<<endl;
        States->handleChange(myCountry);
//        if (Opps->getHp() < 500)
//            Opps->notify();

        States->handleChange(Opps);
//        if (myCountry->getHp() < 500)
//            myCountry->notify();
    }

    /*
    while(!country->surrender()){
        selectOpposingCountry();
    }
*/
}
/*
 void selectOpposingCountry(){
    bool stats=false;
    while(stats=false) {
        cout << "Would you like to see a Country's stats (Yes/No)" << endl;
        cin>>countryStat;
        if(countryStat=="Yes"){
            cout<<"Select a Country Number"<<endl;
            for(int i=0; i<countrySize; i++) {
                cout<<i<<": "<<country[i]<<endl;
            }
        }else if(countryStat=="No"){
            stats=true;
        }
    }
    cout<<"Now you've had a chance to look at the countries, Choose a Country to fight"<<endl;
    for(int i=0; i<countrySize; i++) {
        if(i!=countryNum)
            cout<<i<<": "<<country[i]<<endl;
    }
}*/

//     }
// */
// }

void selectOpposingCountry()
{
    bool stats=false;
    int displacement = 0;
    int opposingNum=0;
    string countryStat;

    while(stats==false) {
        cout << "Would you like to see a Country's stats (Yes/No)" << endl;
        cin>>countryStat;
        if(countryStat=="Yes"){
            cout<<"Select a Country Number"<<endl;
            if (alliances[0]->contains(myCountry))
            {
                for (int i = 0; i < countrySize; i++)
                {
                    if ( alliances[0]->contains(country[i]) ){
                        displacement++;
                    }
                    else{
                        cout << (i) << ": " << country[i]->getName() << endl;
                    }

                }
                cin >> opposingNum;
                getCountryStats(opposingNum);
            }
            else if (alliances[1]->contains(myCountry))
            {
                for (int i = 0; i < countrySize; i++)
                {
                    if ( alliances[1]->contains(country[i]) ){
                        displacement++;
                    }
                    else{
                        cout << (i) << ": " << country[i]->getName() << endl;
                    }

                }
                cin >> opposingNum;
                getCountryStats(opposingNum);
            }else{
                for ( int i=0; i< countrySize; i++ ){
                    if ( myCountry == country[i]){
                        displacement++;
                    }else{
                        cout << (i) << ": " << country[i]->getName() << endl;
                    }
                }
                cin >> opposingNum;
                getCountryStats(opposingNum);
            }
        }else if(countryStat=="No"){
            stats=true;
        }
    }
    opposingNum=0;
    displacement = 0;
    cout << "Select the opposing country from the list below by entering its number." << endl;
    if (alliances[0]->contains(myCountry))
    {
        for (int i = 0; i < countrySize; i++)
        {
            if ( alliances[0]->contains(country[i]) ){
                displacement++;
            }
            else{
                cout << (i) << ": " << country[i]->getName() << endl;
            }

        }
        cin >> opposingNum;
        myOpposingCountry = country[opposingNum];

    }
    else if (alliances[1]->contains(myCountry))
    {
        for (int i = 0; i < countrySize; i++)
        {
            if ( alliances[1]->contains(country[i]) ){
                displacement++;
            }
            else{
                cout << (i) << ": " << country[i]->getName() << endl;
            }

        }
        cin >> opposingNum;
        myOpposingCountry = country[opposingNum];
    }else{
        for ( int i=0; i< countrySize; i++ ){
            if ( myCountry == country[i]){
                displacement++;
            }else{
                cout << (i) << ": " << country[i]->getName() << endl;
            }
        }
        cin >> opposingNum;
        myOpposingCountry = country[opposingNum];
    }

    cout<<"You have selected "<<myOpposingCountry->getName()<<" as your enemy! Get ready to rumble!"<<endl;
}
/*
 void selectOpposingCountry(){
    bool stats=false;
    while(stats=false) {
        cout << "Would you like to see a Country's stats (Yes/No)" << endl;
        cin>>countryStat;
        if(countryStat=="Yes"){
            cout<<"Select a Country Number"<<endl;
            for(int i=0; i<countrySize; i++) {
                cout<<i<<": "<<country[i]<<endl;
            }
        }else if(countryStat=="No"){
            stats=true;
        }
    }
    cout<<"Now you've had a chance to look at the countries, Choose a Country to fight"<<endl;
    for(int i=0; i<countrySize; i++) {
        if(i!=countryNum)
            cout<<i<<": "<<country[i]<<endl;
    }
}*/

void getCountryStats(int cNum)
{
    cout<<"---------------------------------------"<<endl;
    cout<<country[cNum]->getName()<<endl;
    cout<<country[cNum]->getHp()<<endl;
    cout<<"---------------------------------------"<<endl;
}

void endGame()
{
}