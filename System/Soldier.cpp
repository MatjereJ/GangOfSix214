#include "Soldier.h"

Soldier::Soldier(int hp) : WarParticipant("SoldierFactory", "Soldier") {
    this->HP=hp;
}

WarParticipant* Soldier::clone() {
    Soldier* temp=new Soldier(HP);
    return temp;
}

void Soldier::doNotting() {

}