#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "../include/common.h"
#include <string>

extern int selectedRow;
extern int selectedCol;
extern const int numRows;
extern const int numCols;

void updateHighlight();
void handleKeyPress(char key, bool &running);
void handleButtonPress(int row, int col);

extern std::string currentInput;

#endif // INPUT_HANDLER_H
