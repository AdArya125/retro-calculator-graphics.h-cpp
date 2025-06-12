#include "animations.h"
#include <cmath>
#include <conio.h>

float cx = 250, cy = 200, r = 100;

inline float dtr(float deg)
{
    return deg * PI / 180.0;
}

inline float rtd(float rad)
{
    return rad * 180.0 / PI;
}

void adf(float upx, float upy, float dwx, float dwy, float x, float d1)
{
    float a = d1 * cos(x);
    float b = d1 * sin(x);

    float d2 = sqrt(pow(fabs(cx + a - upx), 2) + pow(fabs(cy + b - upy), 2));
    float rArc = d2 - d1;
    float th = acos(d1 / d2);

    x = rtd(x);
    th = rtd(th);

    for (float i = 0; i < (rArc / 7); ++i)
    {
        setcolor(BLACK);
        arc(cx + a, cy + b, 0, 360, d2 + i);
        arc(cx - a, cy - b, 360, 0, d2 + i);
    }

    setfillstyle(SOLID_FILL, BLACK);
    circle(cx, cy, rArc / 2);
    floodfill(cx, cy, BLACK);
}

void playSharinganIntro()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    float x, y = 0, u = 0, i, z = 0;

    while (z < 1)
    {
        z++;
        for (i = 0, y = -120; i < 12; i++, y = u, y += 5)
        {
            cleardevice();

            // Red filled base circle
            setcolor(RED);
            setfillstyle(SOLID_FILL, RED);
            circle(cx, cy, r);
            floodfill(cx, cy, RED);

            u = y;

            // 3 Tomoe swirl trails
            for (int offset = 0; offset < 3; ++offset)
            {
                float angle = y + offset * 60;
                x = dtr(angle);
                adf(cx + r * sin(x), cy - r * cos(x),
                    cx - r * sin(x), cy + r * cos(x),
                    x, 2 * r);
            }

            delay(50);
        }
    }

    cleardevice();
    closegraph();
}
