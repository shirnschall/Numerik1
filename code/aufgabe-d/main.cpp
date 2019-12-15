#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 5
#define PRECISION 10

using namespace Eigen;

double f(double);


int main() {
        Gauss Q(N);
        double error = atan(1) - Q.result(f);
        std::cout << std::setprecision(PRECISION) <<
                  error << std::endl;
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?sin(x)/x : (double)1;
}
