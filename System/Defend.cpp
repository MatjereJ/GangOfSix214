#include "Defend.h"
#include <iostream>

using namespace std;
Defend::Defend() {}

void Defend::handleChange(IndividualCountry *C)
{
    IndividualCountry *temp = C->getOpposingC();
    if (C->getHp() < temp->getHp() && C->getHp() > 4000)
    {
        cout << " Country is going to defend its troops and will not attack" << endl;
    }
    else
    {
        //cout << "Moves on" << endl;
        if (successor != nullptr)
        {
            //cout << "Sent out" << endl;
            successor->handleChange(C);
        }
        else
            cout << "No Chain added" << endl;
    }
}