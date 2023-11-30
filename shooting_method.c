#include <stdio.h>
#include <math.h>
#define f1(x, y, z) (z)
#define f2(x, y, z) -y/x
int main()
{
    float xa, xb, ya, yb, x0, y0, z0, x, y, z, xp, h, sol, ny, nz, error, E, g[3], v[3], gs;
    int i;
    printf("Enter Boundry Conditions: ");
    scanf("%f%f%f%f", &xa, &ya, &xb, &yb);
    printf("Enter x at which value is required: ");
    scanf("%f", &xp);
    printf("Enter the step size: ");
    scanf("%f", &h);
    printf("Enter accuracy limit: ");
    scanf("%f", &E);
    x = xa;
    y = ya;
    g[1] = z = 1.2;
    printf("M1=%f\n", g[1]);
    while (x < xb) // Using Euler's method
    {
        ny = y + (f1(x, y, z)) * h;
        nz = z + (f2(x, y, z)) * h;
        x = x + h;
        y = ny;
        z = nz;
        if (x == xp)
            sol = y;
    }
    v[1] = y;
    if(y<yb)
        g[2] = z = 2*g[1];
    else
         g[2] = z= g[1]/2;

    printf("M2=%f\n", g[2]);
    while (x < xb) // Using Euler's method
    {
        ny = y + (f1(x, y, z)) * h;
        nz = z + (f2(x, y, z)) * h;
        x = x + h;
        y = ny;
        z = nz;
        if (x == xp)
            sol = y;
    }
    while (1)
    {
        x = xa;
        y = ya;
        gs = z = g[2] - (v[2] - yb) * (g[2] - g[1])/ (v[2] - v[1]) ;
        while (x < xb)
        {
            ny = y + (f1(x, y, z)) * h;
            nz = z + (f2(x, y, z)) * h;
            x = x + h;
            y = ny;
            z = nz;
            if (x == xp)
                sol = y;
        }

        error = fabs(y - yb) / y;
        v[1] = v[2];
        v[2] = y;
        g[1] = g[2];
        g[2] = gs;
        if (error < E)
        {
            printf("M: %f \n",gs);
            printf("y(%f)=%f", xp, sol);
            break;
        }
    }
            printf("\n\n------------------------------------------\n");
    printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 5.2");
    return 0;
}
