#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "deque.h"

static Item *s;
static int N;
static int maxN=2;
static int head,tail;

static void resize(int toN);

void init(){
    s=malloc(maxN*sizeof(Item));
    head=tail=0;
}

void enqueue(Item data){
    if(N>=maxN){
        resize(2*maxN);
        maxN=2*maxN;
    }
    s[tail]=data;
    tail=(tail+1)%maxN;
    N++;
}

Item dequeue(){
    if((N<maxN/8) && (maxN>4)){
        resize(maxN/2);
        maxN=maxN/2;
    }
    Item value=s[head];
    head=(head+1)%maxN;
    N--;
    return value;
}

void push(Item data){
    if(N>=maxN){
        resize(2*maxN);
        maxN=2*maxN;
    }
    if(head-1==-1) head=maxN-1;
    else head--;
    s[head]=data;
    N++;
}

Item deleteFromTail(){
    if((N<maxN/8) && (maxN>4)){
        resize(maxN/2);
        maxN=maxN/2;
    }
    if(tail-1==-1) tail=maxN-1;
    else tail--;
    Item value=s[tail];
    N--;
    return value;
}

void printlist(){
    for(int i=head,j=0;j<N;i=(i+1)%maxN,j++)
        printf("%d --> ",s[i]);
    printf("END");
}

int isEmpty(){
    return N==0;
}

void acquire(Item *data){
    scanf("%d",data);
}

static void resize(int toN){
    Item *t=malloc(toN*sizeof(Item));
    for(int i=head,j=0;(j<=N)&&(j<toN);i=(i+1)%maxN,j++)
        t[j]=s[i];
    free(s);
    s=t;
    head=0;
    tail=N;
}