#ifndef CALCULUS_H_INCLUDED
#define CALCULUS_H_INCLUDED

int derivate1(double* , double* , int , double );
int derivate2(double* , double* , int , double );
double integrate_trapz(double* input, int L, double deltax);
double integrate_square_upper(double* input, int L, double deltax);
double integrate_square_lower(double* input, int L, double deltax);
int correlation(double* , double* , double* , int );
int shiftSignal(double* input, int L, int numberofshifts);
int filter(double* A, double* B, double* x, double* output, int L);

#endif // CALCULUS_H_INCLUDED
