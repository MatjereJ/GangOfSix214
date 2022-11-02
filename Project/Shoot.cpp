#include "Shoot.h"

void Shoot::LaunchAttack(Country *C)
{
    int totalD = 0;
    list<WarParticipants *> temp = C->getArtillery();
    list<WarParticipants *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipants *curr = *it;
        if (curr->getDamage() == 6 || curr->getDamage() == 5)
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to shoot at opposing country with its rifles and machine guns" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}