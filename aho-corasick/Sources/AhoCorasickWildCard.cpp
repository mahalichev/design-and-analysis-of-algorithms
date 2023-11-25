#include "../Headers/AhoCorasickWildCard.h"

AhoCorasickWildCard::AhoCorasickWildCard(){
    Bore.push_back(new BoreVertexWildCard());
    std::cin >> Text;
    std::cin >> Pattern;
    Split();
}

void AhoCorasickWildCard::Split(){
    char WildCard;
    std::cin >> WildCard;
    std::string Subpattern;
    int Index = 0;
    std::cout << "Splitting Pattern To Subpatterns\n";
    for (auto &i: Pattern){
        if (i == WildCard){
            if (Subpattern.length()){
                std::cout << "Subpattern - " << Subpattern << std::endl;
                SubpatternsIndexes.push_back(Index - Subpattern.length());
                SetPatternToBore(Subpattern);
            }
            Subpattern.erase();
        } else {
            Subpattern.insert(Subpattern.end(), i);
        }
        Index++;
    }
    if (Subpattern.length()){
        std::cout << "Subpattern - " << Subpattern << std::endl;
        SubpatternsIndexes.push_back(Index - Subpattern.length());
        SetPatternToBore(Subpattern);
    }
}

void AhoCorasickWildCard::SetPatternToBore(std::string &Stroke){
    Subpatterns.push_back(Stroke);
    int VertexIndex = 0;
    std::cout << "Adding \"" << Stroke << "\" To Bore\n";
    for (auto &i: Stroke){
        if (Bore[VertexIndex]->Next.find(i) == Bore[VertexIndex]->Next.end()){
            std::cout << "  -Adding Vertex " << i << " To Bore. Parent Index - " << VertexIndex << std::endl;
            Bore.push_back(new BoreVertexWildCard(i, VertexIndex));
            Bore[VertexIndex]->Next[i] = Bore.size() - 1;
        }
        VertexIndex = Bore[VertexIndex]->Next[i];
    }
    Bore[VertexIndex]->PatternsIndexes.push_back(Subpatterns.size() - 1);
}

int AhoCorasickWildCard::GetSuffixLink(int v){
    if (Bore[v]->SuffixLink == -1){
        if ((!v) || (!Bore[v]->Parent)){
            Bore[v]->SuffixLink = 0;
        } else {
            Bore[v]->SuffixLink = GetTransition(GetSuffixLink(Bore[v]->Parent), Bore[v]->Symbol);
        }
        std::cout << "-Set Suffix Link For " << Bore[v]->Symbol << " With Index " << v << ". Suffix Link - " << Bore[v]->SuffixLink << std::endl;
    }
    return Bore[v]->SuffixLink;
}

int AhoCorasickWildCard::GetTransition(int index, char to){
    if (Bore[index]->TransitionsTo.find(to) == Bore[index]->TransitionsTo.end()){
        if (Bore[index]->Next.find(to) != Bore[index]->Next.end()){
            Bore[index]->TransitionsTo[to] = Bore[index]->Next[to];
        } else {
            if (index){
                Bore[index]->TransitionsTo[to] = GetTransition(GetSuffixLink(index), to);
            } else {
                Bore[index]->TransitionsTo[to] = 0;
            }
        }
        std::cout << "-Set Transition For " << Bore[index]->Symbol << " With Index " << index << " To " << to << ". Transition - " << Bore[index]->TransitionsTo[to] << std::endl;
    }
    return Bore[index]->TransitionsTo[to];
}

void AhoCorasickWildCard::Check(int index, int i){
    for (int j = index; j != 0; j = GetSuffixLink(j)){
        std::cout << "-Checking Symbol " << Bore[j]->Symbol << " With Index " << j << " For Pattern\n";
        if (Bore[j]->PatternsIndexes.size()){
            for (auto &k: Bore[j]->PatternsIndexes){
                int IndexOfPattern = i - Subpatterns[k].length() - SubpatternsIndexes[k] + 1;
                if (IndexOfPattern >= 0){
                    std::cout << "--Subpattern \"" << Subpatterns[k] << "\" Founded.\n";
                    SubpatternsCounter[IndexOfPattern]++;
                }
            }
        }
    }
}

void AhoCorasickWildCard::DoAhoCorasickWildCard(){
    std::cout << "Search Start\n";
    int index = 0;
    SubpatternsCounter.resize(Text.length());
    for (int i = 0; i < Text.length(); i++){
        index = GetTransition(index, Text[i]);
        Check(index, i);
    }
    std::cout << "-End of search-\n";
    for (int i = 0; i <= SubpatternsCounter.size() - Pattern.length(); i++){
        if (SubpatternsCounter[i] == Subpatterns.size()){
            Res.push_back(i+1);
        }
    }
}

void AhoCorasickWildCard::Display(){
    std::cout << "-Result-\n";
    for (auto &i: Res){
        std::cout << i << std::endl;
    }
}

void AhoCorasickWildCard::Individualization(){
    int max = 0;
    for (auto &vertex: Bore){
        if (vertex->Next.size() > max){
            max = vertex->Next.size();
        }
    }
    std::cout << "Max arcs: " << max << std::endl;
    for (auto &i: Res){
        for (int j = i - 1; j < i + Pattern.length() - 1; j++){
            Text[j] = ' ';
        }
    }
    std::cout << "Answer: \"" << Text << "\"\n";
}