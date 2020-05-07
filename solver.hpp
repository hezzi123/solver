//
// Authors: Ariel Yechezkel & Almog Amiga
//

#ifndef SOLVER_SOLVER_HPP
#define SOLVER_SOLVER_HPP
#pragma once
#include <complex>
#include <string>
using namespace std;
namespace solver
{
    class RealVariable
    {
    public:
        double a , b , c;
        RealVariable() :a(0), b(1), c(0) {}    //x
        RealVariable(double a, double b, double c) : a(a), b(b), c(c) {}

        friend RealVariable operator*(const RealVariable& x, const double num);
        friend RealVariable operator*(const double num, const RealVariable& x);

        friend RealVariable operator/(const RealVariable& x, const double num);
        friend RealVariable operator/(const double num , const RealVariable& x);

        friend RealVariable operator+(const RealVariable& x, const double num);
        friend RealVariable operator+(const double num, const RealVariable& x);
        friend RealVariable operator+(const RealVariable& rv1, const RealVariable& rv2);

        friend RealVariable operator-(const RealVariable& x, const double num);
        friend RealVariable operator-(const double num, const RealVariable& x);
        friend RealVariable operator-(const RealVariable& rv1, const RealVariable& rv2);

        friend RealVariable operator^(const RealVariable& x, const double num);

        friend RealVariable operator==(const RealVariable& x, const double num);
        friend RealVariable operator==(const double num, const RealVariable& x);
        friend RealVariable operator==(const RealVariable& rv1, const RealVariable& rv2);
    };

    class ComplexVariable
    {
    public:
        complex<double> a,b,c;
        ComplexVariable():a(0), b(1), c(0) {}    //x
        ComplexVariable(complex<double> a, complex<double> b, complex<double> c):a(a), b(b), c(c) {}

        friend ComplexVariable operator*(const ComplexVariable& x, const complex<double> num);
        friend ComplexVariable operator*(const complex<double> num, const ComplexVariable& x);

        friend ComplexVariable operator/(const ComplexVariable& x, const complex<double> num);
        friend ComplexVariable operator/(const complex<double> num, const ComplexVariable& x);

        friend ComplexVariable operator+(const ComplexVariable& x, const complex<double> num);
        friend ComplexVariable operator+(const complex<double> num, const ComplexVariable& x);
        friend ComplexVariable operator+(const ComplexVariable& cv1, const ComplexVariable& cv2);

        friend ComplexVariable operator-(const ComplexVariable& x, const complex<double> num);
        friend ComplexVariable operator-(const complex<double> num, const ComplexVariable& x);
        friend ComplexVariable operator-(const ComplexVariable& cv1, const ComplexVariable& cv2);

        friend ComplexVariable operator^(const ComplexVariable& x, const complex<double> num);

        friend ComplexVariable operator==(const ComplexVariable& x, const complex<double> num);
        friend ComplexVariable operator==(const complex<double> num, const ComplexVariable& x);
        friend ComplexVariable operator==(const ComplexVariable& cv1, const ComplexVariable& cv2);
    };

    double solve(const RealVariable x);
    complex<double> solve(const ComplexVariable& x);

}
#endif //SOLVER_SOLVER_HPP
