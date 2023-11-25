H = ./Headers
S = ./Sources

all: main.o PrefixFunction.o KMP.o
	g++ main.o PrefixFunction.o KMP.o

PrefixFunction.o: $(S)/PrefixFunction.cpp $(H)/PrefixFunction.h
	g++ -c $(S)/PrefixFunction.cpp

KMP.o: $(S)/KMP.cpp $(H)/KMP.h $(S)/PrefixFunction.cpp $(H)/PrefixFunction.h
	g++ -c $(S)/KMP.cpp

main.o: $(S)/main.cpp $(S)/KMP.cpp $(H)/KMP.h $(S)/PrefixFunction.cpp $(H)/PrefixFunction.h
	g++ -c $(S)/main.cpp

clear:
	rm *.o *.out 
