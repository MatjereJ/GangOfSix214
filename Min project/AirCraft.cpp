#include "AirCraft.h"

AirCraft::AirCraft(int d, int h) : WarParticipant("WarTransportFactory", "AirCraft", d, h)
{
}

AirCraft *AirCraft::clone()
{
    AirCraft *temp = new AirCraft(this->getDamage(), this->getHP());
    return temp;
}

void AirCraft::doNotting()
{
}