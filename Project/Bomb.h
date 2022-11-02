#ifndef Bomb_h
#define Bomb_h
#include "WarParticipants.h"

using namespace std;

class Bomb : public WarParticipants
{
private:
    int damage = 12;

public:
    Bomb(string type) : WarParticipants(type) { damage = 12; };
};

#endif