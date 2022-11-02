#ifndef Rifle_h
#define Rifle_h
#include "WarParticipants.h"

using namespace std;

class Rifle : public WarParticipants
{
private:
    int damage = 5;

public:
    Rifle(string type) : WarParticipants(type) { damage = 5; };
};

#endif