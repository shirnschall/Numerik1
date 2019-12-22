#include <iostream>
#include <cmath>

using namespace std;
double f(double);
double h(double);

int main()
{
    cout << f(1) << endl;
    return 0;
}

double f(double x)
{
    if(x == 0)
        return 1;
    else
        return (sin(x)/x)*exp(-x);
}

double h(double n)
{
    return solve
}


