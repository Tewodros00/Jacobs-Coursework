all: LongestOrderedSubarray SumInTriangles

LongestOrderedSubarray: LongestOrderedSubarray.o
	g++ -Wall -o LongestOrderedSubarray LongestOrderedSubarray.o

LongestOrderedSubarray.o: LongestOrderedSubarray.cpp
	g++ -Wall -c LongestOrderedSubarray.cpp
	
SumInTriangles: SumInTriangles.o
	g++ -Wall -o SumInTriangles SumInTriangles.o

SumInTriangles.o: SumInTriangles.cpp
	g++ -Wall -c SumInTriangles.cpp

compileonly: LongestOrderedSubarray.o SumInTriangles.o

deleteofiles:
	rm -f *.o
	
deleteexec:
	rm -f LongestOrderedSubarray SumInTriangles

deleteall: deleteexec deleteofiles