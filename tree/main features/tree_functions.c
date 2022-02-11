#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "item.h"
#include <stdbool.h>
#include <limits.h>

int counter;

struct treeNode {
  struct treeNode *left;
  Item item;
  struct treeNode *right;  
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

static TreeNodePtr rootPtr;

static int level = 0;

static void insertNode(TreeNodePtr *, Item);

static int search(TreeNodePtr, Item);

static TreeNodePtr min(TreeNodePtr);

static void deleteMin(TreeNodePtr *); 

static void delete(TreeNodePtr *, Item);
     
static void stampa(TreeNodePtr);

static void inOrder(TreeNodePtr); 
static void preOrder(TreeNodePtr);
static void postOrder(TreeNodePtr); 
  
static int distance(int x, int y, TreeNodePtr);                                                                                      
static int distanceFromRoot(int x, TreeNodePtr);

void treeInit(void) {
  rootPtr = NULL;
}

int treeIsEmpty(void) {
  return rootPtr == NULL;
}

void treeInsertNode(Item item) {
  insertNode(&rootPtr, item);
}

static void insertNode(TreeNodePtr *treePtr, Item item) {
  if (*treePtr == NULL) {
    *treePtr = malloc(sizeof(TreeNode));
    if (*treePtr != NULL) {
      (*treePtr)->item = item;
      (*treePtr)->left = NULL;
      (*treePtr)->right = NULL;
    }
    else printf("No memory available.\n");
  }
  else {
    if (item < (*treePtr)->item)
      insertNode(&((*treePtr)->left), item);
    else if (item > (*treePtr)->item)
      insertNode(&((*treePtr)->right), item);
    else printf("%s", "dup"); // item already present
  }
}


int treeSearch(Item item) {
  counter = 0;
  int found = search(rootPtr, item);
  printf("\n %d confronti \n", counter);
  return(found);
}

static int search(TreeNodePtr treePtr, Item item) {
  if (treePtr == NULL) return(false);
  else {
    counter++;
    if (item < treePtr->item)
      return(search(treePtr->left, item));
    else if (item > treePtr->item)
      return(search(treePtr->right, item));
    else return(true);
  }
}

void treeDeleteMin() {
  deleteMin(&rootPtr);
}

static void deleteMin(TreeNodePtr *treePtr) {
  if ((*treePtr)->left == NULL) {
    TreeNodePtr tmp = (*treePtr)->right;
    printf("deleting %d \n", (*treePtr)->item);
    free(*treePtr);
    *treePtr = tmp;
  }
  else deleteMin(&((*treePtr)->left));
}   

static TreeNodePtr min(TreeNodePtr treePtr) {
  if (treePtr->left == NULL) return treePtr;
  else return min(treePtr->left);
}


void treeDelete(Item item) {
  delete(&rootPtr, item);
}

static void delete(TreeNodePtr *treePtr, Item item) {
  // Hibbard deletion
  if ((*treePtr) == NULL) return;
  else {
    if (item < (*treePtr)->item) {
      delete(&((*treePtr)->left), item);
      return; 
    }
    else if (item > (*treePtr)->item) {
      delete(&((*treePtr)->right), item);
      return;
    }
    else {
      if ((*treePtr)->right == NULL) {
        TreeNodePtr tmp = (*treePtr)->left;
        free(*treePtr);
        *treePtr = tmp;
        return;
      }
      if ((*treePtr)->left == NULL) {
        TreeNodePtr tmp = (*treePtr)->right;
        free(*treePtr);
        *treePtr = tmp;
        return;
      }
      (*treePtr)->item = (min((*treePtr)->right))->item;
      deleteMin(&((*treePtr)->right));     
    }
  }
}


void treePrint(void)
{ 
  if (!treeIsEmpty()) 
      stampa(rootPtr);
  printf("------------------------\n");
} 

static void stampa(TreeNodePtr treePtr) {
  if (treePtr != NULL) {
    level++;
    stampa(treePtr->right);         
    printf(">%*s%5d\n", level*5, "", treePtr->item);      
    stampa(treePtr->left);
    level--;
  }                           
} 

void treeInOrder(void)
{ 
  if (!treeIsEmpty()) 
      inOrder(rootPtr);         
} 

static void inOrder(TreeNodePtr treePtr) {
  if (treePtr != NULL) {                
    inOrder(treePtr->left);         
    printf("%5d", treePtr->item);      
    inOrder(treePtr->right);        
  }                           
} 

void treePreOrder(void)
{ 
  if (!treeIsEmpty()) 
      preOrder(rootPtr);         
}

static void preOrder(TreeNodePtr treePtr) { 
  if (treePtr != NULL) {                
    printf("%5d", treePtr->item);      
    preOrder(treePtr->left);        
    preOrder(treePtr->right);       
  }                           
} 

void treePostOrder(void)
{ 
  if (!treeIsEmpty()) 
      postOrder(rootPtr);         
}

static void postOrder(TreeNodePtr treePtr) { 
   if (treePtr != NULL) {                
      postOrder(treePtr->left);       
      postOrder(treePtr->right);      
      printf("%5d", treePtr->item);      
   }                           
} 

int treeDistance(int x, int y)
{
  if ((x<0)||(y<0)) return -1;
  if (!treeIsEmpty()) 
    return distance(x, y, rootPtr);
  else return -1;
}

int distance(int x, int y, TreeNodePtr treePtr) {
  if ( x >= y ) {int tmp = x; x = y; y = tmp;}
  if (treePtr != NULL) {
    if ((x < treePtr->item) && (y < treePtr->item))
      return distance(x, y, treePtr->left);
    else if ((x > treePtr->item) && (y > treePtr->item))
      return distance(x, y, treePtr->right);
    else {
      int d1 = distanceFromRoot(x, treePtr);
      int d2 = distanceFromRoot(y, treePtr);
      if ((d1>=0)&&(d2>=0)) return d1+d2;
      else return -2; // at least one negative distance if not present
    }
  }
  else return -1;
}

int distanceFromRoot(int x, TreeNodePtr treePtr) {
  if (treePtr == NULL) return -INT_MAX; 
  if (x == treePtr->item) return 0;
  else if (x < treePtr->item) return 1 + distanceFromRoot(x, treePtr->left);
  else return 1 + distanceFromRoot(x, treePtr->right);
}

