#include "item.h"

typedef struct queue *Q;

Q queueInit();
int queueIsEmpty(Q);
void enqueue(Q,Item);
Item dequeue(Q);