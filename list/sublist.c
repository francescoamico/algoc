#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
typedef Node *NodePtr;

typedef struct nodeS{
    NodePtr list;
    struct nodeS *next;
}NodeS;
typedef NodeS *NodeSPtr;

void enqueue(NodePtr *head,NodePtr *tail,int data);
void printlist(NodePtr cPtr);
void freeList(NodePtr startPtr);
void freeSlist(NodeSPtr head);
NodeSPtr sublist(NodePtr l);

void main(){
    NodePtr startPtr=NULL;
    NodePtr tail=NULL;
    NodeSPtr head,cPtr;
    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)insert node\n2)print list\n3)sublist\n4)exit");
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
                    head=sublist(startPtr);
                    cPtr=head;
                    while(cPtr!=NULL){
                        printlist(cPtr->list);
                        cPtr=cPtr->next;
                    }
                } 
                break;
            default:
                break;
        }
    }
    freeList(startPtr);
    freeSlist(head);
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
    if(cPtr==NULL) puts("NULL\n");
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

void freeSlist(NodeSPtr head){
    NodeSPtr pp=head;
    NodeSPtr ppp;

    while(pp!=NULL){
        ppp=pp->next;
        free(pp->list);
        free(pp);
        pp=ppp;
    }
}

NodeSPtr sublist(NodePtr l){
    NodeSPtr new;
    NodePtr newnode;
    NodeSPtr cPtr,sPtr;

    if(l==NULL){
        new=malloc(sizeof(NodeS));
        new->list=NULL;
        new->next=NULL;
        return new;
    }
    else{
        cPtr=sublist(l->next);
        sPtr=cPtr;
        while(sPtr!=NULL){
            new=malloc(sizeof(NodeS));
            newnode=malloc(sizeof(Node));
            newnode->data=l->data;
            newnode->next=sPtr->list;
            new->list=newnode;
            new->next=cPtr;
            cPtr=new;
            sPtr=sPtr->next;
        }
        return cPtr;
    }
}