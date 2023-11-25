#ifndef BOREVERTEX_H
#define BOREVERTEX_H

#include <vector>
#include <map>

class BoreVertex{
    public:
        BoreVertex(char symbol = -1, int parent = -1);
        char Symbol;
        int Parent;
        int SuffixLink = -1;
        int Pattern = -1;
        std::map<char, int> Next;
        std::map<char, int> TransitionsTo;
};

#endif