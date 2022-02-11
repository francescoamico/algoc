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
    int btmup[n+1][knapsize+1];
 
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= knapsize; j++){
            if (!i || !j) 
                btmup[i][j] = 0;
            else
                btmup[i][j] = (items[i-1].weight <= j) ? MAX(btmup[i-1][j - items[i-1].weight] + items[i-1].value,btmup[i-1][j]):btmup[i-1][j];
        }
    }

    return btmup[n][knapsize];
}