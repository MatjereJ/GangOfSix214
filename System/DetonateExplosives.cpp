#include "DetonateExplosives.h"

void DetonateExplosives::LaunchAttack(IndividualCountry *C)
{
    int totalD = 0;

    IndividualCountry *Opps = C->getOpposingC();
    vector<WarParticipant*> temp = C->getArtillery();
    vector<WarParticipant*>::iterator it = temp.begin();

    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipant *curr = *it;
        if (curr->getDamage() == 12)
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to detonate its bombs to damage the opposing country" << endl;
    Opps->InflictDamage(totalD);
}