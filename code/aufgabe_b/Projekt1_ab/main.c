#include <stdio.h>
#include <stdlib.h>

double f(double);
double sumtrapez(int,int);

int main()
{
    double t = 2;
    int i, j, n;
    printf("t\tn\ty\tfunktion\n");
    for(j = 1; j <= 10; j++)
    {
        for(i=1; i<=20 ; i++)
        {
            printf("%d\t%d\t%f\t%s\n", j, i,sumtrapez(j,i),"x*x");
            //printf("Fehler ist:");
            //printf("");
        }
    }


    return 0;
}

double f(double x)
{
    return x*x; //sin(x)/x*exp(-x);
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
