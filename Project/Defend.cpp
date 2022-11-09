#include "Defend.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void Defend::handleChange(Country *C)
{
    srand(time(0));
    Country *temp = C->getOpposingC();
    int Chanceindex = rand() % 11;
    if (C->getHp() < temp->getHp() && C->getHp() > 300)
    {
        if (Chanceindex <= 4)
        {
            this->TakeChance(C);
        }
        else
            cout << " Country is going to defend its troops and will not attack" << endl;
    }
    else
    {
        if (successor != nullptr)
        {
            successor->handleChange(C);
        }
        else
            cout << "No Chain added" << endl;
    }
}

void Defend::TakeChance(Country *C)
{
    cout << "Country is taking a chance and is gonna attack the opposing country" << endl;
    int totalD = 0;
    Country *Opps = C->getOpposingC();
    vector<WarParticipants *> temp = C->getArtillery();
    vector<WarParticipants *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipants *curr = *it;
        totalD = totalD + curr->getDamage();
    }
    double increase = totalD * 1.8;
    totalD = int(increase);
    Opps->InflictDamage(totalD);
}