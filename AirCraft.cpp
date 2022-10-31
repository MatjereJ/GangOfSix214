#include "AirCraft.h"

AirCraft::AirCraft(int hp) : WarParticipant("WarTransportFactory", "AirCraft"){
    this->HP=hp;
}

WarParticipant* AirCraft::clone() {
    AirCraft* temp=new AirCraft(HP);
    return temp;
}

void AirCraft::doNotting() {

}