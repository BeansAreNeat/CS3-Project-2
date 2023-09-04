#include <iostream>
#include "WordList.h"

// Word Occurrence Class implementation
WordOccurrence::WordOccurrence(const string& word = "", int num = 0) {
	word_ = word;
	num_ = num;
}

bool WordOccurrence::matchWord(const string& word) {
	return word_ == word;
}

void WordOccurrence::increment() {
	num_++;
}

string WordOccurrence::getWord() const {
	return word_;
}

int WordOccurrence::getNum() const{
	return num_;
}


// Word List class implementation
WordList::WordList() {
	size_ = 0;
	wordArray_ = new WordOccurrence[10];
}

// Copy constructor

WordList::~WordList() {
	delete[] wordArray_;
}

void WordList::addWord(const string& word) {
	for (int i = 0; i < size_; i++) {
		if (wordArray_[i].matchWord(word)) {
			wordArray_->increment();
		}
	}
}

void WordList::printList() {
	// Bubble Sort
	for (int i = 0; i < size_ - 1; ++i) {
		for (int j = 0; j < size_ - i - 1; ++j) {
			if (wordArray_[j].getNum() < wordArray_[j + 1].getNum()) {
				swap(wordArray_[j], wordArray_[j + 1]);
			}
		}
	}

	// Print the sorted list
	for (int i = 0; i < size_; ++i) {
		cout << wordArray_[i].getWord() << ": " << wordArray_[i].getNum() << endl;
	}
}