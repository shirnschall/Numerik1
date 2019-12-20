#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include "gauss.hpp"

#define N 5
#define PRECISION 10
#define INTF (double)(3*log(2))/7
#define INTG ((double)1/49)*(7-log(8))
#define INTH 0.100146559237255042842031358826979521350464122400515832560306429572817834137774216903720755338989939836188953559757375415594185218468328969224042350631
#define T (double)10e6

double f(double,double);
double g(double,double);
double h(double,double);
double intf(double,double);
double intg(double,double);
double inth(double,double);
double integral(double(f)(double), double a, double b, int n);
double sumtrapez( double fkt(double),double t, double n);



int main() {
    Gauss Q(64);
    std::cout << "T\tIntegral T bis Unendlich\tFunktion" << std::endl;
    for(double x=0;x<N;x+=0.01) {
        printf("%f\t%e\t1/(exp(x)+7)\n",x,fabs(INTF - intf(0,x)));
    }
    //std::cout << intf(0,5);
    for(double x=0;x<N;x+=0.01) {
        printf("%f\t%e\t1/(exp(x)+7)*exp(-x)\n",x,fabs(INTG - intg(0,x)));
    }
    //std::cout << fabs(INTH - sumtrapez(h,5,T));
    for(double x=0;x<N;x+=0.01) {
        printf("%f\t%e\t1/(exp(x)+7)*exp(-x*x)\n",x,fabs(Q.result(h,x)));
    }
    //printf("%e\tsin(x)/x*exp(-x*x)\n",Q.result(h,5));
}

double f(double x,double off){
    x+=off;
    //sin(x)/x      sonst
    //1             x=0
    return ((1/(exp(x)+7))*exp(x-off)*exp(-x));
}
double g(double x,double off){
    x+=off;
    //sin(x)/x      sonst
    //1             x=0
    return (exp(x-off)*exp(-(x))*(1/(exp(x)+7)));
}
double h(double x,double off){
    x+=off;
    //sin(x)/x      sonst
    //1             x=0
    return (exp(x-off)*exp(-(x*x))*(1/(exp(x)+7)));
}

double intf(double a,double b){
    return (((double)1/7)*(b-log(exp(b)+7)))-(((double)1/7)*(a-log(exp(a)+7)));
}
double intg(double a,double b){
    return (((double)1/49)*(log(7*exp(-b)+1)-7*exp(-b)))-(((double)1/49)*(log(7*exp(-a)+1)-7*exp(-a)));
}
double inth(double a,double b){
    return (((double)1/7)*(b-log(exp(b)+7)))-(((double)1/7)*(a-log(exp(a)+7)));
}


double integral(double(f)(double x), double a, double b, int n) {
    double step = (b - a) / n;  // width of each small rectangle
    double area = 0.0;  // signed area
    for (int i = 0; i < n; i ++) {
        area += f(a + (i + 0.5) * step) * step; // sum up each small rectangle
    }
    return area;
}
double sumtrapez( double fkt(double),double t, double n){
    double sum = fkt(0)/2 + fkt(t)/2;
    for(int i = 1; i < n; ++i){
        sum += fkt(i*t/n);
    }
    return t/n*sum;
}

