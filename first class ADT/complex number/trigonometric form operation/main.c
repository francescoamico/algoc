#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "complex.h"


void main(){
    Complex a=init(3.0,180);
    Complex b=init(4.2,270);
    printf("a = ");show(a);
    printf("\nb = ");show(b);

    printf("\n\na+b = ");show(add(a,b));
    printf("\na-b = ");show(sub(a,b));
    printf("\na*b = ");show(mul(a,b));
    printf("\na/b = ");show(divid(a,b));
}

