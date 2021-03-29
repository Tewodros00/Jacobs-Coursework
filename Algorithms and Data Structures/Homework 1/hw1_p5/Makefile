all: hw1_p5

hw1_p5: hw1_p5.o
	g++ -Wall -o hw1_p5 hw1_p5.o
	
hw1_p5.o : hw1_p5.cpp
	g++ -Wall -c hw1_p5.cpp
	
compileonly: hw1_p5.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f hw1_p5	

deleteall: deleteexec deleteofiles

createdir:
	mkdir test_directory

deletedir:
	rmdir test_directory