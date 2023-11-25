#include "../Headers/CyclicShift.h"

int CyclicShift(std::string &A, std::string &B){
    if (A.length() != B.length()){
        std::cout << "\nString lengths do not match\n";
        std::cout << "\n--Result--\n";
        return -1;
    }
    int Shift = 0;
    std::string S = A + A;
    std::cout << "\n--Finding B \"" << B << "\" in AA \"" << S << "\"--\n";
    for (int i = 0; i < A.length(); i++){
        std::cout << "  -Shift by " << Shift << '\n';
        int j = 0;
        std::cout << "    -Comparing letters\n";
        while (B[j] == S[j + i]){
            std::cout << "      B[" << j << "] = AA[" << j + i << "] = " << B[j] << '\n';
            if (j == (B.length() - 1)){
                std::cout << "The offset was found\n";
                std::cout << "\n--Result--\n";
                return Shift;
            }
            j++;
        }
        std::cout << "      Not all letters match\n";
        Shift++;
    }
    std::cout << "The offset was not found\n";
    std::cout << "\n--Result--\n";
    return -1;
}