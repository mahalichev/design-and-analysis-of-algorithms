#include "../Headers/KMP.h"

std::vector<int> KMP(std::string &P, std::string &T){
    std::vector<int> p = PrefixFunction(P + "#" + T);
    std::vector<int> Indexes;
    std::cout << "\n--Comparing P length and prefixes--\n";
    for (int i = 0; i < T.length(); i++){
        std::cout << "  -Comparing " << P.length() << " and " << p[P.length() + 1 + i] << '\n';
        if (p[P.length() + 1 + i] == P.length()){
            std::cout << "    -Equals. Adding index " << i - P.length() + 1 << " in vector\n";
            Indexes.push_back(i - P.length() + 1);
        }
    }
    std::cout << "\n--Result--\n";
    return Indexes;
}