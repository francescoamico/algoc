#include <stdio.h>
#include "item.h"
#include "graph.h"

void main(){
    unsigned int nNodes=7; //numero nodi
    Graph graph=createGraph(nNodes); 
    printf("\nGraph\n");printGraph(graph,nNodes);
    printf("\n\nGraph pre-order visit ::");GraphPreOrder(graph,nNodes,2); //terzo parametro=indice nodo radice
}
