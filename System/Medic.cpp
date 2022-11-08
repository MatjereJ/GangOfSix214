#include "Medic.h"

Medic::Medic(int hp) : WarParticipant("MedicFactory", "Medic",0,0) {
    this->HP=hp;
}

WarParticipant* Medic::clone() {
    Medic* temp=new Medic(HP);
    return temp;
}

void Medic::doNotting() {

}