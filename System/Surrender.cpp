#include "Surrender.h"
#include <iostream>

using namespace std;

void Surrender::handleChange(IndividualCountry *C)
{
    IndividualCountry *temp = C->getOpposingC();
    if (C->getHp() < temp->getHp() && C->getHp() <= 300)
    {
        cout << "Country has decided to surrender, Its a Long Day" << endl;
    }
    else
    {
        if (successor != nullptr)
            successor->handleChange(C);
        else
            cout << "No Chain added" << endl;
    }
}