#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct queue{
    int head;
    int tail;
    int N;
    int maxN;
    FILE *file;
};

static int n=0;

Q queueInit(int maxN){
    Q coda=malloc(sizeof(Q)); 
    char filename[15];
    sprintf(filename,"queue_%d.txt",n);
    if((coda->file=fopen(filename,"wb+"))==NULL){
        puts("FILE COULD NOT BE OPENED.");
        return NULL;
    }
    n++;
    coda->head=coda->tail=coda->N=0;
    coda->maxN=maxN;
    return coda;
}

int queueIsEmpty(Q coda){
    return coda->N==0;
}

void enqueue(Q coda,Item data){
    if(coda->N < coda->maxN){
        fseek(coda->file,(coda->tail)*sizeof(Item),SEEK_SET);
        fwrite(&data,sizeof(Item),1,coda->file);
        coda->tail=(coda->tail+1)%coda->maxN;
        coda->N++;
    }else puts("Queue overflow.\n");
}

Item dequeue(Q coda){
    if(coda->N>0){
        fseek(coda->file,(coda->head)*sizeof(Item),SEEK_SET);
        Item data;
        fread(&data,sizeof(Item),1,coda->file);
        coda->head=(coda->head+1)%coda->maxN;
        coda->N--;
        return data;
    }else puts("Queue underflow.\n");
}