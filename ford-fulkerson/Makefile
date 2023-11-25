H = ./Headers
S = ./Sources

all: main.o Edge.o MaxFlow.o
	g++ main.o Edge.o MaxFlow.o
	
Edge.o: $(S)/Edge.cpp $(H)/Edge.h
	g++ -c $(S)/Edge.cpp

MaxFlow.o: $(S)/MaxFlow.cpp $(H)/MaxFlow.h $(S)/Edge.cpp $(H)/Edge.h
	g++ -c $(S)/MaxFlow.cpp
	
main.o: $(S)/main.cpp $(S)/MaxFlow.cpp $(H)/MaxFlow.h $(S)/Edge.cpp $(H)/Edge.h
	g++ -c $(S)/main.cpp
	
clear:
	rm *.o *.out 
