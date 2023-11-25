#ifndef EDGE_H
#define EDGE_H

class Edge{
public:
    Edge(char from, char to, int maxflow, bool isreversed);
    int ResidualFlow();
    char From;
    char To;
    int Flow;
    int MaxFlow;
    bool IsReversed;
};

#endif
