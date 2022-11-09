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
#include "ObservingAllies.h"
#include "DetonateExplosives.h"
#include "ExplosiveFactory.h"
#include "Surrender.h"
#include "Medics.h"
#include <vector>

#include <iostream>
using namespace std;

void initializeCountries();
void pickCountry();
void fight();
void selectOpposingCountry();
void getCountryStats(int cNum);
void endGame();
void displayStats();
void AutoSelectCountry();
void AutoOppCountry();
void Autofight();
void tester();                                      //unit testing
template<typename T>
void test(T expected, T actual, string TestName);  //line 570
template<typename T>
void testExpect(T expected,T received,string testName);
template<typename T>
void testLessThan0(T received,string testName);
template<typename T>
void testLessThan(T received1,T received2,string testName);
//tests on lines 105,281,387.


IndividualCountry *country[10];
Alliance *alliances[2];
Medics *MmyCountry;
Medics *MOppCountry;
IndividualCountry *myCountry;
ObservingAllies * ObsmyC;
ObservingAllies * ObsOppC;
IndividualCountry *myOpposingCountry;
int countryNum, countrySize = 10;
CountryBackup* backup;

int main()
{
    int input=2;
    cout << "*************    Game Simulation    ***************\n";
    cout<<" There two options, automatic simulation with no user input or with user input"<<endl;
    cout<<"enter 1 for program without user input"<<endl;
    cout<<"enter 2 for program with user input"<<endl;
    cin>>input;
    initializeCountries();

    if(input == 1)
    {
        cout<<"===================================================="<<endl;
        cout<<"See you chose No user input, sit back and enjoy"<<endl;
        cout<< " "<<endl;
        AutoSelectCountry();
        AutoOppCountry();
        Autofight();
    }
    else
    {
        pickCountry();
        selectOpposingCountry();
    }
    //fight();
    // endGame();
    for(int i=0;i<countrySize;i++){
        delete country[i];
    }

    delete alliances[0];
    delete alliances[1];
    return 0;
}

void initializeCountries()
{
    country[0] = new IndividualCountry("Brazil", 2, false);
    country[1] = new IndividualCountry("Russia", 1, false);
    country[2] = new IndividualCountry("India", 2, true);
    country[3] = new IndividualCountry("China", 1, false);
    country[4] = new IndividualCountry("South Africa", 3, true);
    country[5] = new IndividualCountry("Canada", 2, true);
    country[6] = new IndividualCountry("Germany", 1, false);
    country[7] = new IndividualCountry("France", 2, false);
    country[8] = new IndividualCountry("United States", 1, true);
    country[9] = new IndividualCountry("Australia", 3, true);
/*
    testLessThan(country[0]->getHp(),country[1]->getHp(),"rankingCountriesTest");
    testLessThan(country[2]->getHp(),country[3]->getHp(),"rankingCountriesTest");
    testLessThan(country[4]->getHp(),country[3]->getHp(),"rankingCountriesTest");
    testLessThan(country[4]->getHp(),country[2]->getHp(),"rankingCountriesTest");
    testLessThan(country[5]->getHp(),country[6]->getHp(),"rankingCountriesTest");
    testLessThan(country[5]->getHp(),country[6]->getHp(),"rankingCountriesTest");
    testLessThan(country[7]->getHp(),country[8]->getHp(),"rankingCountriesTest");
    testLessThan(country[4]->getHp(),country[5]->getHp(),"rankingCountriesTest");
    testLessThan(country[2]->getHp(),country[3]->getHp(),"rankingCountriesTest");
    testLessThan(country[9]->getHp(),country[8]->getHp(),"rankingCountriesTest");
    testLessThan(country[8]->getHp(),country[7]->getHp(),"rankingCountriesTest");
    testLessThan(country[2]->getHp(),country[1]->getHp(),"rankingCountriesTest");
*/

//tester();


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
    if(alliances[0]->contains(myCountry) == true)
    {
        vector<Country *> temp = alliances[0]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myCountry)
                myCountry->addAlliance(*it);
        }
    }

    if(alliances[1]->contains(myCountry) == true)
    {
        vector<Country *> temp = alliances[1]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myCountry)
                myCountry->addAlliance(*it);
        }
    }
    ObsmyC = new ObservingAllies(myCountry);
    MmyCountry = new Medics(myCountry);
    cout<<"You have selected "<<myCountry->getName()<<" as your Fighter!"<<endl;
}

void AutoSelectCountry()
{
    srand(time(0));
    myCountry = country[rand()%10];
    ObsmyC = new ObservingAllies(myCountry);
    MmyCountry = new Medics(myCountry);

    cout<<"Country that is selected : "<<myCountry->getName()<<endl;

    if(alliances[0]->contains(myCountry) == true)
    {
        vector<Country *> temp = alliances[0]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myCountry)
                myCountry->addAlliance(*it);
        }
    }

    if(alliances[1]->contains(myCountry) == true)
    {
        vector<Country *> temp = alliances[1]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myCountry)
                myCountry->addAlliance(*it);
        }
    }
}

void fight()
{
    BattleState *States = new BattleState();
    Attack *att = new Attack();
    Defend *def = new Defend();
    Surrender *surr = new Surrender();
    bool fight=false;

    States->Add(att);
    States->Add(def);
    States->Add(surr);

    IndividualCountry *Opps = myCountry->getOpposingC();
    while (Opps->getHp() > 0 && myCountry->getHp() > 0 && fight==false)
    {
        States->handleChange(myCountry);
        displayStats();
        if (Opps->getHp() < 10000 && Opps->getHp() > 0)
            Opps->notify();

        if(myCountry->getHp() > 2000)
        {
            States->handleChange(Opps);
            if (myCountry->getHp() < 8000 && Opps->getHp() > 0)
                myCountry->notify();
            displayStats();
        }
//        if (myCountry->getHp() < 500)
//            myCountry->notify();
        string tempFight;
        if(Opps->getHp() > 0 && myCountry->getHp() > 0 && !myCountry->getLose() || !Opps->getLose())  {
            cout << "Would you like to carry on fighting? (Yes/No)" << endl;
            cin >> tempFight;
            if (tempFight == "No" || tempFight=="no"|| tempFight=="n")
                fight = true;
            else
                fight = false;
        }
    }

    if(Opps->getHp() < 0)
    {
        cout<<Opps->getName()<< " has decided to surrender as it has no more health"<<endl;
        Opps->setLose();
    }

    if(myCountry->getHp() < 0)
    {
        cout<<myCountry->getName()<< " has decided to surrender as it has no more health"<<endl;
        myCountry->setLose();
    }
    /*
    while(!country->surrender()){
        selectOpposingCountry();
    }
*/
    if(fight==false){
        selectOpposingCountry();
        fight=false;
    }else if(myCountry->getHp()>0) {
        cout << myCountry->getName()<<" welldone for Winning the Battle" << endl;
       // selectOpposingCountry();
    }
    else if(myCountry->getOpposingC()->getHp()>0) {
        cout << myCountry->getOpposingC()->getName()<<" welldone for Winning the Battle" << endl;
        // selectOpposingCountry();
    }
    else{
        string temp;
        cout<<"Would you Like to restart the game and give it another try? (Yes/No)"<<endl;
        cin>>temp;
        if(temp=="Yes" ||temp=="yes"||temp=="y" ) {
            myCountry->reinstateCountry(backup);
            selectOpposingCountry();
        }
    }
}

void Autofight()
{
    BattleState *States = new BattleState();
    Attack *att = new Attack();
    Defend *def = new Defend();
    Surrender *surr = new Surrender();
    States->Add(att);
    States->Add(def);
    States->Add(surr);

    IndividualCountry *Opps = myCountry->getOpposingC();
    while (Opps->getHp() > 0 && myCountry->getHp() > 0)
    {

/*
        testLessThan0(Opps->getHp(),"stillAliveTest1");
        testLessThan0(myCountry->getHp(),"stillAliveTest2");
*/

        States->handleChange(myCountry);
        displayStats();
        if (Opps->getHp() < 10000 && Opps->getHp() > 0)
            Opps->notify();

        if (myCountry->getHp() > 2000)
        {
            States->handleChange(Opps);
            if (myCountry->getHp() < 8000 && Opps->getHp() > 0)
                myCountry->notify();
            displayStats();
        }

        if (Opps->getHp() < 0) {
            cout << Opps->getName() << " has decided to surrender as it has no more health" << endl;
        }

        if (myCountry->getHp() < 0) {
            cout << myCountry->getName() << " has decided to surrender as it has no more health" << endl;
        }
    }
}

void selectOpposingCountry()
{
    bool stats=false;
    int displacement = 0;
    int opposingNum=0;
    string countryStat;

    while(stats==false) {
        cout << "Would you like to see a Country's stats (Yes/No)" << endl;
        cin>>countryStat;
        if(countryStat=="Yes" || countryStat=="yes" ||countryStat=="y"){
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
               // stats= true;
            }
        }else if(countryStat=="No" || countryStat=="no"|| countryStat=="n"){
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


/*
        testExpect(country[opposingNum]->getName(),myOpposingCountry->getName(),"pickOppCountryTest");
*/

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

    myCountry->setOpposingC(myOpposingCountry);
    myOpposingCountry->setOpposingC(myCountry);

    cout<<"You have selected "<<myOpposingCountry->getName()<<" as your enemy! Get ready to rumble!"<<endl;

    if(alliances[0]->contains(myOpposingCountry) == true)
    {
        vector<Country *> temp = alliances[0]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myOpposingCountry)
                myOpposingCountry->addAlliance(*it);
        }
    }

    if(alliances[1]->contains(myOpposingCountry) == true)
    {
        vector<Country *> temp = alliances[1]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myOpposingCountry)
                myOpposingCountry->addAlliance(*it);
        }
    }

    ObsOppC = new ObservingAllies(myOpposingCountry);
    backup=new CountryBackup(myCountry->getHp(), myCountry->getWarTheatre(), myCountry->getArtillery(), myCountry->getCountryObservers(), myCountry->getOpposingC(), false);
    fight();
    //myOpposingCountry->add(ObsOppC);
    MOppCountry = new Medics(myOpposingCountry);
}

void AutoOppCountry()
{
    srand(time(0));
    if(alliances[0]->contains(myCountry) == false)
    {
        myOpposingCountry = country[rand()%5];
    }
    else myOpposingCountry = country[rand()%5 + 5];

    cout<<" The opposing Country chosen : "<< myOpposingCountry->getName()<<endl;

    myCountry->setOpposingC(myOpposingCountry);
    myOpposingCountry->setOpposingC(myCountry);

    if(alliances[0]->contains(myOpposingCountry) == true)
    {
        vector<Country *> temp = alliances[0]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myOpposingCountry)
                myOpposingCountry->addAlliance(*it);
        }
    }

    if(alliances[1]->contains(myOpposingCountry) == true)
    {
        vector<Country *> temp = alliances[1]->getAlliance();
        vector<Country *>::iterator it = temp.begin();
        for(it = temp.begin(); it != temp.end(); it++)
        {
            if(*it != myOpposingCountry)
                myOpposingCountry->addAlliance(*it);
        }
    }

    ObsOppC = new ObservingAllies(myOpposingCountry);
    MOppCountry = new Medics(myOpposingCountry);

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

void displayStats(){
    //system("Color 02");
    cout<<"======================================"<<endl;
    cout<<myCountry->getName()<<"'s HP: "<<myCountry->getHp()<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<myOpposingCountry->getName()<<"'s HP: "<<myOpposingCountry->getHp()<<endl;
    cout<<"======================================"<<endl;
    //system("Color 07");
}

void endGame()
{
}

template<typename T>
void testExpect(T expected,T received,string testName){
    if(expected==received)
        cout<<testName<<" passed"<<endl;
    else
        cout<<testName<<" failed"<<endl;
}

template<typename T>
void testLessThan0(T received,string testName){
    if(received>0)
        cout<<testName<<" passed"<<endl;
    else
        cout<<testName<<" failed"<<endl;
}
template<typename T>
void testLessThan(T received1,T received2,string testName){
    if(received1<received2)
        cout<<testName<<" passed"<<endl;
    else
        cout<<testName<<" failed"<<endl;
}


template < typename T>
void test(T expected , T realistic, string TestName){
    if (expected == realistic){
        cout << TestName << " : Test Passed!!" << endl;
    }else{
        cout << TestName << " : Test Failed!!" << endl;
    }
}
void tester(){
    IndividualCountry* countries[4];
    Alliance* allies[2];
    countries[0] = new IndividualCountry("Brazil", 2, false);
    countries[1] = new IndividualCountry("Russia", 1, false);
    countries[2] = new IndividualCountry("India", 2, true);
    countries[3] = new IndividualCountry("South Africa", 1, false);
    allies[0] = new Alliance();
    allies[1] = new Alliance();

    countries[0]->initializeHp();
    test((string)"Brazil", countries[0]->getName(), "NameTest");
    test(countries[0]->getInitialHP(), countries[0]->getHp() , "GetHP-Test");

    allies[0]->addAlly(countries[0]);
    allies[1]->addAlly(countries[2]);

    test(allies[0]->getHp() , countries[0]->getHp(), "AllianceHP-Test");
    test( (bool)false , allies[0]->contains(countries[2]) , "Contains-Test");


    countries[0]->setOpposingC( countries[1]);
    countries[1]->setOpposingC(countries[0]);
    allies[1]->addAlly(countries[1]);
    allies[0]->addAlly(countries[3]);
    countries[1]->setAlliance( allies[1]->getAlliance());
    countries[3]->setAlliance( allies[0]->getAlliance());
    countries[0]->setAlliance(allies[0]->getAlliance());
    countries[2]->setAlliance(allies[1]->getAlliance());
    test( countries[1] , countries[0]->getOpposingC() , "OpposingCountry-Test");
    test( allies[1]->getAlliance() , countries[2]->getAlliance() , "GetAlliance-Test(Alliance side)");
    test( countries[2]->getAlliance() , allies[1]->getAlliance(), "GetAlliance-Test(Country side)");
    test( countries[2]->getAlliance() , allies[0]->getAlliance(), "GetAlliance-Test ( False-Info)");

    CountryObserver* cObs = new ObservingAllies(countries[0]);
    CountryObserver* cOBS1 = new ObservingAllies( countries[1]);

    test( true , countries[0]->add(cObs) , "Add Observer-Test");
    test( false, countries[0]->remove(cOBS1), "Failed-Remove Test");
    test ( true , countries[0]->remove(cObs), "Passed-Remove Test");


    test ( countries[1]->getCountryObservers() , countries[0]->getCountryObservers(), "Check observers-Test(Fail)");


}