#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void push(NodePtr *topPtr,int data);
int pop(NodePtr *topPtr);
void printlist(NodePtr cPtr);
void freeList(NodePtr startPtr);

void main(){
    NodePtr startPtr=NULL;
    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)push\n2)print list\n3)pop\n4)exit");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                puts("insert value :: ");
                scanf("%d",&data);
                push(&startPtr,data);
                printlist(startPtr);
                break;
            case 2:
                printlist(startPtr);
                break;
            case 3:
                if(startPtr!=NULL){
                    printf("%d deleted\n",pop(&startPtr));
                    printlist(startPtr);
                }
                break;
            default:
                break;
        }
    }
    freeList(startPtr);
}

void push(NodePtr *topPtr,int data){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=*topPtr;
        *topPtr=newnode;
        
    }else printf("%d not inserted.No memory available\n",data);
}

int pop(NodePtr *topPtr){
    NodePtr tmp=*topPtr;
    int value=(*topPtr)->data;

    *topPtr=(*topPtr)->next;
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