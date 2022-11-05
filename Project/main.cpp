#include "Attack.cpp"
#include "Defend.cpp"
#include "Surrender.cpp"
#include "Shoot.cpp"
#include "FireMissile.cpp"
#include "DetonateExplosives.cpp"
#include "Country.cpp"
#include "WarParticipant.cpp"
#include "Context.cpp"
#include "BattleState.cpp"
// #include "Attack.h"
// #include "Defend.h"
// #include "Surrender.h"
// #include "Shoot.h"
// #include "FireMissile.h"
// #include "DetonateExplosives.h"
#include "Rifle.h"
#include "MachineGun.h"
#include "Missile.h"
#include "Aircraft.h"
#include "Warship.h"
#include "Bomb.h"

int main()
{
    WarParticipants *gun1 = new Rifle("AR15");
    cout << gun1->getDamage() << endl;
    WarParticipants *gun2 = new Rifle("AR15");
    WarParticipants *gun3 = new Rifle("AR15");
    WarParticipants *gun4 = new Rifle("AR15");
    WarParticipants *MG1 = new MachineGun("AK47");
    WarParticipants *MG2 = new MachineGun("AK47");
    WarParticipants *Nuclear = new Missile("Nuke");
    WarParticipants *Nuclear2 = new Missile("Nuke");
    WarParticipants *Nuclear3 = new Missile("Nuke");
    WarParticipants *BlackBomber = new Aircraft("Nazi");
    WarParticipants *Bomb1 = new Bomb("C4");
    WarParticipants *Bomb2 = new Bomb("C4");

    Country *Enemy = new Country();
    Country *Rwanda = new Country(Enemy);
    Rwanda->addArtillery(gun1);
    Rwanda->addArtillery(gun2);
    Rwanda->addArtillery(gun3);
    Rwanda->addArtillery(gun4);
    Rwanda->addArtillery(MG1);
    Rwanda->addArtillery(MG2);
    Rwanda->addArtillery(Nuclear);
    Rwanda->addArtillery(Nuclear2);
    Rwanda->addArtillery(Nuclear3);
    Rwanda->addArtillery(BlackBomber);
    Rwanda->addArtillery(Bomb1);
    Rwanda->addArtillery(Bomb2);

    BattleState State;
    Defend *D = new Defend();
    Attack *att = new Attack();
    Surrender *LongDay = new Surrender();
    State.Add(D);
    State.Add(att);
    State.Add(LongDay);
    Rwanda->setHp(400);
    State.handleChange(Rwanda);
    Country *temp = Rwanda->getOpposingC();
    cout << Rwanda->getHp() << " " << temp->getHp() << endl;
}