#include "expression_evaluator.h"
#include <vector>
// ------------------------
// CharStack Implementation
// ------------------------

CharStack::CharStack()
{
    top = -1;
}

void CharStack::push(char ch)
{
    if (top < MAX - 1)
        data[++top] = ch;
}

char CharStack::pop()
{
    if (top >= 0)
        return data[top--];
    return '#'; // Sentinel value
}

char CharStack::peek() const
{
    if (top >= 0)
        return data[top];
    return '#';
}

bool CharStack::isEmpty() const
{
    return top == -1;
}

// -------------------------------
// ExpressionEvaluator Functions
// -------------------------------

ExpressionEvaluator::ExpressionEvaluator(CalcStack &stackRef)
    : memory(stackRef), nextId(100) {}

int ExpressionEvaluator::precedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

char ExpressionEvaluator::storeNumber(long double value)
{
    CalcEntry entry;
    entry.fromDouble(value);
    entry.id = nextId++;
    memory.push(entry);
    return static_cast<char>(entry.id);
}

string ExpressionEvaluator::infixToPostfix(const string &infix)
{
    CharStack opStack;
    string postfix;

    for (char token : infix)
    {
        if (isalnum(token))
        { // Accept all alphanumeric characters as operands
            postfix += token;
        }
        else if (token == '(')
        {
            opStack.push(token);
        }
        else if (token == ')')
        {
            while (!opStack.isEmpty() && opStack.peek() != '(')
            {
                postfix += opStack.pop();
            }
            opStack.pop(); // pop '('
        }
        else
        { // operator
            while (!opStack.isEmpty() &&
                   precedence(opStack.peek()) >= precedence(token))
            {
                postfix += opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.isEmpty())
    {
        postfix += opStack.pop();
    }

    return postfix;
}

long double ExpressionEvaluator::evaluatePostfix(const string &postfix)
{
    vector<long double> stack;

    for (char token : postfix)
    {
        if (isalnum(token))
        { // Accept all valid ID characters
            int id = static_cast<unsigned char>(token);
            CalcEntry result;
            if (memory.searchById(id, result))
            {
                stack.push_back(result.toDouble());
            }
            else
            {
                cerr << "Invalid ID: " << id << endl;
                return 0;
            }
        }
        else
        {
            if (stack.size() < 2)
            {
                cerr << "Insufficient operands!" << endl;
                return 0;
            }
            long double b = stack.back();
            stack.pop_back();
            long double a = stack.back();
            stack.pop_back();
            switch (token)
            {
            case '+':
                stack.push_back(a + b);
                break;
            case '-':
                stack.push_back(a - b);
                break;
            case '*':
                stack.push_back(a * b);
                break;
            case '/':
                if (b == 0)
                {
                    cerr << "Division by zero!" << endl;
                    return 0;
                }
                stack.push_back(a / b);
                break;
            case '^':
                stack.push_back(pow(a, b));
                break;
            default:
                cerr << "Unknown operator: " << token << endl;
            }
        }
    }

    return (stack.empty() ? 0 : stack.back());
}
