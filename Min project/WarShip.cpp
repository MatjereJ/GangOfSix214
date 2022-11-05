#include "WarShip.h"

WarShip::WarShip(int d, int h) : WarParticipant("WarTransportFactory", "WarShip", d, h)
{
}

WarShip *WarShip::clone()
{
    WarShip *temp = new WarShip(this->getDamage(), this->getHP());
    return temp;
}

void WarShip::doNotting()
{
}