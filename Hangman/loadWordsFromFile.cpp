#include "loadWordsFromFile.h"
    
vector<string> loadWordsFromFile(const string& filename) {
    vector<string> wordsForHangman;
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open the file " << filename << "\n";
        return wordsForHangman;
    }

    string word;
    while (getline(file, word)) {
        if (!word.empty()) {
            wordsForHangman.push_back(word);
        }
    }
    return wordsForHangman;
}