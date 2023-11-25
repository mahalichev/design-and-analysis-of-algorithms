#include "../Headers/PrefixFunction.h"

std::vector<int> PrefixFunction(std::string S){
    std::cout << "\n--Making prefix function--\n";
    std::vector<int> p;
    p.push_back(0);
    for (int i = 1; i < S.length(); i++){
        int j = p[i-1];
        while (j && (S[j] != S[i])){
            j = p[j-1];
        }
        if (S[i] == S[j]){
            j++;
        }
        p.push_back(j);
        std::cout << "  -Prefix #" << i << " = " << j << '\n';
        std::cout << "    -String - ";
        for (int k = 0; k < i + 1; k++){
            std::cout << S[k];
        }
        std::cout << " Prefix - ";
        for (int k = 0; k < j; k++){
            std::cout << S[k];
        }
        std::cout << " Suffix - ";
        for (int k = i - j + 1; k < i + 1; k++){
            std::cout << S[k];
        }
        std::cout << '\n';
    }
    std::cout << "  Prefix function p = ";
    for (auto &n: p){
        std::cout << n << ' ';
    }
    std::cout << '\n';
    return p;
}