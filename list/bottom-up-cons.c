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
NodePtr merge(NodePtr const l1,NodePtr const l2);
void freeList(NodePtr startPtr);
void mergesort(NodePtr *startPtr);

void main(){
    NodePtr startPtr=NULL;
    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)insert node\n2)print list\n3)mergeSort\n4)exit");
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
                mergesort(&startPtr);
                printlist(startPtr);
            default:
                break;
        }
    }
    freeList(startPtr);
}

void insert(NodePtr *startPtr,int data){
    NodePtr newnode=malloc(sizeof(Node));
    NodePtr pPtr;
    NodePtr cPtr=*startPtr;
    
    if(newnode!=NULL){
        newnode->data=data;
        newnode->next=NULL;

        if(*startPtr==NULL) *startPtr=newnode;
        else{
            while(cPtr!=NULL){
                pPtr=cPtr;
                cPtr=cPtr->next;
            }
            pPtr->next=newnode;
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
    return result;
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

void mergesort(NodePtr *startPtr){
    NodePtr cPtr=*startPtr;
    int len=0;

    while(cPtr!=NULL){
        cPtr=cPtr->next;
        len++;
    }

    NodePtr array[len+1];
    cPtr=*startPtr;
    int i,j,k;

    for(i=0;i<len;i++){
        array[i]=cPtr;
        cPtr=cPtr->next;
        array[i]->next=NULL;
    }
    array[i]=NULL;

    for(i=len;i>1;i=(i+1)/2){
        for(j=k=0;k<i;j++,k+=2)
            array[j]=merge(array[k],array[k+1]);
        array[j]=NULL;
    }
    *startPtr=array[0];
}
