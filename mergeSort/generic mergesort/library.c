#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#define SIZE 10

extern int compare();

void mergeSort(void **array,size_t size,int (*sgn)()){
	divide(array,0,size-1,sgn);
}

void divide(void **array,size_t low,size_t high,int (*sgn)()){
	if(high-low>=1){
		size_t middle=(high+low)/2;
		
		divide(array,low,middle,sgn);
		divide(array,middle+1,high,sgn);
		
		merge(array,low,middle,middle+1,high,sgn);
	}
}

void merge(void **array,size_t left,size_t middle1,size_t middle2,size_t right,int (*sgn)()){
	size_t leftIndex=left;
	size_t rightIndex=middle2;
	
	void *tempArray[SIZE];
	size_t tempIndex=left;
	
	while(leftIndex<=middle1 && rightIndex<=right){
		if(compare(array[leftIndex],array[rightIndex])==(*sgn)())
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

int ascending(){
	return -1;
}

int descending(){
	return 1;
}
