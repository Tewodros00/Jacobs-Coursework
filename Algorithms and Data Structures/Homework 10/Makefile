all: main

main: main.o
	g++ -Wall -o main main.o

main.o: main.cpp RedBlackTree.h
	g++ -Wall -c main.cpp 

compileonly: main.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f main

deleteall: deleteexec deleteofiles