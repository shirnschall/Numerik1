#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>


#define N 200
#define T 10
#define PRECISION 10
#define INTF atan(1)
#define INTG (double)1/2*sqrt(4*atan(1))*erf((double)1/2)


double f(double);
double g(double);
double sumtrapez(double, double, double fkt(double));


int main() {
    std::cout << "Quadraturpunkte\tFehler\tFunktion" << std::endl;

        for (int i = 1; i < N + 1; ++i) {

            double minerror = 10e10;
            double mint = 0;
            for(double j = 1; j<T;j+=.001) {
                double error = fabs(INTF - sumtrapez(j, i, f));
                if(error < minerror) {
                    minerror = error;
                    mint=j;
                }
            }
            printf("%d\t%.16e\tTrapez\n",i,minerror);
            //std::cout << std::setprecision(PRECISION) <<
            //      minerror << '\n';
        }
}

double sumtrapez(double t, double n, double fkt(double)){
    double sum = fkt(0)/2 + fkt(t)/2;
    for(int i = 1; i < n; ++i){
        sum += fkt(i*t/n);
    }
    return t/n*sum;
}

double f(double x){
    //sin(x)/x      sonst
    //1             x=0
    return std::abs(x)>10e-15?(exp(-x)*sin(x)/x):(double)1;
}

double g(double x){
    return std::abs(x)>10e-15?((sin(x)/x) * exp(-(x*x))):(double)1;
}

