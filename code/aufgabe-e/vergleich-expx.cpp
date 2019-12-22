#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include "gauss.hpp"

#define N 200
#define PRECISION 10
#define INTF (double)(3*log(2))/7
#define INTG ((double)1/49)*(7-log(8))
#define INTH 0.100146559237255042842031358826979521350464122400515832560306429572817834137774216903720755338989939836188953559757375415594185218468328969224042350631

double f(double,double);
double g(double,double);
double h(double,double);


int main() {
    std::cout << "Quadraturpunkte\tFehler\tFunktion" << std::endl;
    for(double x=0;x<N;++x) {
        Gauss Q(x);
        std::cout << x << '\t' << std::setprecision(PRECISION) <<
                  fabs(atan(1) - Q.result(h,0)) << "\tGauss" << std::endl;
    }
}

double f(double x,double off){
    //sin(x)/x      sonst
    //1             x=0
    return ((1/(exp(x)+7)));
}
double g(double x,double off){
    //sin(x)/x      sonst
    //1             x=0
    return (1/(exp(x*x)+7*exp((x*x)-x)));
}
double h(double x,double off){
    //sin(x)/x      sonst
    //1             x=0
    return sin(x)/x;
}

