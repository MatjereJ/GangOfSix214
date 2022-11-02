#include "DetonateExplosives.h"

void DetonateExplosives::LaunchAttack(Country *C)
{
    int totalD = 0;
    list<WarParticipants *> temp = C->getArtillery();
    list<WarParticipants *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipants *curr = *it;
        if (curr->getDamage() == 12)
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to detonate its bombs to damage the opposing country" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}