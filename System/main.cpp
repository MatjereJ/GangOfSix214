#include "Country.h"
#include "WarParticipant.h"
#include "WarParticipantIterator.h"
#include "CountryObserver.h"
#include "CountryObserverIterator.h"
#include "Alliance.h"
#include "IndividualCountry.h"
#include <iostream>

int main()
{
	std::cout<<"***********     Iterator for War Participants    ***************\n";
	Country* countryA = new IndividualCountry("A", "IndividualCountry");
	std::cout<<"\n";
	std::cout<<"First Country created.\n";
	std::cout<<"First Country Name: "<<countryA->getName()<<"\n";
	WarParticipant* soldiers = new WarParticipant("soldiers", 1000);
	WarParticipant* medicalPersoneel = new WarParticipant("Medical Personeel", 150);
	WarParticipant* explosives = new WarParticipant("Explosives", 5000);
	WarParticipant* firearms = new WarParticipant("Firearms", 3000);
	WarParticipant* transport = new WarParticipant("War Transport", 400);
	
	/*	Add Participants to the diagram	*/
	countryA->addWarParticipant(soldiers);
	countryA->addWarParticipant(medicalPersoneel);
	countryA->addWarParticipant(explosives);
	countryA->addWarParticipant(firearms);
	countryA->addWarParticipant(transport);
	
	/*	Creating a WarParticipantIterator here to traverse the array	*/
	WarParticipantIterator* wpIt = countryA->createWarParticipantIterator();
	std::cout<<"\n";
	
	/*	Iterating through the War Participants (Firearms, MedicalPersoneel, Soldiers, etc)*/
	for(wpIt->first(); !wpIt ->isLastEl(); wpIt->next())
	{
		std::cout<<"Participant type: "<<wpIt->currentEl()->getType()<<"\n";
		std::cout<<"Number of Participants: "<<wpIt->currentEl()->getNumParticipants()<<"\n\n";
	}
	
	std::cout<<"***********     Iterator for Country Observers    ***************\n\n";
	
	CountryObserver* healthOrganisations = new CountryObserver("United Nations");
	CountryObserver* doctors = new CountryObserver("Medical People");
	CountryObserver* countryAlliances = new CountryObserver("Allies");
	countryA -> addCountryObserver(healthOrganisations);
	countryA -> addCountryObserver(doctors);
	countryA -> addCountryObserver(countryAlliances);
	
	CountryObserverIterator* coIt = countryA->createCountryObserverIterator();
	std::cout<<"\n";
	std::cout<<"Country Observers below:\n\n";

	for(coIt -> first(); !coIt -> isLastEl(); coIt -> next())
	{
		std::cout<<"Observer Name: "<<coIt->currentEl()->getName()<<"\n";
	}
	std::cout<<"\n***********     Add country to Alliance    *************\n";
	Country* allianceAA = new Alliance("AA", "Alliance");
	allianceAA->addAlly(countryA);
	Country* allianceAB = new Alliance("AB", "Alliance");
	Country* countryAB = new IndividualCountry("AB", "IndividualCountry");
	allianceAB->addAlly(countryAB);
	//allianceA->addAlly(countryA);
	allianceAA->addAlly(allianceAB);
	std::cout<<"\nBelow we try to add a country that exists in allianceAB\n";
	allianceAA->addAlly(countryAB);
	
	//delete wpIt;
	delete countryA;
	return 0;
}