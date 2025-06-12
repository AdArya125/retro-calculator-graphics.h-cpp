#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include "../include/common.h"

long double calculateSin(long double deg);
long double calculateCos(long double deg);
long double calculateTan(long double deg);

long double calculateInverseSin(long double val);
long double calculateInverseCos(long double val);
long double calculateInverseTan(long double val);

long double calculateSqrt(long double val);
long double calculateLog10(long double val);
long double calculateFactorial(int val); // Returns -1 if invalid
long double calculatePower(long double base, long double exponent);

#endif // MATH_OPERATIONS_H
