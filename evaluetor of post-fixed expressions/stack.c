#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

struct node{
    Item data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

static NodePtr topPtr;

void init(){topPtr=NULL;}
int isEmpty(){return topPtr==NULL;}

void push(Item item){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=item;
        newnode->next=topPtr;
        topPtr=newnode;
        
    }else printf("No memory available\n");
}

Item pop(){
    NodePtr tmp=topPtr;
    Item value=(topPtr)->data;

    topPtr=(topPtr)->next;
    free(tmp);
    return value;
}

void printlist(){
    NodePtr cPtr=topPtr;
    
    while(cPtr!=NULL){
        printf("%d --> ",cPtr->data);
        cPtr=cPtr->next;
    }
    puts("NULL\n");
}