#include<stdio.h>
#define SIZE 10

void divide(int array[],size_t low,size_t high);
void merge(int array[],size_t left,size_t middle1,size_t middle2,size_t right);

void main(){
	int array[SIZE]={9,8,7,6,5,4,3,2,1,0};
	
	printf("array non ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
	
	divide(array,0,SIZE-1);
	
	printf("\narray ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
}

void divide(int array[],size_t low,size_t high){
	if(high-low>=1){
		size_t middle=(high+low)/2;
		
		divide(array,low,middle);
		divide(array,middle+1,high);
		
		merge(array,low,middle,middle+1,high);
	}
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
