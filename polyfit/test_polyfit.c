#include <stdio.h>
#include <stdlib.h>
#include "polyfit.h"

int main(){

    double x[] = {1, 2, 3};
    double y[] = {4, 5, 6};

    int L = 3;
    int order = 1;

    double p[L];

    polyfit(x, y, p, order, L);


    return 0;
}
