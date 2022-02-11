#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

typedef struct node{
    Item data;
    struct node *next;
}Node;
typedef Node *NodePtr;

struct queue{
    NodePtr head;
    NodePtr tail;
};

Q queueInit(){
    Q coda=malloc(sizeof(Q)); 
    coda->head=NULL;
    coda->tail=NULL;
    return coda;
}

int queueIsEmpty(Q coda){
    return coda->head==NULL;
}

void enqueue(Q coda,Item data){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=NULL;
        if(queueIsEmpty(coda)) coda->head=newnode;
        else (coda->tail)->next=newnode;
        coda->tail=newnode;
    }else printf("%d not inserted.No memory available\n",data);
}

Item dequeue(Q coda){
    if(!queueIsEmpty(coda)){
        NodePtr tmp=coda->head;
        Item value=tmp->data;

        coda->head=(coda->head)->next;
        if(queueIsEmpty(coda)) coda->tail==NULL;
        free(tmp);

        return value;
    }else printf("Queue empty.");
}