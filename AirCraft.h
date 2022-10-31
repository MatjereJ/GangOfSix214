#ifndef PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
#define PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class AirCraft: public WarParticipant {
private:
    int HP;
public:
    AirCraft(int hp);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
