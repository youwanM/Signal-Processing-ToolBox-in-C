#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#define PI (3.14159265358979323846264338327950288)

typedef struct RectComplex{
    double a;
    double b;

}RectComplex;

typedef struct ExpComplex{
    double mod;
    double argument;

}ExpComplex;


ExpComplex toExpCplx(RectComplex in);
RectComplex toRectCplx(ExpComplex in);
ExpComplex powCplx(ExpComplex in, int n);
double modulusRect(RectComplex in);

RectComplex multRect(RectComplex x, RectComplex y);
ExpComplex sumExp(ExpComplex x, ExpComplex y);
RectComplex sumRect(RectComplex x, RectComplex y);


#endif // COMPLEX_H_INCLUDED
