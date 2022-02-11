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
static void insertNode(TreeNodePtr *,Item);
static void inOrder(TreeNodePtr);
static void preOrder(TreeNodePtr);
static void postOrder(TreeNodePtr);

void treeInit(){
    rootPtr=NULL;
}

int treeIsEmpty(){
    return rootPtr==NULL;
}

void treeInsertNode(Item item){
    insertNode(&rootPtr,item);
}

static void insertNode(TreeNodePtr *treePtr,Item item){
    if(*treePtr==NULL){
        *treePtr=malloc(sizeof(TreeNode));
        if(*treePtr != NULL){
            (*treePtr)->item=malloc(size(item));
            copy((*treePtr)->item,item);
            (*treePtr)->left=NULL;
            (*treePtr)->right=NULL;
        }else printf("\nNo memory available.\n");
    }else{
        if(lt(item,(*treePtr)->item)) insertNode(&((*treePtr)->left),item);
        else if(gt(item,(*treePtr)->item)) insertNode(&((*treePtr)->right),item);
    }
}

void treeInOrder(){
    if(!treeIsEmpty()) inOrder(rootPtr);
}

static void inOrder(TreeNodePtr treePtr){
    if(treePtr != NULL){
        inOrder(treePtr->left);
        puts(treePtr->item);
        inOrder(treePtr->right);
    }
}

void treePreOrder(){
    if(!treeIsEmpty()) preOrder(rootPtr);
}

static void preOrder(TreeNodePtr treePtr){
    if(treePtr != NULL){
        puts(treePtr->item);
        preOrder(treePtr->left);
        preOrder(treePtr->right);
    }
}

void treePostOrder(){
    if(!treeIsEmpty()) postOrder(rootPtr);
}

static void postOrder(TreeNodePtr treePtr){
    if(treePtr != NULL){
        postOrder(treePtr->left);
        postOrder(treePtr->right);
        puts(treePtr->item);
    }
}
