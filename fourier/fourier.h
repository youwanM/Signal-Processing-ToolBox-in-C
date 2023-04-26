#ifndef FOURIER_H_INCLUDED
#define FOURIER_H_INCLUDED

int generateDFTCore(ExpComplex ** Core, int L);
int MatrixVectorMultiplication(ExpComplex** Core, double* data,int L, RectComplex* DFT);
int DFT(double* data,int L, RectComplex* DFT, double* FreqAxis, double SamplingFreq);
int FFT(double* data, int L, RectComplex* FT);

#endif // FOURIER_H_INCLUDED
