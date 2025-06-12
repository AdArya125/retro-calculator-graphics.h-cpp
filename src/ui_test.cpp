#include "graphics_ui.h"
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawButtons(true);     // true → show trig buttons
    highlightButton(1, 1); // highlight "4" button (row 1, col 1)

    getch(); // Wait for keypress
    closegraph();
    return 0;
}
