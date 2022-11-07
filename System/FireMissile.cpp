#include "FireMissile.h"

FireMissile::FireMissile() {}

void FireMissile::LaunchAttack(IndividualCountry *C)
{
    int totalD = 0;

    vector<WarParticipant*> temp = C->getArtillery();
    vector<WarParticipant*>::iterator it = temp.begin();

    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipant *curr = *it;
        if (curr->getType() == "Missile" || curr->getType() == "Warship" || curr->getType() == "AirCraft")
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to fire missile at " <<  C->getOpposingC()->getName() << " with its Missiles,Airships and and Warcrafts" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}