#include "Rifleman.h"

Rifleman::Rifleman(int d, int h) : WarParticipant("FireArmFactory", "Rifleman", d, h)
{
}

Rifleman::Rifleman() : WarParticipant("FireArmFactory", "Rifleman", 6, 20)
{
}

Rifleman *Rifleman::clone()
{
    Rifleman *temp = new Rifleman(this->getDamage(), this->getHP());
    return temp;
}

void Rifleman::doNotting()
{
}