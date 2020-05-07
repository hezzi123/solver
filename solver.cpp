//
// Authors: Ariel Yechezkel & Almog Amiga
//

#include "solver.hpp"
#include <iostream>
#include <string>
#include <complex>
using namespace std;
using namespace solver;

namespace solver
{
    //RealVariable
    RealVariable operator*(const RealVariable& x, const double num)
    {
        return RealVariable(x.a * num , x.b * num , x.c * num);
    }
    RealVariable operator*(const double num, const RealVariable& x)
    {
        return RealVariable(x.a * num , x.b * num , x.c * num);
    }
    RealVariable operator*(const RealVariable& x, const RealVariable& r)
    {
        if(x.a * r.a == 0 && x.b * r.a==0 && x.a * r.b==0)
        {
            return RealVariable(x.b * r.b, x.b * r.c + x.c * r.b, x.c * r.c);
        }
        throw std::runtime_error("Possession greater than 2");
    }

    RealVariable operator/(const RealVariable& x, const double num)
    {
        if(num == 0) throw std::out_of_range("Can't divide by 0") ;
        return RealVariable(x.a / num, x.b / num , x.c / num);
    }
    RealVariable operator/(const double num , const RealVariable& x)
    {
        if(x.a == 0 && x.b == 0 && x.c == 0 )  throw std::out_of_range("Can't divide by 0") ;
        return RealVariable(num / x.a , num / x.b , num / x.c);
    }

    RealVariable operator+(const RealVariable& x, const double num)
    {
        return RealVariable(x.a * 1 , x.b * 1 , x.c + num);
    }
    RealVariable operator+(const double num, const RealVariable& x)
    {
        return RealVariable(x.a * 1 , x.b * 1 , x.c + num);
    }
    RealVariable operator+(const RealVariable& rv1, const RealVariable& rv2)
    {
        return RealVariable(rv1.a + rv2.a , rv1.b + rv2.b , rv1.c + rv2.c);
    }

    RealVariable operator-(const RealVariable& x, const double num)
    {
        return RealVariable(x.a , x.b , x.c - num);
    }
    RealVariable operator-(const double num, const RealVariable& x)
    {
        return RealVariable(-x.a , -x.b , num - x.c);
    }
    RealVariable operator-(const RealVariable& rv1, const RealVariable& rv2)
    {
        return RealVariable(rv1.a - rv2.a , rv1.b - rv2.b , rv1.c - rv2.c);
    }

    RealVariable operator^(const RealVariable& x, const double num)
    {
        if(num == 0)
            return RealVariable(0,0,1);
        else if(num == 1)
            return x;
        else if(num == 2)
            return operator*(x , x);
        else
        {
            throw std::runtime_error("Can't calculate a number that higher than 2");
        }
    }

    RealVariable operator==(const RealVariable& x, const double num)
    {
        return RealVariable(x.a * 1, x.b * 1, x.c - num);
    }
    RealVariable operator==(const double num, const RealVariable& x)
    {
        return x == num;
    }
    RealVariable operator==(const RealVariable& rv1, const RealVariable& rv2)
    {
        return RealVariable(rv1.a - rv2.a, rv1.a - rv2.b , rv1.c - rv2.c);
    }

    //ComplexVariable
    ComplexVariable operator+(const ComplexVariable& x, const complex<double> num) { return x; }
    ComplexVariable operator+(const complex<double> num, const ComplexVariable& x) { return x; }
    ComplexVariable operator+(const ComplexVariable& cv1, const ComplexVariable& cv2) { return cv1; }

    ComplexVariable operator-(const ComplexVariable& x, const complex<double> num) { return x; }
    ComplexVariable operator-(const complex<double> num, const ComplexVariable& x) { return x; }
    ComplexVariable operator-(const ComplexVariable& cv1, const ComplexVariable& cv2) { return cv1; }

    ComplexVariable operator*(const ComplexVariable& x, const complex<double> num) { return x; }
    ComplexVariable operator*(const complex<double> num, const ComplexVariable& x) { return x; }
    ComplexVariable operator*(const ComplexVariable& cv1, const ComplexVariable& cv2) { return cv1; }

    ComplexVariable operator/(const ComplexVariable& x, const complex<double> num) { return x; }
    ComplexVariable operator/(const ComplexVariable& cv1, const ComplexVariable& cv2) { return cv1; }

    ComplexVariable operator^(const ComplexVariable& x, const complex<double> num) { return x; }

    ComplexVariable operator==(const ComplexVariable& x, const complex<double> num) { return x; }
    ComplexVariable operator==(const complex<double> num, const ComplexVariable& x) { return x; }
    ComplexVariable operator==(const ComplexVariable& cv1, const ComplexVariable& cv2) { return cv1; }

    //solve
    double solve (const RealVariable x)
    {
        if(x.a == 0 && x.b == 0) throw  std::out_of_range("Cant solve c = 0");
        if(x.a > 0 && x.b == 0 && 0 < x.c) throw  std::out_of_range("Cant solve x^2 = -c");
        if(x.a != 0)
        {
            return (-x.b + sqrt((pow(x.b , 2) - 4 * x.a * x.c)))/(2 * x.a);
        }
        return (-x.c / x.b);
    }
    complex<double> solve (const ComplexVariable& x)
    {
        complex<double> complex1;
        return complex1;
    }
}