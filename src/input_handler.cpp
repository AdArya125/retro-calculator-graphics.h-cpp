#include "input_handler.h"
#include "graphics_ui.h"

// Initial selection state
int selectedRow = 0;
int selectedCol = 0;
const int numRows = 6;
const int numCols = 5;

void updateHighlight()
{
    clearUI();
    drawButtons(true); // Pass false if you want to hide trig buttons
    highlightButton(selectedRow, selectedCol);
}

void handleKeyPress(char key, bool &running)
{
    switch (key)
    {
    case 72: // Up arrow
        selectedRow = (selectedRow - 1 + numRows) % numRows;
        break;
    case 80: // Down arrow
        selectedRow = (selectedRow + 1) % numRows;
        break;
    case 75: // Left arrow
        selectedCol = (selectedCol - 1 + numCols) % numCols;
        break;
    case 77: // Right arrow
        selectedCol = (selectedCol + 1) % numCols;
        break;
    case 13: // Enter
        handleButtonPress(selectedRow, selectedCol);
        break;
    case 27: // Esc
        running = false;
        break;
    default:
        break;
    }

    updateHighlight();
}

void handleButtonPress(int row, int col)
{
    // Stub: You can connect this to actual calculator logic
    cout << "Pressed button at Row: " << row << ", Col: " << col << endl;
}
