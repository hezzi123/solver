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
    RealVariable operator*(const RealVariable& rv1, const RealVariable& rv2)
    {
        if(rv1.a * rv2.a == 0 && rv1.b * rv2.a==0 && rv1.a * rv2.b==0)
        {
            return RealVariable(rv1.b * rv2.b, rv1.b * rv2.c + rv1.c * rv2.b, rv1.c * rv2.c);
        }
        throw std::runtime_error("Power greater than 2");
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
        return RealVariable(x.a * 1 , x.b * 1 , x.c - num);
    }
    RealVariable operator-(const double num, const RealVariable& x)
    {
        return RealVariable(-x.a * 1 , -x.b * 1, num - x.c);
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
    ComplexVariable operator+(const ComplexVariable& x, const complex<double> num)
    {
        return ComplexVariable(x.a * 1.0, x.b * 1.0, x.c + num);
    }
    ComplexVariable operator+(const complex<double> num, const ComplexVariable& x)
    {
        return ComplexVariable(-x.a * 1.0, -x.b * 1.0, num + x.c);

    }
    ComplexVariable operator+(const ComplexVariable& cv1, const ComplexVariable& cv2)
    {
        return ComplexVariable(cv1.a + cv2.a , cv1.b + cv2.b , cv1.c + cv2.c);
    }

    ComplexVariable operator-(const ComplexVariable& x, const complex<double> num)
    {
        return ComplexVariable(x.a * 1.0, x.b * 1.0, x.c - num);
    }
    ComplexVariable operator-(const complex<double> num, const ComplexVariable& x)
    {
        return ComplexVariable(-x.a * 1.0, -x.b * 1.0, num - x.c);
    }
    ComplexVariable operator-(const ComplexVariable& cv1, const ComplexVariable& cv2)
    {
        return ComplexVariable(cv1.a - cv2.a , cv1.b - cv2.b , cv1.c - cv2.c);
    }

    ComplexVariable operator*(const ComplexVariable& x, const complex<double> num)
    {
        return ComplexVariable(x.a * num , x.b * num , x.c * num);
    }
    ComplexVariable operator*(const complex<double> num, const ComplexVariable& x)
    {
        return ComplexVariable(x.a * num , x.b * num , x.c * num);
    }

    ComplexVariable operator/(const ComplexVariable& x, const complex<double> num)
    {
        if(num == complex(0.0 , 0.0)) throw std::out_of_range("Can't divide by 0");
        return ComplexVariable(x.a / num , x.b / num , x.c / num);
    }
    ComplexVariable operator/(const complex<double> num, const ComplexVariable& x)
    {
        if(num == 0.0) throw std::out_of_range("Can't divide by 0");
        return ComplexVariable(x.a / num , x.b / num , x.c / num);
    }

    ComplexVariable operator^(const ComplexVariable& x, const complex<double> num)
    {
        if(num == 0.0)
            return ComplexVariable(complex<double>(0.0,0.0),complex<double>(0.0,0.0),complex<double>(1.0,0.0));
        else if(num == 1.0)
            return ComplexVariable(x.a * 1.0, x.b * 1.0, x.c * 1.0);
        else if(num == 2.0)
        {
            if(x.a != complex<double>(0.0,0.0))
                throw std::runtime_error("Power above 2");
            return ComplexVariable(x.b * x.b * 1.0 ,2.0*x.b*x.c , x.c * x.c * 1.0);
        }
        throw std::runtime_error("Power above 2");
    }

    ComplexVariable operator==(const ComplexVariable& x, const complex<double> num) { return x - num; }
    ComplexVariable operator==(const complex<double> num, const ComplexVariable& x) { return x - num; }
    ComplexVariable operator==(const ComplexVariable& cv1, const ComplexVariable& cv2) { return cv1 - cv2; }

    //solve
    double solve (const RealVariable x)
    {
        if(x.a == 0 && x.b == 0) throw  std::out_of_range("Cant solve");
        if(x.a > 0 && x.b == 0 && 0 < x.c) throw  std::out_of_range("Cant solve sqrt of minus");
        if(x.a != 0)
        {
            return (-x.b + sqrt((pow(x.b , 2) - 4 * x.a * x.c)))/(2 * x.a);
        }
        return (-x.c / x.b);
    }
    complex<double> solve (const ComplexVariable& x)
    {
        if (x.a == 0.0 && x.b == 0.0) throw  std::out_of_range("Cant solve");
        if (x.a == 0.0)
        {
            return -x.c / x.b;
        }
        return (-x.b + sqrt(pow(x.b , 2.0) - 4.0 * x.a * x.c)) / (2.0 * x.a);
    }
}