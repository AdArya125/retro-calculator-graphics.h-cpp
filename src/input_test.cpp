#include "graphics_ui.h"
#include "input_handler.h"
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    bool running = true;
    updateHighlight();

    while (running)
    {
        char key = getch();
        handleKeyPress(key, running);
    }

    closegraph();
    return 0;
}
