all: problem_1 problem_2

problem_1: problem_1.o
	g++ -Wall -o problem_1 problem_1.o

problem_2: problem_2.o
	g++ -Wall -o problem_2 problem_2.o


problem_1.o: problem_1.cpp Stack.h Queue.h
	g++ -Wall -c problem_1.cpp 

problem_2.o: problem_2.cpp BinarySearchTree.h LinkedList.h
	g++ -Wall -c problem_2.cpp 

compileonly: problem_1.o problem_2.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f problem_1 problem_2

deleteall: deleteexec deleteofiles