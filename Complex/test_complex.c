#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

int main()
{
    RectComplex x;
    ExpComplex y;
    x.a=56;
    x.b=43;

    y=toExpCplx(x);

    printf("%lf %lf\n", y.modulus, y.argument);

    y.modulus=56;
    y.argument=PI/6.0;

    x=toRectCplx(y);

    printf("%lf %lf\n", x.a, x.b);
    printf("PI is = %lf\n", PI);

    return 0;
}
