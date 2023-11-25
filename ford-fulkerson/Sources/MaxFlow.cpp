#include "../Headers/MaxFlow.h"

char StartVertex;
char FiniteVertex;

bool InputComparator(Edge& a, Edge& b) {
    return (FiniteVertex - b.To) > (FiniteVertex - a.To);
}
 
bool ComparatorByMax(Edge& a, Edge& b) {
    return a.ResidualFlow() > b.ResidualFlow();
}
 
bool OutputComparator(Edge& a, Edge& b) {
    return b.To > a.To;
}
 
MaxFlow::MaxFlow(){
    int n, MaxFlow;
    char VertexFrom, VertexTo;
    std::cin >> n;
    std::cin >> StartVertex >> FiniteVertex;
    for (int i = 0; i < n; i++){
        std::cin >> VertexFrom >> VertexTo >> MaxFlow;
        Graph[VertexFrom].push_back(Edge(VertexFrom, VertexTo, MaxFlow, 0));
        Graph[VertexTo].push_back(Edge(VertexTo, VertexFrom, MaxFlow, 1));
    }
    if (Mode == 1){
        for (auto &Vertex: Graph){
            std::sort(Vertex.second.begin(), Vertex.second.end(), InputComparator);
        }
    }
}
 
void MaxFlow::FindFlow(){
    if (CurrentWay.back() == FiniteVertex){
        return;
    }
    for (auto &Edge: Graph[CurrentWay.back()]){
        if ((std::find(VisitedVertices.begin(), VisitedVertices.end(), Edge.To) == VisitedVertices.end()) && (Edge.ResidualFlow())){
            if ((!MinOfFlows) || (MinOfFlows > Edge.ResidualFlow())){
                MinOfFlows = Edge.ResidualFlow();
            }
            CurrentWay.push_back(Edge.To);
            VisitedVertices.push_back(Edge.To);
            int FindedMin = MinOfFlows;
            FindFlow();
            if (MinOfFlows != -1){
                Edge.Flow += MinOfFlows;
                for (auto &i: Graph[Edge.To]){
                    if (i.IsReversed && (i.To == Edge.From)){
                        i.Flow -= MinOfFlows;
                        break;
                    }
                }
                return;
            }
            MinOfFlows = FindedMin;
            CurrentWay.pop_back();
            VisitedVertices.pop_back();
        }
    }
    MinOfFlows = -1;
}
 
void MaxFlow::FindFlowIndividualization(){
    if (CurrentWay.back() == FiniteVertex){
        return;
    }
    std::sort(Graph[CurrentWay.back()].begin(), Graph[CurrentWay.back()].end(), ComparatorByMax);
    for (auto &Edge: Graph[CurrentWay.back()]){
        if ((std::find(VisitedVertices.begin(), VisitedVertices.end(), Edge.To) == VisitedVertices.end()) && (Edge.ResidualFlow())){
            if ((!MinOfFlows) || (MinOfFlows > Edge.ResidualFlow())){
                MinOfFlows = Edge.ResidualFlow();
            }
            CurrentWay.push_back(Edge.To);
            VisitedVertices.push_back(Edge.To);
            int FindedMin = MinOfFlows;
            FindFlowIndividualization();
            if (MinOfFlows != -1){
                Edge.Flow += MinOfFlows;
                for (auto &i: Graph[Edge.To]){
                    if (i.To == Edge.From){
                        i.Flow -= MinOfFlows;
                        break;
                    }
                }
                return;
            }
            MinOfFlows = FindedMin;
            CurrentWay.pop_back();
            VisitedVertices.pop_back();
        }
    }
    MinOfFlows = -1;
}
 
void MaxFlow::FindMaxFlow(){
    while (MinOfFlows != -1) {
        CurrentWay.push_back(StartVertex);
        VisitedVertices.push_back(StartVertex);
        MinOfFlows = 0;
        if (Mode == 1){
            FindFlow();
        } else {
            FindFlowIndividualization();
        }
        if (MinOfFlows != -1){
            MaxFlowResult += MinOfFlows;
        }
        CurrentWay.clear();
        VisitedVertices.clear();
    };
}
 
void MaxFlow::DisplayResult(){
    std::cout << MaxFlowResult << std::endl;
    if (MaxFlowResult){
        for (auto &Vertex: Graph){
            std::sort(Vertex.second.begin(), Vertex.second.end(), OutputComparator);
            for (auto &Edge : Vertex.second){
                if (!Edge.IsReversed){
                    std::cout << Edge.From << ' ' << Edge.To << ' ' << Edge.Flow << std::endl;
                }  
            }
        }
    }
}
