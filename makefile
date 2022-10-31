main: main.o Country.o IteratorTool.o WarParticipant.o WarParticipantIterator.o CountryObserver.o CountryObserverIterator.o Alliance.o IndividualCountry.o
	g++ main.o Country.o IteratorTool.o WarParticipant.o WarParticipantIterator.o CountryObserver.o CountryObserverIterator.o Alliance.o IndividualCountry.o -o main
	
main.o: main.cpp 
	g++ -c main.cpp

IteratorTool.o: IteratorTool.cpp
	g++ -c IteratorTool.cpp
	
Country.o: Country.cpp
	g++ -c Country.cpp

WarParticipant.o: WarParticipant.cpp
	g++ -c WarParticipant.cpp

WarParticipantIterator.o: WarParticipantIterator.cpp
	g++ -c WarParticipantIterator.cpp
	
CountryObserver.o: CountryObserver.cpp
	g++ -c CountryObserver.cpp
	
CountryObserverIterator.o: CountryObserverIterator.cpp
	g++ -c CountryObserverIterator.cpp

Alliance.o: Alliance.cpp
	g++ -c Alliance.cpp
	
IndividualCountry.o: IndividualCountry.cpp
	g++ -c IndividualCountry.cpp
run: 
	./main
	
	
clean:
	rm *.o main
	
tar: 	
	tar -cvz *.cpp *.h makefile -f prac7.tar