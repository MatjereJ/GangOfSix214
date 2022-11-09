#include "Country.h"

int Country::getHp()
{
    return hp;
}

Country *Country::getOpposingC()
{
    return OpposingCountry;
}

Country::Country(Country *C)
{
    OpposingCountry = C;
}

void Country::setHp(int HP)
{
    hp = HP;
}

vector<WarParticipants *> Country::getArtillery()
{
    return w;
}

void Country::addArtillery(WarParticipants *W)
{
    w.push_back(W);
}

void Country::InflictDamage(int Dmg)
{
    hp = hp - Dmg;
}

Country::Country()
{
    hp = 1000;
    OpposingCountry = nullptr;
}
