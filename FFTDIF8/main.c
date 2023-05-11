#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <math.h>
#include "../Complex/complex.h"
#include "../File_IO/FileIO.h"
#include "../1DSignalProcessing/1DSignalProcessing.h"
#include "../fourier/fourier.h"

int FFT_DIF_8(RectComplex* data, RectComplex* FT,int L, double* FreqAxis){

    RectComplex* EVENIN = (RectComplex*)malloc(L/2*sizeof(RectComplex));
    RectComplex* ODDIN = (RectComplex*)malloc(L/2*sizeof(RectComplex));
    RectComplex* EVENOUT = (RectComplex*)malloc(L/2*sizeof(RectComplex));
    RectComplex* ODDOUT = (RectComplex*)malloc(L/2*sizeof(RectComplex));
    int i;

    for(i=0; i<L; i++){
        if(i%2==0) EVENIN[i/2]=data[i];
        else ODDIN[i/2]=data[i];
    }

    DFT(EVENIN, L/2 ,EVENOUT, FreqAxis, 999);
    DFT(ODDIN, L/2 ,ODDOUT, FreqAxis, 999);

    butterfly(EVENOUT, ODDOUT, FT, L);


    free(EVENIN);
    free(EVENOUT);
    free(ODDIN);
    free(ODDOUT);
    return 0;
}

int butterfly(RectComplex* EVEN, RectComplex* ODD, RectComplex* OUT, int L){
    int i;

    ExpComplex** Core = (ExpComplex **)malloc(L*sizeof(ExpComplex*));
    for(int j=0; j<L; j++){
        Core[j]=(ExpComplex*)malloc(L*sizeof(ExpComplex));
    }

    generateDFTCore(Core, L);

    for(i=0; i<L; i++){
        if(i<L/2){
            OUT[i]=sumRect(EVEN[i] ,multRect(ODD[i], toRectCplx(Core[i][L-1])));
        }
        else{
            OUT[i]=sumRect(multRect(EVEN[i-L/2],toRectCplx(Core[i][L-1])), ODD[i-L/2]);

        }
    }

    for(int j=0; j<L; j++) free(Core[j]);
    free(Core);

    return 0;
}

int main(){
    char filename[] = "FID8.dat";
    int L=8;

    RectComplex* CplxData = (RectComplex*)malloc(L*sizeof(RectComplex));
    RectComplex* FT=(RectComplex*)malloc(L*sizeof(RectComplex));
    double* amplFT=(double*)malloc(L*sizeof(double));
    double* FreqAxis=(double*)malloc(L*sizeof(double));

    double* col1=(double*)malloc(L*sizeof(double));
    double* col2=(double*)malloc(L*sizeof(double));
    readData2col(L, col1, col2, filename);

    for(int i=0; i<L; i++){
        CplxData[i].a=col1[i];
        CplxData[i].b=col2[i];

    }
    free(col1);
    free(col2);

    FFT_DIF_8(CplxData,FT,L,FreqAxis);


    for(int j=0; j<L; j++){
        amplFT[j]=modulusRect(FT[j]);
        FreqAxis[j]=0;
    }

    //shiftSignal(amplFT, L, L/2);

    writeData2col(L, FreqAxis, amplFT, "FFT.csv");

    free(FreqAxis);
    free(FT);
    free(CplxData);
    free(amplFT);


    return 0;
}
