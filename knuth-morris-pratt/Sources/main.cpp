#include "../Headers/KMP.h"

int main(int argc, char *argv[]){
    std::string P, T;
    std::cin >> P >> T;
    std::vector<int> Indexes;
    Indexes = KMP(P, T);
    if (Indexes.empty()){
        std::cout << -1;
    } else {
        std::cout << Indexes[0];
        for (int i = 1; i < Indexes.size(); i++){
            std::cout << ',' << Indexes[i];
        }
        std::cout << '\n';
    }
    return 0;
}