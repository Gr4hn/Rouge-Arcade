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
#include "clearScreen.h"
#include "sleepForSeconds.h"
#include "Hangman.h"
#include "loadWordsFromFile.h"

using namespace std;

void displayAbout();
void displayOptions();
void mainMenu();
void playgame();

bool gameIsRunning = true;
bool selectionOfGame = true;

class player {
    private:

    string name;
    int scoreInSnake = 0;
    int scoreInTicTacToe = 0;
    int scoreInConnectFour;
    int scoreInHangman;
    int level;

    public:
    player(string name, int score, int level) {
        this->name = name;
        this->level = level;
    }

    string getName() const {
        return name;
    }
    void registerPlayer(string gameType, int score) {
        if (gameType == "Snake") {
            scoreInSnake += score;
        } else if (gameType == "TicTacToe") {
            scoreInTicTacToe += score;
        } else if (gameType == "ConnectFour") {
            scoreInConnectFour += score;
        } else if (gameType == "Hangman") {
            scoreInHangman += score;
        }
        // Update level based on some criteria, for example:
        level = (scoreInSnake + scoreInTicTacToe + scoreInConnectFour + scoreInHangman) / 100;
    }
    void displayPlayerInfo() {
        cout << "Name: " << name << endl;
        cout << "Score: " << scoreInSnake << endl;
        cout << "Score: " << scoreInTicTacToe << endl;
        cout << "Score: " << scoreInConnectFour << endl;
        cout << "Score: " << scoreInHangman << endl;
        cout << "Level: " << level << endl;
    }
    void displayScores() {
        cout << "Scores:" << endl;
        cout << "Snake: " << scoreInSnake << endl;
        cout << "TicTacToe: " << scoreInTicTacToe << endl;
        cout << "ConnectFour: " << scoreInConnectFour << endl;
        cout << "Hangman: " << scoreInHangman << endl;
        cout << "Level: " << level << endl;
    }
};

vector<player> registeredPlayers;


void playerSelection () {
     string choiceOfPlayer;
    bool selectedPlayer = false;
    player* currentPlayer = nullptr;
    do {
        clearScreen();
        cout << "Have you played before?" << endl;
        cout << "Yes or No: ";
        cin >> choiceOfPlayer;
        transform(choiceOfPlayer.begin(), choiceOfPlayer.end(), choiceOfPlayer.begin(), ::tolower);
        if (choiceOfPlayer == "no") {
            cout << "Enter your name: ";
            string name;
            cin >> name;
            registeredPlayers.push_back(player(name, 1, 0));
            currentPlayer = &registeredPlayers.back();
            selectedPlayer = true;
            cout << "Welcome, " << name << "!" << endl;
            cout << "You have been registered." << endl;
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (choiceOfPlayer == "yes") {
            cout << "Current registered players: " << endl;
            for (int i = 0; i < registeredPlayers.size(); i++) {
                cout << registeredPlayers[i].getName() << endl;
            }
            cout << "Enter your name player: ";
            string name;
            cin >> name;
            auto it = find_if(registeredPlayers.begin(), registeredPlayers.end(), [&name](const player& p) {
                return p.getName() == name;
            });
            if (it != registeredPlayers.end()) {
                currentPlayer = &(*it);
                cout << "Welcome back, " << name << "!" << endl;
                cout << "Press enter to continue..." << endl;
                selectedPlayer = true;
            }
            else {
                cout << "Player not found. Please try again." << endl;
            }
            cin.ignore();
            cin.get();
            selectedPlayer = true;
            
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (selectedPlayer == false);
}

void playGame() {
    playerSelection();
    do {
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
                cin.ignore();
                cin.get();
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

    cout << "Welcome to E-Arcade" << endl;
    vector<string>wordsForHangman = loadWordsFromFile("wordsForHangman.txt");
    sleepForSeconds(3);
    mainMenu();
    return 0;
}