#include "../Headers/AhoCorasick.h"
#include "../Headers/AhoCorasickWildCard.h"

int main(int argc, char *argv[]){
    if (argc > 1){
        if (argv[1][0] == 'a'){
                AhoCorasick Bore;
                Bore.DoAhoCorasick();
                Bore.Display();
                Bore.Individualization();
        } else if (argv[1][0] == 'w') {
                AhoCorasickWildCard Bore;
                Bore.DoAhoCorasickWildCard();
                Bore.Display();
                Bore.Individualization();
        } else {
                std::cout << "Incorrect argument\n";
        }
    } else {
        std::cout << "Please, select task: a - Aho-Corasick, w - Wild Card\n";
    }
    return 0;
}