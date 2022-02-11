#include "item.h"

typedef struct queue *Q;

Q queueInit(int);
int queueIsEmpty(Q);
void enqueue(Q,Item);
Item dequeue(Q);