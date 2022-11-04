#ifndef PRACTICAL_ASSIGNMENT_3_MACHINEGUNNER_H
#define PRACTICAL_ASSIGNMENT_3_MACHINEGUNNER_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class MachineGunner: public WarParticipant {
public:
    MachineGunner(int d, int h);
    MachineGunner* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_MACHINEGUNNER_H
