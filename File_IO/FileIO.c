#include <stdio.h>
#include <stdlib.h>

#include "FileIO.h"


int LineNumber(char* filename){
    FILE* f;
    f=fopen(filename,"r");

    if(f==NULL){
        return 1;
    }

    double data;
    int length=0;
    int end;

    do{
        end=fscanf(f, "%lf", &data);
        length++;
    }
    while(end!=-1);
    length--;
    fclose(f);
    return length;
}

int LineNumber2col(char* filename){
    FILE* f;
    f=fopen(filename,"r");

    if(f==NULL){
        return 1;
    }

    double data;
    int length=0;
    int end;

    do{
        end=fscanf(f, "%lf %lf", &data, &data);
        length++;
    }
    while(end!=-1);
    length--;
    fclose(f);
    return length;
}

int readData(int length, double* data, char* filename){
    FILE* f;
    f=fopen(filename,"r");

    if(f==NULL){
        return 1;
    }

    for(int i=0; i<length;i++) {
        fscanf(f, "%lf", &data[i]);
    }
    fclose(f);
    return 0;
}

int readData2col(int length, double* col1, double* col2, char* filename){
    FILE* f;
    f=fopen(filename,"r");

    if(f==NULL){
        return 1;
    }

    for(int i=0; i<length;i++) {
        fscanf(f, "%lf %lf", &col1[i], &col2[i]);
    }
    fclose(f);
    return 0;
}

int writeData(int length, double* data, char* filename){

    FILE* f;
    f=fopen(filename,"w");

    if(f==NULL){
        printf("Error writing %s\n", filename);
        return 1;
    }

    for(int i=0; i<length;i++) {
        fprintf(f, "%f\n", data[i]);
    }
    fclose(f);
    return 0;

}

int writeData2col(int length, double* data1, double* data2, char* filename){

    FILE* f;
    f=fopen(filename,"w");

    if(f==NULL){
        printf("Error writing %s\n", filename);
        return 1;
    }

    for(int i=0; i<length;i++) {
        fprintf(f, "%f,%f\n", data1[i], data2[i]);
    }
    fclose(f);
    return 0;

}

