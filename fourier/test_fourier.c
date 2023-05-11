#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <math.h>
#include "../Complex/complex.h"
#include "../File_IO/FileIO.h"
#include "../1DSignalProcessing/1DSignalProcessing.h"
#include "fourier.h"


int main()
{

    //char filename[] = "5points.txt";
    char filename[] = "FID8.dat";
    double Fs=20.0235; //sampling freq

    //char filename[] = "sine48kHz.txt";
    //double Fs=48000; //sampling freq

    int L=LineNumber2col(filename);
    if(L==1) return 1;

    double* data=(double*)malloc(L*sizeof(double));
    RectComplex* CplxData = (RectComplex*)malloc(L*sizeof(RectComplex));

    RectComplex* FT=(RectComplex*)malloc(L*sizeof(RectComplex));
    double* amplFT=(double*)malloc(L*sizeof(double));
    double* FreqAxis=(double*)malloc(L*sizeof(double));

    //readData(L, data, filename);

    double* col1=(double*)malloc(L*sizeof(double));
    double* col2=(double*)malloc(L*sizeof(double));
    readData2col(L, col1, col2, filename);

    for(int i=0; i<L; i++){
        CplxData[i].a=col1[i];
        CplxData[i].b=col2[i];

    }
    free(col1);
    free(col2);

    //RtoC(data, CplxData, L);

    clock_t start, end;
    double duration;
    start = clock();
    DFT(CplxData, L ,FT, FreqAxis, Fs);
    end = clock();

    duration = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Start : %lf\n",start);
    printf("End : %lf\n",end);
    printf("Duration : %lf\n", duration);

    //FFT(data, L, FT);


    for(int j=0; j<L; j++){
        amplFT[j]=modulusRect(FT[j]);
        FreqAxis[j]=0;
    }

    //shiftSignal(amplFT, L, L/2);

    writeData2col(L, FreqAxis, amplFT, "DFT.csv");

    free(data);
    free(CplxData);
    free(amplFT);
    free(FreqAxis);
    return 0;
}

