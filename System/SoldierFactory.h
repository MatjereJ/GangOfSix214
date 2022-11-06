#ifndef PRACTICAL_ASSIGNMENT_3_SOLDIERFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_SOLDIERFACTORY_H
#include "WarParticipantFactory.h"
#include "MachineGunner.h"
#include "Rifleman.h"


class SoldierFactory: public WarParticipantFactory {
public:
    SoldierFactory();
    Rifleman* createRifleman(int HP,int);
    MachineGunner* createMachineGunner(int HP,int);
};

#endif //PRACTICAL_ASSIGNMENT_3_SOLDIERFACTORY_H
