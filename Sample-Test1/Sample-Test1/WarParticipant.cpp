#include "pch.h"
#include "WarParticipant.h"

WarParticipant::WarParticipant(string manufacturer, string type, int d, int h) {
    this->manufacturer = manufacturer;
    this->type = type;
    this->damage = d;
    this->hp = h;
}

//    WarParticipant::~WarParticipant(){
//        delete this;
//    }


std::string WarParticipant::getType()
{
    return this->type;
}

void WarParticipant::incrementParticipantNumber()
{
    numParticipants++;
}

int WarParticipant::getNumParticipants()
{
    return numParticipants;
}

int WarParticipant::getHP() {
    return hp;
}
int WarParticipant::getDamage() {
    return damage;
}
void WarParticipant::updateHP(int h) {
    this->hp = h;
}
