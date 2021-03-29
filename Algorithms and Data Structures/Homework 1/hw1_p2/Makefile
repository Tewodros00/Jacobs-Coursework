all: testStack

testStack: testStack.o
	g++ -Wall -o testStack testStack.o
	
testStack.o : Stack.h testStack.cpp
	g++ -Wall -c testStack.cpp
	
compileonly: testStack.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f testStack	

deleteall: deleteexec deleteofiles

createdir:
	mkdir test_directory

deletedir:
	rmdir test_directory