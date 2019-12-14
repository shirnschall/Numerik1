#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 5
#define PRECISION 10

using namespace Eigen;

double f(std::complex<double>);


int main() {

    std::cout << "Quadraturpunkte\tFehler\tFunktion"<<std::endl;
    for(int i = 1; i < 10; ++i) {
        Gauss Q(i);
        double error = atan(1) - Q.result(f);
        std::cout <<i<<"\t"<< std::setprecision(PRECISION) <<
                  error << "\tGauss" << std::endl;
    }

}

double f(std::complex<double> arg){
    double x = arg.real();
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?sin(x)/x : (double)1;
}
