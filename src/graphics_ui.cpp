#include "graphics_ui.h"

const int buttonWidth = 80;
const int buttonHeight = 40;
const int numRows = 6;
const int numCols = 5;

void drawCalculatorBox()
{
    setcolor(WHITE);
    // Horizontal lines
    for (int i = 0; i <= numRows; ++i)
    {
        int y = UI_TOP_Y + i * buttonHeight;
        line(UI_LEFT_X, y, UI_LEFT_X + numCols * buttonWidth, y);
    }
    // Vertical lines
    for (int j = 0; j <= numCols; ++j)
    {
        int x = UI_LEFT_X + j * buttonWidth;
        line(x, UI_TOP_Y, x, UI_TOP_Y + numRows * buttonHeight);
    }
}

void highlightButton(int row, int col)
{
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(
        UI_LEFT_X + col * buttonWidth + 2,
        UI_TOP_Y + row * buttonHeight + 2,
        UI_LEFT_X + (col + 1) * buttonWidth - 2,
        UI_TOP_Y + (row + 1) * buttonHeight - 2);
}

void drawTextLabels(bool trigVisible)
{
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    outtextxy(UI_LEFT_X + 10, UI_TOP_Y + 10, "TRIGNO");
    outtextxy(UI_LEFT_X + 110, UI_TOP_Y + 10, "1");
    outtextxy(UI_LEFT_X + 190, UI_TOP_Y + 10, "2");
    outtextxy(UI_LEFT_X + 270, UI_TOP_Y + 10, "3");
    outtextxy(UI_LEFT_X + 350, UI_TOP_Y + 10, "+");

    // Add more text labels like 4-9, -, *, /, etc. if needed
    // You can port labels from your original `text()` function

    if (trigVisible)
    {
        outtextxy(UI_LEFT_X - 70, UI_TOP_Y + 10, "Sin");
        outtextxy(UI_LEFT_X - 70, UI_TOP_Y + 50, "Cos");
        outtextxy(UI_LEFT_X - 70, UI_TOP_Y + 90, "Tan");
    }
}

void drawButtons(bool trigVisible)
{
    drawCalculatorBox();
    drawTextLabels(trigVisible);
}

void clearUI()
{
    cleardevice();
}
