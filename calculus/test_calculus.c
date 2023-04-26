#include <stdio.h>
#include <stdlib.h>

#include "calculus.h"


int main()
{
    char filename[] = "eog.txt";
    int length=LineNumber(filename);
    if(length==1) return 1;
    double* data=(double*)malloc(length*sizeof(double));
    double* derivative1=(double*)malloc(length*sizeof(double));
    double* derivative2=(double*)malloc(length*sizeof(double));
    double* corr=(double*)malloc(2*length*sizeof(double));
    double* conv=(double*)malloc(2*length*sizeof(double));

    readData(length, data, filename);


    derivate1(data, derivative1, length, 1);
    derivate2(data, derivative2, length, 1);
    //double areasu = integrate_square_upper(data, length, 1);
    //double areasl = integrate_square_lower(data, length, 1);
    //double areat = integrate_trapz(data, length, 1);

    //printf("Area with upper square : %lf\nArea with lower square : %lf\nArea with trapz : %lf", areasu, areasl, areat);


    //writeData(length, derivative1, "dx1.txt");
    //writeData(length, derivative2, "dx2.txt");


    double* d1=(double*)malloc(length*sizeof(double));
    double* d2=(double*)malloc(length*sizeof(double));

    int i;
    int L=length;

    for(i=0; i<L; i++){

        if(i>L/5 && i<2*L/5){
            d1[i]=1;
        }

        else if(i>3*L/5 && i<4*L/5){
            d1[i]=1;
        }
        else{
            d1[i]=0;
        }

    }

    for(i=0; i<L; i++){

        if(i>3*L/5 && i<4*L/5){
            d2[i]=1;
        }
        else{
            d2[i]=0;
        }
    }

    writeData(length, d1, "square1.txt");
    writeData(length, d2, "square2.txt");



    correlation(d1,d2, corr, length);
    writeData(2*length, corr, "corr.txt");

    convolution(d2,d2, conv, length);
    writeData(2*length, conv, "conv.txt");

    free(data);
    free(derivative1);
    free(derivative2);
    free(corr);
    free(conv);
    free(d1);
    free(d2);
    return 0;
}
