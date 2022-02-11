#include "item.h"

typedef struct node *Graph;

Graph createGraph(unsigned int);
void printGraph(Graph,unsigned int);
void GraphPreOrder(Graph,unsigned int,unsigned int);