#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 6
#define PRECISION 10

using namespace Eigen;



int main() {


    Gauss Q(N);
    std::cout << "x\ty\tGrad" << std::endl;
    for(int i=1;i<N;++i) {
        for(double j = -5;j<15;j += 0.001)
        std::cout << j << '\t' << std::setprecision(PRECISION) <<
                  Q.q(i,j) << '\t' << i << std::endl;
    }
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?((sin(x)/x)) : (double)1;
}

double g(double x){
    return std::abs(x)>10e-7?(exp(x)*(1/(exp(x*x)+7))) : (double)1;
}

