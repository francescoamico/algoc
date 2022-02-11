#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "tree.h"

typedef struct treeNode{
    struct treeNode *left;
    Item item;
    struct treeNode *right;
}TreeNode;
typedef TreeNode *TreeNodePtr;

static TreeNodePtr rootPtr;
static int level;
static void insertNode(TreeNodePtr *,Item);
static void print(TreeNodePtr);

typedef struct node{
    TreeNodePtr data;
    struct node *next;
}Node;
typedef Node *NodePtr;

static NodePtr head=NULL;
static NodePtr tail=NULL;

void enqueue(TreeNodePtr data);
TreeNodePtr dequeue();

void treeInit(){
    rootPtr=NULL;
}

void treeInsertNode(Item item){
    insertNode(&rootPtr,item);
}

static void insertNode(TreeNodePtr *treePtr,Item item){
    if(*treePtr==NULL){
        *treePtr=malloc(sizeof(TreeNode));
        if(*treePtr != NULL){
            (*treePtr)->item=item;
            (*treePtr)->left=NULL;
            (*treePtr)->right=NULL;
        }else printf("\nNo memory available.\n");
    }else{
        if(item < (*treePtr)->item) insertNode(&((*treePtr)->left),item);
        else{
            if(item > (*treePtr)->item) insertNode(&((*treePtr)->right),item);
            else printf("dup");
        }
    }
}

void treePrint(){
    printf("\n\n");
    print(rootPtr);
    printf("\n\n");
}

static void print(TreeNodePtr treePtr){
    if(treePtr != NULL){
        level++;
        print(treePtr->right);
        printf(">%*s%5d\n",level*5, "",treePtr->item);
        print(treePtr->left);
        level--;
    }
}

void enqueue(TreeNodePtr node){
    NodePtr newnode=malloc(sizeof(Node));
   
    if(newnode!=NULL){
        newnode->data=node;
        newnode->next=NULL;
        if(head==NULL) head=newnode;
        else tail->next=newnode;
        tail=newnode;
    }else printf("%d not inserted.No memory available\n",node->item);
}

TreeNodePtr dequeue(){
    NodePtr tmp=head;
    TreeNodePtr value=head->data;

    head=head->next;
    if(head==NULL) tail==NULL;
    free(tmp);

    return value;
}

void treelvlOrder(){
    enqueue(rootPtr);
    while(head!=NULL){
        TreeNodePtr treePtr=dequeue();
        printf("%d ",treePtr->item);
        if(treePtr->left!=NULL) enqueue(treePtr->left);
        if(treePtr->right!=NULL) enqueue(treePtr->right);
    }
}