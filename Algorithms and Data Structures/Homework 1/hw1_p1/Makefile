all: hw1_p1

hw1_p1: hw1_p1.o
	g++ -Wall -o hw1_p1 hw1_p1.o
	
hw1_p1.o : hw1_p1.cpp
	g++ -Wall -c hw1_p1.cpp
	
compileonly: hw1_p1.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f hw1_p1	

deleteall: deleteexec deleteofiles

createdir:
	mkdir test_directory

deletedir:
	rmdir test_directory