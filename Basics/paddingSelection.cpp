#include "paddingSelection.h"


//Parameters: Text to be printed, left padding, right padding, top padding, bottom padding.
void printCenteredWithPadding(const string& text, int leftPadding, int rightPadding, int topPadding, int bottomPadding) {
    int consoleWidth = getConsoleWidth();
    int totalLength = text.length() + leftPadding + rightPadding;
    int leftMargin = (consoleWidth - totalLength) / 2;

    // Print top padding
    for (int i = 0; i < topPadding; ++i) {
        cout << endl;
    }

    // Print the text with left and right padding
    if (leftMargin > 0) {
        cout << string(leftMargin, ' ') << string(leftPadding, ' ') << text << string(rightPadding, ' ') << endl;
    } else {
        cout << string(leftPadding, ' ') << text << string(rightPadding, ' ') << endl;
    }

    // Print bottom padding
    for (int i = 0; i < bottomPadding; ++i) {
        cout << endl;
    }
}