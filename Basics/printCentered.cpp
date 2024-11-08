#include "printCentered.h"

//Centeres text in the middle of the console window.
void printCentered(const string& text) {
    int consoleWidth = getConsoleWidth();
    int padding = (consoleWidth - text.length()) / 2;
    if (padding > 0) {
        cout << string(padding, ' ') << text << endl;
    } else {
        cout << text << endl;
    }
}