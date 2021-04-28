all: main ActivitySelectionGreedy

main: main.o
	g++ -Wall -o main main.o

main.o: main.cpp HashTable.h
	g++ -Wall -c main.cpp 

ActivitySelectionGreedy: ActivitySelectionGreedy.o
	g++ -Wall -o ActivitySelectionGreedy ActivitySelectionGreedy.o

ActivitySelectionGreedy.o: ActivitySelectionGreedy.cpp
	g++ -Wall -c ActivitySelectionGreedy.cpp 

compileonly: main.o ActivitySelectionGreedy.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f main ActivitySelectionGreedy

deleteall: deleteexec deleteofiles