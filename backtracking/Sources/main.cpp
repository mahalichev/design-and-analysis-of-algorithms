#include "../Headers/Table.h"

int main(){
    int size;
    std::cout << "Size of table - ";
    std::cin >> size;
    Table T(size);
    T.RequiredSquaresRead();
    T.Fill();
    T.DisplayResult();
    return 0;
}
