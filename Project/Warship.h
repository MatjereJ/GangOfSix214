#ifndef Warship_h
#define Warship_h
#include "WarParticipants.h"

using namespace std;

class Warship : public WarParticipants
{
private:
    int damage;

public:
    Warship(string type) : WarParticipants(type, 30){};
};

#endif