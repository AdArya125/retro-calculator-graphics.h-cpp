#include "graphics_ui.h"
#include "ui_constants.h"

const int numRows = 6;
const int numCols = 5;
const int buttonWidth = 80;
const int buttonHeight = 40;

void drawDisplay(const string &text)
{
    setfillstyle(SOLID_FILL, BLACK);
    bar(UI_LEFT_X, UI_TOP_Y - 40, UI_LEFT_X + numCols * buttonWidth, UI_TOP_Y - 5);

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(UI_LEFT_X + 10, UI_TOP_Y - 30, const_cast<char *>(text.c_str()));
}

void drawTextLabels(bool trigVisible)
{
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);

    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            const char *label = buttonLabels[row][col];
            if (label && strlen(label) > 0)
            {
                int x = UI_LEFT_X + col * buttonWidth + 10;
                int y = UI_TOP_Y + row * buttonHeight + 10;
                outtextxy(x, y, const_cast<char *>(label));
            }
        }
    }

    if (trigVisible)
    {
        outtextxy(UI_LEFT_X - 70, UI_TOP_Y + 10, (char *)"Sin");
        outtextxy(UI_LEFT_X - 70, UI_TOP_Y + 50, (char *)"Cos");
        outtextxy(UI_LEFT_X - 70, UI_TOP_Y + 90, (char *)"Tan");
    }
}
