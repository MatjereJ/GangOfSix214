#ifndef MachineGun_h
#define MachineGun_h
#include "WarParticipants.h"

using namespace std;

class MachineGun : public WarParticipants
{
private:
    int damage = 6;

public:
    MachineGun(string type) : WarParticipants(type) { damage = 6; };
};

#endif