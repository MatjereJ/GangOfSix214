#include "WarParticipants.h"

WarParticipants::WarParticipants(string type)
{
    this->type = type;
}

string WarParticipants::getType()
{
    return type;
}

int WarParticipants::getDamage()
{
    return damage;
}