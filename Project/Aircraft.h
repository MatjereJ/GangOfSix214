#ifndef PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
#define PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class AirCraft: public WarParticipant {
private:
    int HP;
    int damage;
public:
    AirCraft(int hp);
    AirCraft(string type) : WarParticipant(type, 25){};
    WarParticipant* clone();
    void doNotting();

};


#endif //PRACTICAL_ASSIGNMENT_3_AIRCRAFT_H
