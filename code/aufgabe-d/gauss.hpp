//
// Created by Sebastian Hirnschall on 14.12.19.
//

#ifndef AUFGABE_D_GAUSS_HPP
#define AUFGABE_D_GAUSS_HPP

#include </usr/local/include/eigen3/Eigen/Dense>
#include </usr/local/include/eigen3/Eigen/Eigenvalues>
#include <iostream>
#include <complex>

using namespace Eigen;

class Gauss {
    int n;
    MatrixXcd T;
    MatrixXcd eigenvectors;
    VectorXcd nodes;
    ComplexEigenSolver<MatrixXcd> ces;
public:

    Gauss(int);
    ~Gauss();
    double norm(int);
    std::complex<double>  weigth(int);
    std::complex<double> node(int);
    double result(double f(double));
    int nodesc();
    double q(int, double);
};


#endif //AUFGABE_D_GAUSS_HPP
