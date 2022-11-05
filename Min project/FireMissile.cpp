#include "FireMissile.h"

void FireMissile::LaunchAttack(Country *C)
{
    int totalD = 0;
    vector<WarParticipant *> temp = C->getArtillery();
    vector<WarParticipant *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipant *curr = *it;
        if (curr->getType() == "Missile" || curr->getType() == "WarShip" || curr->getType() == "Aircraft")
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to fire msisile at opposing country with its Missiles,Airships and and Warcrafts" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}