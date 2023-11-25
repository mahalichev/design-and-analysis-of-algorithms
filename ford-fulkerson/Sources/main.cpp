#include "../Headers/MaxFlow.h"

int Mode = 0;

int main(){
    std::cout << "Choose mode: 1 - Ford; 2 - Individualization\nMode: ";
    while (!Mode){
        std::cin >> Mode;
        if ((Mode != 1) && (Mode != 2)){
            Mode = 0;
            std::cout << "Wrong argument\nMode: ";
        }
    }
    MaxFlow Graph;
    Graph.FindMaxFlow();
    Graph.DisplayResult();
    return 0;
}
