#include <stdio.h>

void TransposeMatrix(int rows, int cols, int src[rows][cols], int dest[cols][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(dest + j) + i) = *(*(src + i) + j);
        }
    }
}

void RowSumOfMatrix(int rows, int cols, int src[rows][cols], int dest[rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(dest + i) += *(*(src + i) + j);
        }
    }
}