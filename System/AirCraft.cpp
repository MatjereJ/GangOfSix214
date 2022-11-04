#include "AirCraft.h"

AirCraft::AirCraft(int d, int h) : WarParticipant("WarTransportFactory", "AirCraft", d, h){

}

Aircraft* AirCraft::clone() {
    AirCraft* temp=new AirCraft(HP);
    return temp;
}

void AirCraft::doNotting() {

}