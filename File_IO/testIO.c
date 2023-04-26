#include <stdio.h>
#include <stdlib.h>

#include "Stat.h"
#include "FileIO.h"


int main()
{
    char filename[] = "eog.txt";
    int length=LineNumber(filename);
    double* data=(double*)malloc(length*sizeof(double));
    readData(length, data, filename);

    for(int i=0; i<length;i++) {
        printf("%lf\n",data[i]);
    }
    printf("Mean is : %lf\n", mean(data, length));

    writeData(length, data, "data.txt");

    return 0;
}
