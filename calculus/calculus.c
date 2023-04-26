#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "calculus.h"

int derivate1(double* input, double* output, int L, double deltax){
    //printf("%d\n",L);
    for(int i=3;i<L-3;i++){
        // Order 2 Taylor
        //output[i]=(input[i]-4*input[i+1]+3*input[i+2])/2/(double)deltax;
        //Order 6 Taylor
        output[i]=(-1*input[i-3]+9*input[i-2]-45*input[i-1]+45*input[i+1]-9*input[i+2]+input[i+3])/60/(double)deltax;
    }
    return 0;
}


int derivate2(double* input, double* output, int L, double deltax){
    //printf("%d\n",L);
    for(int i=1;i<L-1;i++){
        // Order 2 Taylor
        output[i]=(input[i-1]-2*input[i]+input[i+1])/(double)(deltax*deltax);
    }
    return 0;
}

double integrate_trapz(double* input, int L, double deltax){
    //printf("%d\n",L);
    double output = 0;
    for(int i=0;i<L-1;i++){
        output= output + deltax*(input[i]+input[i+1])/2.0;
    }
    return output;
}

double integrate_square_upper(double* input, int L, double deltax){
    //printf("%d\n",L);
    double output = 0;
    for(int i=0;i<L-1;i++){
        if(input[i]<=input[i+1]){
                output=output + deltax*input[i+1];
        }
        if(input[i]>input[i+1]){
                output=output + deltax*input[i];
        }
    }
    return output;
}

double integrate_square_lower(double* input, int L, double deltax){
    //printf("%d\n",L);
    double output = 0;
    for(int i=0;i<L-1;i++){
        if(input[i]<=input[i+1]){
                output=output + deltax*input[i];
        }
        if(input[i]>input[i+1]){
                output=output + deltax*input[i+1];
        }
    }
    return output;
}


