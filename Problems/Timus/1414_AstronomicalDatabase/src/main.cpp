/*
 * @author v.sharayenko (grand87@yandex.ru)
 */

#pragma comment(linker, "/STACK:16777216")

#include <stdio.h>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

// #define ONLINE_JUDGE

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
        default:
            return c - 'a' + 10;
    }
}

char indexToAscii(int index) {
    if (index < 10) {
        return '0' + index;
    }
    return index - 10 + 'a';
}

struct TrieNode {
    static const int kMaxNodes = 10 + 26;  // 26
    TrieNode* children[kMaxNodes] = {};
    bool wordEndsHere = false;
};

TrieNode* allocateNode() {
    //static vector<vector<TrieNode>> pagedNodePool(20);
    //static const int kMaxNodePerPoolSize = 20000;
    //static int allocationIndex = 0;
    //static int allocationPool = 0;
    //
    //if (allocationIndex == 0) {
    //    pagedNodePool[allocationPool].resize(kMaxNodePerPoolSize);
    //}

    //TrieNode* result = &pagedNodePool[allocationPool][allocationIndex];

    //allocationIndex++;
    //if (allocationIndex % kMaxNodePerPoolSize == 0) {
    //    allocationPool++;
    //    allocationIndex = 0;
    //}

    static const int kMaxNodePoolSize = 200001;
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
        int posInWord = 0;
        TrieNode* current = node;
        while (current && posInWord < word.size()) {
            int index = asciiToIndex(word[posInWord]);
            current = current->children[index];
            posInWord++;
        }
        if (posInWord == word.size()) {
            return current;
        }
        return nullptr;
    }

    void loopOverAllChildren(TrieNode* node, string result, int pos, int maxToPrint, int& printedCounter) {
        if (printedCounter == maxToPrint) {
            return;
        }

        if (node == nullptr) {
            return;
        }

        if (node->wordEndsHere) {
            if (printedCounter < maxToPrint) {
                string_view w(result.c_str(), pos);
                cout << "  " << w << endl;
                printedCounter++;
            } else {
                return;
            }
        }

        for (int i = 0; i < TrieNode::kMaxNodes; i++) {
            if (node->children[i]) {
                loopOverAllChildren(node->children[i], result + indexToAscii(i), pos + 1, maxToPrint, printedCounter);
            }
        }
    }

    void printAllStartingWith(const string_view& word) {
        TrieNode* prefixNode = findStartsWith(&root, word);
        if (prefixNode) {
            string result(word);
            int printedCounter = 0;
            loopOverAllChildren(prefixNode, result, result.size(), 20, printedCounter);
        }
    }
};

class DB {
    Trie trie;

public:
    void query(const string_view& q) {
        cout << q << endl;
        trie.printAllStartingWith(q);
    }

    void insert(const string_view& q) {
        trie.addWord(q);
    }
};

DB db;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    const int kMaxQueryLen = 32;
    char queryBuffer[kMaxQueryLen] = "";
    db.insert("sun");

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
