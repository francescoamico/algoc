#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SIZE 10

void divide(int array[],size_t low,size_t high,int (*compare)(int a,int b));
void merge(int array[],size_t left,size_t middle1,size_t middle2,size_t right,int (*compare)(int a,int b));
int ascending(int a,int b);
int descending(int a,int b);

void main(){
	int array[SIZE];
	size_t choose;
	
	for(int i=0;i<SIZE;array[i]=rand()%90+10,i++);
	
	printf("array non ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
	
	printf("\n\n1)ordine crescente\n2)ordine decrescente\n");
	scanf("%u",&choose);
	assert(choose==1 || choose==2);
	
	choose==1 ? divide(array,0,SIZE-1,ascending):divide(array,0,SIZE-1,descending);
	
	printf("\narray ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
}

void divide(int array[],size_t low,size_t high,int (*compare)(int a,int b)){
	if(high-low>=1){
		size_t middle=(high+low)/2;
		
		divide(array,low,middle,compare);
		divide(array,middle+1,high,compare);
		
		merge(array,low,middle,middle+1,high,compare);
	}
}

void merge(int array[],size_t left,size_t middle1,size_t middle2,size_t right,int (*compare)(int a,int b)){
	size_t leftIndex=left;
	size_t rightIndex=middle2;
	
	int tempArray[SIZE];
	size_t tempIndex=left;
	
	while(leftIndex<=middle1 && rightIndex<=right){
		if((*compare)(array[leftIndex],array[rightIndex]))
			tempArray[tempIndex++]=array[leftIndex++];
		else
			tempArray[tempIndex++]=array[rightIndex++];
	}
	
	if(leftIndex==middle2){
		while(rightIndex<=right)
			tempArray[tempIndex++]=array[rightIndex++];
	}
	else{
		while(leftIndex<=middle1)
			tempArray[tempIndex++]=array[leftIndex++];
	}
	
	for(int i=left;i<=right;array[i]=tempArray[i],i++);
}

int ascending(int a,int b){return a<b;}
int descending(int a,int b){return a>b;}