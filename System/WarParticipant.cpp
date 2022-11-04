#include "WarParticipant.h"

    WarParticipant::WarParticipant(string manufacturer, string type, int d, int h) {
        this->manufacturer=manufacturer;
        this->type=type;
        damage=d;
        hp=h;
    }

//    WarParticipant::~WarParticipant(){
//        delete this;
//    }


std::string WarParticipant::getType()
{
	return type;
}

void WarParticipant::incrementParticipantNumber()
{
	numParticipants++;
}

int WarParticipant::getNumParticipants()
{
	return numParticipants;
}

int getHP(){
    return hp;
}
int getDamage(){
    return damage;
}
    