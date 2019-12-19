#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>


#define N 50
#define T 25
#define PRECISION 10
#define RESULT 0.81759929616592600944298571664996074687532718317818639845753860651354050765699321292812741847678445

double f(double);
double g(double);
double sumtrapez(double, double, double fkt(double));


int main() {
    std::cout << "Quadraturpunkte\tFehler\tFunktion" << std::endl;

        for (int i = 1; i < N + 1; ++i) {

            double minerror = 10e10;
            double mint = 0;
            for(double j = 1; j<T;j+=.1) {
                double error = fabs(RESULT - sumtrapez(j, i, f));
                if(error < minerror) {
                    minerror = error;
                    mint=j;
                }
            }
            printf("%d\t%e\tTrapez\n",i,minerror);
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
    return std::abs(x)>10e-7?((sin(x)/x)*exp(-(x*x))) : (double)1;
}

double g(double x){
    return std::abs(x)>10e-7?(exp(x)*(1/(exp(x*x)+7))) : (double)1;
}

