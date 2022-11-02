#ifndef Missile_h
#define Missile_h
#include "WarParticipants.h"

using namespace std;

class Missile : public WarParticipants
{
private:
    int damage = 20;

public:
    Missile(string type) : WarParticipants(type) { damage = 20; };
};

#endif