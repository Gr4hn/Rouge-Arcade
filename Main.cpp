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
#include <iomanip>
#include "C:/users/eric/Rouge-Arcade/Basics/clearScreen.h"
#include "C:/users/eric/Rouge-Arcade/Basics/sleepForSeconds.h"
#include "C:/users/eric/Rouge-Arcade/Hangman/Hangman.h"
#include "C:/users/eric/Rouge-Arcade/Hangman/loadWordsFromFile.h"
#include "regPlayers.h"

using namespace std;

void displayAbout();
void displayOptions();
void mainMenu();
void playGame();

bool gameIsRunning = true;
bool selectionOfGame = true;

void playGame() {
    string guessString;
    bool roundIsRunning = true;
    playerSelection();
    do {
        vector<string>wordsForHangman = loadWordsFromFile("C:/users/eric/Rouge-Arcade/Hangman/wordsForHangman.txt");
        clearScreen();
        cout << "Select which game you would like to play: " << endl;

        cout << "1. Snake" << endl;
        cout << "2. Tic Tac Toe" << endl;
        cout << "3. Connect Four" << endl;
        cout << "4. Hangman" << endl;
        cout << "5. Return to main menu" << endl << endl;

        cout << "Choice: ";
        int choiceOfGame;
        cin >> choiceOfGame;
        cout << endl;
        switch (choiceOfGame) {
            case 1:
                clearScreen();
                cout << "Playing game 1" << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                clearScreen();
                cout << "Playing game 2" << endl;
                cin.ignore();
                cin.get();
                break;
            case 3:
                clearScreen();
                cout << "Playing game 3" << endl;
                cin.ignore();
                cin.get();
                break;
            case 4:
                clearScreen();
                cout << "Playing game 4" << endl;
                sleepForSeconds(2);
                playHangman(wordsForHangman, guessString, roundIsRunning);
                break;
            case 5:
                selectionOfGame = false;
                break;
            default:
            cout << "Invalid choice. Please try again." << endl;
            sleepForSeconds(2);
            break;
        }
    } while (selectionOfGame);
    
    cout << endl << endl << "Returning to main menu..." << endl;
    sleepForSeconds(2);
}


void displayAbout() {
    clearScreen();
    cout << "About the program" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "About the program go here" << endl;
    cin.ignore();
    cin.get();
}

void displayOptions() {
    clearScreen();
    cout << "Options" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Options go here" << endl;
    cin.ignore();
    cin.get();
}

void mainMenu () {
    do {
        clearScreen();
        cout << "Main menu" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Play" << endl;
        cout << "2. Players and Score" << endl;
        cout << "3. About the program" << endl;
        cout << "4. Options" << endl;
        cout << "5. Quit" << endl;
        cout << endl;
        cout << "Choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayAbout();
                break;
            case 3:
                displayOptions();
                break;
            case 4:
                
                break;
            case 5:
                gameIsRunning = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                sleepForSeconds(2);
                break;
        }
    } while (gameIsRunning);
    
    clearScreen();
    cout << "Thanks for playing!" << endl << endl;
    cout << "Press enter to exit..." << endl;
    cin.ignore();
    cin.get();
}

int main() {
    cout << "Welcome to Rouge-Arcade" << endl;
    sleepForSeconds(3);
    mainMenu();
    return 0;
}