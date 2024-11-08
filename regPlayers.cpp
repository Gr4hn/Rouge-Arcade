#include "regPlayers.h"


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