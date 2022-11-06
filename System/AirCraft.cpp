#include "AirCraft.h"

AirCraft::AirCraft(int d, int h) : WarParticipant("WarTransportFactory", "AirCraft", d, h){
    damage=d;
    hp=h;
}

AirCraft* AirCraft::clone() {
    AirCraft* temp=new AirCraft(damage, hp);
    return temp;
}

void AirCraft::doNotting() {

}