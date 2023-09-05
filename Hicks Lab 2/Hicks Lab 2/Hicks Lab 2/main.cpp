#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "WordList.h"
using namespace std;

vector<string> tokenizeText(const string& text) {
    vector<string> tokens;
    string word;
    for (char c : text) {
        if (isalnum(c)) {
            word += tolower(c);
        }
        else {
            if (!word.empty()) {
                tokens.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tokens.push_back(word);
    }
    return tokens;
}

int main() {
    WordList wordList;
    ifstream inputFile("file.txt");
    if (!inputFile) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }
    string line;
    while (getline(inputFile, line)) {
        vector<string> words = tokenizeText(line);
        for (const string& word : words) {
            wordList.addWord(word);
        }
    }
    wordList.printList();
    return 0;
}
