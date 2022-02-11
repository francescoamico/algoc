#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "item.h"
#include "tree.h"

void main(){
    treeInit();
    srand(time(NULL));
    printf("Numeri caricati ::");
    for(int i=0;i<15;i++){
        Item item=rand()%15;
        printf("  %d",item);
        treeInsertNode(item);
    }
    treePrint();
    printf("Visita per livelli ::");
    treelvlOrder();
}