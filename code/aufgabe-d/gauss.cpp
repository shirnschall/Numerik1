//
// Created by Sebastian Hirnschall on 14.12.19.
//

#include "gauss.hpp"
using namespace Eigen;


Gauss::Gauss(int n):n(n) {
    T = MatrixXcf::Zero(n+1,n+1);

    T(0,0)=1;
    for(int i = 1; i < n+1; ++i){
        T(i-1,i)=-(i);
        T(i,i-1)=-(i);
        T(i,i)=2*(i+1)-1;
    }
    ces = ComplexEigenSolver<MatrixXcf>(T);
    eigenvectors = ces.eigenvectors();
    nodes = T.eigenvalues();

}
Gauss::~Gauss(){

}

double Gauss::norm(int i){
    double sum = 0;
        for(int j = 0; j<eigenvectors.rows();++j) {
            sum += std::abs(eigenvectors(i,j)) * std::abs(eigenvectors(i,j));
        }
    return std::sqrt(sum);
}

std::complex<double> Gauss::weigth(int j) {
    return eigenvectors(0,j) * eigenvectors(0,j);
}
std::complex<double> Gauss::node(int i) {
    return nodes(i);
}

double Gauss::result(double f(std::complex<double>)){
    std::complex<double> sum = 0;
    for(int i = 0; i < n;++i){
        sum += weigth(i)*f(node(i));
    }
    return sum.real();
}