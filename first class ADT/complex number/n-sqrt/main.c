#include <stdio.h>
#include "complex.h"


void main(){
    Complex a=init(1.0,90.0);
    show(a);

    printf("\n\nRadici n-esime.\n");
    showNroots(a,4);
}

