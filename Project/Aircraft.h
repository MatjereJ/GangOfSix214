#ifndef Aircraft_h
#define Aircraft_h
#include "WarParticipants.h"

using namespace std;

class Aircraft : public WarParticipants
{
private:
    int damage;

public:
    Aircraft(string type) : WarParticipants(type, 25){};
};

#endif