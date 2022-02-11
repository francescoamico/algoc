#include<stdio.h>
#include<stdlib.h>
#include "array_maxn.h"
#define len 50

static Item array[len];

void init(){printf("\nATTENTION! MAX_LEN STACK=%d",len);}

int isEmpty(){return !array[0]; }

void push(Item item){
    if(item){//all'interno dello stack non si può inserire lo zero
        if(isEmpty())
            array[0]=item;    
        else{
            for(int i=len-1;i>0;array[i]=array[i-1],i--); 
            array[0]=item;
        }
        printstack();
    }else printf("not possible to insert value\n");
}

Item pop(){
    Item value=array[0];
    int i;
    for(i=0;i<len-1;array[i]=array[i+1],i++);
    array[i]=0;
    printstack();
    return value;
}

void printstack(){
    int i=0;
    while(array[i]!=0 && i<len){
        printf("%d -> ",array[i]);
        i++;
    }
    printf("end stack\n");
}