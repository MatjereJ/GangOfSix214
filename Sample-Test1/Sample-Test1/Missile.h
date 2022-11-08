#pragma once

#ifndef PRACTICAL_ASSIGNMENT_3_MISSILE_H
#define PRACTICAL_ASSIGNMENT_3_MISSILE_H
#include "WarParticipant.h"
#include "WarParticipantFactory.h"

class Missile : public WarParticipant {
public:
    Missile(int d, int h);
    Missile* clone();
    void doNotting();
};


#endif //PRACTICAL_ASSIGNMENT_3_MISSILE_H

