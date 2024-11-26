#include "regPlayers.h"
#include "basicsForPlayers.h"


list<Player> registeredPlayers;

void playerSelection () {
    string choiceOfPlayer;
    bool selectedPlayer = false;
    Player* currentPlayer = nullptr;
    list<Player>::iterator it;

    do {
        clearScreen();
        cout << "Do you have a registered player?" << endl << endl;
        cout << "Yes or No: ";
        cin >> choiceOfPlayer;
        cout << endl;
        transform(choiceOfPlayer.begin(), choiceOfPlayer.end(), choiceOfPlayer.begin(), ::tolower);
        if (choiceOfPlayer == "no") {
            cout << "Enter your name: ";
            string name;
            cin >> name; 
            registeredPlayers.push_back(Player(name));
            currentPlayer = &registeredPlayers.back();
            selectedPlayer = true;
            cout << endl << endl;
            cout << "Welcome, " << name << "!" << endl;
            cout << "You have been registered." << endl;
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
        }
        else if (choiceOfPlayer == "yes") {

            currentP();
            cout << "Enter your name player: ";
            string name;
            cin >> name;
            auto it = find_if(registeredPlayers.begin(), registeredPlayers.end(), [&name](const Player& p) {
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
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (selectedPlayer == false);
}

void displayInfo() {
    string playerName;
    do {
        clearScreen();
        cout << "Players and their levels: " << endl;
        currentP();
        cout << "Enter a name in order to see the scores." << endl;
        cout << "Or press enter to go back to the main menu " << endl;
        cout << "Enter a name: ";
        getline(cin, playerName);
        if (!playerName.empty()) {
            displayPlayerScore(playerName);
            cin.get();
        }
    } while (!playerName.empty());
    printCentered("Returning to main menu...");
    sleepForSeconds(2);
}
void displayPlayerScore(const string& playerName ) {
    bool playerFound = false;
    cout << endl << "Searching for player: " << playerName << endl;
    sleepForSeconds(2);
    for (const auto& player : registeredPlayers) {
        if (player.getName() == playerName) {
            player.displayScores();
            playerFound = true;
            break;
        }
    }
    if (!playerFound) {
        cout << "Player not found." << endl;
    }
    cout << endl << "Press enter to continue..." << endl;
}

Player::Player(string name) {
        this->name = name;
        this->level = 0;
        this->scoreInSnake = 0;
        this->scoreInTicTacToe = 0;
        this->scoreInConnectFour = 0;
        this->scoreInHangman = 0;
    }

    string Player::getName() const {
        return name;
    }

    string Player::setName(const string& name) {
        this->name = name;
        cout << "Name has been set to: " << name << endl;
        return name;
    }
    
    void Player::displayPlayerInfo() const {
        cout << "Name: " << this->name << endl;
        cout << "Level: " << this->level << endl;
    }
    void Player::displayScores() const {
        cout << "Scores:" << endl;
        cout << "Snake: " << scoreInSnake << endl;
        cout << "TicTacToe: " << scoreInTicTacToe << endl;
        cout << "ConnectFour: " << scoreInConnectFour << endl;
        cout << "Hangman: " << scoreInHangman << endl;
        cout << "Level: " << level << endl;
    }
