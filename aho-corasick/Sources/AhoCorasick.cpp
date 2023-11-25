#include "../Headers/AhoCorasick.h"

bool cmp(std::pair<int, int> a, std::pair<int, int> b){
    if (a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

AhoCorasick::AhoCorasick(){
    Bore.push_back(new BoreVertex());
    std::cin >> Text;
    std::string Pattern;
    int Amount = 0;
    std::cin >> Amount;
    for (int i = 0; i < Amount; i++){
        std::cin >> Pattern;
        SetPatternToBore(Pattern);
    }
}

void AhoCorasick::SetPatternToBore(std::string &Stroke){
    Patterns.push_back(Stroke);
    int VertexIndex = 0;
    std::cout << "Adding \"" << Stroke << "\" To Bore\n";
    for (auto &i: Stroke){
        if (Bore[VertexIndex]->Next.find(i) == Bore[VertexIndex]->Next.end()){
            std::cout << "  -Adding Vertex " << i << " To Bore. Parent Index - " << VertexIndex << std::endl;
            Bore.push_back(new BoreVertex(i, VertexIndex));
            Bore[VertexIndex]->Next[i] = Bore.size() - 1;
        }
        VertexIndex = Bore[VertexIndex]->Next[i];
    }
    std::cout << "    -Tagging Vertex " << Bore[VertexIndex]->Symbol << " With Index " << VertexIndex << " As Pattern\n";
    Bore[VertexIndex]->Pattern = Patterns.size() - 1;
}

int AhoCorasick::GetSuffixLink(int index){
    if (Bore[index]->SuffixLink == -1){
        if ((!index) || (!Bore[index]->Parent)){
            Bore[index]->SuffixLink = 0;
        } else {
            Bore[index]->SuffixLink = GetTransition(GetSuffixLink(Bore[index]->Parent), Bore[index]->Symbol);
        }
        std::cout << "-Set Suffix Link For " << Bore[index]->Symbol << " With Index " << index << ". Suffix Link - " << Bore[index]->SuffixLink << std::endl;
    }
    return Bore[index]->SuffixLink;
}

int AhoCorasick::GetTransition(int index, char to){
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

void AhoCorasick::Check(int index, int i){
    for (int j = index; j != 0; j = GetSuffixLink(j)){
        std::cout << "-Checking Symbol " << Bore[j]->Symbol << " With Index " << j << " For Pattern\n";
        if (Bore[j]->Pattern >= 0){
            std::cout << "--Pattern \"" << Patterns[Bore[j]->Pattern] << "\" Founded--\n";
            Res.push_back(std::make_pair(i - Patterns[Bore[j]->Pattern].size() + 1, Bore[j]->Pattern + 1));
        }
    }
}

void AhoCorasick::DoAhoCorasick(){
    std::cout << "Search Start\n";
    int index = 0;
    for (int i = 0; i < Text.size(); i++){
        index = GetTransition(index, Text[i]);
        Check(index, i + 1);
    }
    std::cout << "-End of search-\n";
    std::sort(Res.begin(), Res.end(), cmp);
}

void AhoCorasick::Display(){
    std::cout << "-Result-\n";
    for (auto &i: Res){
        std::cout << i.first << " " << i.second << std::endl;
    }
}

void AhoCorasick::Individualization(){
    int max = 0;
    for (auto &vertex: Bore){
        if (vertex->Next.size() > max){
            max = vertex->Next.size();
        }
    }
    std::cout << "Max arcs: " << max << std::endl;
    for (auto &i: Res){
        for (int j = i.first - 1; j < i.first + Patterns[i.second - 1].size() - 1; j++){
            Text[j] = ' ';
        }
    }
    std::cout << "Answer: \"" << Text << "\"\n";
}