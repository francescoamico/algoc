#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

int len=0;

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
        len++;
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
    NodeSPtr head=malloc(sizeof(NodeS));
    NodeSPtr new,cPtr,ccPtr,scPtr; 
    NodePtr newnode,l1;

    // creo 2^len nodi(numero sottoliste con lunghezza lista=len)
    if(head!=NULL){
        head->next=NULL;
        cPtr=head;
        for(int i=1;i<pow(2,len);cPtr=new,i++){
            new=malloc(sizeof(NodeS));
            if(new!=NULL){
                cPtr->next=new;
                new->next=NULL;
            }else{
                printf("No memory available\n");
                return NULL;
            }
        }
    }else{
        printf("No memory available\n");
        return NULL;
    }
    
    //carico la sottolista vuota e quella con solo il primo elemento
    cPtr=head;
    cPtr->list=NULL;
    newnode=malloc(sizeof(Node));
    if(newnode!=NULL){
        newnode->data=l->data;
        newnode->next=NULL;
        cPtr=cPtr->next;
        cPtr->list=newnode;
    }else{
        printf("No memory available\n");
        return NULL;
    }
    //carico le restanti a partire dalle prime due 
    cPtr=cPtr->next;
    scPtr=cPtr;
    ccPtr=head;
    l1=l->next;
    while(cPtr!=NULL){
        while(ccPtr!=scPtr){
            newnode=malloc(sizeof(Node));
            if(newnode!=NULL){
                newnode->data=l1->data;
                newnode->next=ccPtr->list;
                cPtr->list=newnode;
                ccPtr=ccPtr->next;
                cPtr=cPtr->next;
            }else{
                printf("No memory available\n");
                return NULL;
            }   
        }
        scPtr=cPtr;
        l1=l1->next;
        ccPtr=head;
    }

    return head;
    
}