#include "Bomb.h"

Bomb::Bomb(int d, int h) : WarParticipant("ExplosiveFactory", "Bomb", d, h)
{
}

Bomb *Bomb::clone()
{
    Bomb *temp = new Bomb(this->getDamage(), this->getHP());
    return temp;
}

void Bomb::doNotting()
{
}