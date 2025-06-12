#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include "../include/common.h"
#include "calculator.h"

// Stack used for characters (operators, brackets)
class CharStack
{
private:
    static const int MAX = 100;
    char data[MAX];
    int top;

public:
    CharStack();
    void push(char ch);
    char pop();
    char peek() const;
    bool isEmpty() const;
};

// Handles expression parsing and evaluation
class ExpressionEvaluator
{
private:
    CalcStack &memory; // Reference to number storage
    int nextId;        // Auto-id tracker

public:
    ExpressionEvaluator(CalcStack &stackRef);

    // Convert infix to postfix (e.g., "A+B" => "AB+")
    string infixToPostfix(const string &infix);

    // Evaluate a postfix expression like "AB+"
    long double evaluatePostfix(const string &postfix);

    // Operator precedence helper
    int precedence(char op);

    // Create an ID and push number into memory
    char storeNumber(long double value);
};

#endif // EXPRESSION_EVALUATOR_H
