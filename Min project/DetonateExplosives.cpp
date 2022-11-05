#include "DetonateExplosives.h"

void DetonateExplosives::LaunchAttack(Country *C)
{
    int totalD = 0;
    Country *Opps = C->getOpposingC();
    vector<WarParticipant *> temp = C->getArtillery();
    vector<WarParticipant *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipant *curr = *it;
        if (curr->getType() == "Bomb")
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to detonate its bombs to damage the opposing country" << endl;
    Opps->InflictDamage(totalD);
}