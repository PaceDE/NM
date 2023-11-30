#include <stdio.h>
#include <math.h>
#define f(x,y) 3*(x)*(x)+1

int main()
{
    float x, xp, x0, y0, y, h,fxy;

    printf("Enter initial values of x & y:\n");
    scanf("%f%f", &x0, &y0);

    printf("Enter x at which function to be Evaluated:\n");
    scanf("%f", &xp);

    printf("Enter the step size:\n");
    scanf("%f", &h);

    y = y0;
    x = x0;

    for (x; x<xp; x = x + h)
    {

        fxy=f(x,y);

        y += fxy * h;
         printf("%f %f %f \n",x+h,y,fxy);
    }

    printf("Function value at x = %f is %f\n", xp, y);
   printf("\n\n------------------------------------------\n");
    printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 5.1(i)");
    return 0;
}
