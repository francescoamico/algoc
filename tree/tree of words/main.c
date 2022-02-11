#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "item.h"
#include "tree.h"
#define LEN 100

void main(){
    treeInit();
    char string[LEN];

    printf("Insert string :: ");
    gets(string);
    
    Item s=string;
    int i=0;
    while(*(string+i)){
        if(*(string+i)==' '){
            *(string+i)=0;
            treeInsertNode(s);
            i++;
            s=string+i;
        }else i++;
    }
    treeInsertNode(s);

    printf("\n\nInOrder traversal ::\n");
    treeInOrder();
    printf("\n\nPreOrder traversal ::\n");
    treePreOrder();
    printf("\n\nPostOrder traversal ::\n");
    treePostOrder();
}