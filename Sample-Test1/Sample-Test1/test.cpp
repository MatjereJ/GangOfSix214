#include "pch.h"
#include "Rifleman.h"
#include "MachineGunner.h"
#include "Missile.h"
#include "Bomb.h"
#include <iostream>
using namespace std;



TEST(TestCaseRifle, TestClone) {
	Rifleman* man1 = new Rifleman(50,100);
	//Rifleman* man3 = new Rifleman(51, 200);
	Rifleman* man2 = man1->clone();
	EXPECT_EQ(man1->getHP(),man2->getHP());
}
TEST(TestCaseMachine,	SubTest_CloneMachine) {
	MachineGunner* man3 = new MachineGunner(50, 100);
	//Rifleman* man5 = new Rifleman(51, 200);
	MachineGunner* man4 = man3->clone();
	EXPECT_EQ(man3->getType(), man4->getType());
}
TEST(TestCaseMissile, TestCloneMissile) {
	Missile* missile1 = new Missile(80, 100);
	//Missile* missile1 = new Missile(81, 110);
	Missile* missile2 = missile1->clone();
	EXPECT_EQ(missile1->getDamage(), missile2->getDamage());
}
TEST(TestCaseBomb, SubTest_CloneBomb) {
	Bomb* bomb1 = new Bomb(50, 100);
	//Missile* missile1 = new Missile(81, 110);
	Bomb* bomb2 = bomb1->clone();
	//bomb1->updateHP(70);
	EXPECT_EQ(bomb1->getHP(), bomb2->getHP());
}