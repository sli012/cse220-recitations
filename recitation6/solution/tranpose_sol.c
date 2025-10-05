#include <stdio.h>

// TODO: implement
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
