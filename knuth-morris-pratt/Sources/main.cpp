#include "../Headers/KMP.h"
#include "../Headers/CyclicShift.h"

int main(int argc, char *argv[]){
    if (argc > 1){
        std::string P, T;
        std::cin >> P >> T;
        std::vector<int> Indexes;
        switch (argv[1][0]){
            case 'k':
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
                break;
            case 'c':
                std::cout << CyclicShift(P, T) << '\n';
                break;
            default:
                std::cout << "Incorrect argument\n";
                break;
        }
    } else {
        std::cout << "Please, select task: k - KMP, c - Cyclic shift\n";
    }
    return 0;
}