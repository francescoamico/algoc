#include<stdio.h>
#include<assert.h>
#include<limits.h>

//#define NDEBUG disattiva assert

typedef unsigned long long int ullint;
ullint fibonacci(unsigned int s);

void main(){

	unsigned int s;
	
	printf("inserire la posizione del termine da calcolare :: ");
	scanf("%u",&s);
	
	printf("alla posizione %u corrispone il numero %llu", s,fibonacci(s));
}

ullint fibonacci(unsigned int s){
	
	ullint a=0,b=1,tmp;
		
	if(s==0 || s==1) return s;
	for(int i=0; i<=s; i++){
		tmp=a;
		a=b;
		b=tmp+b;
		assert(b<(ULLONG_MAX/2));
	}
	return b;
}
