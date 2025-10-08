#include <stdio.h>

// TODO: implement
/**
A = 1, 2
    3, 4

A ^ T = 1, 3
        2, 4

        scr[i][j] = dest[j][i]

*/
void TransposeMatrix(int rows, int cols, int src[rows][cols], int dest[cols][rows])
{
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            //dest[j][i] = src[i][j]
            *(*(dest + j) + i) = *(*(src + i) + j); //pointer arithmetic
            //dest[j] == *(dest + i)
        }
    }
}

// TODO: implement
void RowSumOfMatrix(int rows, int cols, int src[rows][cols], int dest[rows])
{
    for(int i= 0; i < rows; i++){
        *(dest + i) = 0; //initialize dest outside and set it to 0
        for(int j = 0; i < cols; j++){
            *(dest + i) += *(*(src+ i) +j);//add values to dest

        }
    }
}