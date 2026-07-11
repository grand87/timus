/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <string>
#include <string_view>
#include <iostream>
#include <vector>

using namespace std;

//#define ONLINE_JUDGE

int asciiToIndex(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return c - '0';
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return c - 'a' + 10; 
    }
}

struct TrieNode {
    static const int kMaxNodes = 10 + 26;
    TrieNode* children[kMaxNodes] = {};
    bool wordEndsHere = false;

};

TrieNode* allocateNode() {
    static const int kMaxNodePoolSize = 10001;
    static TrieNode nodesPool[kMaxNodePoolSize];
    static int allocationIndex = 0;
    return &nodesPool[allocationIndex++];
}

struct Trie {
    TrieNode root;

    void addWord(const string_view& word) {
        TrieNode* currentNode = &root;
        for (char c : word) {
            const int childIndex = asciiToIndex(c);
            if (currentNode->children[childIndex] == nullptr) {
                currentNode->children[childIndex] = allocateNode();
            }
            currentNode = currentNode->children[childIndex];
        }
        currentNode->wordEndsHere = true;
    }

    TrieNode* findStartsWith(TrieNode* node, const string_view& word) const {
    
    }

    void loopOverAllChildren(TrieNode* node, string result, int pos) {
        // TODO: finish traversing

        if (node == nullptr) {
            return;
        }

        const int childIndex = asciiToIndex(word[pos]);
        if (node->children[childIndex] == nullptr) {
            return;
        }

        result[pos] = word[pos];    
    }

    void traverse(const TrieNode* node, const string_view& word) {
        // find end node from the prefix defined by word
        TrieNode* startsWithWord = findStartsWith(&root, word);
        if (startsWithWord == nullptr) {
            return;
        }
        
        // prepend the prefix
        string result(word);
        loopOverAllChildren(startsWithWord, result, result.size());           
    }

    void print(const string_view& word) {

        const int childIndex = asciiToIndex(word[0]);

        
        
        TrieNode* currentNode = &root;
        for (char c : word) {
            
        
        }
    }

};

class DB {
    Trie trie;

public:
    void query(const string_view& q) const {
        cout << q << endl;
    }

    void insert(const string_view& q) {
        trie.addWord(q);
    }
};

DB db;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    const int kMaxQueryLen = 32;
    char queryBuffer[kMaxQueryLen] = "";
    while (scanf("%s", queryBuffer) != EOF) {
    
        const string_view query(queryBuffer + 1);
        switch (queryBuffer[0]) {
        case '?':
            db.query(query);
            break;
        case '+':
            db.insert(query);
            break;
        }
    }

    return 0;
}
