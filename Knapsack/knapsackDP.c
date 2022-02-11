#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define N 4
#define KNAPSIZE 5

typedef struct{
    int weight;
    int value;
}Item;

static int dpTable[N][KNAPSIZE];//static minimo privilegio(visibile solo alle funzioni all'interno del file)
int knapsack(Item items[],int n,int knapsize);

void main(){
    Item items[N];

    puts("\ni | W | V");
    srand(time(NULL));
    for(int i=0;i<N;i++){
        items[i].weight=1+rand()%9; 
        items[i].value=1+rand()%9; 
        printf("%d | %d | %d\n",i,items[i].weight,items[i].value);
    }

    printf("\nwith knapsack size %d the maximum value is %d\n",KNAPSIZE,knapsack(items,N,KNAPSIZE));
}

int knapsack(Item items[],int n,int knapsize){
    if (knapsize <= 0 || !n) return 0;
    if (items[n-1].weight > knapsize) return knapsack(items, n-1, knapsize);
    if (!dpTable[n-1][knapsize - items[n-1].weight])
        dpTable[n-1][knapsize - items[n-1].weight] = knapsack(items, n-1, knapsize - items[n-1].weight);
    if (!dpTable[n-1][knapsize]) 
        dpTable[n-1][knapsize] = knapsack(items, n-1, knapsize);
    return MAX(dpTable[n-1][knapsize - items[n-1].weight] + items[n-1].value,dpTable[n-1][knapsize]);
}