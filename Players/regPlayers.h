#ifndef REGPLAYERS_H
#define REGPLAYERS_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include "clearScreen.h"
#include "sleepForSeconds.h"
#include "printCentered.h"

using namespace std;

void playerSelection();
void displayInfo();
void displayScores();
void displayPlayerScore(const string& playerName );

class Player {
    private:
    int scoreInSnake;
    int scoreInTicTacToe;
    int scoreInConnectFour;
    int scoreInHangman;
    int level;
    string name;
    

    public:
    Player(const string name);
    string getName() const; 
    string setName(const string& name);
    
    void displayPlayerInfo() const;

    void displayScores() const;
};

extern list<Player> registeredPlayers;



#endif