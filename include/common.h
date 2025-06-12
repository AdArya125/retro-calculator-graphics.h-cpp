#ifndef COMMON_H
#define COMMON_H

// Standard includes
#include <graphics.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>

using namespace std;
// Coordinates
const int UI_LEFT_X = 200;
const int UI_TOP_Y = 40;

// Calculator constants
const double PI = 3.141592653589793;

// Global app state
extern std::string currentInput;

#include "../src/calculator.h"
#include "../src/expression_evaluator.h"

extern CalcStack stack;
extern ExpressionEvaluator evaluator;

#endif // COMMON_H
