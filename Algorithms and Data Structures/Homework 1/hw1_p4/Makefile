all: hw1_p4

hw1_p4: hw1_p4.o
	g++ -Wall -o hw1_p4 hw1_p4.o
	
hw1_p4.o : hw1_p4.cpp
	g++ -Wall -c hw1_p4.cpp
	
compileonly: hw1_p4.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f hw1_p4	

deleteall: deleteexec deleteofiles

createdir:
	mkdir test_directory

deletedir:
	rmdir test_directory