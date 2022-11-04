#include "CountryObserver.h"
#include "Country.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Country::Country(){

}
void Country::setHp(int hp){
    this->hp=hp;
}
int Country::getHP(){
    return hp;
}
void Country::updateHp(int currHP){
    this->hp=currHP;
}