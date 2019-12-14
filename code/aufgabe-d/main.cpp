#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 5

using namespace Eigen;

double f(std::complex<double>);


int main() {

    Gauss quadratur(N);
    std::cout << std::setprecision(10) <<
                   quadratur.result(f) << std::endl;

}

double f(std::complex<double> arg){
    double x = arg.real();
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?sin(x)/x : (double)1;
}
