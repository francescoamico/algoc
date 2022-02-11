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

void mergesort(NodePtr *startPtr){
    NodePtr pPtr=*startPtr;
    NodePtr cPtr=pPtr->next;
    int len=1;

    while(cPtr!=NULL){  
        if(cPtr->data < pPtr->data) len++;
        pPtr=cPtr;     
        cPtr=cPtr->next;
    }

    NodePtr array[len+1];
    cPtr=*startPtr;
    int i,j,k;

    for(i=0;i<len;i++){ 
        if(cPtr->next==NULL)  array[i]=cPtr;
        else{
            array[i]=cPtr;
            pPtr=cPtr;
            while((cPtr->data >= pPtr->data) && cPtr!=NULL){
                pPtr=cPtr;        
                cPtr=cPtr->next;
            }
            pPtr->next=NULL;
        }
    }
    array[i]=NULL;
    
    for(i=len;i>1;i=(i+1)/2){
        for(j=k=0;k<i;j++,k+=2)
            array[j]=merge(array[k],array[k+1]);
        array[j]=NULL;
    }
    *startPtr=array[0];
}
