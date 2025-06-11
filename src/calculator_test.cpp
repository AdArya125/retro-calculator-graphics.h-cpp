#include "calculator.h"

int main()
{
    CalcStack stack;

    CalcEntry e1;
    e1.fromDouble(12.345);
    e1.id = 101;
    stack.push(e1);

    CalcEntry e2;
    e2.fromDouble(7.89);
    e2.id = 102;
    stack.push(e2);

    stack.display();

    CalcEntry found;
    if (stack.searchById(101, found))
    {
        cout << "Found: " << found.toDouble() << endl;
    }

    return 0;
}
