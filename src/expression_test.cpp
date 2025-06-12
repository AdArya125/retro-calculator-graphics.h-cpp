#include "calculator.h"
#include "expression_evaluator.h"

void runTest(ExpressionEvaluator &eval, const string &label, const string &infix)
{
    string postfix = eval.infixToPostfix(infix);
    cout << "🧪 " << label << "\n";
    cout << "Infix   : " << infix << "\n";
    cout << "Postfix : " << postfix << "\n";
    cout << "Result  : " << eval.evaluatePostfix(postfix) << "\n\n";
}

int main()
{
    CalcStack stack;
    ExpressionEvaluator eval(stack);

    // Test 1: 4 + 5
    char a = eval.storeNumber(4);
    char b = eval.storeNumber(5);
    runTest(eval, "Test 1: 4 + 5", string(1, a) + "+" + string(1, b));

    // Test 2: (2 + 3) * 4
    char c = eval.storeNumber(2);
    char d = eval.storeNumber(3);
    char e = eval.storeNumber(4);
    runTest(eval, "Test 2: (2 + 3) * 4", "(" + string(1, c) + "+" + string(1, d) + ")*" + string(1, e));

    // Test 3: 10 - 2 * 3
    char f = eval.storeNumber(10);
    char g = eval.storeNumber(2);
    char h = eval.storeNumber(3);
    runTest(eval, "Test 3: 10 - 2 * 3", string(1, f) + "-" + string(1, g) + "*" + string(1, h));

    // Test 4: 8 / 2 + 3 ^ 2
    char i = eval.storeNumber(8);
    char j = eval.storeNumber(2);
    char k = eval.storeNumber(3);
    runTest(eval, "Test 4: 8 / 2 + 3 ^ 2", string(1, i) + "/" + string(1, j) + "+" + string(1, k) + "^" + string(1, j));

    // Test 5: Division by zero
    char m = eval.storeNumber(5);
    char n = eval.storeNumber(0);
    runTest(eval, "Test 5: 5 / 0 (Division by Zero)", string(1, m) + "/" + string(1, n));

    return 0;
}
