#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void insert(NodePtr *startPtr,int data);
void printListBackward(NodePtr cPtr);
void printlist(NodePtr cPtr);
void freeList(NodePtr startPtr);

void main(){
    NodePtr startPtr=NULL;
    int choice=0,data;

    while(choice!=3){
        puts("\n\n1)insert node\n2)printListBackward\n3)exit\n");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                puts("insert value :: ");
                scanf("%d",&data);
                insert(&startPtr,data);
                printlist(startPtr);
                break;
            case 2:
                printf("NULL <-- ");
                printListBackward(startPtr);
                printf("startPtr");
                break;
            default:
                break;
        }
    }
    freeList(startPtr);
}

void insert(NodePtr *startPtr,int data){
    NodePtr newnode=malloc(sizeof(Node));
    NodePtr pPtr=NULL;
    NodePtr cPtr=*startPtr;
    
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=NULL;

        while(cPtr!=NULL && data > cPtr->data){
            pPtr=cPtr;
            cPtr=cPtr->next;
        }

        if(pPtr==NULL){
            newnode->next=*startPtr;
            *startPtr=newnode;
        }else{
            pPtr->next=newnode;
            newnode->next=cPtr;
        }
    }else printf("%d not inserted.No memory available\n",data);
}

void printListBackward(NodePtr cPtr){
    if(cPtr==NULL){
        puts("the list is empty\n");
        return;
    }
    if(cPtr->next==NULL) printf("%d <-- ",cPtr->data);
    else{
        printListBackward(cPtr->next);
        printf("%d <-- ",cPtr->data);
    }
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