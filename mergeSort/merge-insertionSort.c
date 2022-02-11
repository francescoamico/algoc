#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

void divide(int array[],size_t low,size_t high,int (*compare)(int a,int b));
void merge(int array[],size_t left,size_t middle1,size_t middle2,size_t right,int (*compare)(int a,int b));
int ascending(int a,int b);
int descending(int a,int b);
void insertion_sort(int *array,size_t start,size_t end,int (*compare)(int a,int b));

size_t SIZE;

void main(){
	size_t choose;
	struct timespec start,end;
	
	printf("Inserire la taglia del vettore :: ");
	scanf("%u",&SIZE);
	assert(SIZE>0);
	
	int array[SIZE];
	srand(time(NULL));
	for(int i=0;i<SIZE;array[i]=rand()%SIZE,i++);
	
	printf("array non ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
	
	printf("\n\n1)ordine crescente\n2)ordine decrescente\n");
	scanf("%u",&choose);
	assert(choose==1 || choose==2);
	
	clock_gettime(CLOCK_REALTIME,&start);
	choose==1 ? divide(array,0,SIZE-1,ascending):divide(array,0,SIZE-1,descending);
	clock_gettime(CLOCK_REALTIME,&end);
	
	printf("\narray ordinato :: ");
	for(int i=0;i<SIZE;printf("%d ",array[i]),i++);
	printf("\ntempo impiegato per riordinare=%ld microsecondi\n",end.tv_sec*1000000+end.tv_sec/1000-start.tv_sec*1000000+start.tv_sec/1000);
}

void divide(int array[],size_t low,size_t high,int (*compare)(int a,int b)){
	size_t middle=(high+low)/2;
	if(high-low>=13){
		divide(array,low,middle,compare);
		divide(array,middle+1,high,compare);
		merge(array,low,middle,middle+1,high,compare);
	}
	else{
		insertion_sort(array,low,middle,compare);
		insertion_sort(array,middle+1,high,compare);
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

void insertion_sort(int *array,size_t start,size_t end,int (*compare)(int a,int b)){
	int i,j,v;
	for (i=start;i<=end;i++){ 
		v=*(array+i);
		for (j=i-1;(j>=0) && !(*compare)(*(array+j),v);j--)
			*(array+j+1)=*(array+j);
		*(array+j+1)=v;	
	}
}