
#include <stdio.h>
#include <math.h>

#define N 3
#define MAX_ITER 50
#define EPSILON 1e-6

void jacobiIteration(double A[N][N], double B[N], double X[N])
{
    double temp[N];
    int iteration = 0;

    while (iteration < MAX_ITER)
    {
        for (int i = 0; i < N; i++)
        {
            temp[i] = B[i];
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    temp[i] -= A[i][j] * X[j];
                }
            }
            temp[i] /= A[i][i];
        }

        double maxDiff = 0.01;
        for (int i = 0; i < N; i++)
        {
            double diff = fabs(X[i] - temp[i]);
            if (diff > maxDiff)
            {
                maxDiff = diff;
            }
            X[i] = temp[i];
        }

        if (maxDiff < EPSILON)
        {
            break;
        }

        iteration++;
    }
}

int main()
{
    double A[N][N] =  { {2, 1, 1},
        {3, 5, 2},
        {2, 1, 4}};

    double B[N] = {5, 15, 8};
    double X[N] = {0}; // Initial guess

    jacobiIteration(A, B, X);

    printf("Solution of the Jacobi Iteration method:\n");
    for (int i = 0; i < N; i++)
    {
        printf("X%d = %.6lf\n", i + 1, X[i]);
    }
    printf("\n\n------------------------------------------\n");
    printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 4.3(i)");

    return 0;
}
