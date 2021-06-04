#include <stdio.h>

void setIdentityMatrix(double(*m)[4], int n)
{
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 1.0;
    }
}

int main()
{
    int i, j;
    double matrix[4][4] = { 0.0 };

    int n = sizeof(matrix[0]) / sizeof(double);

    setIdentityMatrix(matrix, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.2f ", matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}
