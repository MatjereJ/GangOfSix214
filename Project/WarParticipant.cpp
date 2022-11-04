#include "WarParticipants.h"

WarParticipants::WarParticipants(string type, int dmg)
{
    this->type = type;
    damage = dmg;
}

string WarParticipants::getType()
{
    return type;
}

int WarParticipants::getDamage()
{
    return damage;
}