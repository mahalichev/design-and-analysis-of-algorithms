#ifndef AHOCORASICKWILDCARD_H
#define AHOCORASICKWILDCARD_H

#include <iostream>
#include <string>
#include "../Headers/BoreVertexWildCard.h"

class AhoCorasickWildCard{
    public:
        AhoCorasickWildCard();
        void Split();
        void SetPatternToBore(std::string &Stroke);
        int GetSuffixLink(int index);
        int GetTransition(int index, char to);
        void Check(int index, int i);
        void DoAhoCorasickWildCard();
        void Display();
        void Individualization();
    private:
        std::string Text;
        std::string Pattern;
        std::vector<BoreVertexWildCard*> Bore;
        std::vector<std::string> Subpatterns;
        std::vector<int> SubpatternsIndexes;
        std::vector<int> SubpatternsCounter;
        std::vector<int> Res;
};

#endif