#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "graph.h"

struct cnode{
    int v;
    struct cnode *link;
};
typedef struct cnode *Cnode;

struct node{
    Item x,y;
    int value;
    int Nneighbors;
    struct cnode *neighbors;
};

static void preOrder(Graph g,int a[],unsigned int ind);

Graph createGraph(unsigned int Nnodes){
    Graph root=calloc(Nnodes,sizeof(struct node));
    Cnode cPtr;
    int flag[Nnodes];
    int i,k,j,n;
    /*creazione nodi del grafo*/
    srand(time(NULL));
    for(i=0;i<Nnodes;i++){
        root[i].x=rand()%91; //latitudine compresa tra 0 e 90 gradi
        root[i].y=rand()%181; //longitudine compresa tra 0 e 180 gradi
        root[i].value=i;
        root[i].Nneighbors=0;
        root[i].neighbors=NULL;
    }
    /*caricamento lista di adiacenza per nodo*/
    for(i=0;i<Nnodes;i++){
        for(k=0;k<Nnodes;flag[k]=0,k++);
        cPtr=root[i].neighbors;
        while(cPtr!=NULL){
            flag[cPtr->v]=1;
            cPtr=cPtr->link;
        }
        n=root[i].Nneighbors;
        root[i].Nneighbors= n ? n+rand()%(Nnodes-n):1+rand()%(Nnodes-1); //massimo Nnodes-1 nodi adiacenti e minimo 1
        for(j=n;j<root[i].Nneighbors;j++){
            Cnode new=malloc(sizeof(struct cnode));
            if(new!=NULL){
                while((new->v=rand()%Nnodes)==i || flag[new->v]);
                flag[new->v]=1;
                new->link=root[i].neighbors;
                root[i].neighbors=new;
                /*se il nodo i è collegato al nodo new->v allora vale anche il viceversa*/
                Cnode new2=malloc(sizeof(struct cnode));
                if(new2!=NULL){
                    new2->v=i;
                    new2->link=root[new->v].neighbors;
                    root[new->v].neighbors=new2;
                    root[new->v].Nneighbors++;
                }else{
                    puts("No memory available.\n");
                    return NULL;
                }
            }else{
                puts("No memory available.\n");
                return NULL;
            }
        }
    }

    return root;
}

void printGraph(Graph g,unsigned int n){
    Cnode cPtr;
    for(int i=0;i<n;i++){
        printf("\nNode %d : (%f,%f),%d neighbors",g[i].value,g[i].x,g[i].y,g[i].Nneighbors);
        cPtr=g[i].neighbors;
        while(cPtr!=NULL){
            printf("--> %d ",cPtr->v);
            cPtr=cPtr->link;
        }
    }
}

void GraphPreOrder(Graph g,unsigned int n,unsigned int ind){
    int flag[n];
    for(int i=0;i<n;flag[i]=0,i++);
    preOrder(g,flag,ind);
}

static void preOrder(Graph g,int a[],unsigned int ind){
    if(!a[g[ind].value]){
        printf(" %d",g[ind].value);
        a[g[ind].value]=1;
        Cnode cPtr=g[ind].neighbors;
        while(cPtr!=NULL){
            preOrder(g,a,cPtr->v);
            cPtr=cPtr->link;
        }
    }
}