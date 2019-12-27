#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double sumtrapez(int,int);

int main()
{
    double t = 100;
    int i, j, n;
    /*printf("t\tn\ty\tfunktion\n");
    for(j = 1; j <= 100; j+=5)
    {
        for(i=1; i<=200 ; i+=10)
        {
            printf("%d\t%d\t%f\t%s\n", j, i,sumtrapez(j,i),"x*x");
            printf("Fehler ist:");
            printf("%f\n", (double) fabs(M_PI/4 - sumtrapez(j,i)));
        }
    }*/
    printf("t\tn\tFehler\n");
    for(i=1; i<=30000 ; i+=1000)
        {
            printf("%.2f\t%d\t%f\n", t, i, (double) fabs(M_PI/4 - sumtrapez(t,i)));
        }
    return 0;
}

double f(double x)
{
    if(x == 0)
        return 1;
    else
        return (sin(x)/x)*exp(-x);
}

double sumtrapez(int t, int n){
    double x, h, s = 0;
    int j;
    h = (double) t / n;
    for(j = 1; j <= n - 1; j++)
    {
        x = j * h;
        s += f(x);
    }
    return (double) (h / 2) * (f(0) + 2 * s + f(t));
}
