#include <stdio.h>
#include "item.h"
#include "LCRS.h"

void main(){

    lcrsnode root=LCRSinit(5);                      
              
    lcrsnode n1=addChild(root,8);                  /*       5            */      
    lcrsnode n2=addChild(root,9);                 /*    /   |   \       */
    lcrsnode n3=addSibling(n1,12);               /*    8 -- 9 --  12   */
    lcrsnode n4=addChild(n1,22);                /*    /           /   */      
    lcrsnode n5=addChild(n3,43);               /*    22          43  */  
    lcrsnode n6=addChild(n4,11);              /*    / \             */ 
    lcrsnode n7=addChild(n4,12);             /*    11 12           */ 
    
    printf("LCRS pre-order visit ::");LCRSpreOrder(root);
    printf("\nLCRS level-order visit ::");LCRSlvlOrder(root);
    printf("\nBT pre-order visit ::");BTpreOrder(LCRStoBT(root));
    
}