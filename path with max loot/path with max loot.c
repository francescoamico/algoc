#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define N 3
#define M 3

int dptable[N][M];
int tpath[N][M];

int loot(int a[][M],int i,int j);
void path(int a[][M],int n,int m);
int Max(int a,int b);
void print(int a[][M]);

void main(){
    int array[N][M];

    srand(time(NULL));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            array[i][j]=1+rand()%10;
    }
  
    printf("\nTabella\n");
    print(array);
    printf("\nLoot = %d", loot(array,N-1,M-1));
   
    printf("\n\nPath ::\n");
    path(array,N-1,M-1);
	print(tpath);
}

int loot(int a[][M],int i,int j){
    if(!i && !j) return a[i][j];
    if(!i && !dptable[i][j]) return dptable[i][j]=(loot(a,i,j-1)+a[i][j]);
    if(!j && !dptable[i][j]) return dptable[i][j]=(loot(a,i-1,j)+a[i][j]);
    if(!dptable[i][j]) dptable[i][j]=(Max(loot(a,i,j-1),loot(a,i-1,j))+a[i][j]);
    return dptable[i][j];
}

void path(int a[][M],int n,int m){
	tpath[0][0]=1;
    int max=dptable[n][m];
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(dptable[i][j]==max){
                tpath[i][j]=1;
                max-=a[i][j];
            }
        }
    }
}

int Max(int a,int b){
    return a>b ? a:b;
}

void print(int a[][M]){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}