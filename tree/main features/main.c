#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include "item.h"
#include "tree.h"

void main(){
    treeInit();
    Item n,m;
    int d,choice=0;

    while(choice!=8){
        puts("\n\n1)load tree\n2)print tree\n3)traversal\n4)delete\n5)distance from the root of\n6)distance between\n7)search\n8)exit\n");
        scanf("%d",&choice);
        system("cls");
        switch(choice){
            case 1:
                srand(time(NULL));
                printf("Numbers loaded ::");
                for(int i=0;i<15;i++){
                    Item item=rand()%15;
                    printf("  %d",item);
                    treeInsertNode(item);
                }
                treePrint();
                break;
            case 2:
                treePrint();
                break;
            case 3:
                printf("\n\nInOrder traversal :: ");
                treeInOrder();
                printf("\n\nPreOrder traversal :: ");
                treePreOrder();
                printf("\n\nPostOrder traversal :: ");
                treePostOrder();
                break;
            case 4:
                printf("\n\nInsert number to delete :: ");
                acquire(&n);
                treeDelete(n);
                treePrint();
                break;
            case 5:
                printf("\n\nDistance from the root of number :: ");
                acquire(&n);
                d=distanceFromTheRoot(n); 
                d ? printf("is %d",d):printf("number not found");
                break;
            case 6:
                printf("\n\nDistance between(insert two numbers):: ");
                acquire(&n);
                acquire(&m);
                assert(n!=m);
                d=distanceBetween(n,m);
                d!=-1 ? printf("is %d",d):printf("%d or %d not found",n,m);
                break;
            case 7:
                printf("\n\nInsert number to search :: ");
                acquire(&n);
                treeSearch(n) ? printf("\nnumber found"):printf("\nnumber not found");
                break;
            default:
                break;
        }
    }
}