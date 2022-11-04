#ifndef WarParticipants_h
#define WarParticipants_h
#include <string>
#include <iostream>

using namespace std;

class WarParticipants
{
private:
    std::string type;
    int damage;

public:
    WarParticipants(string type, int dmg);
    string getType();
    int getDamage();
};

#endif