#include "Soldier.h"

Soldier::Soldier(int hp,int dam) : WarParticipant("SoldierFactory", "Soldier",hp,dam) {
type="Soldier";
}

WarParticipant* Soldier::clone() {
    Soldier* temp=new Soldier(HP,damage);
    return temp;
}

void Soldier::doNotting() {

}