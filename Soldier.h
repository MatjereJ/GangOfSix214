#ifndef PRACTICAL_ASSIGNMENT_3_SOLDIER_H
#define PRACTICAL_ASSIGNMENT_3_SOLDIER_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class Soldier: public WarParticipant {
private:
    int HP;
public:
    Soldier(int hp);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_MEDIC_H
