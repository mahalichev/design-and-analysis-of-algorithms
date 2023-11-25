#ifndef AHOCORASICK_H
#define AHOCORASICK_H

#include <iostream>
#include <algorithm>
#include <string>
#include "../Headers/BoreVertex.h"

class AhoCorasick{
    public:
        AhoCorasick();
        void SetPatternToBore(std::string &Stroke);
        int GetSuffixLink(int index);
        int GetTransition(int index, char to);
        void Check(int index, int i);
        void DoAhoCorasick();
        void Display();
        void Individualization();
    private:
        std::string Text;
        std::vector<BoreVertex*> Bore;
        std::vector<std::string> Patterns;
        std::vector<std::pair<int, int>> Res;
};

bool cmp(std::pair<int, int> a, std::pair<int, int> b);

#endif