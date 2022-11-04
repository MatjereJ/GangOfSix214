#include "FireMissile.h"

void FireMissile::LaunchAttack(Country *C)
{
    int totalD = 0;
    list<WarParticipants *> temp = C->getArtillery();
    list<WarParticipants *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipants *curr = *it;
        if (curr->getDamage() == 20 || curr->getDamage() == 25 || curr->getDamage() == 30)
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to fire msisile at opposing country with its Missiles,Airships and and Warcrafts" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}