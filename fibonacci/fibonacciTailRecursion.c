#include<stdio.h>
#include<time.h>

typedef unsigned long long int ullint;

ullint fibonacci(unsigned int n, ullint a, ullint b);

void main(){

	time_t start=time(NULL);
	printf("fibonacci(43) = %llu", fibonacci(43,0,1));
	time_t end=time(NULL);
	puts("\nTempo di calcolo per fibonacci(43).");
	printf("%lf secondi",difftime(end,start));
	printf("\n%f minuti",difftime(end,start)/60.0);
}

ullint fibonacci(unsigned int n, ullint a, ullint b){
	if(n==0) return a;
	if(n==1) return b;
	return fibonacci(n-1,b,a+b);
}