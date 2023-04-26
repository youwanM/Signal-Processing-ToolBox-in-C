#include <stdio.h>
#include <stdlib.h>

#include "1DSignalProcessing.h"

int main()
{
    char filename[] = "eog.txt";
    int length=LineNumber(filename);
    if(length==1) return 1;

    double* data=(double*)malloc(length*sizeof(double));
    double* corr=(double*)malloc(2*length*sizeof(double));
    double* conv=(double*)malloc(2*length*sizeof(double));
    double* d1=(double*)malloc(length*sizeof(double));
    double* d2=(double*)malloc(length*sizeof(double));
    double* filtered=(double*)malloc(length*sizeof(double));

    readData(length, data, filename);
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

    //Moving average filter test,
    float windowSize = 30;

    double* b=(double*)malloc(windowSize*sizeof(double));

    for(int i=0; i<windowSize;i++){
        b[i]=1/(double)windowSize;
    }
    double a[] = {1.0};
    int La=1;
    int Lb=windowSize;
    filter(b,a,data,filtered,L, Lb, La);
    writeData(length, filtered, "ma_filter.txt");

    free(data);
    free(corr);
    free(conv);
    free(d1);
    free(d2);
    free(b);
    free(filtered);
    return 0;
}
