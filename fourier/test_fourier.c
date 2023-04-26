#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "../Complex/complex.h"
#include "../File_IO/FileIO.h"
#include "../1DSignalProcessing/1DSignalProcessing.h"
#include "fourier.h"


int main()
{

    //char filename[] = "5points.txt";
    char filename[] = "MagnitudeFID.dat";
    double Fs=20.0235; //sampling freq

    //char filename[] = "sine48kHz.txt";
    //double Fs=48000; //sampling freq

    int L=LineNumber(filename);
    if(L==1) return 1;

    double* data=(double*)malloc(L*sizeof(double));

    RectComplex* FT=(RectComplex*)malloc(L*sizeof(RectComplex));
    double* amplFT=(double*)malloc(L*sizeof(double));
    double* FreqAxis=(double*)malloc(L*sizeof(double));

    readData(L, data, filename);

    /*for(int j=0; j<L; j++){
        printf("%lf \n", data[j]);
    }*/


    DFT(data, L ,FT, FreqAxis, Fs);

    //FFT(data, L, FT);


    for(int j=0; j<L; j++){
        amplFT[j]=modulusRect(FT[j]);
    }

    shiftSignal(amplFT, L, L/2);

    writeData2col(L, FreqAxis, amplFT, "DFT.csv"); //FFTSHIFT in matlab


    free(data);
    free(amplFT);
    free(FreqAxis);
    return 0;
}

