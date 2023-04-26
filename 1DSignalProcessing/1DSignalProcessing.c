#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "1DSignalProcessing.h"

int correlation(double* x, double* y, double* output, int L){
    int i,j;
    for(i=-L; i<L; i++){
        int sum=0;
        for(j=-L; j<L; j++){
            if((i+j>0) && (i+j<L) && j>0 && j<L)
            sum+=x[j]*y[i+j];
        }
        output[i+L]=sum;
    }
    return 0;
}

int convolution(double* x, double* y, double* output, int L){
    int i;
    double* invertedkernel=(double*)malloc(L*sizeof(double));


    for(i=0; i<L; i++){
        invertedkernel[i]=y[L-i];
    }
    correlation(invertedkernel,x, output, L);
    free(invertedkernel);
    return 0;
}

int shiftSignal(double* input, int L, int numberofshifts){
    int i,j;
    int n=numberofshifts;

    for(j=0; j<n; j++){

        double temp=input[L-1];
        for(i=L-1;i>0;i--){
            input[i]=input[i-1];
        }
        input[0]=temp;
    }
    return 0;
}

int filter(double* B, double* A, double* x, double* output, int L, int Lb, int La){
    int i,j;
    double sum=0;


    for(i=0; i<L; i++){

        sum=0;
        for(j=0; j<Lb; j++){

            if(i-j>0) sum=sum+B[j]*x[i-j];
        }
        output[i]=sum;
        sum=0;
        for(j=0; j<La; j++){
            if(i-j>0) sum=sum-A[j]*x[i-j];
        }
    }

    return 0;
}

