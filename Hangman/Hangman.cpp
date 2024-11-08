#include "Hangman.h"


void endRunningRound(bool& roundIsRunning) {
    roundIsRunning = false;
}

void playHangman(vector<string>& wordsForHangman, string& guessString, bool& roundIsRunning){

    string randomWord = Randomizer(wordsForHangman);
    Game game(randomWord);

    cout << "Random word: " << randomWord << endl; // Debug
    //cout << "Random letter: " << (game.mysteryLetter()) << endl; // Debug
    sleepForSeconds(1);

    int attempts = 0;
    while(!game.endOfAttempts()) {
        game.displayStatus();
            cout << endl <<"Gissa en bokstav eller ord: ";
        cin >> guessString;
            if(guessString == "0") {
                endRunningRound(roundIsRunning);
                break;
        }
        if(!game.guess(guessString[0], guessString) || game.hasGuessedString) { // Behövs guessString här egentligen? Det är ju bara en bokstav som ska gissas och om det är en string ska vi hoppa direkt till förkorat eller vunnit?
            if (!game.hasGuessedString) {
                cout << "Fel gissning!" << endl;
                sleepForSeconds(2);
            }
        } else {
            if (!game.hasGuessedString) {
                cout << "R\u00E4tt gissning!" << endl;
                sleepForSeconds(2);
            }
        }

        if(game.win()) { // Den här körs när man har gissat rätt bokstäver.
            game.win();
            int attempts = game.incorrectGuesses.size();
            cout << "Grattis! Du vann! " << "Du gissade r\u00E4tt ord: " << randomWord << endl;
            cout << "Antal felgissningar: " <<  attempts << endl;
            cout << endl;
            cout << "Tryck p\u00E5 valfri tangent f\u00F6r att forts\u00E4tta" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }

    if(!game.win() && !game.hasGuessedString) { // Den här körs när man har gissat på hela ordet och får korrekt, vilket den inte ska
        cout << "Spelet \u00E4r \u00F6ver! Ordet var: " << randomWord << endl
        << "Tryck p\u00E5 valfri tangent f\u00F6r att forts\u00E4tta" << endl;
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