#include <stdio.h>
#include <stdlib.h>

double g(double);
double f(double);

int main(){

    int i;
    printf("x\ty\tfunktion\n");
    for(i=0; i<=255 ; i++) {
        printf("%f\t%f\t%s\n",(double) i / 100,g((double) i / 100),"sin(x)/x");
        printf("%f\t%f\t%s\n",(double) i / 100,f((double) i / 100),"x");
    }

    return 0;
}

double g(double x){
    //sin(x)/x      sonst
    //1             x=0
    return abs(x)>10e-14?sin(x)/x : (double)1;
}

double f(double x){
    return x;

}
