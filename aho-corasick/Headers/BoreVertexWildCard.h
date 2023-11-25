#ifndef BOREVERTEXWILDCARD_H
#define BOREVERTEXWILDCARD_H

#include <vector>
#include <map>

class BoreVertexWildCard{
    public:
        BoreVertexWildCard(char symbol = -1, int parent = -1);
        char Symbol;
        int Parent;
        int SuffixLink = -1;
        std::vector<int> PatternsIndexes;
        std::map<char, int> Next;
        std::map<char, int> TransitionsTo;
};

#endif