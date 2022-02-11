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

Complex add(Complex a,Complex b){
    float re1=a->mod*cos(a->phase*M_PI/180);
    float im1=a->mod*sin(a->phase*M_PI/180);
    float re2=b->mod*cos(b->phase*M_PI/180);
    float im2=b->mod*sin(b->phase*M_PI/180);

    float re=re1+re2;
    float im=im1+im2;

    float mod=sqrt(pow(re,2)+pow(im,2));
    float phase=atan(im/re)*180/M_PI;

    return(init(mod,phase));

}

Complex sub(Complex a,Complex b){
    float re1=a->mod*cos(a->phase*M_PI/180);
    float im1=a->mod*sin(a->phase*M_PI/180);
    float re2=b->mod*cos(b->phase*M_PI/180);
    float im2=b->mod*sin(b->phase*M_PI/180);

    float re=re1-re2;
    float im=im1-im2;

    float mod=sqrt(pow(re,2)+pow(im,2));
    float phase=atan(im/re)*180/M_PI;

    return(init(mod,phase));
}

Complex mul(Complex a,Complex b){
    return(init(a->mod*b->mod,a->phase+b->phase));
}

Complex divid(Complex a,Complex b){
    return(init(a->mod/b->mod,a->phase-b->phase));
}

void show(Complex a){
    printf("%f(cos(%f)+isin(%f))",a->mod,a->phase,a->phase);
}
