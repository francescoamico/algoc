#include<stdio.h>
#include<time.h>

unsigned long long int fibonacci(unsigned int number);

void main(){

	time_t start=time(NULL);
	printf("fibonacci(43) = %llu", fibonacci(43));
	time_t end=time(NULL);
	puts("\nTempo di calcolo per fibonacci(43).");
	printf("%lf secondi",difftime(end,start));
	printf("\n%f minuti",difftime(end,start)/60.0);
}

unsigned long long int fibonacci(unsigned int n){
	if(n==0 || n==1) return n;
	else return(fibonacci(n-1)+fibonacci(n-2));
}