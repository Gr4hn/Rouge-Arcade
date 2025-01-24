#include "Hangman.h"


void endRunningRound(bool& roundIsRunning) {
    roundIsRunning = false;
}

void playHangman(vector<string>& wordsForHangman, string& guessString, bool& roundIsRunning, Player *currentPlayer) {

    string randomWord = Randomizer(wordsForHangman);
    Game game(randomWord);

    cout << "Random word: " << randomWord << endl; // Debug
    //cout << "Random letter: " << (game.mysteryLetter()) << endl; // Debug
    sleepForSeconds(1);

    int attempts = 0;
    while(!game.endOfAttempts()) {
        game.displayStatus();
            cout << endl <<"Guess a word or a letter: ";
        cin >> guessString;
            if(guessString == "0") {
                endRunningRound(roundIsRunning);
                break;
        }
        if(!game.guess(guessString[0], guessString, currentPlayer) || game.hasGuessedString) { // Behövs guessString här egentligen? Det är ju bara en bokstav som ska gissas och om det är en string ska vi hoppa direkt till förkorat eller vunnit?
            if (!game.hasGuessedString) {
                cout << "Wrong guess!" << endl;
                sleepForSeconds(2);
            }
        } else {
            if (!game.hasGuessedString) {
                cout << "Correct guess!" << endl;
                sleepForSeconds(2);
            }
        }

        if(game.win()) { // Den här körs när man har gissat rätt bokstäver.
            game.win();
            int attempts = game.incorrectGuesses.size();
            currentPlayer->setScoreInHangman(attempts);
            currentPlayer->setLevel(1);
            cout << "Congratulations! You won! " <<  "You guessed: " << randomWord << endl;
            cout << "The number of wrong guesses: " <<  attempts << endl;
            cout << endl;
            cout << "Enter a key of your choice to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }

    if(!game.win() && !game.hasGuessedString) { // Den här körs när man har gissat på hela ordet och får korrekt, vilket den inte ska
        cout << "Game over! The word was: " << randomWord << endl
        << "Enter a key of your choice to continue..." << endl;
        cin.ignore();
        cin.get();
    }
}

string Randomizer(vector<string> list) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, list.size() - 1);
    int index = dis(gen);
    return list.at(index);
}