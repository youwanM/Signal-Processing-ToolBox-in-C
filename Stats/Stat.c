#include <stdio.h>
#include "Stat.h"
#include "math.h"

double mean(double* array, int L){
    //This function returns the mean of a 1D array of known length L
    double sum=0.0;
    for(int i=0; i<L; i++){
            sum=sum+array[i];
       }
       double mean = sum/(double)L;
    return mean;
}

double max(double* array, int L){
    //This function returns the max of a 1D array of known length L
    double max=0;
    for(int i=0; i<L; i++){
        if(array[i]>max) max=array[i];
    }
    return max;
}

double min(double* array, int L){
    //This function returns the min of a 1D array of known length L
    double min=array[0];
    for(int i=0; i<L; i++){
        if(array[i]<min) min=array[i];
    }
    return min;
}

double std_dev(double* array, int L){
    //This function returns the std dev of a 1D array of known length L
    double average=mean(array,L);
    double stddev=0;
    for(int i=0; i<L; i++){
        stddev=stddev+(array[i]-average)*(array[i]-average);
    }
    stddev=stddev/(double)L;
    stddev=sqrt(stddev);
    return stddev;
}

double median(double* array, int L){
    quickSort(array,0,L);

    if(L%2==0) return 0.5*(array[L/2-1]+array[L/2]);
    else return array[L/2+1];

}

double mode(double* array, int L){

    double frequency[L];
    int i=0;
    int j=0;

    for(i=0; i<L; i++){
        int count=0;
        for(j=0;j<L; j++){
            if(array[i]==array[j]){
                count++;
            }
        }
        frequency[i]=count;
    }
    double maximum=max(frequency, L);
    int k;
    for(k=0; k<L; k++){
        if(frequency[k]==maximum) break;
    }

    return array[k];

}

int MovingAverage(double* input, int inputSize, int window, double* output){
    //output size is inputSize-windowSize
    //if(inputSize<=window) return 1;

    int i;
    int j;
    for(i=0; i<inputSize-window; i++){
        double mean=0;

        for(j=0; j<window; j++){
            mean=mean+input[i+j];
        }
        mean=mean/window;
        output[i]=mean;

    }
    return 0;
}


