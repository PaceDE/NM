#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 50
#define F(x) (x)*(x)-(x)-1
#define G(x) 1+1/(x)
int main()
{
 int count;
   float x0,xn,error,absError;

   printf("Enter the initial guess value: ");
   scanf("%f",&x0);

   printf("\n ---Solutions by Fixed Point Method--- \n\n");
   printf("x0\t\t xn\t\t Error\n");

    count=1;
    begin:
        xn=G(x0);
        error=(xn-x0)/xn;
        absError=fabs(error);

        printf("%f\t %f\t %f\n",x0,xn,absError);


        if(absError<EPS)
        {
            printf("\nRoot : %f \n",xn);
            printf("Functional Value : %f \n",F(xn));
            printf("Number of iterations : %d \n",count);
        }
        else
        {

            count++;
            if(count<MAXIT)
            {
                x0=xn;
                goto begin;
            }
            else
            {
                printf("Solutions does not exist in %d iteration",MAXIT);
            }
        }

        printf("\n------------------------------------------\n");
        printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 1.4\n\n");
}
