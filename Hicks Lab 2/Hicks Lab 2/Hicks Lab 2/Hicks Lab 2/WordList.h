#pragma once
#include <string>
using namespace std;

class WordOccurrence
{
public:
    WordOccurrence(const string& word = "", int num = 0);
    bool matchWord(const string&); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const;
    int getNum() const;

private:
    string word_;
    int num_;
};

class WordList
{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList();
    WordList(const WordList&);
    ~WordList();
    void addWord(const string&);
    void printList();
private:
    // a dynamically allocated array of WordOccurrences
    // may or may not be sorted
    WordOccurrence* wordArray_;

    int size_;
};