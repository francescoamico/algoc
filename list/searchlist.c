#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void insert(NodePtr *startPtr,int data);
void printlist(NodePtr cPtr);
NodePtr searchlist(NodePtr cPtr,NodePtr end,int data);
void freeList(NodePtr startPtr);
NodePtr mid(NodePtr startPtr);

void main(){
    NodePtr startPtr=NULL;
    NodePtr middle;
    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)insert node\n2)print list\n3)search list\n4)exit");
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
                printlist(startPtr);
                break;
            case 3:
                if(startPtr!=NULL){
                    puts("insert value to search :: ");
                    scanf("%d",&data);
                    middle=mid(startPtr);
                    if(middle->data==data) printf("%d found",data);
                    else{
                        if(data>middle->data) searchlist(middle->next,NULL,data)!=NULL ? printf("%d found",data):printf("%d not found",data);
                        else searchlist(startPtr,middle,data)!=NULL ? printf("%d found",data):printf("%d not found",data);
                    }
                }else puts("the list is empty\n");
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

NodePtr searchlist(NodePtr cPtr,NodePtr end,int data){
    if(cPtr==end || cPtr->data>data) return NULL;
    if(cPtr->data==data) return cPtr;
    else searchlist(cPtr->next,end,data);
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

NodePtr mid(NodePtr startPtr){
    NodePtr middle=startPtr;
    NodePtr end=middle->next;
    while(end!=NULL && end->next!=NULL){
        middle=middle->next;
        end=end->next->next;
    }
    return middle;
}
