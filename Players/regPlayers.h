#ifndef REGPLAYERS_H
#define REGPLAYERS_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>
#include "clearScreen.h"
#include "sleepForSeconds.h"
#include "printCentered.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;


class Player {
    private:
    int scoreInSnake;
    int scoreInTicTacToe;
    int scoreInConnectFour;
    int scoreInHangman;
    int level;
    string name;
    

    public:
    Player(string& name);
    Player();
    Player(const json& playerJson);
    

    string getName() ; 
    string setName(string& name);
    int getLevel();
    int setLevel(int level);
    int getScoreInSnake();
    int setScoreInSnake(int scoreInSnake);
    int getScoreInTicTacToe();
    int setScoreInTicTacToe(int scoreInTicTacToe);
    int getScoreInConnectFour();
    int setScoreInConnectFour(int scoreInConnectFour);
    int getScoreInHangman();
    int setScoreInHangman(int scoreInHangman);

    
    void displayPlayerInfo() ;

    void displayScores() ;

    string toString() ;

    //json loadPlayers(const string& DataBase);
};

void playerSelection(list<Player> &registeredPlayers, string &ptrDataBase);
void displayInfo(list<Player> &registeredPlayers);
void displayScores();
void displayPlayerScore(string &playerName, list<Player> &registeredPlayers);
json loadPlayers(const string &ptrDataBase, list<Player> &registeredPlayers);
json savePlayers(string &ptrDataBase, list<Player> &registeredPlayers);

//extern list<Player> registeredPlayers;
extern list<Player>::iterator it;



#endif