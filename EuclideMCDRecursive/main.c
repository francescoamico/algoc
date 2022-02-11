#include<stdio.h>

size_t MCD(size_t m, size_t n);
void scambia(int *a, int *b);

void main(){
	size_t m,n;
	
	puts("Inserire due numeri naturali ::");
	scanf("%u%u",&m,&n);
	
	if(m<n) scambia(&m,&n);
	
	printf("MCD(%u,%u)=%u", m,n,MCD(m,n));
}

void scambia(int *a, int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

size_t MCD(size_t m, size_t n){
	//passo base
	if(!n) return m; 
	if(!m%n) return n;
	return MCD(n,m%n); //passo induttivo
}