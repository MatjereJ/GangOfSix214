#ifndef Rifle_h
#define Rifle_h
#include "WarParticipants.h"

using namespace std;

class Rifle : public WarParticipants
{
private:
    int damage;

public:
    Rifle(string type) : WarParticipants(type, 5){};
};

#endif