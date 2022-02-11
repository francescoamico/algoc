#include<stdio.h>
#include<limits.h>
#define MAX 50 //possiamo calcolare solo i numeri in posizione[0-49]

unsigned long int fibonacci(unsigned int n);
unsigned long int dpTable[MAX];

void main(){
	unsigned int n;
	printf("inserire la posizione del termine da calcolare :: ");
	scanf("%u",&n);
	
	printf("alla posizione %u corrispone il numero %lu", n,fibonacci(n));
}

unsigned long int fibonacci(unsigned int n){
	/*static unsigned long int dptable[MAX]; 
	alternativa all'inizializzazione globale(non memorizza nello stack)
	*/
	if(n>=MAX) return ULONG_MAX;
	if(n==0 || n==1) return n;
	if(dpTable[n]==0)
		dpTable[n]=fibonacci(n-1)+fibonacci(n-2);
	return dpTable[n];
	
}