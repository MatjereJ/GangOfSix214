#ifndef Aircraft_h
#define Aircraft_h
#include "WarParticipants.h"

using namespace std;

class Aircraft : public WarParticipants
{
private:
    int damage = 25;

public:
    Aircraft(string type) : WarParticipants(type) { damage = 25; };
};

#endif