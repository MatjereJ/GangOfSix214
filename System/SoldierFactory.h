#ifndef PRACTICAL_ASSIGNMENT_3_SOLDIERFACTORY_H
#define PRACTICAL_ASSIGNMENT_3_SOLDIERFACTORY_H
#include "WarParticipantFactory.h"
#include "Soldier.h"


class SoldierFactory: public WarParticipantFactory {
public
    SoldierFactory();
    Soldier* createRifleman(int HP);
    Soldier* createMachineGunner(int HP);
};

#endif //PRACTICAL_ASSIGNMENT_3_SOLDIERFACTORY_H
