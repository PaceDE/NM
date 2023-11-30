#include <stdio.h>

#define f(x) (x) * (x) + 2 * (x)-5

int main()
{
    float h, x0, x1, x2, fx0, fx1, fx2, v;

    printf("Enter lower and upper limit: ");
    scanf("%f%f", &x0, &x2);

    h = (x2 - x0) /2;
    x1 = x0 + h;
    fx0 = f(x0);
    fx1 = f(x1);
    fx2 = f(x2);
    v = h / 3 * (fx0 + 4 * fx1 + fx2);

    printf("\nValue of Integration using Simpson's 1/3 rule=%f\n", v);
   printf("\n\n------------------------------------------\n");
    printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 3.2");

    return 0;
}
