#ifndef PRACTICAL_ASSIGNMENT_3_FIREARMFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_FIREARMFACTORY_H
#include "WarParticipantFactory.h"
#include "WarParticipant.h"
#include "MachineGun.h"
#include "Rifle.h"

class FireArmFactory: public WarParticipantFactory{
public:
    Rifle* createRifle(int damage);
    MachineGun* createMachineGun(int damage);
};


#endif //PRACTICAL_ASSIGNMENT_3_FIREARMFACTORY_H
