#include<stdio.h>
#include<stdlib.h>
#include "array_maxn.h"

void main(){
    init();

    int choice=0,data;

    while(choice!=4){
        puts("\n\n1)push\n2)is empty?\n3)pop\n4)exit");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                puts("insert value :: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                isEmpty() ? printf("yes\n"):printf("no\n");
                break;
            case 3:
                if(!isEmpty()) printf("%d popped\n",pop());
                break;
            default:
                break;
        }
    }
}
