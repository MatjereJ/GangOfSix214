#include "ExplosiveFactory.h"
#include "Bomb.h"
#include "Missile.h"

WarParticipant *ExplosiveFactory::createBomb(int damage)
{
    Bomb *temp = new Bomb(damage, 40);
    return temp;
}

WarParticipant *ExplosiveFactory::createMissile(int damage)
{
    Missile *temp = new Missile(damage, 50);
    return temp;
}

void Missile::doNotting()
{
}