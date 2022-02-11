#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void enqueue(NodePtr *head,NodePtr *tail,int data);
int dequeue(NodePtr *head,NodePtr *tail);
void printlist(NodePtr cPtr);
void freeList(NodePtr startPtr);

void main(){
    NodePtr startPtr=NULL;
    NodePtr tail=NULL;
    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)enqueue\n2)print list\n3)denqueue\n4)exit");
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
                    printf("%d deleted\n",dequeue(&startPtr,&tail));
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

int dequeue(NodePtr *head,NodePtr *tail){
    NodePtr tmp=*head;
    int value=(*head)->data;

    *head=(*head)->next;
    if(*head==NULL) *tail==NULL;
    free(tmp);

    return value;
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

void freeList(NodePtr startPtr){
    NodePtr pp=startPtr;
    NodePtr ppp;

    while(pp!=NULL){
        ppp=pp->next;
        free(pp);
        pp=ppp;
    }
}