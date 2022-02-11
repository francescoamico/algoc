#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))

typedef struct{
    int weight;
    int value;
}Item;

int knapsack(Item items[],int n,int knapsize);

void main(){
    int n,knapsize;

    printf("\ninsert number of items :: ");
    scanf("%d",&n);
    assert(n>=0);

    Item items[n];

    puts("\ni | W | V");
    srand(time(NULL));
    for(int i=0;i<n;i++){
        items[i].weight=1+rand()%9; 
        items[i].value=1+rand()%9; 
        printf("%d | %d | %d\n",i,items[i].weight,items[i].value);
    }

    printf("\ninsert knapsack size :: ");
    scanf("%d",&knapsize);
    assert(knapsize>=0);

    printf("\nwith knapsack size %d the maximum value is %d\n",knapsize,knapsack(items,n,knapsize));
}

int knapsack(Item items[],int n,int knapsize){
    if(knapsize<=0 || !n) return 0;
    if(items[n-1].weight>knapsize) return knapsack(items,n-1,knapsize);
    return MAX(knapsack(items,n-1,knapsize-items[n-1].weight)+items[n-1].value,knapsack(items,n-1,knapsize));
}