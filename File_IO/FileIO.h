#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED

int LineNumber(char*);
int LineNumber2col(char*);
int readData(int , double*, char* );
int writeData(int , double*, char* );
int writeData2col(int length, double* data1, double* data2, char* filename);
int readData2col(int length, double* col1, double* col2, char* filename);


#endif // FILEIO_H_INCLUDED
