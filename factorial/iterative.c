#include<stdio.h>

unsigned long long int factorial(unsigned int number);

void main(){

	unsigned int n;
	printf("fattoriale del numero?");
	scanf("%u",&n);
	
	printf("fattoriale del numero %u = %llu", n,factorial(n));
}

unsigned long long int factorial(unsigned int number){
	unsigned long long int factorial=1;
	for(int counter=number; counter>=1; counter--)
		factorial *= counter;
	return factorial;
}