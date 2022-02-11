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

static NodePtr head;

void init(){
    head=NULL;
}

void enqueue(Item data){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=data;
        if(head==NULL){
            head=newnode;
            head->nextR=head;
            head->nextL=head;
        }
        else{
            newnode->nextR=head;
            newnode->nextL=head->nextL;
            head->nextL=newnode;
            newnode->nextL->nextR=newnode;
        }
    }else printf("No memory available\n");
}

Item dequeue(){
    NodePtr tmp=head;
    Item data=head->data;

    if(head->nextR!=head){
        head=head->nextR;
        head->nextL=tmp->nextL;
        tmp->nextL->nextR=head;
    }else head=NULL;
   
    tmp->nextR=NULL;
    tmp->nextL=NULL;
    free(tmp);    
    
    return data;
}

void push(Item data){
    enqueue(data);
    head=head->nextL;
}

Item deleteFromTail(){
    head=head->nextL;
    dequeue();  
}

void printlist(){
    NodePtr cPtr=head->nextR;
    printf("%d --> ",head->data);
    while(cPtr!=head){
        printf("%d --> ",cPtr->data);
        cPtr=cPtr->nextR;
    }
    puts("END\n");
}

int isEmpty(){
    return head==NULL;
}

void acquire(Item *data){
    scanf("%d",data);
}