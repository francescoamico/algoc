#include "item.h"

void treeInit();
int treeIsEmpty();
void treeInsertNode(Item);
void treeInOrder();
void treePreOrder();
void treePostOrder();
void acquire(Item *);
int treeSearch(Item);
void treePrint();
void treeDeletemin();
void treeDelete(Item);
int distanceFromTheRoot(Item);
int distanceBetween(Item,Item);