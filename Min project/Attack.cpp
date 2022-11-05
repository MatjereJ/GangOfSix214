#include "Attack.h"

using namespace std;

void Attack::handleChange(Country *C)
{
    Country *temp = C->getOpposingC();
    if (C->getHp() >= temp->getHp() || C->getHp() >= 800)
    {
        vector<WarParticipant *> temp = C->getArtillery();
        if (temp.empty() == true)
        {
            cout << "Country cannot attack as it has no artillery to attack" << endl;
        }
        vector<WarParticipant *>::iterator it = temp.begin();
        WarParticipant *curr = *it;
        while (curr->getDamage() != 12 && it != temp.end()) ////////This os fpr Detonate
        {
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

        while ((curr->getDamage() != 6 && curr->getDamage() != 5) && it != temp.end())
        {
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

        while ((curr->getDamage() != 20 && curr->getDamage() != 25 && curr->getDamage() != 30) && it != temp.end())
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