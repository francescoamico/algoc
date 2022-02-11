#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "library.h"

#define SIZE 10
#define tipo char
#define formato "%c "

int compare(tipo *a, tipo *b){
	return((*a>*b)-(*a<*b));
}

void main(){
	
	size_t i;
	tipo array[SIZE]={'l','i','h','g','f','e','d','c','b','a'};
	void **V= (void **)malloc(SIZE*sizeof(tipo *));
	
	for (i=0;i<SIZE;i++)
		V[i]=&array[i];
	
	printf("\narray non ordinato :: ");
	for (i=0;i<SIZE;i++)
		printf(formato,*((tipo*)V[i]));	
	
	printf("\n\n1)ordine crescente\n2)ordine decrescente\n");
	scanf("%u",&i);
	assert(i==1 || i==2);
	
	i==1 ? mergeSort(V,SIZE,ascending):mergeSort(V,SIZE,descending);
	
	printf("\narray ordinato :: ");
	for (i=0;i<SIZE;i++)
		printf(formato,*((tipo*)V[i]));
}