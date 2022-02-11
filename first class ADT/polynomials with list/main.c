#include <stdio.h>
#include <stdlib.h>
#include "POLY.h"

void main(int argc, char *argv[]){
    int N = atoi(argv[1]); 
    float p = atof(argv[2]);
    Poly t, x;
    printf("Binomial coefficients\n");
    t = add(term(1, 1), term(1, 0));
    show(t);
    x=t;
    for (int i=0; i<N; i++){
        x=mult(t,x); 
        show(x); 
    }
    printf("\nx(%f)=%f\n",p,eval(x,p));

    freePOLY(t);
    freePOLY(x);
}
