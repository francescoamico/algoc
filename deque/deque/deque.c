#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "deque.h"

typedef struct node{
    Item data;
    struct node *next;
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
        newnode->next=NULL;
        if(head==NULL) head=newnode;
        else tail->next=newnode;
        tail=newnode;
    }else printf("No memory available\n");
}

Item dequeue(){
    NodePtr tmp=head;
    Item data=head->data;

    head=head->next;
    if(head==NULL) tail==NULL;
    free(tmp);
    
    return data;
}

void push(Item data){
    NodePtr newnode=malloc(sizeof(Node));
    
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=head;
        if(head==NULL) tail=newnode;
        head=newnode;
    }else printf("No memory available\n");
}

Item deleteFromTail(){
    NodePtr cPtr,tmp=tail;
    Item data=tail->data;

    if(head==tail) dequeue();
    else{
        cPtr=head;
        while(cPtr->next!=tail) cPtr=cPtr->next;
        cPtr->next=NULL;
        tail=cPtr;
        free(tmp);
    }
    
    return data;
}

void printlist(){
    NodePtr cPtr=head;
    
    while(cPtr!=NULL){
        printf("%d --> ",cPtr->data);
        cPtr=cPtr->next;
    }
    puts("NULL\n");
}

int isEmpty(){
    return head==NULL;
}

void acquire(Item *data){
    scanf("%d",data);
}