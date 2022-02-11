#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"
#define M 10
#define N 15
#define range 100

void main(){
    int i,j;
    Q queues[M];

    srand(time(NULL));
    for(i=0;i<M;i++){
        queues[i]=queueInit(100);
        for(j=0;j<N;j++) enqueue(queues[i],rand()%range);
    }

    for(i=0;i<M;i++){
        printf("\nCoda %d :: ",i);
        while(!queueIsEmpty(queues[i])){
            printf(" %d",dequeue(queues[i]));
        }
    }
    
    for(i=0;i<M;free(queues[i]),i++);
}