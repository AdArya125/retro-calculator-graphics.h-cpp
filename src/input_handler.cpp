#include "input_handler.h"
#include "graphics_ui.h"
#include "ui_constants.h"

void handleButtonPress(int row, int col)
{
    const char *label = buttonLabels[row][col];

    if (!label)
        return;

    cout << "Pressed: " << label << endl;

    if (strcmp(label, "=") == 0)
    {
        try
        {
            string postfix = ExpressionEvaluator(stack).infixToPostfix(currentInput);
            long double result = ExpressionEvaluator(stack).evaluatePostfix(postfix);
            currentInput = to_string(result);
        }
        catch (...)
        {
            currentInput = "ERROR";
        }
    }

    else if (strcmp(label, "AC") == 0)
    {
        currentInput.clear();
    }
    else if (strcmp(label, "<--") == 0)
    {
        if (!currentInput.empty())
            currentInput.pop_back();
    }
    else
    {
        // Append label to expression buffer
        currentInput += label;
    }
}
void updateHighlight()
{
    clearUI();
    drawButtons(true);
    highlightButton(selectedRow, selectedCol);
    drawDisplay(currentInput); // <-- NEW
}
