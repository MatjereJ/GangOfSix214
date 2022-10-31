#ifndef Country_H
#define Country_H
#include <list>
#include "WarParticipant.h"
#include "CountryObserver.h"
#include "WarParticipantIterator.h"
#include "CountryObserverIterator.h"
#include <vector>
#include <string>

class BattleState;
class WarTheatre;
class CountryObserverIterator;
class WarParticipantIterator;
class Country
{
	friend class WarParticipantIterator;
	public:
		Country(std::string);
		Country(std::string, BattleState* state);
		virtual ~Country();
		virtual void setState(BattleState* newState);
		virtual BattleState* getState();
		virtual void addWarParticipant(WarParticipant*);
		virtual std::list<WarParticipant*> getWarParticipants();
		virtual void addCountryObserver(CountryObserver*);
		virtual std::list<CountryObserver*> getCountryObservers();
		virtual void setWarTheatre(WarTheatre*);
		virtual WarTheatre* getWarTheatre();
		virtual void startWar();
		virtual void withdraw();
		virtual void joinExistingGroup();
		virtual void changeSides();
		virtual void requestAssistance();
		virtual WarParticipantIterator* createWarParticipantIterator();
		virtual CountryObserverIterator* createCountryObserverIterator();
		virtual std::string getName();
		virtual void addAlly(Country*) = 0;
		virtual void removeAlly(Country*) = 0;
		virtual std::string getType() = 0;
		virtual std::vector<Country*> getVectArray() = 0;
		virtual void setAlliance(Country*) = 0;
		virtual Country* getAlliance() = 0;
	
	private:
		BattleState* state;
		WarTheatre* wt;
		std::list<WarParticipant*> wp;
		std::list<CountryObserver*> observerList;
		std::string cName;
};
#endif