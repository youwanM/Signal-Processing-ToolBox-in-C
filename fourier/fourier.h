#ifndef FOURIER_H_INCLUDED
#define FOURIER_H_INCLUDED

int generateDFTCore(ExpComplex ** Core, int L);
int MatrixVectorMultiplication(ExpComplex** Core, RectComplex* data,int L, RectComplex* DFT);
int DFT(RectComplex* data,int L, RectComplex* DFT, double* FreqAxis, double SamplingFreq);

#endif // FOURIER_H_INCLUDED
