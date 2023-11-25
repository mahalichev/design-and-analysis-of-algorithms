#include "../Headers/Edge.h"

Edge::Edge(char from, char to, int maxflow, bool isreversed): From(from), To(to), MaxFlow(maxflow), IsReversed(isreversed){
    if (IsReversed){
        Flow = MaxFlow;
    } else {
        Flow = 0;
    }
}
 
int Edge::ResidualFlow(){
    return MaxFlow - Flow;
}
