#include "calculator.h"

// -------------------------
// CalcEntry Implementation
// -------------------------

CalcEntry::CalcEntry()
{
    intPart = 0;
    fracPart = 0;
    fracDigits = 0;
    isNegative = false;
    id = 1;
    next = nullptr;
}

void CalcEntry::clear()
{
    intPart = 0;
    fracPart = 0;
    fracDigits = 0;
    isNegative = false;
    next = nullptr;
}

long double CalcEntry::toDouble() const
{
    long double value = static_cast<long double>(intPart);
    value += static_cast<long double>(fracPart) / pow(10, fracDigits);
    if (isNegative)
        value *= -1.0;
    return value;
}

void CalcEntry::fromDouble(long double val)
{
    isNegative = val < 0;
    val = fabs(val);
    intPart = static_cast<unsigned long int>(val);
    long double frac = val - intPart;
    fracPart = static_cast<unsigned long int>(frac * 100000); // 5-digit precision
    fracDigits = 5;
}

// -------------------------
// CalcStack Implementation
// -------------------------

CalcStack::CalcStack() : top(nullptr) {}

void CalcStack::push(const CalcEntry &entry)
{
    CalcEntry *newNode = new CalcEntry(entry);
    newNode->next = top;
    top = newNode;
}

bool CalcStack::searchById(int id, CalcEntry &result) const
{
    CalcEntry *current = top;
    while (current != nullptr)
    {
        if (current->id == id)
        {
            result = *current;
            return true;
        }
        current = current->next;
    }
    return false;
}

void CalcStack::display() const
{
    CalcEntry *current = top;
    while (current != nullptr)
    {
        cout << "[ID: " << current->id << ", Value: " << current->toDouble() << "] --> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void CalcStack::clear()
{
    while (top != nullptr)
    {
        CalcEntry *temp = top;
        top = top->next;
        delete temp;
    }
    top = nullptr;
}
