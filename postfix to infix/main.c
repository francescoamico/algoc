#include<stdio.h>
#include<string.h>
#include "item.h"
#include"stack.h"

void step(char *s){
    char *b=pop();
    char *a=pop();
    char n[strlen(a)+strlen(b)+strlen(s)+3]; //+3 = '(' , ')', '\0'
    char *p=n;
    p=strcpy(p,"(");
    p=strcat(p,a);
    p=strcat(p,s);
    p=strcat(p,b);
    p=strcat(p,")");
    push(p);
}

int main(int argc,char *argv[]){
    char *c=argv[1];
    int len=strlen(c);
    int j;

    init();
    for(int i=0;i<len;j=0,i++){
        if(c[i]=='+') {c[i+1]=0; step(&c[i]); i++;}
        else if(c[i]=='*') {c[i+1]=0; step(&c[i]); i++;}
        else if(c[i]=='-') {c[i+1]=0; step(&c[i]); i++;}
        else if(c[i]==':') {c[i+1]=0; step(&c[i]); i++;}
        else if(c[i]>='0' && c[i]<='9'){
            j=i;
            while(c[i]!=' ') i++;
            c[i]=0;//fine stringa
            push(&c[j]);
        }
    }
    printf("\nInfixed notation :: %s\n",pop());
}