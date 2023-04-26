#include <stdio.h>
#include <stdlib.h>
#include "Stat.h"

int main(){
    printf("this program calculate various statistical values from a vector (6 values)\n");
    printf("Enter the values for the vector (double)\n");

    int L=6;

    double* array=(double*)malloc(L*sizeof(double));

    for(int i=0; i<L; i++){
        scanf("%lf",&array[i]);
    }

    int choice=0;
    printf("What to do ? 1:Mean 2:Max 3:Min 4:StdDev 5:Median 6:Mode 7:Moving Average\n");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            printf("Mean of array is : %lf", mean(array,L));
            break;

        case 2:
            printf("Max of array is : %lf", max(array,L));
            break;

        case 3:
            printf("Min of array is : %lf", min(array,L));
            break;

        case 4:
            printf("Std.Dev of array is : %lf", std_dev(array,L));
            break;

        case 5:
            printf("Median of array is : %lf", median(array,L));
            break;

        case 6:
            printf("Mode of array is : %lf", mode(array,L));
            break;

        case 7:
            printf("Moving average of eog.txt\n");
            printf("Window Size ? \n");
            int window=0;
            scanf("%d", &window);

            char filename[] = "eog.txt";
            int length=LineNumber(filename);
            double* data=(double*)malloc(length*sizeof(double));
            readData(length, data, filename);

            double* MA=(double*)malloc((length-window)*sizeof(double));
            MovingAverage(data, length, window, MA);
            //output size is inputSize-windowSize
            writeData(length-window, MA, "MA.txt");
            free(data);
            free(MA);
            break;

        default:
            printf("Nothing to do");
            break;
    }
   free(array);
   return 0;
}
