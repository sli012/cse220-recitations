#include <stdio.h>
#include <assert.h>

#include "criterion/criterion.h"
#include "matrix.h"

#define TEST_TIMEOUT 30

static void zero_mat(int r, int c, int A[r][c])
{
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            A[i][j] = 0;
}

TestSuite(base_suite, .timeout = TEST_TIMEOUT);

Test(base_suite, TransposeMatrix_case1, .description = "Transpose a 3x2 matrix into 2x3")
{
#define ROWS 3
#define COLS 2

    int M[ROWS][COLS] = {
        {1, 2},
        {3, 4},
        {5, 6}};
    int T[COLS][ROWS];
    zero_mat(COLS, ROWS, T);

    TransposeMatrix(ROWS, COLS, M, T);

    const int expected[COLS][ROWS] = {
        {1, 3, 5},
        {2, 4, 6}};

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            cr_assert_eq(T[i][j], expected[i][j],
                         "Mismatch at [%d][%d]: got %d expected %d",
                         i, j, T[i][j], expected[i][j]);
        }
    }

#undef ROWS
#undef COLS
}

Test(base_suite, RowSum_case1_doc, .description = "RowSum Matrix Case 1")
{
#define ROWS 3
#define COLS 4
    int src[ROWS][COLS] = {
        {1, 2, 3, 4},
        {0, -1, 5, 6},
        {7, 0, 0, 8}};
    int dest[ROWS] = {0};

    RowSumOfMatrix(ROWS, COLS, src, dest);

    const int expected[ROWS] = {10, 10, 15};

    for (int i = 0; i < ROWS; i++)
    {
        cr_assert_eq(dest[i], expected[i],
                     "Row %d sum mismatch: got %d, expected %d", i, dest[i], expected[i]);
    }
#undef ROWS
#undef COLS
}