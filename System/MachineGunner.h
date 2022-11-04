#ifndef PRACTICAL_ASSIGNMENT_3_MACHINEGUNNER_H
#define PRACTICAL_ASSIGNMENT_3_MACHINEGUNNER_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class MachineGunner: public WarParticipant {
private:
    int damage;
public:
    MachineGunner(int damage);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_MACHINEGUNNER_H
