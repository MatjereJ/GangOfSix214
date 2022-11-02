#ifndef MachineGun_h
#define MachineGun_h
#include "WarParticipants.h"

using namespace std;

class MachineGun : public WarParticipants
{
private:
    int damage;

public:
    MachineGun(string type) : WarParticipants(type, 6){};
};

#endif