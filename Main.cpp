#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
#include <unistd.h>

using namespace std;

void displayRules();
void displayOptions();
void mainMenu();
void sleepForSeconds(int seconds);
void clearScreen();

bool gameIsRunning = true;

class Game {
    public:

    void playGame() {
        cout << "Playing game..." << endl;
        cin.ignore();
        cin.get();
    }
};

void mainMenu () {
    Game game;
    
    do {
        clearScreen();
        cout << "Main menu" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Play" << endl;
        cout << "2. Rules" << endl;
        cout << "3. Options" << endl;
        cout << "4. Quit" << endl;
        cout << endl;
        cout << "Choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                game.playGame();
                break;
            case 2:
                displayRules();
                break;
            case 3:
                displayOptions();
                break;
            case 4:
                gameIsRunning = false;
                break;
            default:
            cout << "Invalid choice. Please try again." << endl;
            sleepForSeconds(2);
        }
    } while (gameIsRunning);
    
    clearScreen();
    cout << "Thanks for playing!" << endl;
    cout << "Press enter to exit..." << endl;
    cin.ignore();
    cin.get();
}

void sleepForSeconds(int seconds) {
    Sleep(seconds * 1000);
}

void clearScreen() {
    system("cls");
}



void displayRules() {
    cout << "Rules" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Rules go here" << endl;
    cin.ignore();
    cin.get();
}
void displayOptions() {
    cout << "Options" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Options go here" << endl;
    cin.ignore();
    cin.get();
}

int main() {

    cout << "Welcome to X" << endl;
    sleepForSeconds(3);
    mainMenu();
    return 0;
}

