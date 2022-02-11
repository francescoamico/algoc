#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "deque.h"

typedef struct node{
    Item data;
    struct node *nextR;
     struct node *nextL;
}Node;
typedef Node *NodePtr;

static NodePtr head,tail;

void init(){
    head=NULL;
    tail=NULL;
}

void enqueue(Item data){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=data;
        newnode->nextR=NULL;
        newnode->nextL=tail;
        if(head==NULL) head=newnode;
        else tail->nextR=newnode;
        tail=newnode;
    }else printf("No memory available\n");
}

Item dequeue(){
    NodePtr tmp=head;
    Item data=head->data;

    head=head->nextR;
    if(head!=NULL){
        head->nextL=NULL;
        tmp->nextR=NULL;
    }else tail=NULL;

    free(tmp);    
    
    return data;
}

void push(Item data){
    NodePtr newnode=malloc(sizeof(Node));
    
    if(newnode!=NULL){
        newnode->data=data;
        newnode->nextR=head;
        newnode->nextL=NULL;
        if(head==NULL) tail=newnode;
        else head->nextL=newnode;
        head=newnode;
    }else printf("No memory available\n");
}

Item deleteFromTail(){
    NodePtr tmp=tail;
    Item data=tail->data;

    tail=tail->nextL;
    if(tail!=NULL){
        tail->nextR=NULL;
        tmp->nextL=NULL;
    }else head=NULL;

    free(tmp);
    
    return data;
}

void printlist(){
    NodePtr cPtr=head;
    
    while(cPtr!=NULL){
        printf("%d --> ",cPtr->data);
        cPtr=cPtr->nextR;
    }
    puts("NULL\n");
}

int isEmpty(){
    return head==NULL;
}

void acquire(Item *data){
    scanf("%d",data);
}