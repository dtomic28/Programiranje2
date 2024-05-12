//
// Created by Danijel Tomić on 12. 05. 24.
//
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix<int> matrixA(2, 3);
    matrixA.setData({{1, 2, 3}, {4, 5, 6}});
    std::cout << "Matrix A:\n" << matrixA << std::endl;

    Matrix<int> matixB(2, 3);
    std::cout << "Matrix B:\n" << matixB << std::endl;
    std::cout << "Matrix B with postfix:\n" << matixB++ << std::endl;
    std::cout << "Matrix B with prefix:\n" << ++matixB << std::endl;

    // Matrix addition
    Matrix matrixC = matrixA + matixB;
    std::cout << "Matrix addition:\n" << matrixC << std::endl;

    // Matrix subtraction
    Matrix matrixD = matrixA - matixB;
    std::cout << "Matrix subtraction:\n" << matrixD << std::endl;
    return 0;
}