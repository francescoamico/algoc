#include<stdio.h>
#define dim 11

int binary_search(int *a, int key, int start, int stop);

void main(){
	int array[dim]={1,12,34,65,67,86,98,100,101,200,201};
	int key=104;
	
	printf("Ricerca del numero %u...", key);
	
	int n=binary_search(array,key,0,dim-1);

	n!=-1 ? printf("\n%u trovato in posizione %u", key,n):printf("\n%u non trovato", key);
}

int binary_search(int *a, int key, int start, int stop){
	int mid=(start+stop)/2;
	if(start>stop) return -1;
	if(*(a+mid)==key) return mid;
	else{
		if(key>*(a+mid)) return binary_search(a,key,mid+1,stop);
		else if(key<*(a+mid)) return binary_search(a,key,start,mid-1);
	}
}