all: main

main: main.o Heap.o
	g++ -Wall -o main main.o Heap.o
	
main.o : main.cpp Heap.h
	g++ -Wall -c main.cpp 

Heap.o : Heap.cpp Heap.h
	g++ -Wall -c Heap.cpp

compileonly: main.o Heap.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	main

deleteall: deleteexec deleteofiles