#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 64
#define PRECISION 10

using namespace Eigen;

double f(double);
double g(double);


int main() {
    Gauss Q(N);
    printf("Ergebnis: %.20e\n",Q.result(f));
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?(sin(x)/x) : (double)1;
}

double g(double x){
    return std::abs(x)>10e-7?(exp(x)*(1/(exp(x*x)+7))) : (double)1;
}

