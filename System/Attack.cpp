#include "Attack.h"

using namespace std;

void Attack::handleChange(Country *C)
{
    cout << "Attack" << endl;
    Country *temp = C->getOpposingC();
    if (C->getHp() >= temp->getHp() || C->getHp() >= 800)
    {
        cout << "Its inside" << endl;
        list<WarParticipants *> temp = C->getArtillery();
        if (temp.empty() == true)
        {
            cout << "Country cannot attack as it has no artillery to attack" << endl;
        }
        list<WarParticipants *>::iterator it = temp.begin();
        WarParticipants *curr = *it;
        while (curr->getDamage() != 12 && it != temp.end()) ////////This os fpr Detonate
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
        while ((curr->getDamage() != 6 && curr->getDamage() != 5) && it != temp.end())
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