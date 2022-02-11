#include<stdio.h>
#include<stdlib.h>
#include "mergeSort_btmup_queue.h"

typedef struct queue{
    Item list;
    struct queue *next;
}Queue;
typedef Queue *QueuePtr;

static QueuePtr head,tail;

void init(){
    head=NULL;
}

void enqueue(Item list){
    QueuePtr newnode=malloc(sizeof(Queue));
   
    if(newnode!=NULL){
        newnode->list=list;
        newnode->next=NULL;
        if(head==NULL) head=newnode;
        else tail->next=newnode;
        tail=newnode;
    }else printf("No memory available\n");
}

Item dequeue(){
    QueuePtr tmp=head;
    Item list=head->list;
    head=head->next;
    if(head==NULL) tail==NULL;
    free(tmp);
    return list;
}

int isEmpty(){
    return head==NULL;
}