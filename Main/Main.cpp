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
#include <thread>
#include <chrono>
#include <mutex>
#include "clearScreen.h"
#include "sleepForSeconds.h"
#include "printCentered.h"
#include "getConsolewidth.h"
#include "paddingSelection.h"
#include "Hangman.h"
#include "loadWordsFromFile.h"
#include "regPlayers.h"
#include "C:\Users\Eric\OneDrive\Utbildning\Chas-Academy\SUVX24\Myown\Nlohmann-JSON/json.hpp"


using namespace std;

void displayAbout();
void displayOptions();
void mainMenu(list<Player> &registeredPlayers, string &ptrDataBase);
void playGame(list<Player> &registeredPlayers, string &ptrDataBase);

bool gameIsRunning = true;
bool selectionOfGame = true;
bool isPlayerSelected = false;

// Main function for the choice of game
void playGame(list<Player> &registeredPlayers, string &ptrDataBase) {
    string guessString;
    bool roundIsRunning = true;
    if (!isPlayerSelected) {
        playerSelection(registeredPlayers, ptrDataBase);
        isPlayerSelected = true;
    }
    do {
        vector<string> wordsForHangman;


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
        
        switch (choiceOfGame) {
            case 1:
                //Snake(); Goes here
                clearScreen();
                cout << "Playing game 1" << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                //TicTacToe(); Goes here
                clearScreen();
                cout << "Playing game 2" << endl;
                cin.ignore();
                cin.get();
                break;
            case 3:
                //ConnectFour(); Goes here
                clearScreen();
                cout << "Playing game 3" << endl;
                cin.ignore();
                cin.get();
                break;
            case 4:
                //Plays the game Hangman
                wordsForHangman = loadWordsFromFile("Hangman/wordsForHangman.txt");
                clearScreen();
                cout << "Playing game 4" << endl;
                sleepForSeconds(2);
                //Maybe add a function to display the rules of the game here?
                playHangman(wordsForHangman, guessString, roundIsRunning);
                break;
            case 5:
                //The player can reselect their player
                clearScreen();
                playerSelection(registeredPlayers, ptrDataBase);
                break;
            case 6:
                //Return to main menu
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

// Displays the about screen
void displayAbout() {
    clearScreen();
    printCentered("About the program"); cout << endl;
    printCentered("--------------------------------"); cout << endl;
    cout << endl;
    cout << "About the program go here" << endl;
    cin.get();
}

// Displays the options screen
void displayOptions() {
    clearScreen();
    printCentered("Options"); cout << endl;
    printCentered("--------------------------------"); cout << endl;
    cout << endl;
    cout << "Options go here" << endl;
    cin.get();
}

// Displays the main menu
void mainMenu (list<Player> &registeredPlayers, string &ptrDataBase) {
    
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
        cout << "5. Select player" << endl;
        cout << "6. Quit" << endl;
        cout << endl << endl;
        cout << "Choice: ";
        int choice;
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                playGame(registeredPlayers, ptrDataBase);
                break;
            case 2:
                //Display players and score
                clearScreen();
                cout << endl;
                displayInfo(registeredPlayers);
                break;
            case 3:
                //Display about screen
                displayAbout();
                break;
            case 4:
                //Display options screen
                displayOptions();
                break;
            case 5:
                //Select player from list or add new player
                isPlayerSelected = false;
                playerSelection(registeredPlayers, ptrDataBase);
                isPlayerSelected = true;
                break;
            case 6:
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
    list<Player> registeredPlayers;
    string DataBase = "Players/players.json";
    string *ptrDataBase = &DataBase;
    loadPlayers(*ptrDataBase, registeredPlayers);
    printCentered("*****************************************");
    printCentered("*                                       *");
    printCentered("*       Welcome to Rouge-Arcade!        *");
    printCentered("*                                       *");
    printCentered("*****************************************");
    if (registeredPlayers.empty()) {
        cout << "No players found. Please add a player." << endl;
        cin.get();
        playerSelection(registeredPlayers, *ptrDataBase);
    }
    else {
        cout << "Players found." << endl;
        cin.get();
    }
    loadPlayers(*ptrDataBase, registeredPlayers);
    cin.get();
    //sleepForSeconds(3);
    mainMenu(registeredPlayers, *ptrDataBase);
    savePlayers(*ptrDataBase, registeredPlayers);
    return 0;
}