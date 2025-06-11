#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../include/common.h"

// Represents a single number (e.g., 12.345)
class CalcEntry
{
public:
    unsigned long int intPart;  // Integer part (e.g., 12)
    unsigned long int fracPart; // Fractional part (e.g., 345)
    int fracDigits;             // Digits in fracPart (e.g., 3)
    bool isNegative;            // Sign flag
    int id;                     // Unique identifier for referencing
    CalcEntry *next;

    CalcEntry();                      // Default constructor
    void clear();                     // Reset the entry to 0
    long double toDouble() const;     // Convert to long double
    void fromDouble(long double val); // Load from long double
};

// Manages a stack of CalcEntry nodes
class CalcStack
{
private:
    CalcEntry *top;

public:
    CalcStack();
    void push(const CalcEntry &entry);
    bool searchById(int id, CalcEntry &result) const;
    void display() const;
    void clear();
};

#endif // CALCULATOR_H
