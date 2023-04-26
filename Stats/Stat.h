#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED

double mean(double*, int);
double max(double* , int);
double min(double* , int);
double std_dev(double* , int);
double median(double* , int);
double mode(double* , int);
int MovingAverage(double* , int , int , double* );


void printArray(double* , int );
void quickSort(double* , int , int );


#endif // STAT_H_INCLUDED
