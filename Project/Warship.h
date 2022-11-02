#ifndef Warship_h
#define Warship_h
#include "WarParticipants.h"

using namespace std;

class Warship : public WarParticipants
{
private:
    int damage = 30;

public:
    Warship(string type) : WarParticipants(type) { damage = 30; };
};

#endif