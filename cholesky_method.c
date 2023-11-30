#include <stdio.h>
#include <math.h>

void cholesky_decomposition(int n, double A[][n], double L[][n], double U[][n])
{
    for (int i = 0; i < n; i++)
    {
        // Upper triangular matrix (U)
        for (int j = i; j < n; j++)
        {
            double sum = 0.0;
            if (i == j)
            {
                for (int k = 0; k < i; k++)
                {
                    sum += U[k][i] * U[k][i];
                }
                U[i][i] = sqrt(A[i][i] - sum);
            }
            else
            {
                for (int k = 0; k < i; k++)
                {
                    sum += U[k][i] * U[k][j];
                }
                U[i][j] = (A[i][j] - sum) / U[i][i];
            }
        }

        // Lower triangular matrix (L)
        for (int j = 0; j <= i; j++)
        {
            double sum = 0.0;

            if (i == j)
            {
                for (int k = 0; k < j; k++)
                {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(A[j][j] - sum);
            }
         /*   else if(j==0)
            {
                L[i][0]=A[i][0]/L[0][0];

            }*/
            else
            {
                for (int k = 0; k < j; k++)
                {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

int main()
{
    int n = 3;
    double A[3][3] = {
        {4, 12, -16},
        {12, 37, -43},
        {-16, -43, 98}};
    double L[3][3];
    double U[3][3];

    // Initialize matrices L and U
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            L[i][j] = 0.0;
            U[i][j] = 0.0;
        }
    }

    cholesky_decomposition(n, A, L, U);

    printf("Matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2lf\t", A[i][j]);
        }
        printf("\n");
    }

    printf("Lower triangular Cholesky matrix L:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {

            printf("%.2lf\t", L[i][j]);
        }
        printf("\n");
    }

    printf("Upper triangular Cholesky matrix U:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           /* if(i<j)
            {
                printf("0\t");
            }*/

            printf("%.2lf\t", U[i][j]);
        }
        printf("\n");
    }
   printf("\n\n------------------------------------------\n");
    printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 4.2(ii)");
    return 0;
}
