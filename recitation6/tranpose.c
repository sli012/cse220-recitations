#include <stdio.h>

#define ROWS 3
#define COLS 4

int main()
{
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int transpose[COLS][ROWS];

    // Transpose operation
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("Transposed matrix:\n");
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}