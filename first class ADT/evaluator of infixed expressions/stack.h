#include "item.h"

typedef struct stack *S;

S stackInit();
int stackIsEmpty(S);
void stackPush(S, Item);
Item stackPop(S);
Item stackPeek(S); // looking without popping
int stackSize(S);
