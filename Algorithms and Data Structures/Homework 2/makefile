all: hw2_p1 hw2_p2 testWindGauge hw2_p4 hw2_p5 hw2_p6

hw2_p1: hw2_p1.o
	g++ -Wall -o hw2_p1 hw2_p1.o
	
hw2_p1.o : hw2_p1.cpp
	g++ -Wall -c hw2_p1.cpp

hw2_p2: hw2_p2.o
	g++ -Wall -o hw2_p2 hw2_p2.o
	
hw2_p2.o : hw2_p2.cpp
	g++ -Wall -c hw2_p2.cpp

testWindGauge: testWindGauge.o WindGauge.o
	g++ -Wall -o testWindGauge testWindGauge.o WindGauge.o
	
testWindGauge.o : testWindGauge.cpp WindGauge.h
	g++ -Wall -c testWindGauge.cpp 

WindGauge.o : WindGauge.cpp WindGauge.h
	g++ -Wall -c WindGauge.cpp

hw2_p4: hw2_p4.o
	g++ -Wall -o hw2_p4 hw2_p4.o
	
hw2_p4.o : hw2_p4.cpp
	g++ -Wall -c hw2_p4.cpp

hw2_p5: hw2_p5.o
	g++ -Wall -o hw2_p5 hw2_p5.o
	
hw2_p5.o : hw2_p5.cpp
	g++ -Wall -c hw2_p5.cpp

hw2_p6: hw2_p6.o
	g++ -Wall -o hw2_p6 hw2_p6.o
	
hw2_p6.o : hw2_p6.cpp
	g++ -Wall -c hw2_p6.cpp

compileonly: hw2_p1.o hw2_p2.o testWindGauge.o hw2_p4.o hw2_p5.o hw2_p6.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f hw2_p1 hw2_p2 testWindGauge hw2_p4 hw2_p5 hw2_p6

deleteall: deleteexec deleteofiles