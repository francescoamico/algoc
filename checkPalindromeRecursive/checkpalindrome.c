#include<stdio.h>
#include<string.h>

int palindrome(const char * const sPtr,size_t i);

void main(){
	char str[20];
	printf("Inserire stringa :: ");
	gets(str);
	
	palindrome(str,1) ? printf("stringa palindroma"):printf("stringa non palindroma");
}

int palindrome(const char * const sPtr,size_t i){
	size_t len=strlen(sPtr);
	if(len<=1) return 1;
	else{
		if(sPtr[0]==sPtr[len-i]) return palindrome(&sPtr[1],i+1);
		else return 0;
	}
}