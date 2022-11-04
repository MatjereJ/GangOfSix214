#ifndef PRACTICAL_ASSIGNMENT_3_MISSILE_H
#define PRACTICAL_ASSIGNMENT_3_MISSILE_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class Missile: public WarParticipant {
private:
    int damage;
public:
    Missile(int damage);
    Missile(string type) : WarParticipant(type, 20){};
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_MISSILE_H
