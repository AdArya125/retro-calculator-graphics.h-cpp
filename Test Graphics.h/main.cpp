#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    rectangle(100, 100, 300, 200);
    outtextxy(120, 150, "Graphics.h is working!");

    getch(); // Wait for a key press
    closegraph();

    return 0;
}
