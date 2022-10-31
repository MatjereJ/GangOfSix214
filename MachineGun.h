#ifndef PRACTICAL_ASSIGNMENT_3_MACHINEGUN_H
#define PRACTICAL_ASSIGNMENT_3_MACHINEGUN_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class MachineGun: public WarParticipant {
private:
    int damage;
public:
    MachineGun(int damage);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_MACHINEGUN_H
