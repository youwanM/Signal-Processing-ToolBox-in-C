#ifndef SIGNALPROCESSING_H_INCLUDED
#define SIGNALPROCESSING_H_INCLUDED

int correlation(double* , double* , double* , int );
int shiftSignal(double* input, int L, int numberofshifts);
int filter(double* A, double* B, double* x, double* output, int L, int Lb, int La);


#endif // 1DSIGNALPROCESSING_H_INCLUDED
