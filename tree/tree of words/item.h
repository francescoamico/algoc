#include<string.h>

typedef char *Item;
#define eq(a,b) (strcmp((a),(b))==0)
#define lt(a,b) (strcmp((a),(b))<0)
#define gt(a,b) (strcmp((a),(b))>0)
#define size(a) (strlen(a)+1)
#define copy(a,b) strcpy((a),(b))
