typedef int Item;

struct node{
    Item data;
    struct node *next;
};
typedef struct node Node;
typedef Node *NodePtr;

void init();
int isEmpty();
void push(Item);
Item pop();
void printlist();