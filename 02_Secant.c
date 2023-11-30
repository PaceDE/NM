#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 50
#define F(x) (x)*(x)-(5*x)+6
int main()
{
   int count;
   float x1,x2,x3,f1,f2,error,absError;

   printf("Enter the initial two value: ");
   scanf("%f %f",&x1,&x2);

   printf("\n ---Solutions by Secant Method--- \n\n");
   printf("x1\t\t x2\t\t x3\t\t Error\n");

    count=1;
    begin:
        f1=F(x1);
        f2=F(x2);
        x3=x2-(f2*(x2-x1))/(f2-f1);
        error=(x3-x2)/x3;
        absError=fabs(error);
        printf("%f\t %f\t %f\t %f \n",x1,x2,x3,absError);


        if(absError<EPS)
        {
            printf("\nRoot : %f \n",x3);
            printf("Functional Value : %f \n",F(x3));
            printf("Number of iterations : %d \n",count);
        }
        else
        {

            count++;
            if(count<MAXIT)
            {
                x1=x2;
                x2=x3;
                goto begin;
            }
            else
            {
                printf("Solutions does not exist in %d iteration",MAXIT);
            }
        }

        printf("\n------------------------------------------\n");
        printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 1.2\n\n");
}
