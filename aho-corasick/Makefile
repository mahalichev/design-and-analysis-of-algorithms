H = ./Headers
S = ./Sources

all: main.o BoreVertex.o BoreVertexWildCard.o AhoCorasick.o AhoCorasickWildCard.o
	g++ main.o BoreVertex.o BoreVertexWildCard.o AhoCorasick.o AhoCorasickWildCard.o
	
BoreVertex.o: $(S)/BoreVertex.cpp $(H)/BoreVertex.h
	g++ -c $(S)/BoreVertex.cpp

BoreVertexWildCard.o: $(S)/BoreVertexWildCard.cpp $(H)/BoreVertexWildCard.h
	g++ -c $(S)/BoreVertexWildCard.cpp

AhoCorasick.o: $(S)/AhoCorasick.cpp $(H)/AhoCorasick.h $(S)/BoreVertex.cpp $(H)/BoreVertex.h
	g++ -c $(S)/AhoCorasick.cpp
	
AhoCorasickWildCard.o: $(S)/AhoCorasickWildCard.cpp $(H)/AhoCorasickWildCard.h $(S)/BoreVertexWildCard.cpp $(H)/BoreVertexWildCard.h
	g++ -c $(S)/AhoCorasickWildCard.cpp
	
main.o: $(S)/main.cpp $(S)/AhoCorasick.cpp $(H)/AhoCorasick.h $(S)/BoreVertex.cpp $(H)/BoreVertex.h $(S)/AhoCorasickWildCard.cpp $(H)/AhoCorasickWildCard.h $(S)/BoreVertexWildCard.cpp $(H)/BoreVertexWildCard.h
	g++ -c $(S)/main.cpp
	
clear:
	rm *.o *.out 
