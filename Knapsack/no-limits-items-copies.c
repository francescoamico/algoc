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
    assert(n>=1);

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
    int btmup[knapsize+1];
    int i,j;

    for(i = 0; i <= knapsize; btmup[i]=0,i++);
    
    for (i = 0; i <= knapsize; i++)//btmup[i]=valore massimo con knap size=i
        for (j = 0; j < n; j++)
            btmup[i] = (items[j].weight <= i) ? MAX(btmup[i - items[j].weight] + items[j].value,btmup[i]):btmup[i];
    
    return btmup[knapsize];
}