#ifndef PRACTICAL_ASSIGNMENT_3_BOMB_H
#define PRACTICAL_ASSIGNMENT_3_BOMB_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class Bomb: public WarParticipant {
public:
    Bomb(int d, h);
    Bomb* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_BOMB_H
