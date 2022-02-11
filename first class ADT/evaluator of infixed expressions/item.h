#if !defined(ITEM)
typedef union multiType {
  char c;
  int  i;
  } Item;
#define ITEM 
#endif

#define NULLITEM (Item)(-1)

