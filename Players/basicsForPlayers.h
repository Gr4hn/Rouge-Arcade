#ifndef BASICSFORPLAYERS_H
#define BASICSFORPLAYERS_H
#include <iostream>
#include <string>
#include <vector>
#include "regPlayers.h"

using namespace std;


void currentP() {
    cout << "Current registered players: " << endl;
    for (const auto& Player : registeredPlayers) {
        Player.displayPlayerInfo();
        cout << endl;
    }
}

void currentS() {
    cout << "Current registered players: " << endl;
    for (const auto& Player : registeredPlayers) {
        Player.displayScores();
        cout << endl;
    }
}

#endif