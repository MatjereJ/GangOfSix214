#ifndef PRACTICAL_ASSIGNMENT_3_WARSHIP_H
#define PRACTICAL_ASSIGNMENT_3_WARSHIP_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class WarShip: public WarParticipant {
    int HP;
public:
    WarShip(int hp);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_WARSHIP_H
