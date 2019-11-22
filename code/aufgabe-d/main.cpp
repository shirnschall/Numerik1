#include <iostream>
#include <cmath>
#include <stdio.h>

double g(double);
double f(double);


int main() {
    printf("x\ty\tfunktion\n");
    for(int i = -500; i<=500 ; i+=1) {
        printf("%f\t%f\t%s\n",(double) i / 100,g((double) i / 100),"sin(x)/x");
        printf("%f\t%f\t%s\n",(double) i / 100,f((double) i / 100),"x");
    }


    return 0;
}

double g(double x){
    //sin(x)/x      sonst
    //1             x=0
    return abs(x)>10e-7?sin(x)/x : (double)1;
}

double f(double x){
    return x;

}