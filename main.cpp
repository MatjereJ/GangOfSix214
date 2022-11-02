#include <iostream>
#include "Missile.h"
#include "FireArmFactory.h"
#include "AirCraft.h"
#include "Bomb.h"
#include "ExplosiveFactory.h"
#include "MedicFactory.h"
#include "Medic.h"
#include "FireArmFactory.h"
#include "MachineGun.h"
using namespace std;

int main() {
    cout<<"---------------------------------"<<endl;
    cout<<"Factory Method"<<endl;
    cout<<"Medic Factory"<<endl;
    MedicFactory* meds=new MedicFactory();
    Medic* actMed[5];
    for(int i=0; i<5; i++){
        actMed[i]=meds->createMedic(90);
    }
    cout<<actMed[0]->getDescription()<<endl;

    cout<<"FireArm Factory"<<endl;
    FireArmFactory* fireArms=new FireArmFactory();
    MachineGun* machineGuns[5];
    for(int i=0; i<5; i++){
        machineGuns[i]=fireArms->createMachineGun(40);
    }
    cout<<"-----------------------------"<<endl;
    return 0;
}