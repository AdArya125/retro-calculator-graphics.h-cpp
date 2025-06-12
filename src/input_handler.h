#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "../include/common.h"

// Grid state (shared by navigation functions)
extern int selectedRow;
extern int selectedCol;
extern const int numRows;
extern const int numCols;

// Draws the current button highlight
void updateHighlight();

// Processes keyboard input and updates highlight or triggers action
void handleKeyPress(char key, bool &running);

// Maps selected button to a label or action (for future logic)
void handleButtonPress(int row, int col);

#endif // INPUT_HANDLER_H
