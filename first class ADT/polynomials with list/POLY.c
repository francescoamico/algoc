#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "POLY.h"

typedef struct node *NodePtr;
typedef struct node{
    int coeff;
    int exp;
    NodePtr link;
}Node;

struct poly{NodePtr head;};
static NodePtr newnode(int,int);

void show(Poly p){
    NodePtr cPtr=p->head;
    while(cPtr!=NULL){
        printf(" +%dx^%d",cPtr->coeff,cPtr->exp);
        cPtr=cPtr->link;
    }    
    printf("\n");
}

Poly term(int coeff, int exp){
    Poly t = malloc(sizeof *t);
    if(t!=NULL){
        NodePtr new=newnode(coeff,exp);
        t->head=new;
        return t;
    }else{
        puts("No memory available.\n");
        return NULL;
    }
}

Poly add(Poly p, Poly q){
    Poly t = malloc(sizeof *t);
    if(t!=NULL){
        t->head=NULL;
        NodePtr cPtr1 = p->head;
        NodePtr cPtr2 = q->head;
        NodePtr curr,new;
        while(cPtr1!=NULL && cPtr2!=NULL){
            if(cPtr1->exp==cPtr2->exp){ 
                new=newnode(cPtr1->coeff+cPtr2->coeff,cPtr1->exp);
                if(t->head==NULL) t->head=new;
                else curr->link=new;
                curr=new;
                cPtr1=cPtr1->link;
                cPtr2=cPtr2->link;
            }else{
                if(cPtr1->exp>cPtr2->exp){
                    new=newnode(cPtr1->coeff,cPtr1->exp);
                    if(t->head==NULL) t->head=new;
                    else curr->link=new;
                    curr=new;
                    cPtr1=cPtr1->link;
                }else{
                    new=newnode(cPtr2->coeff,cPtr2->exp);
                    if(t->head==NULL) t->head=new;
                    else curr->link=new;
                    curr=new;
                    cPtr2=cPtr2->link;
                }
            }
        }
        if(cPtr1==NULL){
            while(cPtr2!=NULL){
                new = newnode(cPtr2->coeff,cPtr2->exp);
                curr->link=new;
                curr=new;
                cPtr2=cPtr2->link;
            }
        }
        if(cPtr2==NULL){
            while(cPtr1!=NULL){
                new = newnode(cPtr1->coeff,cPtr1->exp);
                curr->link=new;
                curr=new;
                cPtr1=cPtr1->link;
            }
        }
        return t;
    }else{
        puts("No memory available.\n");
        return NULL;
    }
}

Poly mult(Poly p, Poly q){ 
    Poly t=malloc(sizeof *t);
    if(t!=NULL){
        t->head=NULL;
        NodePtr new,curr,cPtr,cPtr1=p->head,cPtr2;
        while(cPtr1!=NULL){
            cPtr2=q->head;
            while(cPtr2!=NULL){
                cPtr=t->head;
                while(cPtr!=NULL && cPtr->exp!=cPtr1->exp+cPtr2->exp) cPtr=cPtr->link;
                if(cPtr!=NULL){
                   cPtr->coeff+=cPtr1->coeff*cPtr2->coeff;
                }else{
                    new = newnode(cPtr1->coeff*cPtr2->coeff,cPtr1->exp+cPtr2->exp);
                    if(t->head==NULL) t->head=new;
                    else curr->link=new;
                    curr=new;
                }
                cPtr2=cPtr2->link;
            }
            cPtr1=cPtr1->link;
        }
        return t;
    }else{
        puts("No memory available.\n");
        return NULL;
    }
}

float eval(Poly p, float x){
    float t = 0.0;
    NodePtr cPtr=p->head;
    int n=cPtr->exp;
    /*horner*/
    for(int i=n;i>=0;i--){
        if(cPtr->exp==i){
            t=t*x+cPtr->coeff;
            cPtr=cPtr->link;
        }else t*=x;
    }
    return t;
 }

static NodePtr newnode(int coeff,int exp){
    NodePtr new = malloc(sizeof(Node));
    if(new!=NULL){
        new->coeff=coeff;
        new->exp=exp;
        new->link=NULL;
        return new;
    }else{
        puts("No memory available.\n");
        return NULL;
    }
}

void freePOLY(Poly x){
    NodePtr cPtr=x->head;
    NodePtr tmp;
    while(cPtr!=NULL){
        tmp=cPtr->link;
        free(cPtr);
        cPtr=tmp;
    }
    free(x);
}