#include <iostream>
#include <string>
#include <vector>
#include "CountryObserver.h"
#include "IndividualCountry.h"
using namespace std;

IndividualCountry::IndividualCountry(string n)
{
  this->initialHP = this->getHp();
  this->name = n;
}

IndividualCountry::IndividualCountry(string c, int level, bool sea) : Country(c, sea)
{
  this->classofC = level;
}

bool IndividualCountry::add(CountryObserver *assistance)
{
  countryObservers.push_back(assistance);
  cout << "Added Country Observer" << endl;
  return true;
}
bool IndividualCountry::remove(CountryObserver *assistance)
{
  bool found = false;

  vector<CountryObserver *>::iterator it = countryObservers.begin();
  while ((it != countryObservers.end()) && (!found))
  {
    if (*it == assistance)
    {
      found = true;
      countryObservers.erase(it);
    }
    ++it;
  }
  return found;
}
void IndividualCountry::notify()
{
  vector<CountryObserver *>::iterator it = countryObservers.begin();
  for (it = countryObservers.begin(); it != countryObservers.end(); ++it)
  {
    (*it)->update();
  }
}
string IndividualCountry::getName()
{
  return this->name;
}
int IndividualCountry::getWeaponHP()
{
  return this->weaponHP;
}
int IndividualCountry::getSoldierHP()
{
  return this->soldierHP;
}
int IndividualCountry::getTransport()
{
  return this->transport;
}
vector<IndividualCountry *> IndividualCountry::getAlliance()
{
  return this->alliance;
}
void IndividualCountry::setAlliance(vector<IndividualCountry *> alliance)
{
  this->alliance = alliance;
}
void IndividualCountry::checkHp()
{
  notify();
}

int IndividualCountry::getInitialHP()
{
  return this->initialHP;
}