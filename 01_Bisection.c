#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 50
#define F(x) 4*(x)*(x)*(x)-(2*x)+6
int main()
{
   int count;
   float x1,x2,xm,f1,f2,fxm,absError;
   do{
   printf("Enter the initial two value of interval: ");
   scanf("%f %f",&x1,&x2);
   f1=F(x1);
   f2=F(x2);
   }while((f1*f2)>=0);

   printf("\n ---Solutions by Bisection Method--- \n\n");
   printf("x1\t\t f(x1)\t\t x2\t\t f(x2)\t\t xm\t\t f(xm)\n");

    count=1;
    begin:
        xm=(x1+x2)/2;
        fxm=F(xm);
        absError=fabs(fxm);
        printf("%f\t %f\t %f\t %f\t %f\t %f\n",x1,f1,x2,f2,xm,fxm);


        if(absError<EPS)
        {
            printf("\nRoot : %f \n",xm);
            printf("Functional Value : %f \n",fxm);
            printf("Number of iterations : %d \n",count);
        }
        else
        {
            count++;
            if(count<MAXIT)
            {
                if(f1*fxm<0)
                {
                    x2=xm;
                    f2=fxm;
                }
                else
                {
                    x1=xm;
                    f1=fxm;
                }
                goto begin;
            }
            else
            {
                printf("Solutions does not exist in %d iteration\n\n",MAXIT);
            }
        }

        printf("\n------------------------------------------\n");
        printf("Name: Dipesh Shrestha \nRoll no: 08 \nLab no 1.1");
}
