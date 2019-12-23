#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>


#define N 200
#define T 5
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

        for (int i = 1; i < N + 1; ++i) {

            double minerror = 10e10;
            double mint = 0;
            for(double j = 1; j<T;j+=.001) {
                double error = fabs(INTV - sumtrapez(j, i, v));
                if(error < minerror) {
                    minerror = error;
                    mint=j;
                }
            }
            printf("%d\t%.16e\texp(-x*x)\n",i,minerror);
            //std::cout << std::setprecision(PRECISION) <<
            //      minerror << '\n';
        }
}

double sumtrapez(double t, double n, double fkt(double)){
    double sum = fkt(0)/2 + fkt(t)/2;
    for(int i = 1; i < n; ++i){
        sum += fkt(i*t/n);
    }
    return t/n*sum;
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
    return std::abs(x)>10e-15?(exp(-(x*x))/(exp(x)+7)):(double)1;
}

double v(double x){
    return std::abs(x)>10e-15?(exp(-(x))/(exp(x)+7)):(double)1;
}

