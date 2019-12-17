#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 50
#define PRECISION 10

using namespace Eigen;

double f(double);
double g(double);


int main() {
    std::cout << "Quadraturpunkte\tFehler\tFunktion" << std::endl;
        for(int i=0;i<N+1;++i) {
            Gauss Q(i);

            double error = fabs(atan(1) - Q.result(f));
            //double error = Q.result(f);
            std::cout << i << '\t' << std::setprecision(PRECISION) <<
                      error << "\tGauss" << std::endl;
        }
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?(exp(x)*(sin(x)/x)) : (double)1;
}

double g(double x){
    return std::abs(x)>10e-7?(exp(x)*(1/(exp(x*x)+7))) : (double)1;
}

