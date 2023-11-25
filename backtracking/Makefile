H = ./Headers
S = ./Sources

all: a.out

a.out: Coordinate.o Part.o Table.o main.o
	g++ main.o Table.o Part.o Coordinate.o
Coordinate.o: $(H)/Coordinate.h $(S)/Coordinate.cpp
	g++ -c $(S)/Coordinate.cpp
Part.o: $(H)/Part.h $(S)/Part.cpp $(H)/Coordinate.h $(S)/Coordinate.cpp
	g++ -c $(S)/Part.cpp
Table.o: $(H)/Table.h $(S)/Table.cpp $(H)/Part.h $(S)/Part.cpp $(H)/Coordinate.h $(S)/Coordinate.cpp
	g++ -c $(S)/Table.cpp
main.o: $(H)/Table.h $(S)/Table.cpp $(H)/Part.h $(S)/Part.cpp $(H)/Coordinate.h $(S)/Coordinate.cpp
	g++ -c $(S)/main.cpp
clear:
	rm *.o a.out
