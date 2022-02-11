#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "complex.h"

struct complex{
    double mod;
    double phase;
};

Complex init(double mod,double phase){
    Complex n=malloc(sizeof *n);
    n->mod=mod;
    n->phase=phase;
}

void showNroots(Complex a,unsigned int n){
    for(int i=0;i<n;i++) show(init(pow(a->mod,pow(n,-1)),(a->phase+2*i*180)/n));
}

void show(Complex a){
    printf("\n%f(cos(%f)+isin(%f))",a->mod,a->phase,a->phase);
}
