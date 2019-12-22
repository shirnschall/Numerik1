#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>


#define N 5
#define PRECISION 10

double f(double);
double g(double);
double h(double);


int main() {
    std::cout << "x\ty\tFunktion" << std::endl;
        for(double x=0;x<N;x+=0.001) {
            std::cout << x << '\t' << std::setprecision(PRECISION) <<
                          f(x) << "\t1/(exp(x)+7)" << std::endl;
        }
    for(double x=0;x<N;x+=0.001) {
        std::cout << x << '\t' << std::setprecision(PRECISION) <<
                  g(x) << "\t1/(exp(x)+7)*exp(-x)" << std::endl;
    }
    for(double x=0;x<N;x+=0.001) {
        std::cout << x << '\t' << std::setprecision(PRECISION) <<
                  h(x) << "\t1/(exp(x)+7)*exp(-x*x)" << std::endl;
    }
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return ((1/(exp(x)+7)));
}
double g(double x){
    //sin(x)/x      sonst
    //1             x=0
    return (exp(-x)*(1/(exp(x)+7)));
}
double h(double x){
    //sin(x)/x      sonst
    //1             x=0
    return (exp(-x*x)*(1/(exp(x)+7)));
}

