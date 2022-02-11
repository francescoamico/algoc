#include<stdio.h>
#include<string.h>
#include"stack.h"

int main(int argc,char *argv[]){
    char *c=argv[1];
    int len=strlen(c);
    int a,b;

    init();
    for(int i=0;i<len;i++){
        if(c[i]=='+') push(pop()+pop());
        if(c[i]=='*') push(pop()*pop());
        if(c[i]=='-'){
            a=pop();
            b=pop(); 
            b-=a;
            push(b);
        }
        if(c[i]==':'){
            a=pop();
            b=pop(); 
            b/=a;
            push(b);
        }   
        if(c[i]>='0' && c[i]<='9') push(0);
        while(c[i]>='0' && c[i]<='9') push(10*pop()+c[i++]-'0');
    }
    printf("result=%d",pop());
}