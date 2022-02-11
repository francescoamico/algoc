#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

void print(int a[]);
void merge(int array[],size_t left,size_t middle1,size_t middle2,size_t right);
void mergesort(int array[],size_t lenght);

void main(){
    int array[SIZE]={128,14,7,6,5,0,3,2,1,0};

    printf("array non ordinato :: ");
    print(array);

    mergesort(array,SIZE);

    printf("\narray ordinato :: ");
    print(array);
}

void print(int a[]){
    for(int i=0;i<SIZE;i++)
        printf("%d ",a[i]);
}

void merge(int array[],size_t left,size_t middle1,size_t middle2,size_t right){
	size_t leftIndex=left;
	size_t rightIndex=middle2;
	
	int tempArray[SIZE];
	size_t tempIndex=left;
	
	while(leftIndex<=middle1 && rightIndex<=right){
		if(array[leftIndex]<=array[rightIndex])
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

void mergesort(int array[],size_t length){
    for(int sz=1;sz<length;sz+=sz){
        for(int lo=0;lo<length-sz;lo+=sz+sz)
            merge(array,lo,lo+sz-1,lo+sz,MIN(lo+sz+sz-1,length-1));
    }
}
