#include "animations.h"
#include "graphics_ui.h"
#include "input_handler.h"
#include "calculator.h"
#include "expression_evaluator.h"
#include "math_operations.h"
#include <conio.h>
#include "../include/common.h"
string currentInput = "";
CalcStack stack;
ExpressionEvaluator evaluator(stack);

int main()
{
    // Step 1: Play Sharingan Intro
    playSharinganIntro();

    // Step 2: Launch calculator UI
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    bool running = true;

    // Step 3: Create memory stack and evaluator
    CalcStack stack;
    ExpressionEvaluator evaluator(stack);

    // Step 4: Initial draw
    updateHighlight();

    // Step 5: Input loop
    while (running)
    {
        if (kbhit())
        {
            char key = getch();
            handleKeyPress(key, running);
        }
    }

    // Step 6: Clean up
    closegraph();
    return 0;
}
