all: testLinkedList

testLinkedList: testLinkedList.o
	g++ -Wall -o testLinkedList testLinkedList.o
	
testLinkedList.o : LinkedList.h testLinkedList.cpp
	g++ -Wall -c testLinkedList.cpp
	
compileonly: testLinkedList.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f testLinkedList	

deleteall: deleteexec deleteofiles

createdir:
	mkdir test_directory

deletedir:
	rmdir test_directory