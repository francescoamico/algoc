#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "mergeSort_btmup_queue.h"

void printlist(Item head);
void freeList(Item head);
Item merge(Item l1,Item l2);
void mergeSort(Item *start);

void main(){
    Item head=NULL;
    Item new,cPtr;

    srand(time(NULL));
    for(int i=0;i<10;i++){
        if(head==NULL){
            head=malloc(sizeof(Node));
            if(head!=NULL){
                head->data=rand()%100;
                head->next=NULL;
                cPtr=head;
            }
            else{
                printf("No memory available\n");
                return;
            }
        }
        else{
            new=malloc(sizeof(Node));
            if(new!=NULL){
                new->data=rand()%100;
                new->next=NULL;
                cPtr->next=new;
                cPtr=new;
            }
            else{
                printf("No memory available\n");
                return;
            }
        }
    }
    printlist(head);
    init();
    mergeSort(&head);
    printlist(head);
    freeList(head);
}

void printlist(Item head){
    Item cPtr=head;
    if(cPtr==NULL) puts("the list is empty\n");
    else{
        while(cPtr!=NULL){
            printf("%d --> ",cPtr->data);
            cPtr=cPtr->next;
        }
        puts("NULL\n");
    }
}

void freeList(Item head){
    Item pp=head;
    Item ppp;

    while(pp!=NULL){
        ppp=pp->next;
        free(pp);
        pp=ppp;
    }
}

Item merge(Item l1,Item l2){
	Node res;
    Item cPtr=&res;

    while(l1!=NULL && l2!=NULL){
        if(l1->data >= l2->data){
            cPtr->next=l2;
            cPtr=l2;
            l2=l2->next;
        }else{
            cPtr->next=l1;
            cPtr=l1;
            l1=l1->next;
        }
    }
    cPtr->next = (l2==NULL) ? l1:l2;
    return res.next;
}

void mergeSort(Item *start){
    Item cPtr=*start;
    Item sPtr;

    while(cPtr!=NULL){ 
        sPtr=cPtr->next;
        cPtr->next=NULL;
        enqueue(cPtr);     
        cPtr=sPtr;
    }
    
    cPtr=dequeue();
    while(!isEmpty()){
        enqueue(cPtr);
        cPtr=merge(dequeue(),dequeue());
    }
    *start=cPtr;
}                  