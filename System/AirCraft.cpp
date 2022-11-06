#include "AirCraft.h"

AirCraft::AirCraft(int d, int h) : WarParticipant("WarTransportFactory", "AirCraft", d, h){
 type="Aircraft";
}

AirCraft* AirCraft::clone() {
    AirCraft* temp=new AirCraft(damage, hp);
    return temp;
}

void AirCraft::doNotting() {

}