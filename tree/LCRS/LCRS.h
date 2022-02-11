#include "item.h"

typedef struct lcrsnode *lcrsnode;
typedef struct bnode *bnodePtr;

lcrsnode LCRSinit(Item);
lcrsnode addChild(lcrsnode,Item);
lcrsnode addSibling(lcrsnode,Item);
void LCRSpreOrder(lcrsnode);
void LCRSlvlOrder(lcrsnode);
bnodePtr LCRStoBT(lcrsnode);
void BTpreOrder(bnodePtr);
