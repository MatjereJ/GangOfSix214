#include "Missile.h"

Missile::Missile(int d, int h) : WarParticipant("FireArmFactory", "Missile", d, h)
{
}

Missile *Missile::clone()
{
    Missile *temp = new Missile(this->getDamage(), this->getHP());
    return temp;
}
