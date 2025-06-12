#ifndef GRAPHICS_UI_H
#define GRAPHICS_UI_H

#include "../include/common.h"

// UI rendering functions
void drawCalculatorBox();
void drawButtons(bool trigVisible = false);
void highlightButton(int row, int col);
void drawTextLabels(bool trigVisible = false);
void clearUI();

#endif // GRAPHICS_UI_H
