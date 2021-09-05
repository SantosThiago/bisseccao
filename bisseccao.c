#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double absol(double x1,double x2)
{
    double res=0;
    if (x1>x2)
    {
        res=x1-x2;
    }

    else
    {
        res=x2-x1;
    }
    return res;
}

double f(double x)
{
    double fun=pow(x,3)-87;
    return fun;
}

int main()
{
    double a=0,b=0,x0;
    int n=1;
    printf("Digite o valor de a:\n");
    scanf("%lf",&a);
    printf("Digite o valor de b:\n");
    scanf("%lf",&b);
    if(f(a)*f(b)>0)
    {
        printf("Digite outro intervalo");
        return 0;
    }
    double x=(a+b)/2;

    double er=f(x);
    double ex=0;
    double erro=pow(10,-8);

    //printf("\nf(x)=x^5-x^3+3x-5\n");
    printf("\nf(x)=x^3-87\n");
    printf("Intervalo:[%.0lf,%.0lf]\n",a,b);
    printf("Erro:%.15lf\n\n",erro);

    printf("iteracao:%d\t",n);
    printf("x=%0.15lf\t",x);
    printf("er:%0.15lf\t",er);
    printf("ex:%0.15lf\n",ex);

    do
    {
        if(f(a)*f(b)>0)
        {
            printf("Digite outro intervalo");
            return 0;
        }

        if (f(x)==0)
        {
            printf("x=%0.15lf",x);
            return 0;
        }

        n++;
        x0=x;

        if (f(a)*f(x)<0)
            b=x;

        else
            a=x;

        x=(a+b)/2;
        er=absol(f(x),0);
        ex=absol(x,x0);
        printf("iteracao:%d\t",n);
        printf("x=%0.15lf\t",x);
        printf("er:%0.15lf\t",er);
        printf("ex:%0.15lf\n",ex);

    }while(er>erro || ex>erro);

    return 0;
}
