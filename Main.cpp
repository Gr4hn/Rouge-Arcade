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
#include "Basics/clearScreen.h"
#include "Basics/sleepForSeconds.h"
#include "Basics/printCentered.h"
#include "Basics/getConsolewidth.h"
#include "Basics/paddingSelection.h"
#include "Hangman/Hangman.h"
#include "Hangman/loadWordsFromFile.h"
#include "regPlayers.h"


using namespace std;

void displayAbout();
void displayOptions();
void mainMenu();
void playGame();

bool gameIsRunning = true;
bool selectionOfGame = true;
bool isPlayerSelected = false;

// Main function for the choice of game
void playGame() {
    string guessString;
    bool roundIsRunning = true;
    if (!isPlayerSelected) {
        playerSelection();
        isPlayerSelected = true;
    }
    do {
        clearScreen();
        cout << "Select which game you would like to play: " << endl;

        cout << "1. Snake" << endl;
        cout << "2. Tic Tac Toe" << endl;
        cout << "3. Connect Four" << endl;
        cout << "4. Hangman" << endl;
        cout << "5. Return to main menu" << endl << endl;
        cout << "6. Select player" << endl;

        cout << "Choice: ";
        int choiceOfGame;
        cin >> choiceOfGame;
        cout << endl;
        
        vector<string> wordsForHangman;
        switch (choiceOfGame) {
            case 1:
                clearScreen();
                cout << "Playing game 1" << endl;
                //Snake(); Goes here
                cin.ignore();
                cin.get();
                break;
            case 2:
                clearScreen();
                cout << "Playing game 2" << endl;
                //TicTacToe(); Goes here
                cin.ignore();
                cin.get();
                break;
            case 3:
                clearScreen();
                cout << "Playing game 3" << endl;
                //ConnectFour(); Goes here
                cin.ignore();
                cin.get();
                break;
            case 4:
                wordsForHangman = loadWordsFromFile("C:/users/eric/Rouge-Arcade/Hangman/wordsForHangman.txt");
                clearScreen();
                cout << "Playing game 4" << endl;
                sleepForSeconds(2);
                //Maybe add a function to display the rules of the game here?
                playHangman(wordsForHangman, guessString, roundIsRunning);
                break;
            case 5:
                // Return to main menu
                selectionOfGame = false;
                break;
            case 6:
                clearScreen();
                playerSelection();
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

// Displays the about screen
void displayAbout() {
    clearScreen();
    cout << "About the program" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "About the program go here" << endl;
    cin.ignore();
    cin.get();
}

// Displays the options screen
void displayOptions() {
    clearScreen();
    cout << "Options" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Options go here" << endl;
    cin.ignore();
    cin.get();
}

// Displays the main menu
void mainMenu () {
    
    do {
        clearScreen();
        printCentered("Main menu"); cout << endl;
        printCentered("--------------------------------"); cout << endl;
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

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                //Display players and score
                clearScreen();
                cout << endl;
                displayInfo();
                break;
            case 3:
                displayAbout();
                break;
            case 4:
                displayOptions();
                break;
            case 5:
                //Quits the program
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

// Start and end function for the program
int main() {
    bool isPlayerSelected = false;
    printCentered("*****************************************");
    printCentered("*                                       *");
    printCentered("*       Welcome to Rouge-Arcade!        *");
    printCentered("*                                       *");
    printCentered("*****************************************");
    sleepForSeconds(3);
    mainMenu();
    return 0;
}