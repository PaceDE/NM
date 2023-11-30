#include <stdio.h>
#include <math.h>

#define N 3
#define MAX_ITER 50
#define EPSILON 1e-6

void gaussSeidelIteration(double A[N][N], double B[N], double X[N])
{
    int iteration = 0;

    while (iteration < MAX_ITER)
    {
        double maxDiff = 0.01;
        for (int i = 0; i < N; i++)
        {
            double oldX = X[i];
            X[i] = B[i];

            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    X[i] -= A[i][j] * X[j];
                }
            }

            X[i] /= A[i][i];

            double diff = fabs(X[i] - oldX);
            if (diff > maxDiff)
            {
                maxDiff = diff;
            }
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
    double A[N][N] = {
        {2, 1, 1},
        {3, 5, 2},
        {2, 1, 4}};

    double B[N] = {5, 15, 8};
    double X[N] = {0}; // Initial guess

    gaussSeidelIteration(A, B, X);

    printf("Solution for Gauss-Seidal-Method:\n");
    for (int i = 0; i < N; i++)
    {
        printf("X%d = %.6lf\n", i + 1, X[i]);
    }

    printf("\n\n------------------------------------------\n");
    printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 4.3(ii)");

    return 0;
}
