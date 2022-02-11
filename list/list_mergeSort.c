#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void enqueue(NodePtr *head,NodePtr *tail,int data);
void printlist(NodePtr cPtr);
void mergesort(NodePtr *startPtr);
NodePtr merge(NodePtr const l1,NodePtr const l2);
void freeList(NodePtr startPtr);

void main(){
    NodePtr startPtr=NULL;
    NodePtr tail=NULL;
    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)insert node\n2)print list\n3)mergeSort\n4)exit");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                puts("insert value :: ");
                scanf("%d",&data);
                enqueue(&startPtr,&tail,data);
                printlist(startPtr);
                break;
            case 2:
                printlist(startPtr);
                break;
            case 3:
                if(startPtr!=NULL){
                    mergesort(&startPtr);
                    printlist(startPtr);
                }
                break;
            default:
                break;
        }
    }
    freeList(startPtr);
}

void enqueue(NodePtr *head,NodePtr *tail,int data){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=NULL;
        if(*head==NULL) *head=newnode;
        else (*tail)->next=newnode;
        *tail=newnode;
    }else printf("%d not inserted.No memory available\n",data);
}

void printlist(NodePtr cPtr){
    if(cPtr==NULL) puts("the list is empty\n");
    else{
        while(cPtr!=NULL){
            printf("%d --> ",cPtr->data);
            cPtr=cPtr->next;
        }
        puts("NULL\n");
    }
}

void mergesort(NodePtr *startPtr){
    NodePtr a,b,c;
    c=*startPtr;

    if(c==NULL || c->next==NULL) return;
    a=c;
    b=c->next;
    while(b!=NULL && b->next!=NULL){
        c=c->next;
        b=b->next->next;
    }
    b=c->next;
    c->next=NULL;
    mergesort(&a);
    mergesort(&b);
    *startPtr=merge(a,b);
}

NodePtr merge(NodePtr l1,NodePtr l2){
	Node res;
    NodePtr cPtr=&res;

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
    cPtr->next= (l2==NULL) ? l1:l2;
    return res.next;
}

void freeList(NodePtr startPtr){
    NodePtr pp=startPtr;
    NodePtr ppp;

    while(pp!=NULL){
        ppp=pp->next;
        free(pp);
        pp=ppp;
    }
}