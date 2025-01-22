#include "regPlayers.h"
#include "basicsForPlayers.h"
#include "json.hpp"




list<Player>::iterator it;


void playerSelection (list<Player> &registeredPlayers, string &ptrDataBase) {
    int choice;
    string choiceOfPlayer;
    bool selectedPlayer = false;
    Player *currentPlayer = nullptr;

    //There is an error in this part of the code, it is not working properly.
    do {
        clearScreen();
        cout << "Currently selected player: " << endl;
        if (currentPlayer == nullptr) {
            cout << "Player not found." << endl;
            sleepForSeconds(2);
        }
        else {
            cout << currentPlayer->getName() << endl;
        }

        cout << endl << "Press 1 to select a player." << endl << "Press 2 to add a new player." 
        << endl << "Press 3 to go back to the main menu." << endl
        << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                clearScreen();
                for (auto& player : registeredPlayers) {
                    cout << player.getName() << endl;
                }
                cout << endl << "Enter the name of the player you want to select: ";
                cin >> choiceOfPlayer;
                for (auto& player : registeredPlayers) {
                    if (player.getName() == choiceOfPlayer) {
                        currentPlayer = &player;
                        cout << "Welcome back, " << currentPlayer->getName() << "!" << endl;
                        sleepForSeconds(2);
                        selectedPlayer = true;
                        break;
                    }
                    else {
                        cout << "Player not found." << endl;
                        sleepForSeconds(2);
                    }
                }
/*                 if (currentPlayer == nullptr) {
                    cout << "Player not found." << endl;
                    sleepForSeconds(2);
                } */
                break;

            case 2:
                clearScreen();
                cout << "Enter the name of the new player: ";
                cin >> choiceOfPlayer;
                registeredPlayers.push_back(Player(choiceOfPlayer));
                currentPlayer = &registeredPlayers.back();
                savePlayers(ptrDataBase, registeredPlayers);
                cout << "Welcome, " << currentPlayer->getName() << "!" << endl
                << "You have been added to the list of registered players." << endl;
                selectedPlayer = true;
                sleepForSeconds(2);
                break;
            case 3:
                cout << "Returning to main menu..." << endl;
                sleepForSeconds(2);
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                sleepForSeconds(2);
                break;
        }
    } while (selectedPlayer == false);
}


void displayInfo(list<Player> &registeredPlayers) {
    string playerName;
    do {
        clearScreen();
        cout << "Players and their levels: " << endl;
        currentP(registeredPlayers);
        cout << "Enter a name in order to see the scores." << endl;
        cout << "Or press enter to go back to the main menu " << endl;
        cout << "Enter a name: ";
        getline(cin, playerName);
        if (!playerName.empty()) {
            displayPlayerScore(playerName, registeredPlayers);
            cin.get();
        }
    } while (!playerName.empty());
    printCentered("Returning to main menu...");
    sleepForSeconds(2);
}


void displayPlayerScore(string& playerName, list<Player> &registeredPlayers) {
    bool playerFound = false;
    cout << endl << "Searching for player: " << playerName << endl;
    sleepForSeconds(2);
    for (auto& player : registeredPlayers) {
        if (player.getName() == playerName) {
            playerFound = true;
            player.displayScores();
            break;
        }
    }
    if (playerFound == false) {
        cout << "Player not found." << endl;
    }
    cout << endl << "Press enter to continue..." << endl;
}

Player::Player(string& name) {
    this->name = name;
    this->level = 0;
    this->scoreInSnake = 0;
    this->scoreInTicTacToe = 0;
    this->scoreInConnectFour = 0;
    this->scoreInHangman = 0;
}

Player::Player() {
    list<Player> registeredPlayers;
}

Player::Player(const json& playerJson) {
    // Initialize Player object from JSON data
    // Example:
    name = playerJson["name"];
    level = playerJson["level"];
    scoreInSnake = playerJson["scoreInSnake"];
    scoreInTicTacToe = playerJson["scoreInTicTacToe"];
    scoreInConnectFour = playerJson["scoreInConnectFour"];
    scoreInHangman = playerJson["scoreInHangman"];
}


string Player::getName()  {
    return name;
}

string Player::setName(string& name) {
    this->name = name;
    cout << "Name has been set to: " << name << endl;
    return name;
}

int Player::getLevel()  {
    return level;
}

int Player::setLevel(int level) {
    this->level = level;
    cout << "Level has been set to: " << level << endl;
    return level;
}

int Player::getScoreInSnake()  {
    return scoreInSnake;
}

int Player::setScoreInSnake(int scoreInSnake) {
    this->scoreInSnake = scoreInSnake;
    cout << "Score in Snake has been set to: " << scoreInSnake << endl;
    return scoreInSnake;
}

int Player::getScoreInTicTacToe()  {
    return scoreInTicTacToe;
}

int Player::setScoreInTicTacToe(int scoreInTicTacToe) {
    this->scoreInTicTacToe = scoreInTicTacToe;
    cout << "Score in Tic Tac Toe has been set to: " << scoreInTicTacToe << endl;
    return scoreInTicTacToe;
}

int Player::getScoreInConnectFour()  {
    return scoreInConnectFour;
}

int Player::setScoreInConnectFour(int scoreInConnectFour) {
    this->scoreInConnectFour = scoreInConnectFour;
    cout << "Score in Connect Four has been set to: " << scoreInConnectFour << endl;
    return scoreInConnectFour;
}

int Player::getScoreInHangman()  {
    return scoreInHangman;
}

int Player::setScoreInHangman(int scoreInHangman) {
    this->scoreInHangman = scoreInHangman;
    cout << "Score in Hangman has been set to: " << scoreInHangman << endl;
    return scoreInHangman;
}
    
void Player::displayPlayerInfo()  {
    cout << "Name: " << this->name << endl;
    cout << "Level: " << this->level << endl;
}

void Player::displayScores()  {
    cout << "Scores:" << endl;
    cout << "Snake: " << this->scoreInSnake << endl;
    cout << "TicTacToe: " << this->scoreInTicTacToe << endl;
    cout << "ConnectFour: " << this->scoreInConnectFour << endl;
    cout << "Hangman: " << this->scoreInHangman << endl;
    cout << "Level: " << this->level << endl;
}

string Player::toString()  {
    
    return "Player: " + name + " Level: " + to_string(level) + " Score in Snake: " + to_string(scoreInSnake) + " Score in Tic Tac Toe: " + to_string(scoreInTicTacToe) + " Score in Connect Four: " + to_string(scoreInConnectFour) + " Score in Hangman: " + to_string(scoreInHangman);

}

  
    
json loadPlayers (const string &ptrDataBase, list<Player> &registeredPlayers) {
    try {
        cout << "Attempting to open file: " << ptrDataBase << endl;

        ifstream file(ptrDataBase);
        if (file.is_open()) {
            if (file.peek() == ifstream::traits_type::eof()) {
                cout << "The file is empty. No players loaded." << endl;
                return json();
            } 
            json jsonFile;
            file >> jsonFile;
            for (const auto& player : jsonFile) {
                registeredPlayers.push_back(Player(player));
            }
            file.close();
            return jsonFile;
        }
        else {
            throw runtime_error("The file wasn't opened..." + ptrDataBase); 
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl << endl;
        return json(); // Return an empty JSON object on error
    }
}

json savePlayers (string &ptrDataBase, list<Player> &registeredPlayers) {
    
    try {
        ofstream file(ptrDataBase);
        if (file.is_open()) {


            json jsonFile;
            for (auto& player : registeredPlayers) {

            json playerJson;
            playerJson["name"] = player.getName();
            playerJson["level"] = player.getLevel();
            playerJson["scoreInSnake"] = player.getScoreInSnake();
            playerJson["scoreInTicTacToe"] = player.getScoreInTicTacToe();
            playerJson["scoreInConnectFour"] = player.getScoreInConnectFour();
            playerJson["scoreInHangman"] = player.getScoreInHangman();
            jsonFile.push_back(playerJson);
        }

        file << jsonFile.dump(4);
        file.close();
        return jsonFile;

        } 
        else {
            throw runtime_error("The file wasn't opened...");
        }
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
        return json(); // Return an empty JSON object on error
    }
}

void peakPlayers (ifstream &file) {
    if (file.peek() == ifstream::traits_type::eof()) {
        cout << "The file is empty. No players loaded." << endl;
    } 
}
    