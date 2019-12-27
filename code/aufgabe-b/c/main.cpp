#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>


#define N 200
#define T 6
#define PRECISION 10
#define INTF atan(1)
#define INTG (double)2*atan(1)*erf((double)1/2)
#define INTU 0.100146559237255042842031358826979521350464122400515832560306429572817834137774216903720755338989939836188953559757375415594185218468328969224042350631
#define INTV ((double)1/49)*(7-log(8))

double f(double);
double g(double);
double u(double);
double v(double);
double sumtrapez(double, double, double fkt(double));


int main() {
    std::cout << "Quadraturpunkte\tFehler\tFunktion" << std::endl;

        //printf("%.16e\texp(-x)\n",sumtrapez(6, 100, v));
        //printf("%.16e\texp(-x*x)\n",sumtrapez(6, 100, u));
        for (int i = 1; i < N + 1; ++i) {
            //double error = fabs(INTV - sumtrapez(T, i, v));
            //printf("%d\t%.16e\tTrapezregel\n",i,error);
            double error = fabs(INTU - sumtrapez(T, i, u));
            printf("%d\t%.16e\tTrapezregel\n",i,error);
            //std::cout << std::setprecision(PRECISION) <<
            //      minerror << '\n';
        }
}

double sumtrapez(double t, double n, double fkt(double)){
    double h = t/n;
    double sum = 0;
    for(double i = 1; i <= n; ++i){
        sum += (fkt(i*h)+fkt((i-1)*h))/2*h;
    }
    return sum;
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-15?(exp(-x)*sin(x)/x):(double)1;
}

double g(double x){
    return std::abs(x)>10e-15?(exp(-(x*x))*sin(x)/x):(double)1;
}

double u(double x){
    return (exp(-(x*x))/(exp(x)+7));
}

double v(double x){
    return (exp(-(x))/(exp(x)+7));
}

