#include <assert.h>
#include <utils.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Trie {

    struct level;

    typedef unordered_map<char, level*> Slice;

    struct level {
        level() {
            wordEnd = false;
        }

        bool isEmpty() const {
            return slice.size() == 0;
        }

        Slice slice;
        bool wordEnd;
    };

    level root;

public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        level* current = &root;
        
        for (char c : word) {
            Slice* currentSlice = &current->slice;
            if (currentSlice->find(c) != currentSlice->end()) {
                current = currentSlice->find(c)->second;
            } else {
                level* tmp = new level();
                (*currentSlice)[c] = tmp;
                current = tmp;
            }
        }
        current->wordEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        level* current = &root;

        for (char c : word) {
            Slice* currentSlice = &current->slice;

            if (currentSlice->find(c) == currentSlice->end())
                return false;
            current = (*currentSlice)[c];
        }
        
        return current->wordEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        level* current = &root;

        for (char c : prefix) {
            Slice* currentSlice = &current->slice;

            if (currentSlice->find(c) == currentSlice->end())
                return false;
            current = (*currentSlice)[c];
        }
        return true;
    }
};

int main() {
#ifdef LOCAL_TEST
    freopen("input.txt", "rt", stdin);
#endif

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Trie obj;

        int commands;

        cin >> commands;
        string str;

        for (int c = 0; c < commands; c++) {
            char command;
            cin >> command;
            cin >> str;
            switch (command) {
                case 'i':
                    obj.insert(str);
                    break;
                case 's':
                    cout << obj.search(str) << endl;
                    break;
                case 'w':
                    cout << obj.startsWith(str) << endl;
                    break;
            }
        }
    }
}