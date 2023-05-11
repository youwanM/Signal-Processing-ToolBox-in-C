#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"

double pi(){
    return (double)M_PI;
}

RectComplex toRectCplx(ExpComplex in){

    RectComplex out;
    out.a=in.mod*cos(in.argument);
    out.b=in.mod*sin(in.argument);

    return out;
}


ExpComplex toExpCplx(RectComplex in){
    ExpComplex out;
    out.mod=sqrt(in.a*in.a + in.b*in.b);

    double a=in.a;
    double b=in.b;

    if(a>=0 && b>=0) out.argument=atan(in.b/in.a);
    else if(a>0 && b<0) out.argument=2*PI-atan(in.b/in.a);
    else if(a<0 && b>0) out.argument=PI-atan(in.b/in.a);
    else if(a<0 && b<0) out.argument=PI+atan(in.b/in.a);

    return out;
}

ExpComplex powCplx(ExpComplex in, int n){

    ExpComplex out=in;
    out.argument=out.argument*n;

    return out;
}

double modulusRect(RectComplex in)
{
    return sqrt(in.a*in.a + in.b*in.b);
}

RectComplex sumRect(RectComplex x, RectComplex y){

    RectComplex z;
    z.a=x.a+y.a;
    z.b=x.b+y.b;

    return z;
}

RectComplex subRect(RectComplex x, RectComplex y){

    RectComplex z;
    z.a=x.a-y.a;
    z.b=x.b-y.b;

    return z;
}

ExpComplex sumExp(ExpComplex x, ExpComplex y){
    ExpComplex z;
    RectComplex u,v,w;

    u=toRectCplx(x);
    v=toRectCplx(y);
    w=sumRect(u,v);

    z=toExpCplx(w);
    return z;
}

RectComplex multRect(RectComplex x, RectComplex y){

    RectComplex z;

    z.a = (x.a*y.a)-(x.b*y.b);
    z.b = (x.b*y.a)-(x.a*y.b);

    return z;
}

int RtoC(double* in, RectComplex* out, int L){
    int i;
    for(i=0; i<L; i++){
        out[i].a=in[i];
        out[i].b=0.0;
    }
    return 0;
}
