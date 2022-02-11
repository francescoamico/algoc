#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"

void main(){
    
    unsigned int n=3;
    Coord *coord=calloc(n,sizeof(Coord));
    coord[0].x=1;coord[0].y=6;
    coord[1].x=2;coord[1].y=15;
    coord[2].x=3;coord[2].y=28;
    Poly z=interpola(coord,n);
    printf("\nInterpolazione :: ");show(z);

    free(coord);
    freePOLY(z);
}
