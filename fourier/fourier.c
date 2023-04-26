#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "../Complex/complex.h"
#include "fourier.h"


int generateDFTCore(ExpComplex ** Core, int L)
{
    int i,j;
    ExpComplex w;
    w.mod=1.00;
    w.argument=-2.0*PI/(double)L;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++){
            Core[i][j].mod=w.mod;
            Core[i][j].argument=powCplx(w, i*j).argument;
        }
    }
    return 0;
}

int MatrixVectorMultiplication(ExpComplex** Core, double* data, int L, RectComplex* FT)
{
    int i,j;
    RectComplex rectCoreValue;

    for (i = 0; i < L; i++) {
        FT[i].a=0;
        FT[i].b=0;



        for (j = 0; j < L; j++) {
            rectCoreValue=toRectCplx(Core[i][j]);
            RectComplex datacplx;
            datacplx.a=data[j];
            datacplx.b=0;

            FT[i]=sumRect(FT[i] , multRect(rectCoreValue, datacplx));

        }
        //printf("%lf %lf \n", FT[i].a, FT[i].b);

    }
    return 0;
}

int DFT(double* data,int L, RectComplex* FT, double* FreqAxis, double SamplingFreq){

    ExpComplex** Core = (ExpComplex **)malloc(L*sizeof(ExpComplex*));
    for(int j=0; j<L; j++){
        Core[j]=(ExpComplex*)malloc(L*sizeof(ExpComplex));
    }

    generateDFTCore(Core, L);
    MatrixVectorMultiplication(Core, data, L, FT);



    for(int i=0; i<L; i++){
        FreqAxis[i]=-SamplingFreq/2+i*SamplingFreq/L;

    }

    for(int j=0; j<L; j++) free(Core[j]);
    free(Core);
    return 0;
}

