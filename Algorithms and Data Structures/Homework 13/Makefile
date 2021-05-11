all: OptimalMeetingPoint NumberMaze

OptimalMeetingPoint: OptimalMeetingPoint.o
	g++ -Wall -o OptimalMeetingPoint OptimalMeetingPoint.o

OptimalMeetingPoint.o: OptimalMeetingPoint.cpp
	g++ -Wall -c OptimalMeetingPoint.cpp

NumberMaze: NumberMaze.o
	g++ -Wall -o NumberMaze NumberMaze.o

NumberMaze.o: NumberMaze.cpp PuzzleBoard.h
	g++ -Wall -c NumberMaze.cpp

compileonly: OptimalMeetingPoint.o NumberMaze.o

deleteofiles:
	rm -f *.o

deleteexec:
	rm -f OptimalMeetingPoint NumberMaze

deleteall: deleteexec deleteofiles