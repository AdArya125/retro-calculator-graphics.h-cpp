#include "math_operations.h"

long double calculateSin(long double degrees)
{
    return sin(degrees * PI / 180.0); // Convert to radians
}

long double calculateCos(long double degrees)
{
    return cos(degrees * PI / 180.0);
}

long double calculateTan(long double degrees)
{
    return tan(degrees * PI / 180.0);
}

long double calculateInverseSin(long double val)
{
    if (val < -1.0 || val > 1.0)
        return NAN;
    return asin(val) * 180.0 / PI; // Return in degrees
}

long double calculateInverseCos(long double val)
{
    if (val < -1.0 || val > 1.0)
        return NAN;
    return acos(val) * 180.0 / PI;
}

long double calculateInverseTan(long double val)
{
    return atan(val) * 180.0 / PI;
}

long double calculateSqrt(long double val)
{
    return (val >= 0.0) ? sqrt(val) : NAN;
}

long double calculateLog10(long double val)
{
    return (val > 0.0) ? log10(val) : NAN;
}

long double calculatePower(long double base, long double exponent)
{
    return pow(base, exponent);
}

long double calculateFactorial(int val)
{
    if (val < 0)
        return -1;
    long double result = 1;
    for (int i = 2; i <= val; ++i)
    {
        result *= i;
    }
    return result;
}
