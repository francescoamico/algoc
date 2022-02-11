#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "deque.h"

void main(){
    init();

    int choice=0,data;

    while(choice!=5){
        puts("\n\n1)push\n2)dequeue\n3)enqueue\n4)deleteFromTail\n5)exit");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                puts("insert value :: ");
                acquire(&data);
                push(data);
                printlist();
                break;
            case 2:
                if(!isEmpty()) printf("%d deleted\n",dequeue());
                break;
            case 3:
                puts("insert value :: ");
                acquire(&data);
                enqueue(data);
                printlist();
                break;
            case 4:
                if(!isEmpty()) printf("%d deleted\n",deleteFromTail());
                break;
            default:
                break;
        }
    }
}