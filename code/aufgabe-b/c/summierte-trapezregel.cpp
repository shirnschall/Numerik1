double sumtrapez(double t, double n, double fkt(double)){
    double h = t/n;
    double sum = 0;
    for(double i = 1; i <= n; ++i){
        sum += (fkt(i*h)+fkt((i-1)*h))/2*h;
    }
    return sum;
}