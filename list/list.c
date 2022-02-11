#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void insert(NodePtr *startPtr,int data);
int delete(NodePtr *startPtr,int data);
int isEmpty(NodePtr startPtr);
void printlist(NodePtr cPtr);
void freeList(NodePtr startPtr);

void main(){
    NodePtr startPtr=NULL;
    int choice=0,data;

    while(choice!=5){
        puts("\n\n1)insert node\n2)delete node\n3)print list\n4)is empty?\n5)exit");
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
                if(!isEmpty(startPtr)){
                    puts("insert value to delete :: ");
                    scanf("%d",&data);
                    if(delete(&startPtr,data))
                        printlist(startPtr);
                    else printf("%d not found",data);
                }else printf("Impossible to delete.The list is empty");
                break;
            case 3:
                printlist(startPtr);
                break;
            case 4:
                isEmpty(startPtr) ? puts("yes"):puts("no");
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

int delete(NodePtr *startPtr,int data){
    if(data==(*startPtr)->data){ 
       *startPtr=(*startPtr)->next;
       return data;
    }else{
        NodePtr pPtr=*startPtr;
        NodePtr cPtr=(*startPtr)->next;

        while(cPtr!=NULL && cPtr->data!=data){
            pPtr=cPtr;
            cPtr=cPtr->next;
        }

        if(cPtr!=NULL){
            pPtr->next=cPtr->next;
            return data;
        }
    }
    return 0;
}

void printlist(NodePtr cPtr){
    if(isEmpty(cPtr)) puts("the list is empty\n");
    else{
        while(cPtr!=NULL){
            printf("%d --> ",cPtr->data);
            cPtr=cPtr->next;
        }
        puts("NULL\n");
    }
}

int isEmpty(NodePtr startPtr){
    return startPtr==NULL;
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