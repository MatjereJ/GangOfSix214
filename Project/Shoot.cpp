#include "Shoot.h"

void Shoot::LaunchAttack(Country *C)
{
    int totalD = 0;
    vector<WarParticipants *> temp = C->getArtillery();
    vector<WarParticipants *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipants *curr = *it;
        if (curr->getType() == "MachineGunner" || curr->getType() == "RIfleman")
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to shoot at opposing country with its rifles and machine guns" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}