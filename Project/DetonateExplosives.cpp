#include "DetonateExplosives.h"

void DetonateExplosives::LaunchAttack(Country *C)
{
    int totalD = 0;
    Country *Opps = C->getOpposingC();
    vector<WarParticipants *> temp = C->getArtillery();
    vector<WarParticipants *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipants *curr = *it;
        if (curr->getType() == "Bomb")
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to detonate its bombs to damage the opposing country" << endl;
    Opps->InflictDamage(totalD);
}