#ifndef PRACTICAL_ASSIGNMENT_3_BOMB_H
#define PRACTICAL_ASSIGNMENT_3_BOMB_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class Bomb: public WarParticipant {
    int damage;
public:
    Bomb(int damage);
    WarParticipant* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_BOMB_H
