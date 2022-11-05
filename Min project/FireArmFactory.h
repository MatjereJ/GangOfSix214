#ifndef PRACTICAL_ASSIGNMENT_3_FIREARMFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_FIREARMFACTORY_H
#include "WarParticipantFactory.h"
#include "WarParticipant.h"
#include "MachineGunner.h"
#include "MachineGunner.cpp"
#include "Rifleman.h"
#include "Rifleman.cpp"

class FireArmFactory : public WarParticipantFactory
{
public:
    Rifleman *createRifle(int damage);
    MachineGunner *createMachineGun(int damage);
};

#endif // PRACTICAL_ASSIGNMENT_3_FIREARMFACTORY_H
