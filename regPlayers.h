#ifndef REGPLAYERS_H
#define REGPLAYERS_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "C:/users/eric/Rouge-Arcade/Basics/clearScreen.h"

using namespace std;

void playerSelection();

class player {
    private:
    int scoreInSnake = 0;
    int scoreInTicTacToe = 0;
    int scoreInConnectFour;
    int scoreInHangman;
    int level;

    string name;
    

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

extern vector<player> registeredPlayers;



#endif