#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include "gauss.hpp"

#define N 200
#define PRECISION 10
#define INTF ((double)1/49)*(7-log(8))
#define INTG 0.100146559237255042842031358826979521350464122400515832560306429572817834137774216903720755338989939836188953559757375415594185218468328969224042350631



double f(double,double);
double g(double,double);
double h(double,double);


int main() {
    std::cout << "Quadraturpunkte\tFehler\tFunktion" << std::endl;
    for(double x=0;x<N;++x) {
        Gauss Q(x);
        //std::cout << x << '\t' << std::setprecision(PRECISION) <<
        //          fabs(INTF - Q.result(f,0)) << "\tGauss-Laguerre" << std::endl;
        std::cout << x << '\t' << std::setprecision(PRECISION) <<
                  fabs(INTG - Q.result(g,0)) << "\tGauss-Laguerre" << std::endl;
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

