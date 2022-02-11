#include<stdio.h>

unsigned long long int fibonacci(unsigned int number);

void main(){

	unsigned int n;
	printf("inserire la posizione del termine da calcolare :: ");
	scanf("%u",&n);
	
	printf("alla posizione %u corrispone il numero %llu", n,fibonacci(n));
}

unsigned long long int fibonacci(unsigned int n){
	
	if(n==0 || n==1) return n;
	else return(fibonacci(n-1)+fibonacci(n-2));
}