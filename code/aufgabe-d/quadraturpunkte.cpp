#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include </usr/local/include/eigen3/Eigen/Dense>
#include "gauss.hpp"

#define N 3
#define PRECISION 10

using namespace Eigen;

double f(double);


int main() {
    Gauss Q(N);

    std::cout<<"Quadraturpunkte\tGewichte\tn"<<std::endl;

    for(int i = 0; i < Q.nodesc(); ++i) {
        double error = atan(1) - Q.result(f);
        std::cout << std::setprecision(PRECISION) <<
                  Q.node(i).real() << "\t" << Q.weigth(i).real() <<
                  "\t"<<N<<std::endl;
    }
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-7?sin(x)/x : (double)1;
}
