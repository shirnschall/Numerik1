#include <iostream>
#include <cmath>

using namespace std;
double f(double);
double h(double);

int main()
{
    cout << f(0) << endl;
    return 0;
}

double f(double x)
{
    return 1/(exp(x)+7)*exp(-x);
}

double h(double n)
{
    return solve(n+2=5);
}


