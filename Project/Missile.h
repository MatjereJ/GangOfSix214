#ifndef Missile_h
#define Missile_h
#include "WarParticipants.h"

using namespace std;

class Missile : public WarParticipants
{
private:
    int damage;

public:
    Missile(string type) : WarParticipants(type, 20){};
};

#endif