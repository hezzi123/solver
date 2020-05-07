//
// Authors: Ariel Yechezkel & Almog Amiga
//

#include <iostream>
#include <complex>
#include "solver.hpp"
#include "doctest.h"
using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("RealVariable")
{
    RealVariable x ;//the real variable
            CHECK(solve(4*x == 16) == 4);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(x == 1) == 1);
            CHECK(solve(x+x == 8) == 4);
            CHECK(solve(x+2 == 10) == 8);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(x == 0) == 0);
            CHECK(solve(3*x/3 == 1) == 1);
            CHECK(solve(4*x+4*x == 8) == 1);
            CHECK(solve(x == 12/4) == 3);
            CHECK(solve(18*x+4/4 == 19) == 1);
            CHECK(solve(x+x == 8) == 4);
            CHECK(solve(x == 6) == 6);
            CHECK(solve(x+2 == 10) == 8);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(x == 1) == 1);
            CHECK(solve(x == 0) == 0);
            CHECK(solve(2*x == 10) == 5);
            CHECK(((solve((x^2) == 4) == 2) || (solve((x^2) == 4) == -2)));// should answer both
            CHECK(solve(5*x-20 == 5) == 5);
            CHECK(solve(x/x) == 1);
            CHECK(solve(x == 4) == 4);
            CHECK(solve((-2*x) == 14) == -7);
            CHECK(solve(12*x == 12+1-1) == 1);
            CHECK(solve(6*x == 5*x+1) == 1);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(2*x == 10) == 5);
            CHECK(solve(5*x-20 == 5) == 5);
            CHECK(solve(x/x) == 1);
            CHECK(solve(x == 4) == 4);
            CHECK(solve((-2*x) == 14) == -7);
            CHECK(solve(12*x == 12+1-1) == 1);
            CHECK(solve(6*x == 5*x +1) == 1);
            CHECK(solve(x == 0) == 0);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(x == 1) == 1);
            CHECK(solve(x+x == 8) == 4);
            CHECK(solve(x+2 == 10) == 8);
            CHECK(solve(x+2 == 10) == 8);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(18*x+4/4 == 19) == 1);
            CHECK(solve(x == 6) == 6);
            CHECK(solve(3*x/3 == 1) == 1);
            CHECK(solve(4*x+4*x == 8) == 1);
            CHECK(solve(x == 12/4) == 3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(12*x == 12+1-1) == 1);
            CHECK(solve(6*x == 5*x +1) == 1);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(4*x == 16) == 4);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(x+x == 8) == 4);
            CHECK(solve(x+2 == 10) == 8);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(x+2 == 10) == 8);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(x/x) == 1);
            CHECK(solve(x == 4) == 4);
            CHECK(solve(x == 6) == 6);
            CHECK(solve((-2*x) == 14) == -7);
            CHECK(solve(12*x == 12+1-1) == 1);
            CHECK(solve(18*x+4/4 == 19) == 1);
            CHECK(solve(3*x/3 == 1) == 1);
            CHECK(solve(4*x+4*x == 8) == 1);
            CHECK(solve(x == 12/4) == 3);
            CHECK(solve((-2*x) == 14) == -7);
            CHECK(solve(x == 4) == 4);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(12*x == 12+1-1) == 1);
            CHECK(solve(6*x == 5*x +1) == 1);
            CHECK(solve(2*x +1+1 == 4) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve((-2*x) == 14) == -7);
            CHECK(solve(12*x == 12+1-1) == 1);
            CHECK(solve(6*x == 5*x +1) == 1);
            CHECK(solve(x == 1) == 1);
            CHECK(solve(-2*x == 6) == -3);
            CHECK(solve(5*x-5 == 15) == 3);
            CHECK(solve(x+4 == 0) == -4);
            CHECK(solve(2*x == 10) == 5);
            CHECK(solve(5*x-20 == 5) == 5);
            CHECK(solve(x == 6) == 6);
            CHECK(solve(2*x == 10) == 5);
}

TEST_CASE("ComplexVariable"){
    ComplexVariable  x ;//the complex variable (with i)
            CHECK(solve(x+5 == 3i) == std::complex<double>(5,4));
            CHECK(solve(x == -2i) == std::complex<double>(0,2));
            CHECK(solve(5*x+14i == 10*x+4i) == std::complex<double>(0,2));
            CHECK(solve(5*x == 25i) == std::complex<double>(0,5));
}