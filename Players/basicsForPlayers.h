#ifndef BASICSFORPLAYERS_H
#define BASICSFORPLAYERS_H
#include <iostream>
#include <string>
#include <vector>
#include "regPlayers.h"

using namespace std;


void currentP(list<Player> &registeredPlayers) {
    cout << "Current registered players: " << endl;
    for (auto& Player : registeredPlayers) {
        Player.displayPlayerInfo();
        cout << endl;
    }
}

void currentS(list<Player> &registeredPlayers) {
    cout << "Current registered players: " << endl;
    for (auto& Player : registeredPlayers) {
        Player.displayScores();
        cout << endl;
    }
}

#endif