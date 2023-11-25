#ifndef MAXFLOW_H
#define MAXFLOW_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include "./Edge.h"

extern int Mode;

class MaxFlow{
public:
    MaxFlow();
    void FindFlow();
    void FindFlowIndividualization();
    void FindMaxFlow();
    void DisplayResult();
private:
    int MinOfFlows = 0;
    int MaxFlowResult = 0;
    std::map<char, std::vector<Edge>> Graph;
    std::vector<char> CurrentWay;
    std::vector<char> VisitedVertices;
};
 
bool InputComparator(Edge& a, Edge& b);
 
bool ComparatorByMax(Edge& a, Edge& b);
 
bool OutputComparator(Edge& a, Edge& b);

#endif
