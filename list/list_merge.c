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
NodePtr merge(NodePtr const l1,NodePtr const l2);
void freeList(NodePtr startPtr);
void menu(NodePtr *startPtr);

void main(){
    NodePtr startPtr1=NULL;
    NodePtr startPtr2=NULL;
    int choice=0,data;

    while(choice!=4){
        printf("\n\n1)list1\n2)list2\n3)merge list1-list2\n4)exit");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                menu(&startPtr1);
                break;
            case 2:
                menu(&startPtr2);
                break;
            case 3:
                merge(startPtr1,startPtr2);
                break;
            default:
                break;
        }
    }
    freeList(startPtr1);
    freeList(startPtr2);
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

NodePtr merge(NodePtr const l1,NodePtr const l2){
	NodePtr cl1,cl2,result,rc;
    cl1=l1;
    cl2=l2;
    if((rc=malloc(sizeof(Node)))==NULL) return NULL;
    rc->next=NULL;
    result=rc;
    while((cl1!=NULL)&&(cl2!=NULL)){
        if(cl1->data<=cl2->data){
            rc->data=cl1->data;
            cl1=cl1->next;
        }else{
            rc->data=cl2->data;
            cl2=cl2->next;
        }
        if((rc->next=malloc(sizeof(Node)))==NULL){
            freeList(result);
            return NULL;
        }
        rc=rc->next;
        rc->next=NULL;
    }
    if(cl1==NULL){
        rc->data=cl2->data;
        while((cl2=cl2->next)!=NULL){
            if((rc->next=malloc(sizeof(Node)))==NULL){
                freeList(result);
                return NULL;
            }
            rc=rc->next;
            rc->data=cl2->data;
            rc->next=NULL;
        }
    }else{
        rc->data=cl1->data;
        while((cl1=cl1->next)!=NULL){
            if((rc->next=malloc(sizeof(Node)))==NULL){
                freeList(result);
                return NULL;
            }
            rc=rc->next;
            rc->data=cl1->data;
            rc->next=NULL;
        }
    }
    printlist(result);
    freeList(result);
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

void menu(NodePtr *startPtr){
    int choice=0,data;

    while(choice!=5){
        puts("\n\n1)insert node\n2)delete node\n3)print list\n4)is empty?\n5)exit");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                puts("insert value :: ");
                scanf("%d",&data);
                insert(startPtr,data);
                printlist(*startPtr);
                break;
            case 2:
                if(!isEmpty(*startPtr)){
                    puts("insert value to delete :: ");
                    scanf("%d",&data);
                    if(delete(startPtr,data))
                        printlist(*startPtr);
                    else printf("%d not found",data);
                }else printf("Impossible to delete.The list is empty");
                break;
            case 3:
                printlist(*startPtr);
                break;
            case 4:
                isEmpty(*startPtr) ? puts("yes"):puts("no");
            default:
                break;
        }
    }
}