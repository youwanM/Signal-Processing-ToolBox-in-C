#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polyfit.h"

int polyfit(double* x, double* y, double* p, int order, int length)
{
    double A[order+1][length]; //Vandermonde Matrix of order+1 col and length(x) row
    double At[length][order+1];

    transposeMatrix(A,At, order+1, length); //NEED TO CORRECT THIS FUNCTION

    int i;
    int j;
    int power;

    for(i=0;i<order+1;i++){
        for(j=0;j<length;j++){

            power = i;
            if (i<0) power=0;
            A[i][j] = pow(x[j],power);
        }
    }

    // see http://www.rozhovor.cz/ma+fy/03metodanejmensichctvercu.pdf page 12



    return 0;
}

void gausselimination(double** A, double* x){
    int i,j,k,n;
    double c,sum=0.0;

    for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];

    /* backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
}
void multiplyMatrix(double** a, double** b, double** c, int m, int n, int p, int q){
    //m n size of A
    //p q size of B
    int i, j, k;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < q; ++j) {
            c[i][j] = 0;
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < q; ++j) {
            for (k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(double** a, double** b, int m, int n) {
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            b[i][j] = a[j][i];
        }
    }
}
