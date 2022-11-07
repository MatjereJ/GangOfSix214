#include "Shoot.h"

Shoot::Shoot() {}

void Shoot::LaunchAttack(IndividualCountry *C)
{
    int totalD = 0;
    vector<WarParticipant *> temp = C->getArtillery();
    vector<WarParticipant *>::iterator it = temp.begin();
    for (it = temp.begin(); it != temp.end(); it++)
    {
        WarParticipant *curr = *it;
        if (curr->getType() == "Rifleman" || curr->getType() == "MachineGunner")
        {
            totalD = totalD + curr->getDamage();
        }
    }
    cout << "Country is going to shoot at "<< C->getOpposingC()->getName() << " with its rifles and machine guns" << endl;
    C->getOpposingC()->InflictDamage(totalD);
}