#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "LCRS.h"

struct lcrsnode{
    Item data;
    struct lcrsnode *sibling;
    struct lcrsnode *child;
};

struct bnode{
    Item data;
    struct bnode *left;
    struct bnode *right;
};

static void convert(bnodePtr*,lcrsnode);

lcrsnode LCRSinit(Item data){
    lcrsnode LCRSnode=malloc(sizeof(struct lcrsnode));
    if(LCRSnode!=NULL){
        LCRSnode->data=data;
        LCRSnode->child=LCRSnode->sibling=NULL;
    }else puts("No memory available.\n");
    return LCRSnode;
}

lcrsnode addChild(lcrsnode n1,Item data){
    if(n1){
        if(n1->child)
            return addSibling(n1->child,data);  
        else return (n1->child=LCRSinit(data));
    }else puts("Not possible add child.\n");
}

lcrsnode addSibling(lcrsnode n1,Item data){
    if(n1){
        while(n1->sibling)
            n1=n1->sibling;
        return (n1->sibling=LCRSinit(data));
    }else puts("Not possible add child.\n");
}

void LCRSpreOrder(lcrsnode LCRSptr){
    if(LCRSptr!=NULL){
        printf(" %d",LCRSptr->data);
        LCRSpreOrder(LCRSptr->child);
        LCRSpreOrder(LCRSptr->sibling);
    }
}
 
void LCRSlvlOrder(lcrsnode node){
    if(node!=NULL){
        static lcrsnode queue[50];
        static int N,head,tail;

        if(node->child!=NULL){
            queue[tail]=node->child;
            tail=(tail+1)%50;
            N++;
        }
        printf(" %d ",node->data);
        if(node->sibling!=NULL) LCRSlvlOrder(node->sibling);
        else{
            if(N){
                lcrsnode tmp=queue[head];
                head=(head+1)%50;
                N--;
                LCRSlvlOrder(tmp);
            }
        }
    }
}

bnodePtr LCRStoBT(lcrsnode LCRSroot){
    if(LCRSroot!=NULL){
        bnodePtr BTroot=NULL;
        convert(&BTroot,LCRSroot);
        return BTroot;
    }else{
        puts("LCRS tree is empty.\n");
        return NULL;
    }
}

static void convert(bnodePtr *BTptr ,lcrsnode LCRSptr){
    if(LCRSptr!=NULL){
        (*BTptr)=malloc(sizeof(struct bnode));
        (*BTptr)->data=LCRSptr->data;
        (*BTptr)->left=NULL;
        (*BTptr)->right=NULL;
        convert(&((*BTptr)->left),LCRSptr->child);
        convert(&((*BTptr)->right),LCRSptr->sibling);
    }
}

void BTpreOrder(bnodePtr treePtr){
    if(treePtr!=NULL){
        printf(" %d",treePtr->data);
        BTpreOrder(treePtr->left);
        BTpreOrder(treePtr->right);
    }
}