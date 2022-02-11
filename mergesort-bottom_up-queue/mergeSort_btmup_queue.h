typedef struct nodo{
    int data;
    struct nodo *next;
}Node;
typedef Node *Item;

void init();
void enqueue(Item);
Item dequeue();
Item merge(Item,Item);
void mergeSort(Item*);
int isEmpty();