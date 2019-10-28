#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class WordDictionary {
    struct level {
        level() {
            wordEnd = false;
            next = nullptr;
        }
        void* next;
        bool wordEnd;

        bool isEmpty() {
            return next == nullptr;
        }
    };

    typedef unordered_map<char, level> slice;
    level dict;

    bool searchHelp(const level* current, const char* str) const {
        int charPos = 0;
        while (str[charPos]) {
            const char c = str[charPos];
            const slice* currentSlice = static_cast<const slice*>(current->next);

            if (c == '.') {
                // iterate through every letter in the current slice
                for (slice::const_iterator it = currentSlice->begin(); it != currentSlice->end(); ++it) {
                    if (searchHelp(static_cast<const level*>(&it->second), str + charPos + 1))
                        return true;
                }
                return false;
            } else {
                if (currentSlice->find(c) != currentSlice->end()) {
                    current = &currentSlice->at(c);
                } else
                    return false;
            }

            charPos++;
        }

        return current->wordEnd;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        dict.next = new slice();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        level* currentLevel = &dict;

        for (char c : word) {
            slice* currentSlice = static_cast<slice*>(currentLevel->next);

            if (currentSlice->find(c) != currentSlice->end())
                currentLevel = &currentSlice->at(c);
            else {
                (*currentSlice)[c].next = new slice();
                currentLevel = &(*currentSlice)[c];
            }
        }
        currentLevel->wordEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one
     * letter. */
    bool search(string word) {
        level* current = &dict;
        return searchHelp(current, word.c_str());
    }
};

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        WordDictionary obj;

        int wCount, qCount;

        cin >> wCount >> qCount;
        string str;

        for (int w = 0; w < wCount; w++) {
            cin >> str;
            obj.addWord(str);
        }

        for (int w = 0; w < qCount; w++) {
            cin >> str;
            cout << obj.search(str) << endl;
        }
    }
}