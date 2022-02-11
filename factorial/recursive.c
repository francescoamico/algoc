#include<stdio.h>

unsigned long long int factorial(unsigned int number);

void main(){

	unsigned int n;
	printf("fattoriale del numero?");
	scanf("%u",&n);
	
	printf("fattoriale del numero %u = %llu", n,factorial(n));
}

unsigned long long int factorial(unsigned int number){
	
	if(number<=1) return 1;
	else return(number*factorial(number-1));
}