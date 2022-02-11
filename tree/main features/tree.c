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
