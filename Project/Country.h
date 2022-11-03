#ifndef Country_h
#define Country_h
#include "WarParticipants.h"
#include <list>

class Country
{
private:
    int hp = 1000;
    Country *OpposingCountry;
    list<WarParticipants *> w;

public:
    void InflictDamage(int dmg);
    int getHp();
    Country *getOpposingC();
    void setHp(int HP);
    list<WarParticipants *> getArtillery();
    void addArtillery(WarParticipants *W);
    Country(Country *C);
    Country();
};

#endif