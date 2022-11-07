#include "Attack.h"

using namespace std;

Attack::Attack() {}

void Attack::handleChange(IndividualCountry *C)
{
    cout << "Attack" << endl;

    IndividualCountry *temp = C->getOpposingC();
    if (C->getHp() >= temp->getHp() || C->getHp() >= 800)
    {
        cout << "Its inside" << endl;

        vector<WarParticipant*> temp = C->getArtillery();

        if (temp.empty() == true)
        {
            cout << "Country cannot attack as it has no artillery to attack" << endl;
        }


        vector<WarParticipant*>::iterator it = temp.begin();

        WarParticipant *curr = *it;
        while (curr->getType() == "Bomb" && it != temp.end()) ////////This os fpr Detonate
        {
            cout << "COme on now " << curr->getDamage() << endl;
            it++;
            curr = *it;
        }
        if (it != temp.end())
        {
            Context *Cx = new Context(new DetonateExplosives());
            Cx->implement(C);
            it = temp.begin();
            curr = *it;
        }
        else
            it = temp.begin();

        cout << "Next one" << endl;
        while ((curr->getType() != "Rifleman" && curr->getType() != "MachineGunner") && it != temp.end())
        {
            cout << "Yeah " << curr->getDamage() << endl;
            it++;
            curr = *it;
        }
        if (it != temp.end())
        {
            Context *Cx = new Context(new Shoot());
            Cx->implement(C);
            it = temp.begin();
            curr = *it;
        }
        else
            it = temp.begin();

        while ((curr->getType() != "Missile" && curr->getType() == "AirCraft" && curr->getType() != "Warship") && it != temp.end())
        {
            it++;
            curr = *it;
        }
        if (it != temp.end())
        {
            Context *Cx = new Context(new FireMissile());
            Cx->implement(C);
            it = temp.begin();
            curr = *it;
        }
        else
            it = temp.begin();
    }
    else
    {
        cout << "No attack" << endl;
        if (successor != nullptr)
            successor->handleChange(C);
        else
            cout << "No Chain added" << endl;
    }
}