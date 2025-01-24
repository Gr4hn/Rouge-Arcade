#ifndef HANGMAN_H
#define HANGMAN_H
#include "clearScreen.h"
#include "sleepForSeconds.h"
#include "regPlayers.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <locale>
#include <fstream>


using namespace std;

void endRunningRound(bool& roundIsRunning);
void playHangman(vector<string>& wordsForHangman, string& guessString, bool& roundIsRunning, Player *currentPlayer);
string Randomizer(vector<string> list);


class Game
{
    private:
    string wordToGuess;
    string guessString;
    string guessedLetters;
    int maxAttempts;
    char mysteryLetter;

    public:
    vector<char> incorrectGuesses;
    bool hasGuessedString = false;
    Game(const string& word, int maxAttempts = 10) : wordToGuess(word), maxAttempts(maxAttempts) {
        guessedLetters = string(word.size(), '_');
        mysteryLetter = selectMysteryLetter();
    }

    string randomword; 

    void drawHangman() const {
        int error = incorrectGuesses.size();

        if (error == 0) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "" << endl;
            cout << endl;
        }
        if (error == 1) {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "   ______" << endl;
            cout << endl;
        }
        if (error == 2) {
            cout << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 3) {
            cout << "   ______" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 4) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 5) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |    O" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 6) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |    O" << endl;
            cout << "   |    |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 7) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |    O" << endl;
            cout << "   |   /|" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 8) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |    O" << endl;
            cout << "   |   /|\\" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 9) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |    O" << endl;
            cout << "   |   /|\\" << endl;
            cout << "   |   /" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
        if (error == 10) {
            cout << "   ______" << endl;
            cout << "   |    |" << endl;
            cout << "   |    O" << endl;
            cout << "   |   /|\\" << endl;
            cout << "   |   / \\" << endl;
            cout << "   |" << endl;
            cout << "   |______" << endl;
            cout << endl;
        }
    }

    void displayStatus() const {
        clearScreen();
        drawHangman();
        cout << "Ord: ";
        for (char c : guessedLetters) {
            cout << c << " ";
        }
        cout << endl << "Felgissningar: ";
        for (char ch : incorrectGuesses) {
            cout << ch << " ";
        }
        cout << endl << "Antal f\u00F6rs\u00F6k kvar: " << maxAttempts - incorrectGuesses.size() << endl;
        cout <<endl <<"För att avsluta spelet, tryck in 0.\n";
    }

    char selectMysteryLetter() {
        string alphabet = "abcdefghijklmnopqrstuvwxyzåäö";
        vector<char> possibleLetters;

        for (char c : alphabet) {
            if (wordToGuess.find(c) == string::npos) {
                possibleLetters.push_back(c);
            }
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, possibleLetters.size() - 1);
        return possibleLetters[dis(gen)];
    }

    bool guess(char letter, string input, Player *currentPlayer) {
        string lowerInput = input;
        transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
        letter = tolower(letter);

        if (lowerInput.length() == 1) {
            bool correct = false;
            if(isLetterGuessed(letter))
            {
                cout <<"Du har redan gissat på bokstaven " << letter <<" försök igen!" << endl;
                sleepForSeconds(2);
                return false;
            }

            //cout << "Mystisk bokstav: " << mysteryLetter << endl; // Debug
            if (letter == mysteryLetter) {
                cout << "Du träffade vår mystiska bokstav och är nu än mer närmare döden!\n";
                incorrectGuesses.push_back(letter);
                incorrectGuesses.push_back(letter); // Räknas som dubbla felgissningar
                return false;
            }

            for (size_t i = 0; i < wordToGuess.size(); ++i) {
                if (wordToGuess[i] == letter) {
                    guessedLetters[i] = letter;
                    correct = true;
                }
            }

            if (!correct) {
                incorrectGuesses.push_back(letter);
            }

            return correct;
        } else {
            hasGuessedString = true;
            if (lowerInput == wordToGuess) {
                //guessedLetters = wordToGuess;
                cout << "Grattis! Du vann! " << "Du gissade r\u00E4tt ord: " << wordToGuess << endl;
                sleepForSeconds(1);
                currentPlayer->setScoreInHangman(maxAttempts - incorrectGuesses.size());
                currentPlayer->setLevel(1);
                cout << "Tryck på valfri tangent för att fortsätta." << endl;
                cin.ignore();
                cin.get();
                return true;
            }
            else {
                cout << "Fel gissning! Du har förlorat spelet." << endl;
                sleepForSeconds(3);
                return false;
            }
        }
    }


    bool endOfAttempts() const
    {
        return incorrectGuesses.size() >= maxAttempts || guessedLetters == wordToGuess || guessString == wordToGuess || hasGuessedString == true;
    }

    bool win() const
    {
        return guessedLetters == wordToGuess;
    }

    bool isLetterGuessed(char letter) {
        // Kontrollera om bokstaven finns i guessedLetters eller incorrectGuesses
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            return true;
        }
        if (find(incorrectGuesses.begin(), incorrectGuesses.end(), letter) != incorrectGuesses.end()) {
            return true;
        }
        return false;
    }
};



#endif