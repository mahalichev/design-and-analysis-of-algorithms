H = ./Headers
S = ./Sources

all: main.o PrefixFunction.o KMP.o CyclicShift.o
	g++ main.o PrefixFunction.o KMP.o CyclicShift.o
	
PrefixFunction.o: $(S)/PrefixFunction.cpp $(H)/PrefixFunction.h
	g++ -c $(S)/PrefixFunction.cpp
	
KMP.o: $(S)/KMP.cpp $(H)/KMP.h $(S)/PrefixFunction.cpp $(H)/PrefixFunction.h
	g++ -c $(S)/KMP.cpp
	
CyclicShift.o: $(S)/CyclicShift.cpp $(H)/CyclicShift.h
	g++ -c $(S)/CyclicShift.cpp
	
main.o: $(S)/main.cpp $(S)/KMP.cpp $(H)/KMP.h $(S)/CyclicShift.cpp $(H)/CyclicShift.h $(S)/PrefixFunction.cpp $(H)/PrefixFunction.h
	g++ -c $(S)/main.cpp
	
clear:
	rm *.o *.out 
