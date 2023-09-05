#include <string>
using namespace std;

class WordOccurrence
{
public:
    WordOccurrence(const string& word = "", int num = 0) {
        word_ = word;
        num_ = num;
    }

    bool matchWord(const string& word) {
        return word_ == word;
    }

    void increment() {
        num_++;
    }

    string getWord() const {
        return word_;
    }

    int getNum() const {
        return num_;
    }

private:
    string word_;
    int num_;
};

class WordList {
public:
    WordList(int initialSize = 50) // Constructor with initial size
        : size_(initialSize), wordArray_(new WordOccurrence[initialSize]) {
    }

    // Copy constructor
    WordList(const WordList& other)
        : size_(other.size_), wordArray_(new WordOccurrence[other.size_]) {
        // Copy each Word from the other WordList
        for (int i = 0; i < size_; ++i) {
            wordArray_[i] = other.wordArray_[i];
        }
    }

    ~WordList() {
        delete[] wordArray_;
    }

    void addWord(const string& word) {
        if (size_ >= maxSize_) {
            // Resize the array if it's full
            resizeArray();
        }

        bool wordExists = false;
        for (int i = 0; i < size_; i++) {
            if (wordArray_[i].matchWord(word)) {
                wordArray_[i].increment();
                wordExists = true;
                break;
            }
        }

        if (!wordExists) {
            wordArray_[size_] = WordOccurrence(word, 1);
            size_++;
        }
    }

    void bubbleSort() {
        for (int i = 0; i < size_ - 1; ++i) {
            for (int j = 0; j < size_ - i - 1; ++j) {
                if (wordArray_[j].getNum() < wordArray_[j + 1].getNum()) {
                    swap(wordArray_[j], wordArray_[j + 1]);
                }
            }
        }
    }

    void printList() {
        bubbleSort();
        for (int i = 0; i < size_; ++i) {
            if (wordArray_[i].getNum() > 0) {
                cout << wordArray_[i].getWord() << ": " << wordArray_[i].getNum() << endl;
            }
        }
    }

private:
    WordOccurrence* wordArray_;
    int size_;
    int maxSize_ = 50; // Maximum size of the array

    // Helper function to resize the array
    void resizeArray() {
        int newSize = maxSize_ * 2;
        WordOccurrence* newArray = new WordOccurrence[newSize];
        for (int i = 0; i < size_; ++i) {
            newArray[i] = wordArray_[i];
        }
        delete[] wordArray_;
        wordArray_ = newArray;
        maxSize_ = newSize;
    }
};